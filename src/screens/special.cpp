#include "special.h"
#include "display.h"
#include <string>
#include "../imgs/Strength.h"
#include "../imgs/perception.h"
#include "../imgs/Endurance.h"
#include "../data/monofonto_rg12pt7b.h"
#include "../data/monofonto_rg13pt7b.h"
#include "../data/monofonto_rg70pt7b.h"
#include "../imgs/Strength.h"
#include "../imgs/perception.h"
#include "../imgs/Endurance.h"

struct Entry{
    const char* name;
    int value;
    const char* opis;
    int obrazId;
};
static LGFX_Sprite special_sprites[3];


void load_special_sprites(){
    special_sprites[0].createFromBmp(Strength2_icon);
    special_sprites[1].createFromBmp(perception);
    special_sprites[2].createFromBmp(Endurance);
}

int special_cursor = 0;
Entry special_entries[] = {
    {"Sila", 8, "Opis sily", 0},
    {"Percepcja", 4, "Opis percepcji", 1},
    {"Wytrzymalosc", 5, "Opis wytrzymalosc", 2}
};
void drawDetails(){
    special_sprites[0].pushRotateZoom(&tft, 
    200,      // środek X na ekranie
    120,      // środek Y na ekranie
    0,      // rotacja w stopniach
    1.0,    // zoom X (0.5 = połowa rozmiaru)
    1.0  );   // zoom Y (0.5 = połowa rozmiaru)
}
void drawList(){
    tft.setFont(&monofonto_rg9pt7b);
    tft.setTextColor(COLOR_GREEN);
    tft.setTextDatum(ML_DATUM);
    int y =80;
    int n = 0;
    for (Entry i : special_entries){
        if(n==special_cursor){
            tft.fillRect(20,y-17,46,30,COLOR_GREEN);
            tft.fillRect(23,y-14,40,24,COLOR_BG);
        }
        tft.drawString(i.name, 50, y);
        y+= 30;
        n++;
    }
    
    tft.unloadFont();
    drawDetails();
}

