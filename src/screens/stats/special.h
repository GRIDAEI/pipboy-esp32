#pragma once
#include "../statsanditems.h"
// tu includujesz grafiki perception, Endurance, itd.

extern Entry special_entries[];
extern int special_max_entries;


class Special : public StatsTemplate {
    private:
        LGFX_Sprite special_sprites[7];
    public:
        Special() : StatsTemplate(special_entries, special_max_entries) {}
        void load_special_sprites();
        // Nadpisujesz pustą funkcję z szablonu, żeby obsłużyć SWOJE obrazki
        void drawDetails(int cur) override {
            int idObrazka = entries[cur].obrazId;

            if (idObrazka >= 0 && idObrazka < 3) {
                Serial.println("PROBUJE RYSOWAC OBRAZEK ID: " + String(idObrazka));
                
                // Czyszczenie tła
                tft.fillRect(260, 48, 80, 130, COLOR_BG); 
                
                // TUTA DODAJEMY 0xF81F NA KONCU!
                special_sprites[idObrazka].pushRotateZoom(&tft, 300, 108, 0, 1.0, 1.0, 0xF81F);
            }
        }
        };