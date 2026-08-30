#ifndef ROT_SWITCH_H
#define ROT_SWITCH_H

#include <Arduino.h>
#include "ESP32Encoder.h"
class RotSwitch {
  private:
  int analogPin = 9;
  int are_you_sure = 0;
  int getSwitchPosition(int adcValue);
  public:
  int lastPosition = -1;
    RotSwitch(int pin);
    void setPin(int p){analogPin = p;}
    int getPin(int p){return analogPin;}
    // Funkcja inicjalizująca (wywoływana w setup)
    void begin();
    
    // Główna funkcja aktualizująca stan (wywoływana w loop)
    int update();
    void update(ESP32Encoder &encoder, bool &up, bool &down);
    // Zwraca aktualną pozycję enkodera
    int getPosition();
    
    // Zwraca true, jeśli przycisk został wciśnięty (i resetuje flagę)
    bool isClicked();
    
    bool change_confidence(){
      are_you_sure += 1;
      // Zmieniamy z 3 na np. 50 lub 100, żeby dać mechanice czas
      if(are_you_sure > 10){ 
        are_you_sure = 0;
        Serial.println("Confident");
        return true;
      }
      return false;
    }
  };

#endif