#pragma once
#include <LovyanGFX.hpp>
#include <config.h>
#include "../data/monofonto_rg7pt7b.h"
#include "../data/monofonto_rg12pt7b.h"
#include "../data/monofonto_rg13pt7b.h"
#include "../data/monofonto_rg70pt7b.h"
class LGFX : public lgfx::LGFX_Device {
  lgfx::Panel_ST7796 _panel_instance;
  lgfx::Bus_SPI      _bus_instance;
  lgfx::Light_PWM    _light_instance;
public:
  LGFX(void);
};

extern LGFX tft; 

void initDisplay();