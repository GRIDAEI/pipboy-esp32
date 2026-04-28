#include "skille.h"

#include "../../imgs/Scienta.h"
#include "../../display.h"
extern LGFX tft;
Entry skille_entries[] = {


    {"Handel", 12, "'Studiowanie na polibudzie sprawia ze czekasz na nuklearna zime.'\n\nPermametne zwiekszenie percepcji", 0},
    {"Bron Ene.", 28, "Posiadasz nie tylko zapal do nauki, a rowniez szczescie ze mozesz ja czerpac z twoich licznych bledow.", 1},
    {"Pirotechnika", 31, "Musi pic", 2},
    {"Bron Palna", 35, "Zadajesz wszystkim innym frakcjom 1.5 razy wiecej obrazen, ale tyle samo od nich otrzymujesz.", 3},
    {"Wytrych", 38, "Zadajesz wszystkim innym frakcjom 1.5 razy wiecej obrazen, ale tyle samo od nich otrzymujesz.", 3},
    {"Medycyna", 29, "Zadajesz wszystkim innym frakcjom 1.5 razy wiecej obrazen, ale tyle samo od nich otrzymujesz.", 3},
    {"Bron Biala", 48, "Zadajesz wszystkim innym frakcjom 1.5 razy wiecej obrazen, ale tyle samo od nich otrzymujesz.", 3},
    {"Naprawa", 34, "Zadajesz wszystkim innym frakcjom 1.5 razy wiecej obrazen, ale tyle samo od nich otrzymujesz.", 3},
    {"Wiedza", 41, "Zadajesz wszystkim innym frakcjom 1.5 razy wiecej obrazen, ale tyle samo od nich otrzymujesz.", 3},
    {"Mowa", 34, "Zadajesz wszystkim innym frakcjom 1.5 razy wiecej obrazen, ale tyle samo od nich otrzymujesz.", 3},
    {"Przetrwanie", 26, "Zadajesz wszystkim innym frakcjom 1.5 razy wiecej obrazen, ale tyle samo od nich otrzymujesz.", 3},
    {"Walka wrecz", 17, "Zadajesz wszystkim innym frakcjom 1.5 razy wiecej obrazen, ale tyle samo od nich otrzymujesz.", 3},
};

int skille_max_entries = 7;
// 3. INICJALIZACJA: Przypisujemy główny ekran do każdego sprite'a w tablicy

struct skilleImageData {
    const uint16_t* img; // Wskaźnik do tablicy z obrazkiem
    int width;           // Szerokość obrazka
    int height;          // Wysokość obrazka
};
void Skille::load_skille_sprites() {
    
    // 2. Tablica z obrazkami i ich indywidualnymi wymiarami
    const skilleImageData images[] = {
        { Here_and_Now, 67, 120 }, // [0] Szerokość 70, wysokość 120
        { Here_and_Now, 67, 120 },  // [1] Przykład innej wielkości (np. 60x60)
        { Here_and_Now,67, 120 }  // [2] Kolejny przykład (np. 80x100)
        // Jak dodasz nowe, po prostu dopisuj kolejne linijki: { nazwa_pliku, szerokosc, wysokosc }
    }; 
    
    // Automatyczne liczenie ilości obrazków (nie musisz już tego zmieniać ręcznie!)
    int images_to_load = sizeof(images) / sizeof(images[0]); 
    
    for (int i = 0; i < images_to_load; i++) {
        // Pobieramy wymiary dla aktualnie ładowanego obrazka
        int w = images[i].width;
        int h = images[i].height;

        skille_sprites[i].setColorDepth(16);
        
        // Odkomentuj to, jeśli masz płytkę z PSRAM
        skille_sprites[i].setPsram(true); 

        // ZABEZPIECZENIE: Tworzymy sprite'a z indywidualnymi wymiarami (w, h)
        if (!skille_sprites[i].createSprite(w, h)) {
            Serial.print("Blad alokacji RAM dla sprite'a skille id: ");
            Serial.println(i);
        } else {
            skille_sprites[i].setSwapBytes(true); // Zmień na false jeśli kolory będą złe
            
            // Wgrywamy obrazek używając specyficznych wymiarów i wskaźnika
            skille_sprites[i].pushImage(0, 0, w, h, images[i].img);
            
            // Pivot ustawiany dynamicznie na środek (w/2, h/2)
            skille_sprites[i].setPivot(w / 2, h / 2);
            
        }
    }
}