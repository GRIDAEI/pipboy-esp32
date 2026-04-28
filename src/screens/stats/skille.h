#pragma once
#include "../statsanditems.h"
// tu includujesz grafiki perception, Endurance, itd.

extern Entry skille_entries[];
extern int skille_max_entries;


class Skille : public StatsTemplate {
    private:
        LGFX_Sprite skille_sprites[7];
    public:
        Skille() : StatsTemplate(skille_entries, skille_max_entries) {}
        void load_skille_sprites();
        // Nadpisujesz pustą funkcję z szablonu, żeby obsłużyć SWOJE obrazki
        void drawDetails(int cur) override {
            int idObrazka = entries[cur].obrazId;

            if (idObrazka >= 0 && idObrazka < 3) {
                Serial.println("PROBUJE RYSOWAC OBRAZEK ID: " + String(idObrazka));
                
                // Czyszczenie tła
                tft.fillRect(260, 48, 80, 130, COLOR_BG); 
                
                // TUTA DODAJEMY 0xF81F NA KONCU!
                skille_sprites[idObrazka].pushRotateZoom(&tft, 300, 108, 0, 1.0, 1.0, 0xF81F);
            }
        }
        };