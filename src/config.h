#pragma once
#ifndef CONFIG_H
#define CONFIG_H
#include <LovyanGFX.hpp>
// Rozdzielczość
constexpr int SCREEN_W = 480;
constexpr int SCREEN_H = 320;

// Kolory
constexpr uint32_t COLOR_BG        = 0x052409;
constexpr uint32_t COLOR_GREEN      = 0x48E868;


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