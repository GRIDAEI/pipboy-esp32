#include "special.h"
#include "display.h"
#include <string>
#include "../imgs/perception.h"
#include "../imgs/Endurance.h"
#include "../data/monofonto_rg12pt7b.h"
#include "../data/monofonto_rg13pt7b.h"
#include "../data/monofonto_rg70pt7b.h"
#include "../imgs/Strength2_icon.h"
#include "../imgs/perception.h"
#include "../imgs/Endurance.h"

struct Entry{
    const char* name;
    int value;
    const char* opis;
    int obrazId;
};
static LGFX_Sprite special_sprites[3];


void load_special_sprites(){
    special_sprites[0].createFromBmp(Strength2_icon);
    special_sprites[1].createFromBmp(perception);
    special_sprites[2].createFromBmp(Endurance);
}

int special_cursor = 0;
Entry special_entries[] = {
    {"Sila", 8, "Surowa siła fizyczna. Wysoka siła jest przydatna zwłaszcza dla postaci bazujących na cechach fizycznych.", 0},
    {"Percepcja", 4, "Opis percepcji", 1},
    {"Wytrzymalosc", 5, "Opis wytrzymalosc", 2},
    {"Charyzma", 4, "Opis wytrzymalosc", 2},
    {"Inteligencja", 7, "Opis wytrzymalosc", 2},
    {"Zwinnosc", 4, "Opis wytrzymalosc", 2},
    {"Sczescie", 3, "Opis wytrzymalosc", 2}
};
void drawDetails(){
    special_sprites[0].pushRotateZoom(&tft, 
    350,      // środek X na ekranie
    110,      // środek Y na ekranie
    0,      // rotacja w stopniach
    1.0,    // zoom X (0.5 = połowa rozmiaru)
    1.0  );   // zoom Y (0.5 = połowa rozmiaru)
}
void drawList() {
    tft.setFont(&monofonto_rg9pt7b);
    tft.setTextColor(COLOR_GREEN);
    
    // --- Sekcja rysowania listy ---
    tft.setTextDatum(ML_DATUM);
    int y = 80;
    int n = 0;
    for (Entry i : special_entries){
        if(n == special_cursor){
            tft.fillRect(40, y-17, 146, 30, COLOR_GREEN);
            tft.fillRect(43, y-14, 140, 24, COLOR_BG);
        }
        tft.drawString(i.name, 50, y);
        char str[4];
        itoa(i.value, str, 10);
        tft.drawString(str, 170, y);
        y += 30;
        n++;
    }

    // --- Sekcja ramki dla opisu ---
    int descX = 230;
    int descY = 180;
    int descW = 220;
    int descH = 80; // Zwiększyłem wysokość, żeby zmieścić więcej tekstu

    // Rysowanie obramowania
    tft.fillRect(descX, descY, descW, descH, COLOR_GREEN);
    tft.fillRect(descX , descY + 3, descW-3, descH , COLOR_BG);

    // --- Sekcja zawijania tekstu przy użyciu Sprite'a ---
    LGFX_Sprite descSprite(&tft);
    // 1. Skopiuj głębię kolorów z ekranu (żeby kolory się zgadzały)
    descSprite.setColorDepth(tft.getColorDepth()); 
    
    // 2. Zabezpieczenie: Sprawdzamy czy starczyło pamięci RAM na Sprite'a
    if (descSprite.createSprite(descW - 10, descH - 10)) {
        
        // 3. Wypełniamy Sprite kolorem tła (inaczej może mieć losowe "śmieci" lub przezroczystość)
         descSprite.fillSprite(COLOR_BG);
        
        descSprite.setFont(&monofonto_rg9pt7b);
        descSprite.setTextColor(COLOR_GREEN); // Ustawiamy tylko kolor tekstu
        descSprite.setTextWrap(true);
        
        // 4. BARDZO WAŻNE: Przesuwamy kursor startowy w dół o wysokość czcionki!
        // Dzięki temu tekst nie wyjdzie "górą" poza Sprite.
        int fontH = descSprite.fontHeight();
        descSprite.setCursor(0, fontH); 
        
        // Używamy print, żeby zadziałało zawijanie
        descSprite.print(special_entries[special_cursor].opis);
        
        // Rysujemy na ekranie
        descSprite.pushSprite(descX + 5, descY + 5);
        
        // Zwalniamy RAM
        descSprite.deleteSprite();
    } else {
        // Jeśli ten tekst pojawi się w konsoli, oznacza to, 
        // że ESP32/mikrokontroler ma za mało RAMu w danej chwili na stworzenie płótna.
        Serial.println("Blad: Za malo RAM na Sprite!"); 
    }
    tft.setTextDatum(TL_DATUM);
    tft.unloadFont();
    drawDetails();
}

