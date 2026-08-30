#include "ammo.h"

#include "../../imgs/Scienta.h"
#include "../../display.h"

#include "../../imgs/FNV_Energy_cell_icon.h"

extern LGFX tft;
Entry ammo_entries[] = {
    {"Ogniwo ener.", -1, "Amunicja do broni laserowej.", 0, 100, 1, 3, 8}

};

int ammo_max_entries = 1;


struct ammoImageData {
    const uint16_t* img; // Wskaźnik do tablicy z obrazkiem
    int width;           // Szerokość obrazka
    int height;          // Wysokość obrazka
};
void Ammo::load_ammo_sprites() {
    
    // 2. Tablica z obrazkami i ich indywidualnymi wymiarami
    const ammoImageData images[] = {
        {FNV_Energy_cell_icon, FNV_Energy_cell_icon_width, FNV_Energy_cell_icon_height},

       }; 
    
    int images_to_load = sizeof(images) / sizeof(images[0]); 
    
    for (int i = 0; i < images_to_load; i++) {
        // Pobieramy wymiary dla aktualnie ładowanego obrazka
        int w = images[i].width;
        int h = images[i].height;

        ammo_sprites[i].setColorDepth(16);
        
        // Odkomentuj to, jeśli masz płytkę z PSRAM
        ammo_sprites[i].setPsram(true); 
        loadTintedSprite(ammo_sprites[i], images[i].img, w, h, COLOR_GREEN, COLOR_BG);
        ammo_sprites[i].setPivot(w / 2, h / 2);
        
    }
}