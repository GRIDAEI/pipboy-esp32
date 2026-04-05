#pragma once
#include <functional>
struct AppScreen{
    std::function<void()> drawFunction;
    std::function<void()> up;
    std::function<void()> down;
    std::function<void()> select;
};
void draw_screen();
void topbot();
void load_all_sprites();

void current_up();

void current_down();

extern AppScreen current_screen;
extern AppScreen Status_Screen;
extern AppScreen Special_Screen;
extern AppScreen Skille_Screen;
extern AppScreen Cechy;
extern AppScreen Relacje;