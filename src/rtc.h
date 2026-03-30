#pragma once
#include <RTClib.h> // Konieczne, aby kompilator wiedział, czym jest typ RTC_DS3231

// Obiecujemy kompilatorowi, że obiekt 'rtc' istnieje gdzieś w projekcie.
// Dzięki temu będziesz mógł używać rtc.now() w swoim głównym pliku programu.
extern RTC_DS3231 rtc;

// Deklaracja Twojej funkcji
void ustawZegarRTC(int rok, int miesiac, int dzien, int godzina, int minuta, int sekunda);
void start_zeg(int rtc_sda, int rtc_scl);
const char* getTime();
void odczytajCzasCoSekunde();