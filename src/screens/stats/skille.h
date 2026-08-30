#pragma once
#include "../statsanditems.h"
// tu includujesz grafiki perception, Endurance, itd.

extern Entry skille_entries[];
extern int skille_max_entries;

class Skille : public StatsTemplate {
    private:
        LGFX_Sprite skille_sprites[12];
    public:
        Skille() : StatsTemplate(skille_entries, skille_max_entries) {}
        void load_skille_sprites();

        void drawDetails(int cur) override {
            int idObrazka = entries[cur].obrazId;

            if (idObrazka >= 0 && idObrazka < 12) {

                tft.fillRect(260, 48, 80, 130, COLOR_BG); 

                int imgW = skille_sprites[cur].width();
                int imgH = skille_sprites[cur].height();
                int drawX = 210 + (220 - imgW) / 2;
                int drawY = 50 + (120 - imgH) / 2;

                skille_sprites[cur].pushSprite(&tft, drawX, drawY);
            }
        }
        };