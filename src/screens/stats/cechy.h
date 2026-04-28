#pragma once
#include "../statsanditems.h"
// tu includujesz grafiki perception, Endurance, itd.

extern Entry cechy_entries[];
extern int cechy_max_entries;


class Cechy : public StatsTemplate {
    private:
        LGFX_Sprite cechy_sprites[7];
    public:
        Cechy() : StatsTemplate(cechy_entries, cechy_max_entries) {}
        void load_cechy_sprites();
        // Nadpisujesz pustą funkcję z szablonu, żeby obsłużyć SWOJE obrazki
        void drawDetails(int cur) override {
            int idObrazka = entries[cur].obrazId;

            if (idObrazka >= 0 && idObrazka < 3) {
                Serial.println("PROBUJE RYSOWAC OBRAZEK ID: " + String(idObrazka));
                
                // Czyszczenie tła
                tft.fillRect(260, 48, 80, 130, COLOR_BG); 
                
                // TUTA DODAJEMY 0xF81F NA KONCU!
                cechy_sprites[idObrazka].pushRotateZoom(&tft, 300, 108, 0, 1.0, 1.0, 0xF81F);
            }
        }
        };