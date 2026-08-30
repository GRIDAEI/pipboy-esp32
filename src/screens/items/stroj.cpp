#include "stroj.h"

#include "../../imgs/Scienta.h"
#include "../../display.h"

#include "../../imgs/Icon_Vault_21_jumpsuit.h"

extern LGFX tft;
Entry stroj_entries[] = {
    {"Zbroja Sch.21", -1, "test", 0, 100, 15, 180, 8}

};

int stroj_max_entries = 1;
// 3. INICJALIZACJA: Przypisujemy główny ekran do każdego sprite'a w tablicy

struct strojImageData {
    const uint16_t* img; // Wskaźnik do tablicy z obrazkiem
    int width;           // Szerokość obrazka
    int height;          // Wysokość obrazka
};
void Stroj::load_stroj_sprites() {
    
    // 2. Tablica z obrazkami i ich indywidualnymi wymiarami
    const strojImageData images[] = {
        {Icon_Vault_21_jumpsuit, Icon_Vault_21_jumpsuit_width, Icon_Vault_21_jumpsuit_height},

       }; 
    
    int images_to_load = sizeof(images) / sizeof(images[0]); 
    
    for (int i = 0; i < images_to_load; i++) {
        // Pobieramy wymiary dla aktualnie ładowanego obrazka
        int w = images[i].width;
        int h = images[i].height;

        stroj_sprites[i].setColorDepth(16);
        
        // Odkomentuj to, jeśli masz płytkę z PSRAM
        stroj_sprites[i].setPsram(true); 
        loadTintedSprite(stroj_sprites[i], images[i].img, w, h, COLOR_GREEN, COLOR_BG);
        stroj_sprites[i].setPivot(w / 2, h / 2);
        
    }
}