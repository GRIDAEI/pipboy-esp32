# Pip-Boy 3000 - ESP32-S3 Replica OS ☢️

![PlatformIO](https://img.shields.io/badge/PlatformIO-Compatible-orange)
![ESP32-S3](https://img.shields.io/badge/Hardware-ESP32--S3-blue)
![C++](https://img.shields.io/badge/Language-C++-00599C)
![Fallout](https://img.shields.io/badge/Theme-Fallout-green)

Projekt ma na celu jak najdokładniejsze odtworzenie kultowego urządzenia z serii gier Fallout.
**Pip-Boy 3000**, znany głównie z _Fallout 3_ oraz _Fallout: New Vegas_, zyskuje tu nowe życie dzięki mikrokontrolerowi ESP32-S3. Projekt łączy oprogramowanie (UI/UX) z fizycznym sprzętem, tworząc realistyczny rekwizyt.

## Funkcje

- **Płynny Interfejs i Animacje**: Wykorzystanie biblioteki [LovyanGFX](https://github.com/lovyan03/LovyanGFX) zapewnia wysoką wydajność renderowania na ekranie.
- **System Audio I2S**: Autentyczne efekty dźwiękowe interfejsu (kliknięcia, przejścia w menu) odtwarzane przez `ESP8266Audio` i miksowane w czasie rzeczywistym.
- **Pełna Nawigacja**: Enkoder obrotowy, przełącznik obrotowy oraz fizyczne przyciski idealnie zmapowane, co pozwala na nawigację po zakładkach Statystyk, Ekwipunku i Danych, dokładnie tak jak w grze.
- **Ładowanie Obrazów do PSRAM**: Wysokiej rozdzielczości sprite'y (mapy, przedmioty) ładowane dynamicznie do 8MB pamięci PSRAM w celu oszczędzania pamięci RAM.
- **Zegar Czasu Rzeczywistego (RTC)**: Zegar systemowy z możliwością dostosowania i zapisem w pamięci NVS, odporny na restarty.
- **Motywy Kolorystyczne**: Obsługa różnych kolorów interfejsu (Klasyczny Zielony, Bursztynowy, Quantum Blue).
- **Oszczędzanie Energii**: Inteligentne wykrywanie bezczynności obniża taktowanie procesora do 80MHz, by oszczędzać baterię podczas długich wędrówek po Pustkowiach.

## Hardware

Projekt jest zintegrowany z dedykowaną elektroniką. Główne komponenty użyte w schemacie:

- **Mikrokontroler**: ESP32-S3-DEVKITC-1-N16R8 (Projekt był robiony na tej wersji, **MOŻE** działa na N8R2).
- **Wyświetlacz**: Wyświetlacz TFT ST7796 na magistrali SPI.
- **Pamięć Zewnętrzna**: Moduł czytnika kart Micro SD.
- **Audio**: Moduł DAC I2S MAX98357A.
- **Sterowanie (Wejścia)**:
  - 1x Enkoder Obrotowy (z przyciskiem - złącze ROTENCODER).
  - Fizyczne przyciski przednie (Front Buttons) i diody LED (FNTBTN, FNTLED).
  - Przełącznik Pozycyjny (PosSwitch).
- **Haptyka**: 2x Silniki wibracyjne sterowane tranzystorami MOSFET dla realistycznego sprzężenia zwrotnego.

## Struktura Projektu

- `/src/screens/` - Logika odpowiedzialna za poszczególne zakładki interfejsu (Status, S.P.E.C.I.A.L, Ekwipunek, Mapy).
- `/src/modules/` - Obsługa modułów takich jak Audio (I2S), Enkoder i karta SD.
- `/src/imgs/` - Sprite'y i tablice z grafikami.
- `main.cpp` - Główna pętla programu, sekwencja startowa i obsługa wejść.

## Licencja

To jest projekt fanowski. _Pip-Boy_, _Vault Boy_ oraz _Fallout_ są zarejestrowanymi znakami towarowymi Bethesda Softworks LLC. Projekt został stworzony wyłącznie w celach edukacyjnych oraz hobbystycznych (cosplay).

---

_"Prepared for the Future"_ -- Vault-Tec Corporation
