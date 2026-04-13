#include "special.h"

#include "../../imgs/Strength2_icon.h"
#include "../../imgs/perception.h"
#include "../../imgs/Endurance.h"
#include "../../display.h"
extern LGFX tft;
Entry special_entries[] = {
    {"Sila", 8, "Surowa sila fizyczna. Wysoka siła jest przydatna zwłaszcza dla postaci bazujących na cechach fizycznych.", 0},
    {"Percepcja", 4, "Opis percepcji", 1},
    {"Wytrzymalosc", 5, "Opis wytrzymalosc", 2},
    {"Charyzma", 4, "Opis charyzmy", 2},
    {"Inteligencja", 7, "Opis inteligencji", 2},
    {"Zwinnosc", 4, "Opis zwinnosci", 2},
    {"Szczescie", 3, "Opis szczescia", 2}
};


// 3. INICJALIZACJA: Przypisujemy główny ekran do każdego sprite'a w tablicy
LGFX_Sprite special_sprites[3];

// 4. Implementacja funkcji ładującej obrazki
void load_special_sprites() {
    special_sprites[0] = LGFX_Sprite(&tft);
    // Dobra praktyka dla ESP32-S3: jeśli masz zewnętrzny RAM (PSRAM), 
    // odkomentuj poniższą linijkę, aby zaoszczędzić cenną pamięć SRAM:
    // special_sprites[0].setPsram(true);

    // special_sprites[0].setColorDepth(16);
    // special_sprites[0].createSprite(70, 120); // Teraz zadziała bez błędu!
    // special_sprites[0].setSwapBytes(true);
    // special_sprites[0].pushImage(0, 0, 70, 120, Strength2_icon);

    // ... reszta Twojego kodu
}