#include "status.h"
#include "../topbar.h"
#include "../../imgs/GRiD_Logo_White.h"
// --- Konstruktor inicjalizujący domyślne wartości ---
Status::Status() {
    cursor = 0;
    ust_cursor = 0;
    ust_edit = false;
    current_selected = SCR_STN;
    action_pool = SCR_NUFN;
    stn_edit = false; // <--- NOWE: flaga edycji STN
    temp_hp = player.hp;
    gmf_last_time = 0;
    gmf_show_grid = false;
    // --- NOWE ZMIENNE DLA IMIENIA ---
    strcpy(playerName, "VAULTBOY"); // Domyślne imię (max 8 znaków)
    name_char_idx = 0;

    // Inicjalizacja tablicy ustawień (zmieniamy rozmiar na 6)
    settings[0] = {"Wroc", 1,0,1,"BOOL"};
    settings[1] = { "IMIE",       0, 0,   0, ""     }; // value ignorowane, używamy playerName
    settings[2] = { "LEVEL",      1, 1, 100, ""     }; 
    settings[3] = { "JASNOSC",   80, 0, 100, "%"    };
    settings[4] = { "GLOSNOSC",  50, 0, 100, "%"    };
    settings[5] = { "KONTRAST",  70, 0, 100, "%"    };
    settings[6] = { "CZAS SYNC",  1, 0,   1, "BOOL" }; // Używamy "BOOL", aby łatwiej odróżnić ON/OFF od LEVEL
    

}

// --- Wczytywanie zasobów ---
void Status::loadSprites() {
    sprite[0].createFromBmp(statusBody);
    // Pamiętaj, aby podać właściwe wymiary. Z pliku .h wynika, że to 60x60.
    int width = 60;
    int height = 60;
    const uint16_t* b[] = { minka0, minka0,minka1, minka2, minka3, minka4 };
    for(int i =1; i<6;i++){
        sprite[i].setColorDepth(16);
        sprite[i].createSprite(width, height);
        sprite[i].setSwapBytes(true);
        sprite[i].pushImage(0, 0, width, height, b[i]);
    }


}
void drawBar(int x,int y, int weight){
    tft.fillRect(x,y,70,16, COLOR_BG);
    tft.fillRect(x,y,70,16, COLOR_GREEN);
    tft.fillRect(x+1,y+1,67,14, COLOR_BG);
    tft.fillRect(x+2,y+2,64*weight/100,12, COLOR_GREEN);
}
void Status::drawThemAll(){
    int weight = temp_hp * 100 / player.maxHp;
    drawBar(205,50,weight);
    drawBar(100,100,weight);
    drawBar(310,100,weight);    
    drawBar(110,210,weight);    
    drawBar(300,210,weight);    
}
void Status::changeCursor(int d) {
    Serial.println(current_selected);
    if (action_pool == SCR_NUFN) {
        cursor += d;
        
        // Zabezpieczenie przed wyjściem poza zakres (0 - 3)
        if (cursor < 0) cursor = 0;
        if (cursor > 3) cursor = 3;

        if (strcmp(label[cursor], "STN") == 0) {
            current_selected = SCR_STN;
        } else if (strcmp(label[cursor], "RAD") == 0) {
            current_selected = SCR_RAD;
        } else if (strcmp(label[cursor], "ZEG") == 0) {
            current_selected = SCR_ZEG;
        } else if (strcmp(label[cursor], "UST") == 0) {
            current_selected = SCR_UST;
        }else if (strcmp(label[cursor], "GMF") == 0) {
            current_selected = SCR_GMF;
        }
        Serial.print("Wybralem: ");
        Serial.println(label[cursor]);
        drawScreen();
    }else if (action_pool == SCR_STN) {
        if (stn_edit) {
            temp_hp += (d * 5); // Zmieniaj HP o 5 punktów za każdym skokiem
            
            // Zabezpieczenie przed wyjściem poza skalę
            if (temp_hp < 0) temp_hp = 0;
            if (temp_hp > player.maxHp) temp_hp = player.maxHp;
            
            drawThemAll(); // Rysuj ponownie, by zaktualizować paski
        }
    }
    
    else if (action_pool == SCR_UST) {
        if (!ust_edit) {
            ust_cursor += d;
            // Pamiętaj by zaktualizować limit na SETTINGS_COUNT (czyli 6)
            if (ust_cursor < 0) ust_cursor = 0;
            if (ust_cursor >= SETTINGS_COUNT) ust_cursor = SETTINGS_COUNT - 1;
        } else {
            // --- TRYB EDYCJI ---
            if (ust_cursor == 0) { 
                // 1. ZMIANA LITERY W IMIENIU (A-Z oraz Spacja)
                char& c = playerName[name_char_idx];
                if (d > 0) {
                    if (c >= 'A' && c < 'Z') c++;
                    else if (c == 'Z') c = ' '; // Po Z jest spacja
                    else if (c == ' ') c = 'A'; // Po spacji znowu A
                    else c = 'A'; // Zabezpieczenie
                } else if (d < 0) {
                    if (c > 'A' && c <= 'Z') c--;
                    else if (c == 'A') c = ' '; // Przed A jest spacja
                    else if (c == ' ') c = 'Z'; // Przed spacją jest Z
                    else c = 'Z'; // Zabezpieczenie
                }
            } else {
                // 2. ZMIANA WARTOŚCI LICZBOWYCH (stary kod)
                int step = 1; 
                if (strcmp(settings[ust_cursor].unit, "%") == 0) step = 5;
                settings[ust_cursor].value += (d * step);

                if (settings[ust_cursor].value < settings[ust_cursor].min_val) settings[ust_cursor].value = settings[ust_cursor].min_val;
                if (settings[ust_cursor].value > settings[ust_cursor].max_val) settings[ust_cursor].value = settings[ust_cursor].max_val;
            }
        }
        drawScreen();
    }
}

