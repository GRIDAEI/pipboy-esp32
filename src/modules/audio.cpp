#include <Arduino.h>
#include "AudioGeneratorWAV.h"
#include "AudioOutputI2S.h"
#include "AudioFileSourceLittleFS.h"
#include "AudioOutputMixer.h" // Dodajemy mikser

// Definiujemy, ile dźwięków maksymalnie może grać jednocześnie
// 3 to bezpieczna wartość dla pamięci RAM w ESP
#define MAX_VOICES 3 

AudioOutputI2S *outI2S;
AudioOutputMixer *mixer;

// Zamiast pojedynczych zmiennych, tworzymy tablice (kanały)
AudioGeneratorWAV *wav[MAX_VOICES];
AudioFileSourceLittleFS *file[MAX_VOICES];
AudioOutputMixerStub *stub[MAX_VOICES];

void initAudio() {
    outI2S = new AudioOutputI2S();
    outI2S->SetPinout(6, 7, 8);
    outI2S->SetGain(0.6); // Główna głośność całego wyjścia (może być wyższa)

    // 1. ZWIĘKSZ BUFOR MIKSERA
    // Zmieniamy z 32 na 128 lub 256. Daje to procesorowi więcej czasu 
    // na doczytanie danych z LittleFS, zapobiegając przerywaniu.
    mixer = new AudioOutputMixer(128, outI2S);

    for (int i = 0; i < MAX_VOICES; i++) {
        wav[i] = nullptr;
        file[i] = nullptr;
        stub[i] = mixer->NewInput();
        
        // 2. DRASTYCZNIE ZMNIEJSZ GŁOŚNOŚĆ KANAŁÓW
        // Jeśli masz MAX_VOICES = 3, ustaw kanały na 0.3
        // (0.3 + 0.3 + 0.3 = 0.9, co jest bezpiecznie poniżej limitu 1.0)
        stub[i]->SetGain(0.25); 
    }
}
void playSound(const char* name) {
    // 1. Szukamy wolnego kanału (który aktualnie nic nie odtwarza)
    int freeChannel = -1;
    for (int i = 0; i < MAX_VOICES; i++) {
        if (wav[i] == nullptr || !wav[i]->isRunning()) {
            freeChannel = i;
            break;
        }
    }

    // 2. Zabezpieczenie: jeśli wszystkie kanały są zajęte, ignorujemy klik
    // (przy krótkich kliknięciach i 3 kanałach rzadko się to zdarza)
    if (freeChannel == -1) {
        return; 
    }

    // 3. Czystka na znalezionym kanale (upewnienie się, że zwalniamy pamięć)
    if (wav[freeChannel]) { delete wav[freeChannel]; wav[freeChannel] = nullptr; }
    if (file[freeChannel]) { delete file[freeChannel]; file[freeChannel] = nullptr; }

    // 4. Odtwarzanie nowego pliku na wolnym kanale
    file[freeChannel] = new AudioFileSourceLittleFS(name);
    if (!file[freeChannel]->isOpen()) {
        Serial.printf("BŁĄD AUDIO: Nie można otworzyć pliku %s!\n", name);
        delete file[freeChannel]; 
        file[freeChannel] = nullptr;
        return;
    }

    wav[freeChannel] = new AudioGeneratorWAV();
    
    // Zamiast bezpośrednio do "out", wysyłamy dźwięk do "stub'a" (wejścia miksera)
    wav[freeChannel]->begin(file[freeChannel], stub[freeChannel]);
}

void handleAudio() {
    // Mikser sam się napędza, ale musimy "kręcić" każdym aktywnym generatorem WAV
    for (int i = 0; i < MAX_VOICES; i++) {
        if (wav[i] && wav[i]->isRunning()) {
            if (!wav[i]->loop()) {
                wav[i]->stop();
                // KLUCZOWE: Zwalniamy pamięć po zakończeniu utworu na danym kanale!
                delete wav[i]; wav[i] = nullptr;
                delete file[i]; file[i] = nullptr;
            }
        }
    }
}