#pragma once
#include "../statsanditems.h"
// tu includujesz grafiki perception, Endurance, itd.

extern Entry rozne_entries[];
extern int rozne_max_entries;

class Rozne : public StatsTemplate {
    private:
        LGFX_Sprite rozne_sprites[1];
    public:
        Rozne() : StatsTemplate(rozne_entries, rozne_max_entries) {setInfoMode(1);}
        void load_rozne_sprites();
        void drawDetails(int cur) override {
            int idObrazka = entries[cur].obrazId;
            if (idObrazka >= 0 && idObrazka < 1) {
                tft.fillRect(260, 48, 80, 130, COLOR_BG); 
                Serial.println(idObrazka);
                // Pobieramy wymiary wobecnego obrazka
                int imgW = rozne_sprites[cur].width();
                int imgH = rozne_sprites[cur].height();
                int drawX = 210 + (220 - imgW) / 2;
                int drawY = 50 + (120 - imgH) / 2;

                rozne_sprites[idObrazka].pushSprite(&tft, drawX, drawY);
            }
        }
        virtual void drawItemStats(int cur, int startX, int startY) {
        Entry item = entries[cur];

        tft.setFont(&monofonto_rg9pt7b);
        tft.setTextColor(COLOR_GREEN, COLOR_BG);
        
        // Zgodnie z drawList(): descW = 220, więc thirdW = 73
        int thirdW = 220 / 3; 

        
        

        // BOX 2: Waga (WAG / w)
        if (item.w != -1) {
            tft.setTextDatum(TL_DATUM);
            tft.drawString("WAG:", startX + thirdW + 10, startY + 6);
            
            tft.setTextDatum(TR_DATUM);
            tft.drawString(String(item.w), startX + 2 * thirdW, startY + 6);
        }

        // BOX 3: Wartość (WAR / v)
        if (item.v != -1) {
            tft.setTextDatum(TL_DATUM);
            tft.drawString("WAR:", startX + 2 * thirdW + 15, startY + 6);
            
            tft.setTextDatum(TR_DATUM);
            tft.drawString(String(item.v), startX + 3 * thirdW + 5, startY + 6);
        }

        tft.setTextDatum(TL_DATUM);
    }
        };