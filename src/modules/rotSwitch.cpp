#include "RotSwitch.h"

RotSwitch::RotSwitch(uint8_t a, uint8_t b, uint8_t btn) {
    pinA = a;
    pinB = b;
    pinBtn = btn;
    counter = 0;
    buttonClicked = false;
    lastButtonPress = 0;
}

void RotSwitch::begin() {
    // Włączamy wewnętrzne rezystory podciągające dla gołego enkodera
    pinMode(pinA, INPUT_PULLUP);
    pinMode(pinB, INPUT_PULLUP);
    pinMode(pinBtn, INPUT_PULLUP);
    
    // Odczytujemy stan początkowy pinu A
    lastStateA = digitalRead(pinA);
}

void RotSwitch::update() {
    // --- 1. Obsługa obrotu (kodu Graya) ---
    int currentStateA = digitalRead(pinA);
    
    // Reagujemy tylko na zmianę stanu pinu A
    if (currentStateA != lastStateA) {
        // Jeśli pin B ma inny stan niż pin A, kręcimy w jedną stronę
        if (digitalRead(pinB) != currentStateA) {
            counter++;
        } else {
            // W przeciwnym razie kręcimy w drugą
            counter--;
        }
    }
    lastStateA = currentStateA;

    // --- 2. Obsługa przycisku z prostym filtrowaniem (debouncing) ---
    int btnState = digitalRead(pinBtn);
    
    // Sprawdzamy czy wciśnięty (stan LOW przez INPUT_PULLUP)
    if (btnState == LOW) {
        // Filtrowanie drgań styków: sprawdzamy czy minęło 50ms od ostatniego kliknięcia
        if (millis() - lastButtonPress > 50) {
            buttonClicked = true;
        }
        lastButtonPress = millis();
    }
}

int RotSwitch::getPosition() {
    // Enkodery mechaniczne często generują 2 skoki na jedno "kliknięcie" fizyczne.
    // Dzielenie przez 2 pomaga to ustabilizować (możesz usunąć /2 jeśli reaguje za wolno).
    return counter / 2; 
}

bool RotSwitch::isClicked() {
    if (buttonClicked) {
        buttonClicked = false; // Resetujemy flagę po odczytaniu, żeby nie klikał w nieskończoność
        return true;
    }
    return false;
}