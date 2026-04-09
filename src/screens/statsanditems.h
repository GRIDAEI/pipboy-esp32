#pragma once
#include <Arduino.h>
#include "display.h" // Zakładam, że tu masz zadeklarowane tft, fonty i COLOR_BG / COLOR_GREEN

struct Entry {
    const char* name;
    int value;
    const char* opis;
    int obrazId;
};

class StatsTemplate {
protected:
    Entry* entries;      // Wskaźnik na konkretną tablicę danych
    int  max_entries;     // Rozmiar tej tablicy
    int cursor;          // Aktualnie wybrana pozycja

public:
    // Konstruktor, który przyjmuje tablicę i jej rozmiar
    StatsTemplate(Entry* _entries, int _max_entries) {
        entries = _entries;
        max_entries = _max_entries;
        cursor = 0;
    }

    // Wirtualna funkcja - domyślnie nic nie robi.
    // Klasa dziedzicząca (np. Special) NADPISZE JĄ i narysuje swoje obrazki!
    virtual void drawDetails(int cur) {
        // Pusto celowo
    }

    void drawTextWordWrap(const char* text, int x, int y, int maxWidth) {
        tft.setCursor(x, y);
        int startX = x;
        int currentY = y;
        int lineHeight = tft.fontHeight();

        String currentWord = "";
        int len = strlen(text);

        for (int i = 0; i <= len; i++) {
            char c = text[i];

            if (c == ' ' || c == '\n' || c == '\0') {
                int wordWidth = tft.textWidth(currentWord);

                if (tft.getCursorX() + wordWidth > startX + maxWidth) {
                    currentY += lineHeight;
                    tft.setCursor(startX, currentY);
                }

                tft.print(currentWord);
                
                if (c == ' ') {
                    tft.print(" ");
                } else if (c == '\n') {
                    currentY += lineHeight;
                    tft.setCursor(startX, currentY);
                }

                currentWord = ""; 
            } else {
                currentWord += c;
            }
        }
    }

    void drawList() {
        // Optymalizacja: usunięto tft.fillRect(0,50,480,250, COLOR_BG);
        
        tft.setFont(&monofonto_rg9pt7b);
        
        // --- Sekcja rysowania listy ---
        tft.setTextDatum(ML_DATUM);
        int y = 80;
        Serial.printf("my penis1            ",max_entries);
        // Klasyczna pętla (wskaźniki nie obsługują range-based for)
        for (int n = 0; n < max_entries; n++) {
            Entry currentEntry = entries[n];
            Serial.println("my penis2");
            if(n == cursor){
                tft.fillRect(40, y-17, 146, 30, COLOR_GREEN);
                tft.fillRect(43, y-14, 140, 24, COLOR_BG);
            } else {
                tft.fillRect(40, y-17, 146, 30, COLOR_BG); // zmazywanie starej ramki
            }
            
            tft.setTextColor(COLOR_GREEN, COLOR_BG);
            tft.drawString(currentEntry.name, 50, y);
            
            char str[4];
            itoa(currentEntry.value, str, 10);
            String valStr = String(str) + " "; // spacja zamazująca stare cyfry
            tft.drawString(valStr, 170, y);
            
            y += 30;
        }

        // --- Sekcja ramki dla opisu ---
        int descX = 230;
        int descY = 180;
        int descW = 220;
        int descH = 80; 

        // Rysowanie obramowania i czyszczenie TYLKO wnętrza
        tft.fillRect(descX, descY, descW, descH, COLOR_GREEN);
        tft.fillRect(descX + 3, descY + 3, descW - 6, descH - 6, COLOR_BG);
        
        tft.setClipRect(descX + 5, descY + 5, descW - 10, descH - 10);
        
        tft.setFont(&monofonto_rg7pt7b);
        tft.setTextColor(COLOR_GREEN, COLOR_BG);
        tft.setTextDatum(TL_DATUM);
        
        // WYŁĄCZAMY wbudowane zawijanie z LovyanGFX
        tft.setTextWrap(false); 
        
        // Wypisanie opisu pod kątem wybranego kursora
        drawTextWordWrap(entries[cursor].opis, descX + 5, descY + 5, descW - 10);
        
        tft.clearClipRect();
        tft.unloadFont();
        
        // Wywołanie rysowania obrazka specyficznego dla zakładki
        drawDetails(cursor);
    }

    void up(){
        if (cursor > 0){
            cursor -= 1;
            drawList();
        }
    }

    void down(){
        // Używamy zmiennej max_entries zamiast niebezpiecznego sizeof()
        if (cursor < max_entries - 1){
            cursor += 1;
            drawList();
        }
    }

}; // Koniec klasy (bardzo ważny średnik!)