#include "screen.h"

#include "display.h"
#include "topbar.h"
#include "botbar.h"
#include <functional>
#include <vector>

AppScreen* current_screen = nullptr;
Special objSpecialScreen;
Status objStatusScreen;
Cechy objCechyScreen;
Relacje objRelacjeScreen;

Special& getSpecial() {
    static Special instSp;
    return instSp;
}

Status& getStatus() {
    static Status instSt;
    return instSt;
}
Skille& getSkille() {
    static Skille instSk;
    return instSk;
}
Cechy& getCechy() {
    static Cechy instCh;
    return instCh;
}

Relacje& getRelacje() {
    static Relacje instRe;
    return instRe;
}

AppScreen Status_Screen{
    []() { getStatus().drawScreen(); },
    []() { getStatus().changeCursor(1); },
    []() { getStatus().changeCursor(-1); },
    []() { getStatus().statusSelect(); }
};
AppScreen Special_Screen{
    []() { getSpecial().drawList(); },
    []() { getSpecial().up(); },
    []() { getSpecial().down(); },
    []() { }
};
AppScreen Skille_Screen{
    []() { getSkille().drawList(); },
    []() { getSkille().up(); },
    []() { getSkille().down(); },
    []() { }
};
AppScreen Cechy_Screen{
    []() { getCechy().drawList(); },
    []() { getCechy().up(); },
    []() { getCechy().down(); },
    []() { }
};
AppScreen Relacje_Screen{
    []() { getRelacje().drawList(); },
    []() { getRelacje().up(); },
    []() { getRelacje().down(); },
    []() { }
};
int screen_id = 0;
struct Section{
    std::vector<const char*> screen_names;
    std::vector<AppScreen> screens;
};
Section STATS{
     {"Status","S.P.E.C.J.A.L.", "Skille","Cechy","Relacje"}, {Status_Screen,Special_Screen,Skille_Screen, Cechy_Screen, Relacje_Screen}
};
void topbot(){
    drawTopBar();
    drawBottomNav(1);
}


void load_all_sprites(){
    getStatus().loadSprites();   // ← getStatus() zamiast objStatusScreen
    getSpecial().load_special_sprites();  // jeśli Special też ma loadSprites
    getCechy().load_cechy_sprites();
    getSkille().load_skille_sprites();
    getRelacje().load_relacje_sprites();
}

void change_screen(int i){
    tft.fillRect(0, 50, 480, 250, COLOR_BG);
    int d = screen_id + i;
    int max_d = (int)STATS.screens.size() - 1;
    if (d > max_d) d = max_d;
    else if (d < 0) d = 0;
    
    if (d != screen_id) {
        screen_id = d;                        // ← aktualizuj screen_id
        current_screen = &STATS.screens[d];
        drawTopBar();
        drawBottomNav(d);
        current_screen->drawFunction();
    }
    
}
void current_up(){
    current_screen->up();
}

void current_down(){
    current_screen->down();
}
void press_current_select(){
    current_screen->select();
}

