#pragma once
#include "../statsanditems.h"
// tu includujesz grafiki perception, Endurance, itd.

extern Entry special_entries[];
constexpr int special_max_entries = 6;
extern LGFX_Sprite special_sprites[3];
void load_special_sprites();
class Special : public StatsTemplate {
public:
    Special() : StatsTemplate(special_entries, 6) {}

    void drawDetails(int cur) override {
        if (cur < 3) {
            special_sprites[cur].pushRotateZoom(&tft, 350, 110, 0, 1.0, 1.0);
        }
    }
};