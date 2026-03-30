#include "display.h"
#include "config.h"
#include <LittleFS.h>
LGFX tft;  // jedyna prawdziwa definicja obiektu

LGFX::LGFX(void) {
  { // Magistrala
    auto cfg = _bus_instance.config();
    cfg.spi_host = SPI2_HOST;
    cfg.spi_mode = 0;
    cfg.freq_write = 40000000;
    cfg.pin_sclk = 18;
    cfg.pin_mosi = 12;
    cfg.pin_miso = 19;
    cfg.pin_dc   = 13;
    _bus_instance.config(cfg);
    _panel_instance.setBus(&_bus_instance);
  }
  { // Panel
    auto cfg = _panel_instance.config();
    cfg.pin_cs  = 15;
    cfg.pin_rst = 4;
    cfg.panel_width  = 320;
    cfg.panel_height = 480;
    cfg.rgb_order = true;
    _panel_instance.config(cfg);
  }
  setPanel(&_panel_instance);
}

void initDisplay() {
  tft.init();
  tft.setRotation(1);
  // Uruchom LittleFS
  LittleFS.begin();
  if (!LittleFS.begin()) {
    Serial.println("LittleFS mount failed!");
    return;
  }
  tft.fillScreen(COLOR_BG);
}