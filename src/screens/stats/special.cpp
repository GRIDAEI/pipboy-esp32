#include "special.h" // Twój plik nagłówkowy z klasą

// Includujemy grafiki tylko tutaj, bo tylko tutaj są fizycznie ładowane do pamięci
#include "../../imgs/Strength2_icon.h"
#include "../../imgs/perception.h"
#include "../../imgs/Endurance.h"

// 1. Definicja danych - tworzymy tablicę (zauważ, że tu NIE MA słowa extern)
Entry special_entries[] = {
    {"Sila", 8, "Surowa sila fizyczna. Wysoka siła jest przydatna zwłaszcza dla postaci bazujących na cechach fizycznych.", 0},
    {"Percepcja", 4, "Opis percepcji", 1},
    {"Wytrzymalosc", 5, "Opis wytrzymalosc", 2},
    {"Charyzma", 4, "Opis charyzmy", 2},
    {"Inteligencja", 7, "Opis inteligencji", 2},
    {"Zwinnosc", 4, "Opis zwinnosci", 2},
    {"Szczescie", 3, "Opis szczescia", 2}
};

// 2. Obliczamy faktyczny rozmiar tablicy RAZ i trzymamy w zmiennej
int special_max_entries = sizeof(special_entries) / sizeof(special_entries[0]);

// 3. Tworzymy tablicę obiektów LGFX_Sprite
LGFX_Sprite special_sprites[3];

// 4. Implementacja funkcji ładującej obrazki
void load_special_sprites() {
    special_sprites[0].createFromBmp(Strength2_icon);
    special_sprites[1].createFromBmp(perception);
    special_sprites[2].createFromBmp(Endurance);
}