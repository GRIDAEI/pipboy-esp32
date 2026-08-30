import sys
import os
from PIL import Image

TRANSPARENT_COLOR_565 = 0xF81F
BG_RGB = (0, 0, 0) # Tło ustawiłem na czarne, to uniwersalna baza pod zmianę motywów

def convert(input_path):
    print(f"\n→ Przetwarzanie: {input_path}")
    if not os.path.exists(input_path): return

    img = Image.open(input_path).convert("RGBA")
    width, height = img.size
    pixels = img.getdata()

    out_data = []

    for r, g, b, a in pixels:
        if a == 0:
            out_data.append(TRANSPARENT_COLOR_565)
        else:
            alpha = a / 255.0
            
            # Pobieramy jasność piksela (tworzymy obraz w skali szarości)
            brightness = (r * 0.299 + g * 0.587 + b * 0.114) / 255.0
            gray_val = int(255 * brightness)

            # Mieszamy z czarnym tłem (gładkie krawędzie - anti-aliasing)
            final_r = int(gray_val * alpha + BG_RGB[0] * (1.0 - alpha))
            final_g = int(gray_val * alpha + BG_RGB[1] * (1.0 - alpha))
            final_b = int(gray_val * alpha + BG_RGB[2] * (1.0 - alpha))

            # Bezpieczniki zakresu
            final_r = max(0, min(255, final_r))
            final_g = max(0, min(255, final_g))
            final_b = max(0, min(255, final_b))

            # Konwersja na RGB565
            c565 = ((final_r & 0xF8) << 8) | ((final_g & 0xFC) << 3) | (final_b >> 3)
            
            # Zabezpieczenie przezroczystości
            if c565 == TRANSPARENT_COLOR_565: c565 = 0xF81E
            out_data.append(c565)

    base_name = os.path.splitext(os.path.basename(input_path))[0]
    var_name = base_name.replace(" ", "_").replace("-", "_").replace(".", "_")
    output_path = os.path.join(os.path.dirname(input_path), base_name + ".h")

    with open(output_path, "w", encoding="utf-8") as f:
        f.write("#pragma once\n")
        f.write("#include <stdint.h>\n\n")
        f.write(f"// Wygenerowane w SKALI SZAROSCI (gotowe do kolorowania w ESP)\n")
        f.write(f"// Transparent: 0xF81F\n\n")
        f.write(f"const int {var_name}_width = {width};\n")
        f.write(f"const int {var_name}_height = {height};\n\n")
        f.write(f"const uint16_t {var_name}[{len(out_data)}] PROGMEM = {{\n")
        
        for i in range(0, len(out_data), 12):
            chunk = out_data[i:i+12]
            f.write("    " + ", ".join(f"0x{val:04X}" for val in chunk) + ",\n")
        f.write("};\n")

    print(f"✓ Zapisano szarą bazę: {output_path}")

if __name__ == "__main__":
    files = sys.argv[1:]
    if not files:
        files = [input("Podaj ścieżkę do pliku: ").strip().strip('"')]
    for f in files: convert(f)