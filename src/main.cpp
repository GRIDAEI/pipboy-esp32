#include <Arduino.h>
#include <LovyanGFX.hpp>
#include "screens/screen.h"


#include "display.h"
#include "config.h"
#include <LittleFS.h>
#include "imgs/pip.h"
#include "modules/audio.h"
#include "modules/rtc.h"
#include "modules/rotSwitch.h"


#include "soc/soc.h"
#include "soc/rtc_cntl_reg.h"

const int FNTBTN1 = 38;
const int FNTBTN2 = 47;
const int FNTBTN3 = 14;

const int FNTLED1 = 48;
const int FNTLED2 = 11;
const int FNTLED3 = 1;


bool fntBtn1Prev = HIGH;
bool fntBtn2Prev = HIGH;
bool fntBtn3Prev = HIGH;


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

// int selectBtn = 41;
bool selectPrev = HIGH;
unsigned long vibroEnd = 0;
uint32_t COLOR_BG = F3_BG;
uint32_t COLOR_GREEN = F3_GREEN;
ESP32Encoder encoder;

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
void updateFrontLeds(int active_section) {
    digitalWrite(FNTLED1, active_section == 0 ? HIGH : LOW);
    digitalWrite(FNTLED2, active_section == 1 ? HIGH : LOW);
    digitalWrite(FNTLED3, active_section == 2 ? HIGH : LOW);
}
// Zmienna trzymająca aktualnie przetwarzaną pozycję enkodera
extern int32_t currentRenderEncoderCount; 

// Zwraca true, jeśli użytkownik ruszył enkoderem podczas rysowania

RotSwitch rSwitch(5);
void set_green(){
    COLOR_BG = F3_BG;
    COLOR_GREEN = F3_GREEN;
}
void set_nv(){
    COLOR_BG = NV_BG;
    COLOR_GREEN = NV_AMBER;
}
void setup() {
  delay(500); 
  
  Serial.begin(115200);
  delay(500);
  Serial.println("Startt!!!");
  
  set_green();
  init_all_stats();

  tft.init();               
  tft.setRotation(1);
  if (!LittleFS.begin()) {
    Serial.println("LittleFS mount failed!");
  } else {
     Serial.println("Wczytujemy obrazy");
    load_all_sprites(); 
  } 
  tft.fillScreen(COLOR_BG);
  initAudio();    
  
  auto waitWithAudio = [](unsigned long ms) {
      unsigned long start = millis();
      while (millis() - start < ms) {
          handleAudio();
          delay(1); 
      }
  };

  tft.setFont(&monofonto_rg13pt7b);
  tft.setTextColor(COLOR_GREEN, COLOR_BG);
  tft.setTextDatum(TL_DATUM);
  tft.setCursor(10, 10);
  
  tft.println("RobCo OS v8.1 Boot...");
  playSound("/deck_ui_bumper_end_02.wav");
  waitWithAudio(300);
  
  tft.println("Memory Check: 64K OK");
  waitWithAudio(300);
  
  for (int i = 0; i < 7; i++) {
      String line = "";
      line += "0x" + String(random(0x1000, 0xFFFF), HEX) + "  ";
      for (int j = 0; j < 24; j++) {
          line += (random(2) == 0) ? "0 " : "1 ";
      }
      playSound("/deck_ui_slider_up.wav");
      tft.println(line);
      waitWithAudio(120); 
  }
  
  waitWithAudio(400); 

  tft.fillScreen(COLOR_BG);
  
  tft.setFont(&monofonto_rg70pt7b);
  tft.setTextDatum(MC_DATUM);  
  tft.drawString("PIP-BOY", 240, 100);
  
  tft.setFont(&monofonto_rg13pt7b);
  tft.setTextSize(2.0); 
  tft.drawString("3000", 240, 180);
  
  tft.setTextSize(1.5);
  String welcome = "Witaj, ";
  welcome += objStatusScreen.getPlayerName();
  tft.drawString(welcome, 240, 240);
  playSound("/deck_ui_achievement_toast.wav");
  tft.setTextSize(1.0);
  tft.unloadFont();
  tft.setTextDatum(TL_DATUM); 
  
  unsigned long intro_start = millis(); 

    pinMode(FNTBTN1, INPUT_PULLUP);
    pinMode(FNTBTN2, INPUT_PULLUP);
    pinMode(FNTBTN3, INPUT_PULLUP);

    pinMode(FNTLED1, OUTPUT);
    pinMode(FNTLED2, OUTPUT);
    pinMode(FNTLED3, OUTPUT);
    updateFrontLeds(section_id);
  pinMode(upbtn, INPUT_PULLUP);
  pinMode(downbtn, INPUT_PULLUP);
  pinMode(vibr_pin, OUTPUT);
  digitalWrite(vibr_pin, LOW);


  ESP32Encoder::useInternalWeakPullResistors = puType::up;
  encoder.attachHalfQuad(16, 17);
  encoder.setCount(0);
  


  while (millis() - intro_start < 3000) {
      handleAudio();
      delay(10);
  }
  tft.fillScreen(COLOR_BG); // Zamazujemy napis PIP-BOY nowym tłem
  current_screen = &Status_Screen;
  Serial.println("Rysuje ekran");
  topbot();
  if (current_screen->drawFunction) {
      current_screen->drawFunction();
  } else {
      Serial.println("BLAD: drawFunction jest PUSTE! Brakuje przypisania.");
  }
            // 4. audio
  Serial.println("Done!");

}

