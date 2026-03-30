#include <Arduino.h>
#include <LovyanGFX.hpp>
#include "screens/screen.h"


#include "display.h"
#include "config.h"
#include <LittleFS.h>
#include "imgs/pip.h"
#include "audio.h"
#include "rtc.h"


int upbtn =46;
bool upclk = false;
bool upPrev = HIGH;
int downbtn =3;
bool downclk = false;
bool downPrev = HIGH;

int vibr_pin = 10;
int vibr_ms = 80;

int rtc_sda = 8;
int rtc_scl = 9;


unsigned long vibroEnd = 0;



void vibrate(int ms = vibr_ms) {
    digitalWrite(vibr_pin, HIGH);
    vibroEnd = millis() + ms;
}

void handleVibro() {
    if (vibroEnd > 0 && millis() >= vibroEnd) {
        digitalWrite(vibr_pin, LOW);
        vibroEnd = 0;
    }
}

void setup() {
  Serial.begin(115200);
  Serial.println("Startt!!!");
  tft.init();               // 1. najpierw ekran
  tft.setRotation(1);
  tft.fillScreen(COLOR_BG);
  
  pinMode(upbtn, INPUT_PULLUP);
  pinMode(downbtn, INPUT_PULLUP);
  pinMode(vibr_pin, OUTPUT);
  digitalWrite(vibr_pin, LOW);


  if (!LittleFS.begin()) {
    Serial.println("LittleFS mount failed!");
    return;
  }
  load_all_sprites();
  
  current_screen = Special;
  Serial.println("Rysuje ekran");
  topbot();
  if (current_screen.drawFunction) {
      current_screen.drawFunction();
  } else {
      Serial.println("BLAD: drawFunction jest PUSTE! Brakuje przypisania.");
  }
  //start_zeg(rtc_sda, rtc_scl); // 3. RTC
  //initAudio();              // 4. audio
  playSound("/device_on.wav");
  
}
void loop() {
  handleAudio();
  handleVibro();

  bool upNow = digitalRead(upbtn);
  bool downNow = digitalRead(downbtn);

  
  if(upPrev == HIGH && upNow == LOW){
      current_up();
      vibrate();
      playSound("/switch_opt.wav");
  }
  if(downPrev == HIGH && downNow == LOW){
      current_down();
      vibrate();
      playSound("/switch_opt.wav");
  }
  upPrev = upNow;
  downPrev = downNow;
  delay(10);
}

