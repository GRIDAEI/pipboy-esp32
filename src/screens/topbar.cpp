#include "topbar.h"
#include "../config.h"  
#include "display.h"
#include <LittleFS.h>
#include "../data/monofonto_rg12pt7b.h"
#include "../data/monofonto_rg13pt7b.h"

int staty_begin_x = 15;
int staty_line_length = 180;
int line_width = 2;


String currentTopName = "STATY.";
void drawTopBar() {
  tft.setFont(&monofonto_rg13pt7b);
  
  // === TŁO CAŁEGO TOPBARA ===
  tft.fillRect(0, 0, SCREEN_W, 50, COLOR_BG);

  tft.fillRect(staty_begin_x, 20, staty_line_length, line_width,COLOR_GREEN);
  tft.fillRect(staty_begin_x, 20, line_width, 25,COLOR_GREEN);
  tft.fillRect(staty_begin_x + staty_line_length, 20, line_width, 25,COLOR_GREEN);
  // === "STATS" po lewej ===
  tft.setTextColor(COLOR_GREEN);
  tft.setTextDatum(ML_DATUM);  
  
  tft.fillRect(staty_begin_x + 10, 20, 100, 20,COLOR_BG);
  tft.drawString(currentTopName, 40, 20);
  tft.unloadFont();
  tft.setFont(&monofonto_rg9pt7b);
  int level = 20;
  tft.drawString("LVL " + String(player.level), staty_line_length-45, 35);

 
  struct StatField {
    const char* label;
    const char* value;
    int x;
  };
  char hpBuffer[20];

 
  snprintf(hpBuffer, sizeof(hpBuffer), "%d/%d", player.hp, player.maxHp);

  StatField fields[] = {
      { "HP ",  hpBuffer,     203 },
      { "AP ",  "67/67",      297 },
      { "XP ",  "476/3050",   375 }
  };

  for (auto& f : fields) {

    tft.setTextColor(COLOR_GREEN);
    tft.setTextDatum(ML_DATUM);
    tft.drawString(f.label, f.x, 35);

    tft.setTextColor(COLOR_GREEN);
    int labelW = tft.textWidth(f.label);
    tft.drawString(f.value, f.x + labelW-5, 35);

    int small_line = tft.textWidth(f.label) + tft.textWidth(f.value)-2;

    tft.fillRect(f.x, 20, small_line,line_width);
    tft.fillRect(f.x + small_line, 20, line_width,25);
  }

  tft.setTextDatum(TL_DATUM);  
}