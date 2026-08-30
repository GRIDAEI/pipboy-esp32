#include "relacje.h"

// Definicja zmiennej (musi być w pliku .cpp, aby uniknąć błędów linkera 'multiple definition')

#include "../../imgs/Scienta.h"
#include "../../display.h"
#include "../../imgs/Computer_Whiz.h"
#include "../../imgs/FollowersApocalypseReputation.h"
#include "../../imgs/Budownictwo.h"
#include "../../imgs/GoodspringsReputation.h"
#include "../../imgs/PrimmReputation.h"
extern LGFX tft;
Entry relacje_entries[] = {

    {"AEI", -1, "Dobroduszny Lobuz", 0},
    {"Budownictwo.", -1, "Lubiany", 1},
    {"BioInz", -1, "Neutralny", 2},
    {"Elektronik", -1, "Wielbiony", 3},
};

int relacje_max_entries = 4;

struct relacjeImageData {
    const uint16_t* img; // Wskaźnik do tablicy z obrazkiem
    int width;           // Szerokość obrazka
    int height;          // Wysokość obrazka
};
void Relacje::load_relacje_sprites() {
    
    // 2. Tablica z obrazkami i ich indywidualnymi wymiarami
    const relacjeImageData images[] = {
        { Computer_Whiz, 170, 170 }, // [0] Szerokość 70, wysokość 120
        { GoodspringsReputation, GoodspringsReputation_width, GoodspringsReputation_height },  // [1] Przykład innej wielkości (np. 60x60)
        { FollowersApocalypseReputation,FollowersApocalypseReputation_width, FollowersApocalypseReputation_height },  // [2] Kolejny przykład (np. 80x100)
        { PrimmReputation, PrimmReputation_width, PrimmReputation_height}
    }; 
    
    int images_to_load = sizeof(images) / sizeof(images[0]); 
    
    for (int i = 0; i < images_to_load; i++) {
        // Pobieramy wymiary dla aktualnie ładowanego obrazka
        int w = images[i].width;
        int h = images[i].height;

        relacje_sprites[i].setColorDepth(16);
        
        // Odkomentuj to, jeśli masz płytkę z PSRAM
        relacje_sprites[i].setPsram(true); 

        if (!relacje_sprites[i].createSprite(w, h)) {
            Serial.print("Blad alokacji RAM dla sprite'a relacje id: ");
            Serial.println(i);
        } else {
            loadTintedSprite(relacje_sprites[i], images[i].img, w, h, COLOR_GREEN, COLOR_BG);
            
            // Pivot ustawiany dynamicznie na środek (w/2, h/2)
            relacje_sprites[i].setPivot(w / 2, h / 2);
            
        }
    }
}