#include "topbar.h"
#include "../config.h" 
#include "display.h"
#include "../data/monofonto_rg7pt7b.h"

void drawBottomNav(int activeTab) {
    const char** tabs;
    int tabCount = 0;

    switch (section_id) {
        case 0: { 
            static const char* t[] = {"Status", "S.P.E.C.J.A.L", "Skille", "Cechy", "Relacje"};
            tabs = t;
            tabCount = 5;
            break;
        }
        case 1: { 
            static const char* t[] = {"Bron", "Stroj", "Pomoc", "Roczne", "Amunicja"};
            tabs = t;
            tabCount = 5;
            break;
        }
        case 2: { 
            static const char* t[] = {"Mapa Lok.", "Mapa Sw.", "Zadania", "Dane", "Radio"};
            tabs = t;
            tabCount = 5;
            break;
        }
        default: {
            static const char* t[] = {"Brak"};
            tabs = t;
            tabCount = 1;
            break;
        }
    }

    const int screenW = 480;
    const int navY = 295;
    
    int tabW = (tabCount > 0) ? (screenW / tabCount) : screenW;  

    tft.fillRect(0, 295, 480, 65, COLOR_BG);
    tft.setFont(&monofonto_rg7pt7b);
    tft.drawLine(0, navY - 5, screenW, navY - 5, COLOR_GREEN);

    for (int i = 0; i < tabCount; i++) {
        int x = i * tabW;
        int textX = x + tabW / 2;  

        if (i == activeTab) {
            tft.fillRect(x, navY, tabW, 25, COLOR_GREEN);
            tft.setTextColor(TFT_BLACK, COLOR_GREEN);
        } else {
            tft.setTextColor(COLOR_GREEN, COLOR_BG);
        }

        tft.setTextDatum(TC_DATUM);  
        tft.drawString(tabs[i], textX, navY + 5);
    }
    
    tft.setTextDatum(TL_DATUM);  
    tft.unloadFont();
}
