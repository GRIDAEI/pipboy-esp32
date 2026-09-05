# 🚀 Instrukcja Budowy i Uruchomienia (Build Guide)

Ten projekt zarządzany jest w pełni poprzez środowisko **PlatformIO**, co ułatwia zarządzanie bibliotekami i flagami dla frameworka ESP-IDF / Arduino.

## 1. Wymagania wstępne

- Pobierz i zainstaluj edytor **Visual Studio Code (VS Code)**.
- Zainstaluj rozszerzenie **PlatformIO IDE** w VS Code.
- Przygotuj płytkę ESP32-S3 oraz odpowiedni kabel USB ze wsparciem przesyłu danych.

## 2. Klonowanie i konfiguracja

1. Sklonuj repozytorium:
   ```bash
   git clone https://github.com/TwojaNazwaUzytkownika/PipBoy-ESP32.git
   ```
2. Otwórz pobrany folder w VS Code (PlatformIO powinno automatycznie rozpoznać projekt i rozpocząć pobieranie paczek).
3. (Opcjonalnie) Dostosuj środowisko w pliku `platformio.ini`, upewnij się, że port COM jest prawidłowo wykrywany.

## 3. Wgrywanie systemu plików (PAMIĘTAJ O TYM!)

Projekt wymaga plików multimedialnych (dźwięki, grafiki statyczne, czcionki), które umieszczone są w folderze `data/`. Należy je wgrać na osobną partycję **LittleFS** we Flashu mikrokontrolera.

- W VS Code rozwiń menu **PlatformIO** po lewej stronie (ikona mrówki).
- Wybierz swój profil (np. `esp32-s3-devkitc-1`).
- Rozwiń zakładkę **Platform**.
- Kliknij zadanie **Build Filesystem Image**.
- Następnie kliknij **Upload Filesystem Image**.
  _(Uwaga: w zależności od Twojego układu, wgrywanie obrazu przez USB może wymagać wciśnięcia przycisku BOOT na płytce)._

## 4. Wgrywanie Kodu Głównego

Gdy system plików jest już na mikrokontrolerze, można wgrać kod aplikacji:

1. Kliknij na ikonę strzałki (`Upload`) w dolnym pasku narzędzi VS Code PlatformIO.
2. Po pomyślnym kompilowaniu i wysłaniu, podgląd można uruchomić klikając w ikonę wtyczki (`Serial Monitor`), by śledzić komunikaty logowania i błędów w sekwencji startowej Boot OS.
