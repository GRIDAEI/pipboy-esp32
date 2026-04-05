#include "status.h"
#include "display.h"
#include <LittleFS.h>
#include "../data/monofonto_rg12pt7b.h"
#include "../data/monofonto_rg13pt7b.h"
#include "../data/monofonto_rg70pt7b.h"
#include "../../imgs/status_body.h"
#include "../../imgs/folow.h"
#include "../../imgs/radaxis.h"
#include "modules/rtc.h"
#include "special.h"


int cursor = 0;
static LGFX_Sprite sprite[3];
const char* label[4] = {"STN", "RAD", "ZEG", "UST"};
static int ust_cursor = 0;     // która pozycja jest zaznaczona
static bool ust_edit = false;  // czy jesteśmy w trybie edycji wartości

Screen current_selected = SCR_NUFN;

struct Setting {
    const char* name;
    int value;
    int min_val;
    int max_val;
    const char* unit;
};

static Setting settings[] = {
    { "JASNOSC",  80,  0, 100, "%" },
    { "GLOSNOSC", 50,  0, 100, "%" },
    { "KONTRAST", 70,  0, 100, "%" },
    { "CZAS SYNC", 1,  0,   1, ""  },  // 0=OFF, 1=ON
};
static const int SETTINGS_COUNT = 4;

void load_sprites(){
    sprite[0].createFromBmp(status_body);
    sprite[1].createFromBmp(FollowersApocalypseReputation);
    sprite[2].createFromBmp(radaxis);
}

void change_cursor(int d){


    if (current_selected == SCR_NUFN)
        cursor += d;
        if (label[cursor] == "STN"){
            drawScreen(SCR_STN);
        }else if(label[cursor] == "RAD"){
            drawScreen(SCR_RAD);
        }else if(label[cursor] == "ZEG"){
            drawScreen(SCR_ZEG);
        }else if(label[cursor] == "UST"){
            drawScreen(SCR_UST);
        }
    else if(current_selected == SCR_UST){

    }
}

void drawScreen(Screen prop){
    tft.fillRect(0,50,480,250, COLOR_BG);
    if (prop == SCR_STN){
        drawScreenSTN();
    }else if(prop == SCR_RAD){
        drawScreenRAD();
    }
    else if(prop == SCR_ZEG){
        drawScreenZEG();
    
    }else if(prop == SCR_UST){
        drawScreenUST();
    }


    tft.setFont(&monofonto_rg9pt7b);
    tft.setTextColor(COLOR_GREEN);
    tft.setTextDatum(ML_DATUM);
    int y =90;
    int n = 0;
    for (const char* i : label){
        if(n==cursor){
            tft.fillRect(20,y-17,46,30,COLOR_GREEN);
            tft.fillRect(23,y-14,40,24,COLOR_BG);
        }
        tft.drawString(i, 30, y);
        y+= 40;
        n++;
    }
    
    tft.unloadFont();
}

void drawScreenSTN() {
    
    sprite[0].pushRotateZoom(&tft, 
    240,      // środek X na ekranie
    160,      // środek Y na ekranie
    0,      // rotacja w stopniach
    0.8,    // zoom X (0.5 = połowa rozmiaru)
    0.8  );   // zoom Y (0.5 = połowa rozmiaru)
}
void drawScreenRAD() {
    sprite[2].pushRotateZoom(&tft, 
    240,      // środek X na ekranie
    200,      // środek Y na ekranie
    0,      // rotacja w stopniach
    1,    // zoom X (0.5 = połowa rozmiaru)
    1  );   // zoom Y (0.5 = połowa rozmiaru)
}

void drawScreenZEG() {
    tft.setFont(&monofonto_rg70pt7b);
    tft.drawString(getTime(), 80, 160);
    tft.unloadFont();
}

void drawScreenDIFF() {

    sprite[1].pushRotateZoom(&tft, 
    240,      // środek X na ekranie
    160,      // środek Y na ekranie
    0,      // rotacja w stopniach
    1,    // zoom X (0.5 = połowa rozmiaru)
    1  );   // zoom Y (0.5 = połowa rozmiaru)
}

