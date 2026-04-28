#include "rotSwitch.h"

RotSwitch::RotSwitch(int pin){
    setPin(pin);
}

int RotSwitch::update(){
  int adcValue = analogRead(analogPin);
  int currentPosition = getSwitchPosition(adcValue);

  if(currentPosition !=lastPosition){
    if (!change_confidence()) return 0;
  }
  
  int toreturn = 0;
  if (currentPosition!= lastPosition){
    if (currentPosition> lastPosition){
        Serial.print("WIECEJ");
        Serial.println(currentPosition);
        toreturn = 1;
    }else{
        Serial.print("Mniej");
        Serial.println(currentPosition);
        toreturn = -1;
    }
  }
  lastPosition = currentPosition;
    return toreturn;
}
void RotSwitch::updateEncoder(ESP32Encoder &encoder, bool &up, bool &down) {
    long currentCount = (long)encoder.getCount();
    static long lastCount = 0; 
    
    // Domyślnie resetujemy stany na HIGH (zakładamy brak ruchu)
    up = HIGH;
    down = HIGH;
    
    // Jeśli pozycja się zmieniła
    if (currentCount != lastCount) {
        
        if (currentCount > lastCount) {
            up = LOW;     // Zmiana w górę
        } 
        else {
            down = LOW;   // Zmiana w dół
        }
        
        lastCount = currentCount; 
    }
}
