#ifndef ROT_SWITCH_H
#define ROT_SWITCH_H

#include <Arduino.h>
#include "ESP32Encoder.h"
class RotSwitch {
  private:
  int analogPin = 9;
  int are_you_sure = 0;

  public:
  int lastPosition = 0;
    RotSwitch(int pin);
    void setPin(int p){analogPin = p;}
    int getPin(int p){return analogPin;}
    // Funkcja inicjalizująca (wywoływana w setup)
    void begin();
    
    // Główna funkcja aktualizująca stan (wywoływana w loop)
    int update();
    
    // Zwraca aktualną pozycję enkodera
    int getPosition();
    
    // Zwraca true, jeśli przycisk został wciśnięty (i resetuje flagę)
    bool isClicked();
    
    bool change_confidence(){
      are_you_sure += 1;
      if(are_you_sure>3){
        are_you_sure = 0;
        Serial.println("Confident");
        return true;
      }
      return false;
    }

    int getSwitchPosition(int adcValue) {
      // Sprawdzamy, w którym "oknie" mieści się odczyt.
      // Używamy bezpiecznych marginesów pomiędzy idealnymi wartościami.
      
      if (adcValue > 3500) {
        // Idealnie byłoby 4095 (bezpośrednio 3.3V)
        return 4; 
      } 
      else if (adcValue > 2500) {
        // Idealnie byłoby 3071 (ok. 2.47V)
        return 3; 
      } 
      else if (adcValue > 1500) {
        // Idealnie byłoby 2047 (ok. 1.65V)
        return 2; 
      } 
      else if (adcValue > 500) {
        // Idealnie byłoby 1023 (ok. 0.82V)
        return 1; 
      } 
      else {
        return 0; 
      }
    }
    void updateEncoder(ESP32Encoder &encoder, bool &up, bool &down);
};

#endif