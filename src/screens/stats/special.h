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

            if (idObrazka >= 0 && idObrazka < 7) {
                
                if (special_sprites[idObrazka].getBuffer() != nullptr) {
                    
                    tft.fillRect(260, 48, 80, 130, COLOR_BG); 
                    int imgW = special_sprites[idObrazka].width();
                    int imgH = special_sprites[idObrazka].height();
                    int drawX = 210 + (220 - imgW) / 2;
                    int drawY = 50 + (120 - imgH) / 2;

                    special_sprites[idObrazka].pushSprite(&tft, drawX, drawY);

                    
                } else {
                    // Zamiast tego ESP32 łagodnie powie Ci w konsoli, co jest nie tak.
                    Serial.print("BLAD: Sprite o ID ");
                    Serial.print(idObrazka);
                    Serial.println(" jest PUSTY! (Brak RAM lub błąd w load_special_sprites)");
                }
            }
        }
        };