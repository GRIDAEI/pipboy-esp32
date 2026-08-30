#include "zadania.h"

#include "../../imgs/Scienta.h"
#include "../../display.h"

#include "../../imgs/Icon_Vault_21_jumpsuit.h"

extern LGFX tft;
Entry zadania_entries[] = {
    {"12 groszy", -1, "Zdobadz/Sfalszuj dowody dla Porucznika Nolana ze ma wyzsze wykrztalcenie by mogl ubiegac sie o tytul oficera.",0},
    {"Zakon Marii 3/6", -1, "Wygraj trzy bitwy na arenie by dostac przepustke do podziemia.", 0},
    {"Jak jedwab", -1,"Slawek prosi cie bys zdobyl na jego wesele ciuchy z krypty 71. Kiedys byla wypelniona najlepszymi krawcami i ekspertami mody, lecz od dekad okupowani są przez ghoule. Jest szansa że dalej sa tam nienaruszone garnitury na slub.", 0}

};

int zadania_max_entries = 3;
// 3. INICJALIZACJA: Przypisujemy główny ekran do każdego sprite'a w tablicy
