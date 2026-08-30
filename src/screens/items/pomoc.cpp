#include "pomoc.h"

#include "../../imgs/Scienta.h"
#include "../../display.h"

#include "../../imgs/Icon_stimpak.h"
#include "../../imgs/Icon_Buffout.h"

extern LGFX tft;
Entry pomoc_entries[] = {
    {"Stimpak", -1, "Najpopularniejszy srodek leczniczy, nie powodujacy zadnych skutkow ubocznych.", 0, 100, 2, 200, 15},
    {"Wygrzew", -1, "Wysoce zaawansowane sterydy. Czasowo zwiekszaja sile i poprawiaja refleks. Silnie uzalezniajace.", 1, 0, 2, 200, 15},

};

int pomoc_max_entries = 2;


struct pomocImageData {
    const uint16_t* img; // Wskaźnik do tablicy z obrazkiem
    int width;           // Szerokość obrazka
    int height;          // Wysokość obrazka
};
void Pomoc::load_pomoc_sprites() {
    
    // 2. Tablica z obrazkami i ich indywidualnymi wymiarami
    const pomocImageData images[] = {
        {Icon_stimpak, Icon_stimpak_width, Icon_stimpak_height},
        {Icon_Buffout, Icon_Buffout_width, Icon_Buffout_height}
       }; 
    
    int images_to_load = sizeof(images) / sizeof(images[0]); 
    
    for (int i = 0; i < images_to_load; i++) {
        // Pobieramy wymiary dla aktualnie ładowanego obrazka
        int w = images[i].width;
        int h = images[i].height;

        pomoc_sprites[i].setColorDepth(16);
        
        // Odkomentuj to, jeśli masz płytkę z PSRAM
        pomoc_sprites[i].setPsram(true); 
        loadTintedSprite(pomoc_sprites[i], images[i].img, w, h, COLOR_GREEN, COLOR_BG);
        pomoc_sprites[i].setPivot(w / 2, h / 2);
        
    }
}