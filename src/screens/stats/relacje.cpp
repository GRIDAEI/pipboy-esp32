#include "relacje.h"

#include "../../imgs/Scienta.h"
#include "../../display.h"
#include "../../imgs/Computer_Whiz.h"
#include "../../imgs/BioInz.h"
#include "../../imgs/Budownictwo.h"
extern LGFX tft;
Entry relacje_entries[] = {


    {"AEI", -1, "Lubiany", 0},
    {"Budownictwo.", -1, "Mieszane", 1},
    {"BioInz", -1, "Cieple", 2},
    {"Elektronik", -1, "Zadajesz wszystkim innym frakcjom 1.5 razy wiecej obrazen, ale tyle samo od nich otrzymujesz.", 2},
};

int relacje_max_entries = 4;
// 3. INICJALIZACJA: Przypisujemy główny ekran do każdego sprite'a w tablicy

struct relacjeImageData {
    const uint16_t* img; // Wskaźnik do tablicy z obrazkiem
    int width;           // Szerokość obrazka
    int height;          // Wysokość obrazka
};
void Relacje::load_relacje_sprites() {
    
    // 2. Tablica z obrazkami i ich indywidualnymi wymiarami
    const relacjeImageData images[] = {
        { Computer_Whiz, 170, 170 }, // [0] Szerokość 70, wysokość 120
        { Budownictwo, 104, 120 },  // [1] Przykład innej wielkości (np. 60x60)
        { BioInz,110, 120 }  // [2] Kolejny przykład (np. 80x100)
        // Jak dodasz nowe, po prostu dopisuj kolejne linijki: { nazwa_pliku, szerokosc, wysokosc }
    }; 
    
    // Automatyczne liczenie ilości obrazków (nie musisz już tego zmieniać ręcznie!)
    int images_to_load = sizeof(images) / sizeof(images[0]); 
    
    for (int i = 0; i < images_to_load; i++) {
        // Pobieramy wymiary dla aktualnie ładowanego obrazka
        int w = images[i].width;
        int h = images[i].height;

        relacje_sprites[i].setColorDepth(16);
        
        // Odkomentuj to, jeśli masz płytkę z PSRAM
        relacje_sprites[i].setPsram(true); 

        // ZABEZPIECZENIE: Tworzymy sprite'a z indywidualnymi wymiarami (w, h)
        if (!relacje_sprites[i].createSprite(w, h)) {
            Serial.print("Blad alokacji RAM dla sprite'a relacje id: ");
            Serial.println(i);
        } else {
            relacje_sprites[i].setSwapBytes(true); // Zmień na false jeśli kolory będą złe
            
            // Wgrywamy obrazek używając specyficznych wymiarów i wskaźnika
            relacje_sprites[i].pushImage(0, 0, w, h, images[i].img);
            
            // Pivot ustawiany dynamicznie na środek (w/2, h/2)
            relacje_sprites[i].setPivot(w / 2, h / 2);
            
        }
    }
}