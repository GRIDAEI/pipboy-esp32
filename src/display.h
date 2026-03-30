#pragma once
#include <LovyanGFX.hpp>
#include <config.h>
class LGFX : public lgfx::LGFX_Device {
  lgfx::Panel_ST7796 _panel_instance;
  lgfx::Bus_SPI      _bus_instance;
public:
  LGFX(void);
};

extern LGFX tft;  // <- przesuwamy TUTAJ, bo tu jest definicja klasy

void initDisplay();