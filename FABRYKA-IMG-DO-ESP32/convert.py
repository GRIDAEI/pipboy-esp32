import sys
import os

TRANSPARENT_COLOR_565 = 0xF81F  # Magenta do wycinania przezroczystości

# ── USTAWIENIA KOLORÓW ────────────────────────────────────────────────────────
# Kolor Vault Boya (jasny, jaskrawy zielony)
TARGET_RGB = (72, 232, 104)

# Kolor Twojego tła na ekranie TFT (ciemno-zielony). 
# Podaj tutaj taki kolor, jaki masz jako tło pod Vault Boyem!
BG_RGB = (5, 36, 9) 
# ──────────────────────────────────────────────────────────────────────────────

def convert(input_path):
    try:
        from PIL import Image
    except ImportError:
        print("BŁĄD: Brak biblioteki Pillow.")
        return

    print(f"\n→ Przetwarzanie: {input_path}")
    if not os.path.exists(input_path): return

    img = Image.open(input_path).convert("RGBA")
    width, height = img.size
    pixels = img.getdata()

    out_data = []
    
    for r, g, b, a in pixels:
        # Jeśli piksel jest CAŁKOWICIE przezroczysty -> dajemy magentę
        if a == 0:
            out_data.append(TRANSPARENT_COLOR_565)
        else:
            # Obliczamy jasność oryginalnego piksela, żeby zachować szczegóły rysunku
            brightness = (r * 0.299 + g * 0.587 + b * 0.114) / 255.0
            
            # Docelowy kolor rysunku (jasnozielony)
            fg_r = TARGET_RGB[0] * brightness
            fg_g = TARGET_RGB[1] * brightness
            fg_b = TARGET_RGB[2] * brightness
            
            # MIESZANIE KRAWĘDZI (Anti-aliasing)
            # Jeśli piksel jest półprzezroczysty, mieszamy go z kolorem tła ekranu
            alpha = a / 255.0
            final_r = int(fg_r * alpha + BG_RGB[0] * (1.0 - alpha))
            final_g = int(fg_g * alpha + BG_RGB[1] * (1.0 - alpha))
            final_b = int(fg_b * alpha + BG_RGB[2] * (1.0 - alpha))
            
            # Zabezpieczenie przed przekroczeniem zakresu
            final_r = max(0, min(255, final_r))
            final_g = max(0, min(255, final_g))
            final_b = max(0, min(255, final_b))

            # Konwersja do 16-bitowego formatu RGB565
            c565 = ((final_r & 0xF8) << 8) | ((final_g & 0xFC) << 3) | (final_b >> 3)
            
            # Zabezpieczenie, żeby wygładzony piksel nie stał się magentą (zniknąłby)
            if c565 == TRANSPARENT_COLOR_565: c565 = 0xF81E 
            
            out_data.append(c565)

    base_name = os.path.splitext(os.path.basename(input_path))[0]
    var_name = base_name.replace(" ", "_").replace("-", "_").replace(".", "_")
    output_path = os.path.join(os.path.dirname(input_path), base_name + ".h")

    with open(output_path, "w", encoding="utf-8") as f:
        f.write("#pragma once\n")
        f.write("#include <stdint.h>\n\n")
        f.write(f"// Wymiary: {width} x {height}\n")
        f.write(f"// Kolor rysunku: {TARGET_RGB} | Tło pod spodem: {BG_RGB}\n")
        f.write(f"// Transparent: 0xF81F\n\n")
        f.write(f"const uint16_t {var_name}[{len(out_data)}] PROGMEM = {{\n")
        
        for i in range(0, len(out_data), 12):
            chunk = out_data[i:i+12]
            f.write("    " + ", ".join(f"0x{val:04X}" for val in chunk) + ",\n")
        f.write("};\n")

    print(f"✓ Zapisano wygładzoną tablicę: {output_path}")

if __name__ == "__main__":
    files = sys.argv[1:]
    if not files:
        files = [input("Podaj ścieżkę do pliku: ").strip().strip('"')]
    for f in files: convert(f)