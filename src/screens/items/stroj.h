#pragma once
#include "../statsanditems.h"
// tu includujesz grafiki perception, Endurance, itd.

extern Entry stroj_entries[];
extern int stroj_max_entries;

class Stroj : public StatsTemplate {
    private:
        LGFX_Sprite stroj_sprites[1];
    public:
        Stroj() : StatsTemplate(stroj_entries, stroj_max_entries) {setInfoMode(1);setEquippable(true);}
        void load_stroj_sprites();
        void drawDetails(int cur) override {
            int idObrazka = entries[cur].obrazId;
            Serial.println("Proba rysowania");
            if (idObrazka >= 0 && idObrazka < 1) {
                tft.fillRect(260, 48, 80, 130, COLOR_BG); 
                Serial.print("FUHHH:      ");
                Serial.println(idObrazka);
                // Pobieramy wymiary wobecnego obrazka
                int imgW = stroj_sprites[cur].width();
                int imgH = stroj_sprites[cur].height();
                int drawX = 210 + (220 - imgW) / 2;
                int drawY = 50 + (120 - imgH) / 2;

                stroj_sprites[idObrazka].pushSprite(&tft, drawX, drawY);
            }
        }
        virtual void drawItemStats(int cur, int startX, int startY) {
        Entry item = entries[cur];

        tft.setFont(&monofonto_rg9pt7b);
        tft.setTextColor(COLOR_GREEN, COLOR_BG);
        
        // Zgodnie z drawList(): descW = 220, więc thirdW = 73
        int thirdW = 220 / 3; 

        
        // BOX 1: Obrażenia (OBR / dmg)
        if (item.dmg != -1) {
            tft.setTextDatum(TL_DATUM); // Etykieta do lewej
            tft.drawString("ZDR:", startX, startY + 6);
            
            tft.setTextDatum(TR_DATUM); // Wartość do prawej
            tft.drawString(String(item.dmg), startX + thirdW - 10, startY + 6);
        }

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

        
        // BOX 4 (lewy dolny): Wymagana Siła (SIL / s)
        //     tft.setTextDatum(TL_DATUM);
        //     tft.drawString("SIL:", startX, startY + 51);
            
        //     tft.setTextDatum(TR_DATUM);
        //     tft.drawString(String(item.s), startX + thirdW - 10, startY + 51);
        // }

        // korzystając z offsetów:
        // BOX 5 X: startX + thirdW + 10
        // BOX 6 X: startX + 2 * thirdW + 15

        // Przywrócenie domyślnego wyrównania dla reszty interfejsu

        tft.setTextDatum(TL_DATUM);
    }
        };