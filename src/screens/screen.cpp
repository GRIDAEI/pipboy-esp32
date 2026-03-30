#include "screen.h"
#include "status.h"
#include "special.h"
#include "display.h"
#include "topbar.h"
#include "botbar.h"
#include <functional>
#include <vector>


AppScreen current_screen;

struct Section{
    std::vector<const char*> screen_names= {"Status","S.P.E.C.J.A.L.", "Skille","Cechy","Relacje"};
    std::vector<Screen> screens = {};
};

void topbot(){
    drawTopBar();
    drawBottomNav(0);
}

void draw_screen(){
    tft.fillRect(0,50,480,240, COLOR_BG);
    current_screen.drawFunction();
}

void load_all_sprites(){
    load_sprites();
    load_special_sprites();
}

void current_up(){
    current_screen.up();
}

void current_down(){
    current_screen.down();
}

AppScreen Status{
    draw_screen,
    []() { change_cursor(1); },
    []() { change_cursor(-1); },
    []() { change_cursor(1); }};
AppScreen Special{
    drawList, 
    []() { change_cursor(1); },
    []() { change_cursor(-1); }, 
    []() { change_cursor(1); }};