#include "screen.h"
#include "stats/status.h"
#include "stats/special.h"
#include "display.h"
#include "topbar.h"
#include "botbar.h"
#include <functional>
#include <vector>


AppScreen current_screen;
Special objSpecialScreen;
struct Section{
    std::vector<const char*> screen_names= {"Status","S.P.E.C.J.A.L.", "Skille","Cechy","Relacje"};
    std::vector<Screen> screens = {};
};

void topbot(){
    drawTopBar();
    drawBottomNav(1);
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

AppScreen Status_Screen{
    draw_screen,
    []() { change_cursor(1); },
    []() { change_cursor(-1); },
    []() { change_cursor(1); }};
AppScreen Special_Screen{ // Zmieniłem nazwę z Special na SpecialScreen, by nie myliła się z nazwą Klasy
    []() { objSpecialScreen.drawList(); },  // Wywołuje rysowanie Z OBIEKTU
    []() { objSpecialScreen.up(); },        // Wywołuje ruch do góry Z OBIEKTU
    []() { objSpecialScreen.down(); },      // Wywołuje ruch w dół Z OBIEKTU
    []() { /* Tu co tam miałeś, np. change_cursor(1); */ } 
};