// --- Logika rysowania głównego ekranu ---
void Status::drawScreen() {
    tft.fillRect(0, 50, 480, 250, COLOR_BG);
    Serial.println(current_selected);
    if (current_selected == SCR_STN) {
        drawScreenSTN();
    } else if (current_selected == SCR_RAD) {
        drawScreenRAD();
    } else if (current_selected == SCR_ZEG) {
        drawScreenZEG();
    } else if (current_selected == SCR_UST) {
        drawScreenUST();
    }else if (current_selected == SCR_GMF) {
        drawScreenGMF();
    }


    // --- Pasek zakładek nawigacyjnych ---
    tft.setFont(&monofonto_rg9pt7b);
    tft.setTextColor(COLOR_GREEN);
    tft.setTextDatum(ML_DATUM);
    int y = 90;
    int n = 0;
    
    for (const char* i : label) {
        if (n == cursor) {
            tft.fillRect(20, y - 17, 46, 30, COLOR_GREEN);
            tft.fillRect(23, y - 14, 40, 24, COLOR_BG);
        }
        tft.drawString(i, 30, y);
        y += 40;
        n++;
    }
    
    tft.unloadFont();
}


// --- Prywatne metody rysujące poszczególne widoki ---
void Status::drawScreenSTN() {
    sprite[0].pushRotateZoom(&tft, 
    240,      // środek X na ekranie
    170,      // środek Y na ekranie
    0,        // rotacja w stopniach
    0.8,      // zoom X 
    0.8);     // zoom Y 

    int weight = player.hp * 100 / player.maxHp;
    int picid= 0;
    switch (weight) {
        case 85 ... 100:
            picid = 1;
            break;

        case 65 ... 84:
            picid = 2;
            break;

        case 35 ... 64:
            picid = 3;
            break;

        case 15 ... 34:
            picid = 4;
            break;
        case 0 ... 14:
            picid = 5;
            break;
    }
    sprite[picid].pushRotateZoom(&tft, 
    240,      // środek X na ekranie
    108,      // środek Y na ekranie
    0,        // rotacja w stopniach
    0.8,      // zoom X 
    0.8,
    0xF81F);
    drawThemAll();
}

