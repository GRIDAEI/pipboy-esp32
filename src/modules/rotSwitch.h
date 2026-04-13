#ifndef ROT_SWITCH_H
#define ROT_SWITCH_H

#include <Arduino.h>

class RotSwitch {
  private:
    uint8_t pinA;
    uint8_t pinB;
    uint8_t pinBtn;
    
    int counter;
    int lastStateA;
    
    unsigned long lastButtonPress;
    bool buttonClicked;

  public:
    // Konstruktor - tutaj podajemy numery pinów
    RotSwitch(uint8_t a, uint8_t b, uint8_t btn);
    
    // Funkcja inicjalizująca (wywoływana w setup)
    void begin();
    
    // Główna funkcja aktualizująca stan (wywoływana w loop)
    void update();
    
    // Zwraca aktualną pozycję enkodera
    int getPosition();
    
    // Zwraca true, jeśli przycisk został wciśnięty (i resetuje flagę)
    bool isClicked();
};

#endif