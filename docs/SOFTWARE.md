# 💻 Architektura Oprogramowania (Software)

Projekt jest pisany w **C++** i kompilowany przy użyciu środowiska **PlatformIO** w frameworku Arduino dla ESP32.

Poniżej znajduje się omówienie kluczowych modułów programistycznych i decyzji architektonicznych.

## 🖼️ Interfejs Graficzny i Wyświetlacz (UI)

Zamiast standardowej i wolnej biblioteki TFT_eSPI, silnik GUI opiera się o bibliotekę **[LovyanGFX](https://github.com/lovyan03/LovyanGFX)**.

- **Wydajność:** LovyanGFX pozwala na asynchroniczne transfery DMA (Direct Memory Access) po magistrali SPI. Dzięki temu mikrokontroler nie jest zablokowany podczas przerysowywania pełnoekranowych klatek.
- **Double Buffering (Opcjonalnie):** W celu wyeliminowania zjawiska "migotania" (tearing/flickering) podczas odświeżania zakładek w interfejsie.

### Zarządzanie Pamięcią (PSRAM)

Zwykły ESP32 posiada zbyt mało pamięci RAM (ok. 520 KB), by pomieścić nieskompresowane mapy bitowe w 16-bitowym kolorze (np. 320x480).

- Rozwiązaniem jest wykorzystanie wariantu ESP32-S3 posiadającego **8MB zewnętrznej pamięci PSRAM**.
- Tekstury (jak grafiki Pip-Boya, mapy Pustkowi, ikony ekwipunku) zapisane są w pamięci flash. Podczas pracy programu, odpowiednie tekstury są wgrywane bezpośrednio na bieżąco (lub buforowane z wyprzedzeniem) do PSRAM przy użyciu `ps_malloc()`.
- Zapewnia to błyskawiczny dostęp do grafik podczas szybkiego przełączania między zakładkami.

## 🔊 System Audio (I2S)

Pip-Boy to nie tylko grafika, ale i kultowe dźwięki kliknięć i radiacji.

1.  Dźwięki (w formacie `.wav` lub `.mp3`) przechowywane są we wbudowanej pamięci Flash przy użyciu systemu plików **LittleFS** lub na zewnętrznej karcie pamięci Micro SD.
2.  Wykorzystywana jest biblioteka **ESP8266Audio**.
3.  Mikrokontroler strumieniuje dane dźwiękowe do zewnętrznego układu DAC poprzez sprzętową magistralę **I2S**. Użycie oddzielnego układu cyfrowo-analogowego minimalizuje zakłócenia i zniekształcenia dźwięku.
4.  Uruchomiono sprzętowe miksowanie kanałów, by w przyszłości nakładać efekty dźwiękowe UI (np. szum kliknięcia) na odtwarzane radio.

## 🎛️ Obsługa Wejść (Enkoder i Przyciski)

Do odczytu nawigacji wykorzystywany jest enkoder obrotowy i przyciski przednie (`FNTBTN`).

- **Przerwania (Interrupts):** Odczyt enkodera realizowany jest poprzez asynchroniczne przerwania sprzętowe (ISR), a nie poprzez ciągłe odpytywanie w pętli `loop()` (tzw. polling). Zapewnia to natychmiastową reakcję i to, że żaden "skok" obrotu nie zostanie zgubiony.
- **Debouncing:** Zaimplementowano programowy debouncing dla przycisków przednich oraz przełącznika pozycyjnego, by wyeliminować fałszywe podwójne wciśnięcia wywołane drganiem styków.

## ⚡ Struktura Główna

Kod źródłowy zorganizowany jest wokół głównych widoków:

- `/src/screens/` - Pliki definiujące rysowanie i logikę ekranów (Status, Inventory, Data, Map).
- `/src/modules/` - Klasy abstrakcyjne odpowiedzialne za podzespoły sprzętowe (Manager dźwięku, Manager wejść).
