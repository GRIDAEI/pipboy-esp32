#include "localMap.h"
#include "../../display.h"

// Plik z wyeksportowaną dużą mapą
#include "../../imgs/LocalMapSprite.h"

extern LGFX tft;

LocalMap::LocalMap() : mapSprite(&tft) {
    // Przypisujemy wymiary z wyeksportowanego pliku obrazka do zmiennych klasy
    map_width = LocalMapSprite_width;
    map_height = LocalMapSprite_height;

    // Na start ustawiamy kamerę mniej więcej na środek mapy
    // Ekran widoku ma 480 szerokości i 250 wysokości
    camera_x = (map_width - 480) / 2;
    if(camera_x < 0) camera_x = 0;
    
    camera_y = (map_height - 250) / 2; 
    if(camera_y < 0) camera_y = 0;
}

void LocalMap::load_localMap_sprites() {
    // Używamy zmiennej mapSprite (obiekt LGFX_Sprite), a nie nazwy pliku/tablicy
    mapSprite.setColorDepth(16);
    mapSprite.setPsram(true); // Przy tak dużej bitmapie PSRAM jest obowiązkowy
    
    loadTintedSprite(mapSprite, LocalMapSprite, map_width, map_height, COLOR_GREEN, COLOR_BG);
}

void LocalMap::drawScreen() {
    tft.fillRect(0, 50, 480, 250, COLOR_BG);

    // 2. Ograniczenie rysowania, żeby mapa nie "wylała" się na górny/dolny pasek
    tft.setClipRect(0, 50, 480, 250);

    mapSprite.pushSprite(-camera_x, 50 - camera_y);

    // 4. Kursor gracza - prosty trójkąt zawsze na środku ekranu
    // Środek w osi X = 240, środek widoku Y = 50 + (250/2) = 175
    tft.fillTriangle(240, 165, 233, 180, 247, 180, COLOR_GREEN);

    tft.clearClipRect();

    // 5. Informacja dla użytkownika, w której osi aktualnie się porusza
    tft.setFont(&monofonto_rg9pt7b);
    tft.setTextColor(COLOR_GREEN, COLOR_BG);
    tft.setTextDatum(BL_DATUM); // Wyrównanie do lewego-dołu
    
    if(move_x_axis) {
        tft.drawString("Os: PRAWO / LEWO", 10, 295); // Zakładam że przy Y=300 zaczyna się botbar
    } else {
        tft.drawString("Os: GORA / DOL", 10, 295);
    }
    
    tft.setTextDatum(TL_DATUM); // Reset wyrównania
}

void LocalMap::up() {
    // Kręcenie do góry (lub w lewo)
    if(move_x_axis) {
        camera_x -= step;
        if(camera_x < 0) camera_x = 0;
    } else {
        camera_y -= step;
        if(camera_y < 0) camera_y = 0;
    }
    drawScreen();
}

void LocalMap::down() {
    // Kręcenie w dół (lub w prawo)
    if(move_x_axis) {
        camera_x += step;
        if(camera_x > map_width - 480) camera_x = map_width - 480;
    } else {
        camera_y += step;
        if(camera_y > map_height - 250) camera_y = map_height - 250;
    }
    drawScreen();
}

void LocalMap::select() {
    // Wciśnięcie przycisku zmienia oś poruszania się
    move_x_axis = !move_x_axis;
    drawScreen(); // Odświeżamy żeby zaktualizować tekst na dole
}