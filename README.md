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

## Gotowe Płytki PCB

W projekcie zawarto pliki produkcyjne dla autorskich płytek drukowanych (PCB). Dostępne są **2 wersje** płytki, z czego **najnowsza rewizja v3.0 jest wysoce zalecana** ze względu na znaczne poprawki stabilności układu.

## Dokumentacja Projektu

Szczegółowe informacje techniczne oraz instrukcje zostały wydzielone do osobnych plików, aby ułatwić nawigację po repozytorium:

- **[Sprzęt i Elektronika (Hardware)](docs/HARDWARE.md)** – schemat układu, kompletna lista komponentów (BOM), tabela podłączeń pinów oraz informacje o zastosowanych modułach (wibracje, DAC).
- **[Architektura Oprogramowania (Software)](docs/SOFTWARE.md)** – objaśnienie działania interfejsu wizualnego (LovyanGFX), buforowanie tekstur w PSRAM, obsługa przerwań enkodera oraz zarządzanie dźwiękiem z LittleFS.
- **[Instrukcja Budowy (Build Guide)](docs/BUILD_GUIDE.md)** – przewodnik krok po kroku, jak skompilować projekt, skonfigurować środowisko PlatformIO i wgrać wymagany obraz pamięci Flash.

## 📁 Struktura Projektu

- `/src/screens/` - Logika odpowiedzialna za poszczególne zakładki interfejsu (Status, S.P.E.C.I.A.L, Ekwipunek, Mapy).
- `/src/modules/` - Sterowniki modułów takich jak Audio (I2S), Enkoder i obsługa karty SD.
- `/src/imgs/` - Tekstury, sprite'y i tablice z grafikami przygotowanymi do użycia.
- `/docs/` - Rozszerzona dokumentacja techniczna projektu.
- `main.cpp` - Główna pętla programu, sekwencja startowa (Boot OS) i dystrybucja wejść.

## Licencja

To jest projekt fanowski. _Pip-Boy_, _Vault Boy_ oraz _Fallout_ są zarejestrowanymi znakami towarowymi Bethesda Softworks LLC. Projekt został stworzony wyłącznie w celach edukacyjnych oraz hobbystycznych (cosplay).

---

_"Prepared for the Future"_ -- Vault-Tec Corporation
