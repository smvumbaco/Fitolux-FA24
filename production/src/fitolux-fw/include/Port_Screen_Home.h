#ifndef _PORT_SCREEN_H
#define _PORT_SCREEN_H

#include <TFT_eSPI.h>
#include <Arduino.h>

// Define colors in RGB565 format
#define COLOR_LIGHT_BROWN 0xF7DE // Light Brown in RGB565
#define COLOR_BROWN 0x8A22      // Brown in RGB565
#define COLOR_BLACK 0x0000      // Black color in RGB565
#define COLOR_WHITE 0xFFFF      // White color in RGB565

// Declare external TFT object to ensure no redefinition
extern TFT_eSPI tft;

// Function declarations
void displayStartScreen();
void drawHomeScreen();
void updateWeightDisplay(int weight);
void drawDispensingScreen();
void drawCompleteScreen();

#endif