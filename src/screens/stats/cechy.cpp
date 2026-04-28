#include "cechy.h"

#include "../../imgs/Scienta.h"
#include "../../imgs/Strength2_icon.h"
#include "../../imgs/zydu.h"
#include "../../display.h"
extern LGFX tft;
Entry cechy_entries[] = {
    {"Studium Valet", -1, "'Studiowanie na polibudzie sprawia ze czekasz na nuklearna zime.'\n\nPermametne zwiekszenie percepcji", 0},
    {"Glupi ma szczescie", -1, "Posiadasz nie tylko zapal do nauki, a rowniez szczescie ze mozesz ja czerpac z twoich licznych bledow.", 1},
    {"Polak nie kaktus", -1, "Musi pic", 2},
    {"ZaKimJestes", -1, "Zadajesz wszystkim innym frakcjom 1.5 razy wiecej obrazen, ale tyle samo od nich otrzymujesz.", 2},
    {"nerwwwwwwicaa", -1, "Za każdym rokiem może się coś czychać, serce tak dudni że nie musisz pic kawy. \n\n Percepcja zwiekszona na koszt zdrowia.",2}
};

int cechy_max_entries = 5;
// 3. INICJALIZACJA: Przypisujemy główny ekran do każdego sprite'a w tablicy

struct cechyImageData {
    const uint16_t* img; // Wskaźnik do tablicy z obrazkiem
    int width;           // Szerokość obrazka
    int height;          // Wysokość obrazka
};
void Cechy::load_cechy_sprites() {
    
    // 2. Tablica z obrazkami i ich indywidualnymi wymiarami
    const cechyImageData images[] = {
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

        cechy_sprites[i].setColorDepth(16);
        
        // Odkomentuj to, jeśli masz płytkę z PSRAM
        cechy_sprites[i].setPsram(true); 

        // ZABEZPIECZENIE: Tworzymy sprite'a z indywidualnymi wymiarami (w, h)
        if (!cechy_sprites[i].createSprite(w, h)) {
            Serial.print("Blad alokacji RAM dla sprite'a cechy id: ");
            Serial.println(i);
        } else {
            cechy_sprites[i].setSwapBytes(true); // Zmień na false jeśli kolory będą złe
            
            // Wgrywamy obrazek używając specyficznych wymiarów i wskaźnika
            cechy_sprites[i].pushImage(0, 0, w, h, images[i].img);
            
            // Pivot ustawiany dynamicznie na środek (w/2, h/2)
            cechy_sprites[i].setPivot(w / 2, h / 2);
            
        }
    }
}