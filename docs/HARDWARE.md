# Sprzęt i Elektronika (Hardware)

Ten dokument opisuje warstwę sprzętową projektu Pip-Boy 3000, w tym użyte komponenty, zasilanie oraz peryferia.

## Schemat i Główne Moduły

Projekt opiera się na mikrokontrolerze **ESP32-S3**, który zarządza wyświetlaczem SPI, dźwiękiem I2S oraz czytnikiem kart pamięci, a także zbiera sygnały wejściowe od użytkownika.

### 1. Mikrokontroler

Zastosowano płytkę ewaluacyjną **ESP32-S3-DEVKITC-1-N16R8**.

- **Dlaczego ta wersja?** Układ ESP32-S3 jest wyposażony w dodatkową pamięć **8MB PSRAM (Octal SPI)**, co jest absolutnie kluczowe do buforowania dużych tekstur o wysokiej rozdzielczości (takich jak mapy czy animacje Vault Boya) bez zapychania standardowej pamięci RAM (której jest tylko 512KB).

### 2. Wyświetlacz TFT

Ekran komunikuje się z mikrokontrolerem po szybkiej magistrali SPI (piny `TFT_SCK`, `TFT_SDI`, `TFT_DC`, `TFT_CS`, `TFT_RESET`).

### 3. System Audio

Dźwięk generowany jest w pełni cyfrowo z wykorzystaniem protokołu I2S.

- **DAC:** Zewnętrzny moduł przetwornika (np. MAX98357A).
- Sygnały I2S: Zegar kanałów (`LRCLK`), Zegar bitowy (`BCLK`), oraz linia danych (`DIN`).

### 4. Sprzężenie zwrotne (Haptyka)

Aby symulować działanie "prawdziwego" urządzenia, zastosowano 2 silniczki wibracyjne (`Vibr1`, `Vibr2`).

- Są one sterowane poprzez **N-kanałowe tranzystory MOSFET** (Q2, Q3) działające jako klucze.
- Dołożono diody Schottky'ego (D1, D2) podłączone zaporowo, które pełnią funkcję tzw. _flyback diode_ – chronią porty mikrokontrolera przed przepięciami (skokami napięcia) powstającymi przy wyłączaniu cewek silników.

### 5. Pamięć Masowa

Płyta uwzględnia zewnętrzny moduł karty **Micro SD**, który służy jako dodatkowy magazyn danych na ciężkie pliki multimedialne.

---

## 🖨️ Projekty Płytek Drukowanych (PCB)

W głównym drzewie repozytorium znajdziesz gotowe projekty płytek drukowanych, które pozwalają złożyć system w profesjonalny, kompaktowy sposób bez plątaniny kabli (co ułatwia montaż w obudowie Pip-Boya).

Obecnie udostępniamy dwie wersje projektu PCB:

- **Wersja starsza**: Pierwotna koncepcja układu.
- **Wersja v3.0 (ZALECANA)**: Najnowsza rewizja płytki. Posiada kluczowe poprawki dotyczące stabilności układu, lepsze oddzielenie sekcji zasilania od części logicznej oraz zoptymalizowane prowadzenie ścieżek układu audio I2S (niwelacja szumów). Zdecydowanie polecamy produkcję i lutowanie **wersji v3.0**.

---

## 📋 Lista Komponentów (BOM)

Poniżej znajduje się zestawienie części potrzebnych do zbudowania elektroniki.

| Komponent                 | Model / Specyfikacja                 | Rola w systemie                                        | Gdzie kupić (Link)                                                                                                                                                                                                                                    |
| :------------------------ | :----------------------------------- | :----------------------------------------------------- | :---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| **Mikrokontroler**        | ESP32-S3-DEVKITC-1-N16R8             | "Mózg" operacji, renderowanie UI, obsługa PSRAM        | [Link](https://kamami.pl/esp32/1197037-esp32-s3-microcontroller-2-4ghz-wi-fi-development-board-240mhz-dual-core-processor-esp32-s3-wroom-5906623499045.html)                                                                                          |
| **Wyświetlacz**           | [TFT SPI 4.0' ST7796]                | Prezentacja interfejsu tft                             | [Link](https://pl.aliexpress.com/item/1005005787550807.html?spm=a2g0o.tesla.0.0.8777Oh9WOh9WV1&pvid=5250567e-c9e9-49b6-9dc2-6a1e70e9b9a4&afTraceInfo=1005005787550807__pc__c_ppc_item_bridge_pc_same_wf__afOxyRu__1788641705650&gatewayAdapt=glo2pol) |
| **Przetwornik Audio**     | MAX98357A                            | Odtwarzanie kliknięć i dźwięków UI po I2S              | [Link](https://www.gotronik.pl/modul-wzmacniacza-audio-i2s-3w-klasa-d-dacmax98357-p-13866.html)                                                                                                                                                       |
| **Głośnik**               | Głośnik 1W 8Ohm                      | Emisja dźwięku                                         | [Link](https://botland.com.pl/glosniki-analogowe/26596-glosnik-1w-8ohm-30mm-sparkfun-com-27247-5904422387907.html)                                                                                                                                    |
| **Enkoder obrotowy**      | EC10E1220503                         | Nawigacja góra/dół                                     | [Link](https://www.tme.eu/pl/details/ec10e1220503/enkodery-inkrementalne/alps/)                                                                                                                                                                       |
| **Przyciski funkcyjne**   | [Uzupełnij np. Tact Switch 12x12mm]  | Zmiana zakładek (Stats, Items, Data)                   | [Uzupełnij]                                                                                                                                                                                                                                           |
| **Silniki Wibracyjne**    | [Uzupełnij np. płaskie silniki coin] | Haptyczne wibracje zwrotne                             | [Uzupełnij](Link)                                                                                                                                                                                                                                     |
| **Tranzystory MOSFET**    | [Uzupełnij np. 2N7002, logic-level]  | Włączanie zasilania silniczków (3.3V) z GPIO ESP32     | [Uzupełnij]                                                                                                                                                                                                                                           |
| **Diody Zabezpieczające** | SS24                                 | Zabezpieczenie przed przepięciami z silników (flyback) | [Uzupełnij]                                                                                                                                                                                                                                           |
| **Rezystory**             | [Uzupełnij, np. 10kOhm pull-down]    | Stabilizacja stanów na bramkach MOSFETów i SPI         | [Uzupełnij]                                                                                                                                                                                                                                           |
|  |

## 🔌 Tabela Połączeń (Pinout)

_Zostawiam to miejsce na szczegółową rozpiskę pinów. Ułatwia to testowanie na płytce stykowej._

| ESP32-S3 Pin           | Komponent docelowy | Opis Sygnału               |
| :--------------------- | :----------------- | :------------------------- |
| [Uzupełnij np. GPIO15] | `TFT_CS`           | SPI Chip Select dla ekranu |
| ...                    | ...                | ...                        |
