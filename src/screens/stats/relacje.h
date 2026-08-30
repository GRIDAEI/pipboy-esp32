#pragma once
#include "../statsanditems.h"
// tu includujesz grafiki perception, Endurance, itd.

extern Entry relacje_entries[];
extern int relacje_max_entries;

class Relacje : public StatsTemplate {
    private:
        LGFX_Sprite relacje_sprites[7];
    public:
        Relacje() : StatsTemplate(relacje_entries, relacje_max_entries) {setInfoMode(2);}
        void load_relacje_sprites();
        
        void drawDetails(int cur) override {
            int idObrazka = entries[cur].obrazId;
            int reputacja = entries[cur].value; 

            if (idObrazka >= 0 && idObrazka < 7) {
                tft.fillRect(215, 45, 260, 240, COLOR_BG); 
                
                relacje_sprites[idObrazka].pushRotateZoom(&tft, 320, 170, 0, 1.0, 1.0, 0xF81F);
                
                tft.setFont(&monofonto_rg9pt7b);
                tft.setTextColor(COLOR_GREEN); 
                tft.setTextDatum(TC_DATUM); 
                
                tft.drawString(entries[cur].name, 320, 65);

                tft.drawString(entries[cur].opis, 320, 260);
                
                tft.unloadFont();
            }
        }
        };