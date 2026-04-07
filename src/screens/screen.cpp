#include "screen.h"
#include "stats/status.h"
#include "stats/special.h"
#include "display.h"
#include "topbar.h"
#include "botbar.h"
#include <functional>
#include <vector>


AppScreen* current_screen = nullptr;
Special objSpecialScreen;
Status objStatusScreen;
AppScreen Status_Screen{
    []() { objStatusScreen.drawScreen(); },
    []() { objStatusScreen.changeCursor(1); },
    []() { objStatusScreen.changeCursor(-1); },
    []() { objStatusScreen.statusSelect(); }};
AppScreen Special_Screen{ // Zmieniłem nazwę z Special na SpecialScreen, by nie myliła się z nazwą Klasy
    []() { objSpecialScreen.drawList(); },  // Wywołuje rysowanie Z OBIEKTU
    []() { objSpecialScreen.up(); },        // Wywołuje ruch do góry Z OBIEKTU
    []() { objSpecialScreen.down(); },      // Wywołuje ruch w dół Z OBIEKTU
    []() { /* Tu co tam miałeś, np. change_cursor(1); */ } 
};

struct Section{
    std::vector<const char*> screen_names;
    std::vector<AppScreen> screens;
};
Section STATS{
     {"Status","S.P.E.C.J.A.L.", "Skille","Cechy","Relacje"}, {Status_Screen,Special_Screen}
};
void topbot(){
    drawTopBar();
    drawBottomNav(1);
}

// void draw_current_screen(){
//     tft.fillRect(0,50,480,240, COLOR_BG);
//     if (current_screen == nullptr) {
//         Serial.println("BŁĄD: Próba rysowania bez ustawionego ekranu!");
//         return; 
//     }
//     Serial.println("SCREEN: Probuje Rysować");
//     current_screen->drawFunction();
// }

void load_all_sprites(){
    objStatusScreen.loadSprites();
    //load_special_sprites();
}

void change_screen(int i){
    if(i==0 || i==1){
        current_screen = &STATS.screens[i];
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

