#pragma once
#include <Arduino.h>
#include "display.h" 
// Deklarujemy, że taka funkcja istnieje w innym pliku
extern bool isInputChanged(); 

struct Entry {
    const char* name;
    int value;
    const char* opis;
    int obrazId;

    int dmg = -1;
    int w = -1;
    int v = -1;
    int s = -1;

    bool isEquipped = false; // NOWE: Flaga, czy przedmiot jest aktualnie założony

    // Konstruktor dla Cech, Skilli, Relacji (4 parametry)
    Entry(const char* _name, int _value, const char* _opis, int _obrazId)
        : name(_name), value(_value), opis(_opis), obrazId(_obrazId), dmg(-1), w(-1), v(-1), s(-1), isEquipped(false) {}

    // Konstruktor dla Broni, Przedmiotów (8 parametrów)
    Entry(const char* _name, int _value, const char* _opis, int _obrazId, int _dmg, int _w, int _v, int _s)
        : name(_name), value(_value), opis(_opis), obrazId(_obrazId), dmg(_dmg), w(_w), v(_v), s(_s), isEquipped(false) {}
};

class StatsTemplate {
protected:
    Entry* entries;      // Wskaźnik na konkretną tablicę danych
    int  max_entries;    // Rozmiar tej tablicy
    
    // --- NOWE: Tryb wyświetlania okna ---
    // 0 = Opis (domyślnie, dla Skilli/Cech)
    // 1 = Statystyki (dla Broni/Przedmiotów)
    // 2 = Ukryte (brak okna)
    int infoMode = 0; 
    
    // --- NOWE: Czy ta kategoria pozwala na ekwipowanie przedmiotów ---
    bool canEquip = false;
    bool canChangeValue = false; 
    int maxValue = 100;
    const char* prefCategory = "DEF";
public:
    int cursor;          // Aktualnie wybrana pozycja
    bool editing = false;
    StatsTemplate(Entry* _entries, int _max_entries) {
        entries = _entries;
        max_entries = _max_entries;
        cursor = 0;
    }

    // Wirtualna funkcja do rysowania obrazka
    virtual void drawDetails(int cur) { }
    
    // Wirtualna funkcja do rysowania statystyk (Dmg, Waga, itp.)
    virtual void drawItemStats(int cur, int startX, int startY) {}
    
    // Funkcja do zmiany trybu wyświetlania
    void setInfoMode(int mode) {
        infoMode = mode;
    }