void drawScreenUST() {
    const int TABLE_X     = 80;   // lewa krawędź tabelki
    const int TABLE_Y     = 60;   // górna krawędź
    const int ROW_H       = 42;   // wysokość wiersza
    const int COL_NAME_W  = 180;  // szerokość kolumny "Nazwa"
    const int COL_VAL_W   = 140;  // szerokość kolumny "Wartość"
    const int TABLE_W     = COL_NAME_W + COL_VAL_W;

    // --- Nagłówek ---
    tft.fillRect(TABLE_X, TABLE_Y, TABLE_W, ROW_H - 6, COLOR_GREEN);
    tft.setFont(&monofonto_rg13pt7b);
    tft.setTextColor(COLOR_BG);
    tft.setTextDatum(ML_DATUM);
    tft.drawString("USTAWIENIE", TABLE_X + 10, TABLE_Y + (ROW_H - 6) / 2);
    tft.setTextDatum(MR_DATUM);
    tft.drawString("WARTOSC",    TABLE_X + TABLE_W - 10, TABLE_Y + (ROW_H - 6) / 2);

    // --- Wiersze ---
    for (int i = 0; i < SETTINGS_COUNT; i++) {
        int row_y = TABLE_Y + (ROW_H - 6) + i * ROW_H;
        bool selected = (i == ust_cursor);

        // Tło wiersza
        if (selected && !ust_edit) {
            // Zaznaczony — zielone tło
            tft.fillRect(TABLE_X, row_y, TABLE_W, ROW_H - 2, COLOR_GREEN);
        } else if (selected && ust_edit) {
            // Tryb edycji — ramka migająca (wypełnienie przyciemnione)
            tft.fillRect(TABLE_X, row_y, TABLE_W, ROW_H - 2, COLOR_BG);
            tft.drawRect(TABLE_X, row_y, TABLE_W, ROW_H - 2, COLOR_GREEN);
        } else {
            // Zwykły wiersz — obramowanie
            tft.fillRect(TABLE_X, row_y, TABLE_W, ROW_H - 2, COLOR_BG);
            tft.drawFastHLine(TABLE_X, row_y + ROW_H - 2, TABLE_W, COLOR_GREEN);
        }

        // Linia pionowa między kolumnami
        tft.drawFastVLine(TABLE_X + COL_NAME_W, row_y, ROW_H - 2, COLOR_GREEN);

        // Tekst nazwy
        tft.setFont(&monofonto_rg13pt7b);
        tft.setTextDatum(ML_DATUM);
        tft.setTextColor(selected && !ust_edit ? COLOR_BG : COLOR_GREEN);
        tft.drawString(settings[i].name, TABLE_X + 10, row_y + ROW_H / 2);

        // Tekst wartości (z jednostką)
        char val_buf[16];
        if (strcmp(settings[i].unit, "") == 0) {
            // Dla CZAS SYNC: ON/OFF
            snprintf(val_buf, sizeof(val_buf), "%s",
                     settings[i].value ? "ON" : "OFF");
        } else {
            snprintf(val_buf, sizeof(val_buf), "%d%s",
                     settings[i].value, settings[i].unit);
        }

        tft.setTextDatum(MR_DATUM);
        // W trybie edycji rysujemy strzałki < wartość >
        if (selected && ust_edit) {
            tft.setTextColor(COLOR_GREEN);
            char edit_buf[24];
            snprintf(edit_buf, sizeof(edit_buf), "< %s >", val_buf);
            tft.drawString(edit_buf, TABLE_X + TABLE_W - 10, row_y + ROW_H / 2);
        } else {
            tft.drawString(val_buf, TABLE_X + TABLE_W - 10, row_y + ROW_H / 2);
        }
    }

    // --- Podpowiedź na dole ---
    tft.setFont(&monofonto_rg9pt7b);
    tft.setTextDatum(MC_DATUM);
    tft.setTextColor(COLOR_GREEN);
    if (ust_edit) {
        tft.drawString("[</> ZMIEN]  [OK ZATWIERDZ]", 240, TABLE_Y + (ROW_H - 6) + SETTINGS_COUNT * ROW_H + 20);
    } else {
        tft.drawString("[^/v PORUSZAJ]  [OK EDYTUJ]", 240, TABLE_Y + (ROW_H - 6) + SETTINGS_COUNT * ROW_H + 20);
    }

    tft.unloadFont();
}