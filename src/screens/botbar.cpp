#include "topbar.h"
#include "../config.h" 
#include "display.h"
#include "../data/monofonto_rg7pt7b.h"

void drawBottomNav(int activeTab) {
  const char* tabs[] = {"Status", "S.P.E.C.J.A.L", "Skille", "Cechy", "Relacje"};
  const int tabCount = 5;
  const int screenW = 480;
  const int navY = 295;
  const int tabW = screenW / tabCount;  // 96px każda zakładka
  tft.fillRect(0,295,480,65,COLOR_BG);
  tft.setFont(&monofonto_rg7pt7b);
  tft.drawLine(0, navY - 5, screenW, navY - 5, COLOR_GREEN);

  for (int i = 0; i < tabCount; i++) {
    int x = i * tabW;
    int textX = x + tabW / 2;  // środek zakładki

    if (i == activeTab) {
      // Podświetlona zakładka
      tft.fillRect(x, navY, tabW, 25, COLOR_GREEN);
      tft.setTextColor(TFT_BLACK, COLOR_GREEN);
    } else {
      tft.setTextColor(COLOR_GREEN, COLOR_BG);
    }

    // Centrowanie tekstu
    tft.setTextDatum(TC_DATUM);  // top-center
    tft.drawString(tabs[i], textX, navY + 5);
  }
  tft.setTextDatum(TL_DATUM);  // reset do domyślnego
  tft.unloadFont();
}