void handleFrontButtons() {
    bool btn1Now = digitalRead(FNTBTN1);
    bool btn2Now = digitalRead(FNTBTN2);
    bool btn3Now = digitalRead(FNTBTN3);

    // Reakcja na kliknięcie przycisku 1 (Przejście do STATS)
    if (fntBtn1Prev == HIGH && btn1Now == LOW) {
        if (section_id != 0) { // Zmieniaj tylko jeśli to nowa sekcja
            change_section(0);
            updateFrontLeds(0);
            playSound("/switch_opt.wav");
        }
    }
    
    // Reakcja na kliknięcie przycisku 2 (Przejście do ITEMS)
    if (fntBtn2Prev == HIGH && btn2Now == LOW) {
        if (section_id != 1) {
            change_section(1);
            updateFrontLeds(1);
            playSound("/switch_opt.wav");
        }
    }

    // Reakcja na kliknięcie przycisku 3 (Przejście do DATA)
    if (fntBtn3Prev == HIGH && btn3Now == LOW) {
        if (section_id != 2) {
            change_section(2);
            updateFrontLeds(2);
            playSound("/switch_opt.wav");
        }
    }

    // Zapisz stan do kolejnej pętli
    fntBtn1Prev = btn1Now;
    fntBtn2Prev = btn2Now;
    fntBtn3Prev = btn3Now;
}

unsigned long last_input_time = 0;
bool is_screen_dimmed = false;
const unsigned long DIM_TIMEOUT = 15000; // 15 sekund bezczynności -> tryb oszczędzania

void loop() {
    static unsigned long lastPrint = 0;
if (millis() - lastPrint > 500) {
    lastPrint = millis();
}
  handleAudio();
  bool upNow = digitalRead(upbtn);
  bool downNow = digitalRead(downbtn);
  bool selectNow = HIGH;

    if (Serial.available() > 0) {
        char c = Serial.read();
        if      (c == 'w' || c == 'W') upNow = LOW;
        else if (c == 'd' || c == 'D') {set_screen(screen_id + 1);playSound("/deck_ui_side_menu_fly_in.wav");}
        else if (c == 'a' || c == 'A') {set_screen(screen_id - 1);playSound("/deck_ui_side_menu_fly_in.wav");}
        else if (c == 's' || c == 'S') downNow = LOW;
        else if (c == 'v' || c == 'V') selectNow = LOW;
        else if (c == 'l' || c == 'L'){ change_section(section_id + 1);playSound("/deck_ui_tab_transition_01.wav");}
        else if (c == 'k' || c == 'K'){ change_section(section_id - 1);playSound("/deck_ui_tab_transition_01.wav");}
    }
    int newPos = rSwitch.update();
    if (newPos != -1) {
        playSound("/deck_ui_side_menu_fly_in.wav");
        set_screen(newPos);
    }
    
  static int32_t lastEncoderCount = 0;               
  int32_t currentCount = (int32_t)encoder.getCount(); 

  if (upPrev == HIGH && downPrev == HIGH) {
      if (currentCount > lastEncoderCount) {
          downNow = LOW;       
          lastEncoderCount++;  
      } 
      else if (currentCount < lastEncoderCount) {
          upNow = LOW;         
          lastEncoderCount--;  
      }
  }

    currentRenderEncoderCount = lastEncoderCount;

    bool input_detected = false;
    if (upPrev == HIGH && upNow == LOW) input_detected = true;
    if (downPrev == HIGH && downNow == LOW) input_detected = true;
    if (selectPrev == HIGH && selectNow == LOW) input_detected = true;
    if (newPos != -1) input_detected = true;

    if (input_detected) {
        last_input_time = millis();
        if (is_screen_dimmed) {
            is_screen_dimmed = false;
            setCpuFrequencyMhz(240); 
            
            upNow = HIGH;
            downNow = HIGH;
            selectNow = HIGH;
        }
    }

    if (!is_screen_dimmed && (millis() - last_input_time > DIM_TIMEOUT)) {
        is_screen_dimmed = true;
        setCpuFrequencyMhz(80); 
    }
  if(upPrev == HIGH && upNow == LOW){
      current_up();
      playSound("/deck_ui_navigation.wav");
  }
  if(downPrev == HIGH && downNow == LOW){
      current_down();
      playSound("/deck_ui_navigation.wav");
  }
  if(selectPrev == HIGH && selectNow == LOW){
      press_current_select();
      playSound("/switch_opt.wav");
  }

  if (section_id == 0 && screen_id == 0) {
      objStatusScreen.update();
  }
  
  static int last_saved_minute = -1;
  time_t now;
  struct tm timeinfo;
  time(&now);
  localtime_r(&now, &timeinfo);
  
  if (timeinfo.tm_year > 100 && timeinfo.tm_min != last_saved_minute) {
      last_saved_minute = timeinfo.tm_min;
      
      Preferences prefs;
      prefs.begin("zegar", false);
      prefs.putULong("zapisany_czas", now);
      prefs.end();
  }
  
  upPrev = upNow;
  downPrev = downNow;
  selectPrev = selectNow;
  delay(5);
}
