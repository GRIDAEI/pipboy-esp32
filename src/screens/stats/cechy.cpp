#include "cechy.h"

#include "../../imgs/Here_and_Now.h"
#include "../../imgs/Strength2_icon.h"
#include "../../imgs/WhiskeyRose.h"
#include "../../imgs/TheProfessional.h"
#include "../../imgs/Luck_icon.h"
#include "../../display.h"
extern LGFX tft;
Entry cechy_entries[] = {
    {"Studium Valet", -1, "'Studiowanie na polibudzie az prosi sie o nuklearna zime.'\n\nPermametne zwiekszenie percepcji", 0},
    {"Mocny Leb", -1, "Zdrowie wasze! Ja sie trzymam. \n\nZyskujesz wszystkie pozytywy spozycia alkoholu bez efektow ubocznych.", 1},
    {"G.C.K", -1, "'Mosci panie nic sie nam nie stanie. Przesad to glupota dla plebsu i chlopa.'\n\nRzadziej trafia ci sie pech, ale jak juz to tylko krytycznie.", 2},
    {"Zawodowiec", -1, "'Tak, jestem wolny na wtorek.'\n\nZnacznie polepszona obsluga broni tludamionej",3}
};

int cechy_max_entries = 4;
// 3. INICJALIZACJA: Przypisujemy główny ekran do każdego sprite'a w tablicy

struct cechyImageData {
    const uint16_t* img; // Wskaźnik do tablicy z obrazkiem
    int width;           // Szerokość obrazka
    int height;          // Wysokość obrazka
};
void Cechy::load_cechy_sprites() {
    
    // 2. Tablica z obrazkami i ich indywidualnymi wymiarami
    const cechyImageData images[] = {
        { Here_and_Now, Here_and_Now_width, Here_and_Now_height }, // [0] Szerokość 70, wysokość 120
        { WhiskeyRose, WhiskeyRose_width, WhiskeyRose_height },  // [1] Przykład innej wielkości (np. 60x60)
        { Luck_icon, Luck_icon_width, Luck_icon_height },  // [2] Kolejny przykład (np. 80x100)
        { TheProfessional, TheProfessional_width, TheProfessional_height }
    }; 
    int images_to_load = sizeof(images) / sizeof(images[0]); 
    
    for (int i = 0; i < images_to_load; i++) {
        // Pobieramy wymiary dla aktualnie ładowanego obrazka
        int w = images[i].width;
        int h = images[i].height;

        cechy_sprites[i].setColorDepth(16);
        
        // Odkomentuj to, jeśli masz płytkę z PSRAM
        cechy_sprites[i].setPsram(true); 

        
        loadTintedSprite(cechy_sprites[i], images[i].img, w, h, COLOR_GREEN, COLOR_BG);
        cechy_sprites[i].setPivot(w / 2, h / 2);
    }
}