void Status::drawScreenRAD() {
    sprite[2].pushRotateZoom(&tft, 
    240, 
    200, 
    0, 
    1.0, 
    1.0); 
}

void Status::drawScreenZEG() {
    tft.setFont(&monofonto_rg70pt7b);
    //tft.drawString(getTime(), 80, 160);
    tft.drawString("17:47", 80, 160);
    tft.unloadFont();
}

void Status::drawScreenDIFF() {
    sprite[1].pushRotateZoom(&tft, 
    240, 
    160, 
    0, 
    1.0, 
    1.0); 
}

void Status::drawScreenUST() {
    const int TABLE_X    = 80;   
    const int TABLE_Y    = 60;   
    const int ROW_H      = 42;   
    const int COL_NAME_W = 180;  
    const int COL_VAL_W  = 140;  
    const int TABLE_W    = COL_NAME_W + COL_VAL_W;

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
        int row_y = TABLE_Y+5 + (ROW_H - 6) + i * ROW_H;
        bool selected = (i == ust_cursor);

        if (selected && !ust_edit) {
            tft.fillRect(TABLE_X, row_y, TABLE_W, ROW_H - 2, COLOR_GREEN);
        } else if (selected && ust_edit) {
            tft.fillRect(TABLE_X, row_y, TABLE_W, ROW_H - 2, COLOR_BG);
            tft.drawRect(TABLE_X, row_y, TABLE_W, ROW_H - 2, COLOR_GREEN);
        } else {
            tft.fillRect(TABLE_X, row_y, TABLE_W, ROW_H - 2, COLOR_BG);
            tft.drawFastHLine(TABLE_X, row_y + ROW_H - 2, TABLE_W, COLOR_GREEN);
        }

        tft.drawFastVLine(TABLE_X + COL_NAME_W, row_y, ROW_H - 2, COLOR_GREEN);

        tft.setFont(&monofonto_rg13pt7b);
        tft.setTextDatum(ML_DATUM);
        tft.setTextColor(selected && !ust_edit ? COLOR_BG : COLOR_GREEN);
        tft.drawString(settings[i].name, TABLE_X + 10, row_y + ROW_H / 2);

        char val_buf[24];

        if (i == 1) {
            // RYSOWANIE IMIENIA
            if (ust_edit && selected) {
                // W trybie edycji pokazujemy aktywną literę, np: VA>U<LTBOY
                int pos = 0;
                for(int j = 0; j < 8; j++) {
                    if (j == name_char_idx) val_buf[pos++] = '>';
                    val_buf[pos++] = playerName[j];
                    if (j == name_char_idx) val_buf[pos++] = '<';
                }
                val_buf[pos] = '\0';
            } else {
                // Poza trybem edycji po prostu wyświetlamy imię
                snprintf(val_buf, sizeof(val_buf), "%s", playerName);
            }
        } else {
            // RYSOWANIE RESZTY ZMIENNYCH
            if (strcmp(settings[i].unit, "BOOL") == 0) {
                // Używamy nowej flagi BOOL, by odróżnić torebkę włącznika od pustego stringa LEVEL
                snprintf(val_buf, sizeof(val_buf), "%s", settings[i].value ? "ON" : "OFF");
            } else {
                snprintf(val_buf, sizeof(val_buf), "%d%s", settings[i].value, settings[i].unit);
            }
        }

        tft.setTextDatum(MR_DATUM);
        
        if (selected && ust_edit) {
            tft.setTextColor(COLOR_GREEN);
            
            // Dla imienia nawiasy wstawiliśmy już wyżej wokół pojedynczej litery, więc ich nie dublujemy
            if (i == 0) {
                tft.drawString(val_buf, TABLE_X + TABLE_W - 10, row_y + ROW_H / 2);
            } else {
                // Dla liczb zostawiamy twoje duże nawiasy edycji np: < 80% >
                char edit_buf[32];
                snprintf(edit_buf, sizeof(edit_buf), "< %s >", val_buf);
                tft.drawString(edit_buf, TABLE_X + TABLE_W - 10, row_y + ROW_H / 2);
            }
        } else {
            tft.drawString(val_buf, TABLE_X + TABLE_W - 10, row_y + ROW_H / 2);
        }

    
    }
    tft.unloadFont();
}

