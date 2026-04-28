#pragma once
#include "../statsanditems.h"
// tu includujesz grafiki perception, Endurance, itd.

extern Entry relacje_entries[];
extern int relacje_max_entries;


class Relacje : public StatsTemplate {
    private:
        LGFX_Sprite relacje_sprites[7];
    public:
        Relacje() : StatsTemplate(relacje_entries, relacje_max_entries) {turnDescOff();}
        void load_relacje_sprites();
        // Nadpisujesz pustą funkcję z szablonu, żeby obsłużyć SWOJE obrazki
        void drawDetails(int cur) override {
            int idObrazka = entries[cur].obrazId;

            if (idObrazka >= 0 && idObrazka < 3) {
                Serial.println("PROBUJE RYSOWAC OBRAZEK ID: " + String(idObrazka));
                
                // Czyszczenie tła
                tft.fillRect(260, 48, 80, 130, COLOR_BG); 
                
                // TUTA DODAJEMY 0xF81F NA KONCU!
                relacje_sprites[idObrazka].pushRotateZoom(&tft, 320, 160, 0, 1.0, 1.0, 0xF81F);
                tft.setFont(&monofonto_rg9pt7b);
                tft.setTextColor(COLOR_GREEN, COLOR_BG);
                tft.setTextDatum(TL_DATUM);
                tft.drawString("Dobroduszny Lobuz", 250, 65);
                tft.unloadFont();
            }
        }
        };