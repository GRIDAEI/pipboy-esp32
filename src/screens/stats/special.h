#pragma once
#include "../statsanditems.h"
// tu includujesz grafiki perception, Endurance, itd.

extern Entry special_entries[];
extern int special_max_entries;
extern LGFX_Sprite special_sprites[3];
void load_special_sprites();
class Special : public StatsTemplate {
public:
    Special() : StatsTemplate(special_entries, special_max_entries) {}

    // Nadpisujesz pustą funkcję z szablonu, żeby obsłużyć SWOJE obrazki
    void drawDetails(int cur) override {
        // Żeby nie wywaliło błędu jeśli indeks nie ma jeszcze obrazka (masz ich 3 na razie)
        if (cur < 3) {
            special_sprites[cur].pushRotateZoom(&tft, 350, 110, 0, 1.0, 1.0);
        }
    }
};