    // Funkcja włączająca możliwość zakładania przedmiotów w tej zakładce
    void setEquippable(bool state) {
        canEquip = state;
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
    void setModifiable(bool state, int max_val = 100, const char* pref = "DEF") {
        canChangeValue = state;
        maxValue = max_val;
        prefCategory = pref;
    }

    // --- NOWA FUNKCJA: Wczytanie wszystkich statystyk przy starcie ---
    void loadFromPreferences() {
        if (!canChangeValue) return; // Wczytuj tylko dla zakładek ze statystykami

        Preferences preferences;
        // Otwieramy w trybie odczytu I zapisu (false)
        preferences.begin("pipboy", false); 
        
        for (int i = 0; i < max_entries; i++) {
            char klucz[15];
            snprintf(klucz, sizeof(klucz), "%s_%d", prefCategory, i);
            
            // Jeśli taki wpis jeszcze nie istnieje (np. pierwsze uruchomienie projektu)
            if (!preferences.isKey(klucz)) {
                // Zapisujemy od razu obecną wartość (tą domyślną zadeklarowaną w tablicy) do NVS
                preferences.putInt(klucz, entries[i].value);
            } else {
                // Jeśli istnieje, normalnie go pobieramy
                entries[i].value = preferences.getInt(klucz); 
            }
        }
        
        preferences.end();
    }

    void drawList() {
        if (isInputChanged()) return; // <--- INTERRUPT

        tft.setFont(&monofonto_rg9pt7b);
        tft.setTextDatum(ML_DATUM);
        
        tft.fillRect(10, 60, 190, 230, COLOR_BG); 
        
        // 2. Po wyczyszczeniu tła też warto sprawdzić
        if (isInputChanged()) return; // <--- INTERRUPT

        const int ITEMS_PER_PAGE = 7;
        int current_page = cursor / ITEMS_PER_PAGE;
        int start_idx = current_page * ITEMS_PER_PAGE;
        int end_idx = start_idx + ITEMS_PER_PAGE;
        
        if (end_idx > max_entries) {
            end_idx = max_entries;
        }

        // --- GŁÓWNA PĘTLA RYSUJĄCA LISTĘ ---
        for (int i = start_idx; i < end_idx; i++) {
            
            // 3. NAJWAŻNIEJSZE MIEJSCE: Przerywamy przed narysowaniem kolejnej linijki
            if (isInputChanged()) return; // <--- INTERRUPT

            Entry currentEntry = entries[i];
            
            int screen_row = i - start_idx;
            int y = 80 + (screen_row * 30);

            if(i == cursor){
                tft.fillRect(40, y-17, 156, 30, COLOR_GREEN);
                tft.fillRect(43, y-14, 150, 24, COLOR_BG);
            } 
            
            tft.setTextColor(COLOR_GREEN, COLOR_BG);

            // --- ZMIANA: Rysowanie kwadracika ekwipunku ---
            int textX = 50; 
            if (canEquip) {
                textX = 60; 
                if (currentEntry.isEquipped) {
                    tft.fillRect(47, y - 4, 6, 6, COLOR_GREEN); 
                }
            }
            
            tft.drawString(currentEntry.name, textX, y);
            
            if(currentEntry.value > -1 && infoMode == 0){
                char str[4];
                itoa(currentEntry.value, str, 10);
                String valStr = String(str) + " "; 
                tft.drawString(valStr, 170, y);
            }
        }

        // 4. Zanim zaczniemy rysować skomplikowane okienka dolne
        if (isInputChanged()) return; // <--- INTERRUPT

        int arrow_x = 25; 
        if (start_idx > 0) {
            tft.fillTriangle(arrow_x - 8, 85, arrow_x + 8, 85, arrow_x, 72, COLOR_GREEN);
        }
        if (end_idx < max_entries) {
            int last_row_y = 80 + ((ITEMS_PER_PAGE - 1) * 30); 
            tft.fillTriangle(arrow_x - 8, last_row_y - 7, arrow_x + 8, last_row_y - 7, arrow_x, last_row_y + 6, COLOR_GREEN);
        }

        // Rysowanie okna dolnego na podstawie infoMode
        if (true) {//trza to usunac ale nie chce mi sie
            int descX = 210;
            int descY = 180;
            int descW = 220;
            int descH = 100; 

            if (infoMode == 0) {
                tft.fillRect(descX, descY, descW, descH, COLOR_GREEN);
                tft.fillRect(descX + 3, descY + 3, descW - 6 , descH - 6 , COLOR_BG); 
                
                tft.setClipRect(descX + 5, descY + 5, descW - 10, descH - 10);
                
                tft.setFont(&monofonto_rg7pt7b);
                tft.setTextColor(COLOR_GREEN, COLOR_BG);
                tft.setTextDatum(TL_DATUM);
                tft.setTextWrap(false); 
                drawTextWordWrap(entries[cursor].opis, descX + 5, descY + 5, descW - 10);
                tft.fillRect(210, 50, 220, 130, COLOR_BG); 
            } 
            else if (infoMode == 1) {
                int thirdW = descW/3;
                int thirdH = descH/3;
                //DPS - ONS
                tft.fillRect(descX, descY, thirdW, thirdH, COLOR_GREEN);
                tft.fillRect(descX, descY+3, thirdW - 3 , thirdH , COLOR_BG);
                //V/W - WDW
                tft.fillRect(descX + thirdW+ 10, descY, thirdW, thirdH, COLOR_GREEN);
                tft.fillRect(descX + thirdW + 10, descY+3, thirdW - 3 , thirdH , COLOR_BG);
                //SIL
                tft.fillRect(descX + 2*thirdW+ 15, descY, thirdW, thirdH, COLOR_GREEN);
                tft.fillRect(descX + 2*thirdW + 15, descY+3, thirdW - 3 , thirdH , COLOR_BG);

                tft.fillRect(descX, descY+thirdH+7, descW +15, thirdH*2, COLOR_GREEN);
                tft.fillRect(descX + 3, descY +thirdH+ 10, descW +15, (2*thirdH) , COLOR_BG);    
                tft.setFont(&monofonto_rg7pt7b);
                drawTextWordWrap(entries[cursor].opis, descX + 10, descY + 50, descW +10);

                drawItemStats(cursor, descX + 5, descY + 5);
                tft.fillRect(210, 50, 220, 130, COLOR_BG); 
            }
            else if(infoMode == 2){
                tft.fillRect(210, 50, 220, 130, COLOR_BG); 
            }
            else if(infoMode ==3){
                tft.setFont(&monofonto_rg7pt7b);
                tft.fillRect(descX, 50, descW, 200, COLOR_GREEN);
                tft.fillRect(descX+3, 53, descW - 6 , 194 , COLOR_BG);
                drawTextWordWrap(entries[cursor].opis, descX + 10, 70, descW-20);
            }
            
            tft.clearClipRect();
        }
        tft.unloadFont();
        
        // 5. Ostatnie sprawdzenie przed ładowaniem ewentualnych grafik
        if (isInputChanged()) return; // <--- INTERRUPT
        
        
        drawDetails(cursor);
    }

    // --- NOWA FUNKCJA: Rysuje TYLKO liczbę na ekranie (bez mrugania!) ---
    void redrawStatValue(int idx) {
        if (infoMode != 0) return;
        
        const int ITEMS_PER_PAGE = 7;
        int start_idx = (idx / ITEMS_PER_PAGE) * ITEMS_PER_PAGE;
        
        if (idx >= start_idx && idx < start_idx + ITEMS_PER_PAGE) {
            int y = 80 + ((idx - start_idx) * 30);
            
            tft.setFont(&monofonto_rg9pt7b);
            tft.setTextDatum(ML_DATUM);
            
            // Kolor zaznaczenia w trybie edycji!
            if (editing && idx == cursor) {
                tft.setTextColor(COLOR_BG, COLOR_GREEN); // Inwersja (czarny napis na zielonym tle) by pokazać, że edytujemy
            } else {
                tft.setTextColor(COLOR_GREEN, COLOR_BG); 
            }
            
            char str[6];
            itoa(entries[idx].value, str, 10);
            String valStr = String(str) + " "; // Spacje z tyłu żeby zamalować ewentualne stare zera
            
            tft.drawString(valStr, 170, y);
            tft.unloadFont();
        }
    }

    void up(){
        if(editing){
            entries[cursor].value++;
            if (entries[cursor].value > maxValue) {
                entries[cursor].value = maxValue; 
            }
            // ZAMIAST drawList(), odświeżamy tylko liczbę!
            redrawStatValue(cursor);
            return;
        }
        if (cursor > 0){
            cursor -= 1;
            drawList();
        }
    }

    void down(){
        if(editing){
            entries[cursor].value--;
            if (entries[cursor].value < 0) {
                entries[cursor].value = 0; 
            }
            // ZAMIAST drawList(), odświeżamy tylko liczbę!
            redrawStatValue(cursor);
            return;
        }
        if (cursor < max_entries - 1){
            cursor += 1;
            drawList();
        }
    }

    virtual void select() {
        if (canEquip) {
            bool currentStatus = entries[cursor].isEquipped;
            for (int i = 0; i < max_entries; i++) entries[i].isEquipped = false;
            entries[cursor].isEquipped = !currentStatus;
            drawList();
        } 
        else if (canChangeValue) {
            if (editing) {
                Preferences preferences;
                preferences.begin("pipboy", false);
                char klucz[15];
                snprintf(klucz, sizeof(klucz), "%s_%d", prefCategory, cursor);
                preferences.putInt(klucz, entries[cursor].value);
                preferences.end();
                
                editing = false;
                redrawStatValue(cursor); // Odśwież (wróci normalny kolor)
            } else {
                // ZACZYNAMY EDYCJĘ
                editing = true;
                redrawStatValue(cursor); // Odśwież (zmieni kolor na odwrócony)
            }
        }
    }
};