#ifndef _PORT_SCREEN_COMPLETE_H_
#define _PORT_SCREEN_COMPLETE_H_
#include <Arduino.h>
#include <SPI.h>
#include <TFT_eSPI.h>
#include <RotaryEncoder.h>
#include "driver/i2c.h"
#include "colors.h"
#include "PortScreenHome.h"

void drawCircle(TFT_eSPI &tft, int x, int y, int radius, uint16_t color);
void displayPortCompleteScreen(TFT_eSPI &tft);
#endif