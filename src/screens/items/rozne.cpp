#include "rozne.h"

#include "../../imgs/Scienta.h"
#include "../../display.h"

#include "../../imgs/Icon_junk.h"

extern LGFX tft;
Entry rozne_entries[] = {
    {"Zlom", -1, "Kawalek metalu z czegos co kiedys mialo swoja misje.", 0, 100, 5, 0, 8}

};

int rozne_max_entries = 1;

struct rozneImageData {
    const uint16_t* img; // Wskaźnik do tablicy z obrazkiem
    int width;           // Szerokość obrazka
    int height;          // Wysokość obrazka
};
void Rozne::load_rozne_sprites() {
    
    const rozneImageData images[] = {
        {Icon_junk, Icon_junk_width, Icon_junk_height},

       }; 
    
    int images_to_load = sizeof(images) / sizeof(images[0]); 
    
    for (int i = 0; i < images_to_load; i++) {
        // Pobieramy wymiary dla aktualnie ładowanego obrazka
        int w = images[i].width;
        int h = images[i].height;

        rozne_sprites[i].setColorDepth(16);
        
        rozne_sprites[i].setPsram(true); 
        loadTintedSprite(rozne_sprites[i], images[i].img, w, h, COLOR_GREEN, COLOR_BG);
        rozne_sprites[i].setPivot(w / 2, h / 2);
        
    }
}