#include "special.h"
#include "config.h"
#include "../../imgs/Strength2_icon.h"
#include "../../imgs/perception.h"
#include "../../imgs/Endurance.h"
#include "../../imgs/zydu.h"
#include "../../imgs/Charisma_icon.h"
#include "../../imgs/Agility.h"
#include "../../display.h"
#include "../../imgs/Intelligence_icon.h"
#include "../../imgs/Luck_icon.h"

extern LGFX tft;

Entry special_entries[] = {
    {"Sila", 8, "Surowa sila fizyczna. Wysoka siła jest przydatna zwłaszcza dla postaci bazujących na cechach fizycznych.", 0},
    {"Percepcja", 4, "Zdolnosc dostrzegania, slyszenia a takze wyczuwania dziwnych rzeczy. Wysoka percepcja jest wazna dla strzelca wyborowego.", 1},
    {"Wytrzymalosc", 5, "Kondycja i fizyczna odpornosc. Postacie z wysoka Wytrzymaloscia przetrwaja nawet tam, gdzie inni nie potrafiliby.", 2},
    {"Charyzma", 4, "Polaczenie wygladu i uroku osobistego. Wysoka Charyzma jest wazna dla postaci, ktore chca wplywac na innych ludzi za pomoca slow.", 3},
    {"Inteligencja", 7, "Wiedza, madrosc i umiejetnosc szybkiego myslenia. Wysoka inteligencja jest wazna dla wszystkich postaci.", 4},
    {"Zwinnosc", 4, "Koordynacja i zdolnosc do sprawnego poruszania sie. Wysoka zrecznosc jest wazna dla wszystkich aktywnych postaci.", 5},
    {"Szczescie", 3, "Los. Karma. Skrajnie wysokie lub niskie szczescie wplywa w taki czy inny sposob na twoja postac.", 6}
};

int special_max_entries = 7; 

struct SpecialImageData {
    const uint16_t* img;
    int width;
    int height;
};

void Special::load_special_sprites() {
    
    const SpecialImageData images[] = {
        { Strength2_icon, Strength2_icon_width, Strength2_icon_height }, 
        { perception, perception_width, perception_height }, 
        { Endurance, Endurance_width, Endurance_height },  
        { Charisma_icon, Charisma_icon_width, Charisma_icon_height },
        { Intelligence_icon, Intelligence_icon_width, Intelligence_icon_height }, 
        { Agility, Agility_width, Agility_height }, 
        { Luck_icon, Luck_icon_width, Luck_icon_height } 
    }; 
    
    int images_to_load = sizeof(images) / sizeof(images[0]); 
    Serial.println(images_to_load);
    for (int i = 0; i < images_to_load; i++) {
        int w = images[i].width;
        int h = images[i].height;

        special_sprites[i].setColorDepth(16);
        special_sprites[i].setPsram(true); 

        loadTintedSprite(special_sprites[i], images[i].img, w, h, COLOR_GREEN, COLOR_BG);

        special_sprites[i].setPivot(w / 2, h / 2);
    }
}