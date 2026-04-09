#pragma once
#include <functional>
#include "stats/status.h"
#include "stats/special.h"
struct AppScreen{
    std::function<void()> drawFunction;
    std::function<void()> up;
    std::function<void()> down;
    std::function<void()> select;
};
void draw_screen();
void topbot();
void load_all_sprites();
extern int screen_id;
void current_up();
extern Special objSpecialScreen;
extern Status objStatusScreen;
void current_down();
void change_screen(int f);
void press_current_select();
extern AppScreen* current_screen;
extern AppScreen Status_Screen;
extern AppScreen Special_Screen;
extern AppScreen Skille_Screen;
extern AppScreen Cechy_Screen;
extern AppScreen Relacje_Screen;