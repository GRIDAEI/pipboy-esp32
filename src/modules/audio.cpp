#include <Arduino.h>
#include "AudioGeneratorWAV.h"
#include "AudioOutputI2S.h"
#include "AudioFileSourceLittleFS.h"

AudioGeneratorWAV *wav;
AudioFileSourceLittleFS *file;
AudioOutputI2S *out;

void initAudio() {
    out = new AudioOutputI2S();
    out->SetPinout(6, 5, 7);  // BCLK, LRC, DIN
    out->SetGain(0.3);        // głośność 0.0 - 1.0
}

void playSound(const char* name) {
    // Jeśli już gra — nie przerywaj

    file = new AudioFileSourceLittleFS(name);
    if (!file->isOpen()) return;

    wav = new AudioGeneratorWAV();
    wav->begin(file, out);
}

void handleAudio() {
    if (wav && wav->isRunning()) {
        if (!wav->loop()) {
            wav->stop();
        }
    }
}