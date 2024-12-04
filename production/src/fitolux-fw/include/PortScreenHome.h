
#pragma once

#ifndef _PORT_SCREEN_H
#define _PORT_SCREEN_H
#include <TFT_eSPI.h>
#include <Arduino.h>


// Declare external TFT object to ensure no redefinition
extern TFT_eSPI tft;
extern int batteryLevel;
// Function declarations
// void displayStartScreen();
void displayHomeScreen(TFT_eSPI tft);
void updateValue(TFT_eSPI tft, int value);
void updateWeightDisplay(int weight);
// void drawDispensingScreen();
// void drawCompleteScreen();
#endif