#ifndef _PORT_SCREEN_COMPLETE_H_
#define _PORT_SCREEN_COMPLETE_H_

#include <Arduino.h>
#include <SPI.h>
#include <TFT_eSPI.h>
#include <RotaryEncoder.h>
#include "driver/i2c.h"
#include "colors.h"


void drawCircle(TFT_eSPI tft);

void displayPortCompleteScreen(TFT_eSPI tft);


#endif