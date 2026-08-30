#pragma once
#ifndef CONFIG_H
#define CONFIG_H
#include <LovyanGFX.hpp>
#include <Preferences.h>
// Rozdzielczość
constexpr int SCREEN_W = 480;
constexpr int SCREEN_H = 320;

// --- PALETA KOLORÓW ---
constexpr uint32_t F3_BG       = 0x052409; 
constexpr uint32_t F3_GREEN    = 0x48E868; 

constexpr uint32_t NV_BG       = 0x00152A; // Pustynny ciemny brąz
constexpr uint32_t NV_AMBER    = 0x00B0FF; // Klasyczny bursztyn


constexpr uint32_t QUANTUM_BG  = 0x1A0A00;
constexpr uint32_t QUANTUM_BLU = 0xFFB000;

extern uint32_t COLOR_BG;
extern uint32_t COLOR_GREEN;


extern String currentTopName;
extern int section_id;


inline void setGlobalThemeColors(int theme_id) {
    if (theme_id == 0) {       
        COLOR_GREEN = F3_GREEN;
        COLOR_BG = F3_BG;
    } else if (theme_id == 1) {
        COLOR_GREEN = NV_AMBER;   
        COLOR_BG = NV_BG;
    } else {                    
        COLOR_GREEN = QUANTUM_BLU;   
        COLOR_BG = QUANTUM_BG;
    }
}
inline void loadTintedSprite(LGFX_Sprite& spr, const uint16_t* img_data, int w, int h, uint32_t fg_color, uint32_t bg_color) {
    if (!spr.createSprite(w, h)) {
        Serial.println("Blad RAM przy alokacji!");
        return;
    }
    uint8_t target_r = (fg_color >> 16) & 0xFF;
    uint8_t target_g = (fg_color >> 8) & 0xFF;
    uint8_t target_b = fg_color & 0xFF;
    
    int i = 0; 
    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++) {
            

            uint16_t p = img_data[i++]; 
            

            if (p == 0xF81F) {
                spr.drawPixel(x, y, bg_color); 
            } 

            else {
                uint16_t gray = (p >> 5) & 0x3F;
                float brightness = (float)gray / 63.0f;
                
                uint8_t final_r = target_r * brightness;
                uint8_t final_g = target_g * brightness;
                uint8_t final_b = target_b * brightness;
                

                uint32_t final_color = (final_r << 16) | (final_g << 8) | final_b;
                spr.drawPixel(x, y, final_color);
            }
        }
    }
}


struct PlayerData {
    int level;
    int hp;
    int maxHp;
    int maxAp;
    int exp;
    int maxExp;
    char name[20];
};

extern PlayerData player;

#endif