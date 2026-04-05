#include "rtc.h"
#include <Wire.h>

// Tutaj FIZYCZNIE tworzymy obiekt rtc. Robimy to tylko raz w całym projekcie!
RTC_DS3231 rtc;

void start_zeg(int rtc_sda, int rtc_scl){
    Wire.begin(rtc_sda, rtc_scl);
    if (!rtc.begin()) {
        Serial.println("Nie znaleziono modulu RTC!");
        while (1) delay(10);
    }
    if (rtc.lostPower()) {
        Serial.println("RTC stracil zasilanie, ustawiam czas na nowo!");
        rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
    }
    }

// Funkcja do ręcznego ustawiania czasu w module RTC
void ustawZegarRTC(int rok, int miesiac, int dzien, int godzina, int minuta, int sekunda) {
  // Przekazujemy parametry do metody adjust() z biblioteki RTClib
  rtc.adjust(DateTime(rok, miesiac, dzien, godzina, minuta, sekunda));
  
  // Opcjonalnie: potwierdzenie na porcie szeregowym
  Serial.printf("✅ Czas zaktualizowany na: %04d/%02d/%02d %02d:%02d:%02d\n", 
                rok, miesiac, dzien, godzina, minuta, sekunda);
}
const char* getTime() {
  // Słówko 'static' sprawia, że ta zmienna nie zniknie po wyjściu z funkcji.
  // Rozmiar 6 wystarczy na "HH:MM" i ukryty znak końca tekstu '\0'.
  static char buforCzasu[6]; 
  
  DateTime now = rtc.now();
  
  // Formatujemy tekst: "%02d" oznacza liczbę dwucyfrową z zerem z przodu
  snprintf(buforCzasu, sizeof(buforCzasu), "%02d:%02d", now.hour(), now.minute());
  
  return buforCzasu;
}
// Funkcja nieblokująca, odczytująca czas dokładnie co 1000 milisekund
void odczytajCzasCoSekunde() {
  // Zmienna 'static' zachowuje swoją wartość między wywołaniami funkcji
  static unsigned long zapamietanyCzas = 0; 
  unsigned long aktualnyCzas = millis();

  // Sprawdzamy, czy minęło już 1000 milisekund (1 sekunda)
  if (aktualnyCzas - zapamietanyCzas >= 1000UL) {
    // Aktualizujemy zapamiętany czas
    zapamietanyCzas = aktualnyCzas;

    // Pobieramy i wyświetlamy czas
    getTime();
  }
}