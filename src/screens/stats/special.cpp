#include "special.h"

#include "../../imgs/Strength2_icon.h"
#include "../../imgs/perception.h"
#include "../../imgs/Endurance.h"
#include "../../imgs/zydu.h"
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

struct SpecialImageData {
    const uint16_t* img; // Wskaźnik do tablicy z obrazkiem
    int width;           // Szerokość obrazka
    int height;          // Wysokość obrazka
};
void Special::load_special_sprites() {
    
    // 2. Tablica z obrazkami i ich indywidualnymi wymiarami
    const SpecialImageData images[] = {
        { Strength2_icon, 70, 120 }, // [0] Szerokość 70, wysokość 120
        { Strength2_icon, 70, 120 },  // [1] Przykład innej wielkości (np. 60x60)
        { Zydu, 126, 160 }  // [2] Kolejny przykład (np. 80x100)
        // Jak dodasz nowe, po prostu dopisuj kolejne linijki: { nazwa_pliku, szerokosc, wysokosc }
    }; 
    
    // Automatyczne liczenie ilości obrazków (nie musisz już tego zmieniać ręcznie!)
    int images_to_load = sizeof(images) / sizeof(images[0]); 
    
    for (int i = 0; i < images_to_load; i++) {
        // Pobieramy wymiary dla aktualnie ładowanego obrazka
        int w = images[i].width;
        int h = images[i].height;

        special_sprites[i].setColorDepth(16);
        
        // Odkomentuj to, jeśli masz płytkę z PSRAM
        special_sprites[i].setPsram(true); 

        // ZABEZPIECZENIE: Tworzymy sprite'a z indywidualnymi wymiarami (w, h)
        if (!special_sprites[i].createSprite(w, h)) {
            Serial.print("Blad alokacji RAM dla sprite'a SPECIAL id: ");
            Serial.println(i);
        } else {
            special_sprites[i].setSwapBytes(true); // Zmień na false jeśli kolory będą złe
            
            // Wgrywamy obrazek używając specyficznych wymiarów i wskaźnika
            special_sprites[i].pushImage(0, 0, w, h, images[i].img);
            
            // Pivot ustawiany dynamicznie na środek (w/2, h/2)
            special_sprites[i].setPivot(w / 2, h / 2);
            
            Serial.print("Zaladowano sprite SPECIAL id: ");
            Serial.print(i);
            Serial.print(" (wymiary: ");
            Serial.print(w);
            Serial.print("x");
            Serial.print(h);
            Serial.println(")");
        }
    }
}