void Status::statusSelect() {
    if (action_pool == SCR_NUFN) {
        if (current_selected == SCR_UST) {
            action_pool = SCR_UST;
            ust_cursor = 0;
            ust_edit = false;
            drawScreen();
        }else if (current_selected == SCR_STN) {
            // WEJŚCIE W EDYCJĘ HP
            action_pool = SCR_STN;
            stn_edit = true;
            temp_hp = player.hp; // Pobieramy aktualne HP na start edycji
            drawScreen();
        }
    } else if (action_pool == SCR_STN) {
        if (stn_edit) {
            stn_edit = false;            // Zakończ edycję
            action_pool = SCR_NUFN; // Wróć sterowaniem do zakładek (TopBar)
            player.hp = temp_hp;         // ZAPISZ NOWE HP!
            
            drawTopBar();                // Aktualizacja TopBaru (HP w tekście)
            drawScreen();         // Rysujemy ponownie STN, co teraz zaktualizuje minkę
        }
    }
    else if (action_pool == SCR_UST) {
        if (!ust_edit) {
            ust_edit = true; // Wchodzimy w tryb edycji
            if (ust_cursor == 1) {
                name_char_idx = 1; // Zawsze zaczynamy edycję od 1. litery
            }
            else if(ust_cursor==0){
                action_pool = SCR_NUFN;
                ust_edit = false;
            }
        } else {
            if (ust_cursor == 1) { // Jesteśmy w edycji IMIENIA
                name_char_idx++;   // Przeskocz na następną literę
                
                if (name_char_idx >= 8) { // Jeśli zatwierdzono 8. literę
                    ust_edit = false;     // Zakończ edycję
                    name_char_idx = 0;
                }
            } else if(ust_cursor == 2){
                ust_edit = false; 
                player.level = settings[2].value;
                drawTopBar();
            }else {
                ust_edit = false; // Dla reszty ustawień wyjdź z edycji normalnie
            }
        }
        drawScreen();
    }
}
void Status::drawScreenGMF() {
    // 1. Czyścimy tło (upewnij się, że ten prostokąt zakrywa stare napisy)
    tft.fillRect(70, 60, 350, 120, COLOR_BG); 
    
    // 2. Wymuszamy ustawienia czcionki
    tft.setFont(&monofonto_rg70pt7b);
    tft.setTextColor(COLOR_GREEN, COLOR_BG); // Dodajemy kolor tła, by nadpisywał piksele
    tft.setTextDatum(TL_DATUM); // Standardowe wyrównanie (Top-Left)
    
    
    tft.drawString("SKN", 80, 40);
    tft.drawString("GRiD", 80, 160);
    tft.pushImage(360, 170, 110, 110, GRiD_Logo_White, 0xF81F);
    tft.unloadFont();
}
void Status::update() {
    // Tutaj wstaw stałą oznaczającą ekran GMF (zakładam, że nazywa się SCR_GMF)
    if (current_selected == SCR_GMF) { 
        // Jeśli minęły 4 sekundy (4000 ms)
        if (millis() - gmf_last_time >= 4000) {
            gmf_last_time = millis();
            
            // Odwracamy stan flagi: jeśli była true, staje się false i na odwrót
            if (gmf_show_grid){
                gmf_show_grid = false;
            }else{
                gmf_show_grid = true;
            }
            
            // Wypisz na konsolę, żebyśmy wiedzieli, czy flaga się przełącza
            Serial.print("Aktualizacja GMF. Nowy stan: ");
            Serial.println(gmf_show_grid ? "GRID" : "GMF");
            
            drawScreenGMF();
        }
    }
}