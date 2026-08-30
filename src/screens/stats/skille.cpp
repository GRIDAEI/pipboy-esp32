#include "skille.h"

#include "../../imgs/Scienta.h"
#include "../../display.h"

#include "../../imgs/Barter.h"
#include "../../imgs/EnergyWeaponsFO3.h"
#include "../../imgs/Explosives.h"
#include "../../imgs/Guns.h"
#include "../../imgs/Lockpick.h"
#include "../../imgs/Medicine.h"
#include "../../imgs/MeleeWeapons.h"
#include "../../imgs/Repair_icon.h"
#include "../../imgs/Science_icon.h"
#include "../../imgs/Speech.h"
#include "../../imgs/Survival.h"
#include "../../imgs/Unarmed.h"

extern LGFX tft;
Entry skille_entries[] = {
    {"Handel", 12, "Wplywa na ceny kupna i sprzedazy przedmiotow u handlarzy na pustkowiach.", 0},
    {"Bron Ene.", 28, "Okresla skutecznosc i precyzje w walce przy uzyciu broni laserowej oraz plazmowej.", 1},
    {"Pirotechnika", 31, "Wplywa na obrazenia zadawane przez materialy wybuchowe oraz szanse na ich bezpieczne rozbrojenie.", 2},
    {"Bron Palna", 35, "Okresla twoja celnosc i obrazenia przy uzywaniu tradycyjnej broni na olow.", 3},
    {"Wytrych", 38, "Pozwala na otwieranie zamkow o roznym stopniu trudnosci. Im wyzszy poziom, tym latwiej.", 4},
    {"Medycyna", 29, "Zwieksza ilosc punktow zdrowia odzyskiwanych ze stimpakow oraz ogolna skutecznosc leczenia.", 5},
    {"Bron Biala", 48, "Okresla skutecznosc w walce w zwarciu przy uzyciu nozy, mieczy i tepych narzedzi.", 6},
    {"Naprawa", 34, "Pozwala na skuteczniejsze naprawianie zuzytej broni i elementow pancerza.", 7},
    {"Wiedza", 41, "Odpowiada za zdolnosc hakowania terminali komputerowych i ogolna wiedze technologiczna.", 8},
    {"Mowa", 34, "Wplywa na potyczki slowne, negocjacje i mozliwosc perswazji w trakcie dialogow z postaciami.", 9},
    {"Przetrwanie", 26, "Zwieksza korzysci plynace ze spozywania jedzenia i picia, ulatwiajac przezycie w dziczy.", 10},
    {"Walka wrecz", 17, "Zwieksza obrazenia w walce na gole piesci oraz z uzyciem rekawic bojowych.", 11},

};

int skille_max_entries = 12;

struct skilleImageData {
    const uint16_t* img; // Wskaźnik do tablicy z obrazkiem
    int width;           // Szerokość obrazka
    int height;          // Wysokość obrazka
};
void Skille::load_skille_sprites() {
    

    const skilleImageData images[] = {
        { Barter, Barter_width, Barter_height },                            
        { EnergyWeaponsFO3, EnergyWeaponsFO3_width, EnergyWeaponsFO3_height }, 
        { Explosives, Explosives_width, Explosives_height },                  
        { Guns, Guns_width, Guns_height },                                     
        { Lockpick, Lockpick_width, Lockpick_height },                       
        { Medicine, Medicine_width, Medicine_height },                        
        { MeleeWeapons, MeleeWeapons_width, MeleeWeapons_height },           
        { Repair_icon, Repair_icon_width, Repair_icon_height },                              
        { Science_icon, Science_icon_width, Science_icon_height },                           
        { Speech, Speech_width, Speech_height },                             
        { Survival, Survival_width, Survival_height },                        
        { Unarmed, Unarmed_width, Unarmed_height }
        
       }; 
    

    int images_to_load = sizeof(images) / sizeof(images[0]); 
    
    for (int i = 0; i < images_to_load; i++) {

        int w = images[i].width;
        int h = images[i].height;

        skille_sprites[i].setColorDepth(16);
        
        skille_sprites[i].setPsram(true); 
        loadTintedSprite(skille_sprites[i], images[i].img, w, h, COLOR_GREEN, COLOR_BG);
        skille_sprites[i].setPivot(w / 2, h / 2);
        
    }
}