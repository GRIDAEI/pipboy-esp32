#pragma once
#include <LovyanGFX.hpp>

void applyThemeToSprite(LGFX_Sprite& spr, uint32_t bgColor, uint32_t fgColor) {
    // Generujemy paletę 256 kolorów
    for (int i = 0; i < 256; i++) {
        float ratio = i / 255.0; 
        
        // Mieszanie składowych RGB (Red, Green, Blue)
        uint8_t r = ((fgColor >> 16) & 0xFF) * ratio + ((bgColor >> 16) & 0xFF) * (1.0 - ratio);
        uint8_t g = ((fgColor >> 8) & 0xFF) * ratio + ((bgColor >> 8) & 0xFF) * (1.0 - ratio);
        uint8_t b = (fgColor & 0xFF) * ratio + (bgColor & 0xFF) * (1.0 - ratio);
        
        spr.setPaletteColor(i, r, g, b);
    }
}