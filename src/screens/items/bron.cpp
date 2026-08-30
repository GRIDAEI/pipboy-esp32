#include "bron.h"

#include "../../imgs/Scienta.h"
#include "../../display.h"

#include "../../imgs/556gun.h"
#include "../../imgs/Laser_rifle_icon.h"
#include "../../imgs/Laser_pistol_icon.h"
#include "../../imgs/Dynamite_icon.h"

extern LGFX tft;
Entry bron_entries[] = {
    {"Pistolet", -1, "test", 0, 21, 1, 11, 90},
    {"K. Laserowy", -1, "test", 1, 21, 1, 11, 90},
    {"Dynamit", -1, "test", 2, 21, 1, 11, 90}

};

int bron_max_entries = 3;
// 3. INICJALIZACJA: Przypisujemy główny ekran do każdego sprite'a w tablicy

struct bronImageData {
    const uint16_t* img; // Wskaźnik do tablicy z obrazkiem
    int width;           // Szerokość obrazka
    int height;          // Wysokość obrazka
};
void Bron::load_bron_sprites() {
    
    // 2. Tablica z obrazkami i ich indywidualnymi wymiarami
    const bronImageData images[] = {
        { gun, gun_width, gun_height },
        { Laser_pistol_icon, Laser_pistol_icon_width, Laser_pistol_icon_height},
        { Dynamite_icon, Dynamite_icon_width, Dynamite_icon_height}
       }; 
    
    int images_to_load = sizeof(images) / sizeof(images[0]); 
    
    for (int i = 0; i < images_to_load; i++) {
        // Pobieramy wymiary dla aktualnie ładowanego obrazka
        int w = images[i].width;
        int h = images[i].height;

        bron_sprites[i].setColorDepth(16);
        
        // Odkomentuj to, jeśli masz płytkę z PSRAM
        bron_sprites[i].setPsram(true); 
        loadTintedSprite(bron_sprites[i], images[i].img, w, h, COLOR_GREEN, COLOR_BG);
        bron_sprites[i].setPivot(w / 2, h / 2);
        
    }
}