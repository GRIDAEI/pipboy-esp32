#include "rotSwitch.h"

RotSwitch::RotSwitch(int pin) {
    setPin(pin);
}

// NOWA FUNKCJA: Tłumaczy odczyt ADC na pozycję 0-4 (lub -1 w razie błędu)
int RotSwitch::getSwitchPosition(int adcValue) {
    // Szerokie "okna", żeby wychwycić lekko pływające napięcie
        // Pozycja 0: ~0V
    if (adcValue < 400) {
        return 0;
    }
    // Pozycja 1: Twój odczyt to ok. 1650-1700
    else if (adcValue >= 780 && adcValue <= 820) {
        return 1;
    }
    // Pozycja 2: Twój odczyt to ok. 2600
    else if (adcValue >= 1670 && adcValue <= 1750) {
        return 2;
    }
    // Pozycja 3: TUTAJ STRZELAM (zakładam ok. 3300-3400). 
    // Jeśli nie łapie, sprawdź w Serial Monitorze, jaką wartość wypluwa na 4. nóżce.
    else if (adcValue >= 2580 && adcValue <= 2700) {
        return 3;
    }
    // Pozycja 4: Twój odczyt to ok. 4070
    else if (adcValue > 4000) {
        return 4;
    }

    // Stan nieustalony (pomiędzy "oknami" w trakcie kręcenia)
    return -1; 
}

int RotSwitch::update() {
    int adcValue = analogRead(analogPin);
    int currentPosition = getSwitchPosition(adcValue);

    // 1. ODRZUCENIE BŁĘDÓW: Odczyt nie trafia w żadne "okno"
    if (currentPosition == -1) {
        are_you_sure = 0; 
        return -1; // Zwracamy -1 (brak potwierdzonej akcji)
    }

    // 2. BRAK ZMIANY: Pozycja stabilna
    if (currentPosition == lastPosition) {
        are_you_sure = 0; 
        return -1; 
    }

    // 3. WYKRYTO ZMIANĘ: Czekamy na upewnienie się (debouncing)
    if (!change_confidence()) {
        return -1; 
    }
  
    // 4. MAMY PEWNOŚĆ: Zmiana została potwierdzona
    lastPosition = currentPosition; // Zapisujemy nowy stan
    
    Serial.print("NOWA POZYCJA PRZEŁĄCZNIKA: ");
    Serial.println(currentPosition);
  
    // Zwracamy KONKRETNĄ pozycję (0, 1, 2, 3 lub 4)
    return currentPosition; 
}

void RotSwitch::update(ESP32Encoder &encoder, bool &up, bool &down) {
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