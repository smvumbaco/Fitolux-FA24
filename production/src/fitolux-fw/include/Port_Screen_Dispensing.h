#ifndef PORT_SCREEN_DISPENSING_H // Include guard to prevent multiple inclusions
#define PORT_SCREEN_DISPENSINF_H

#include <Arduino.h>
#include <TFT_eSPI.h> // Include TFT library

// Declare the TFT_eSPI object as external
extern TFT_eSPI tft;

// Define colors in RGB565
#define COLOR_LIGHT_BROWN 0xF1EE // Light Background Color
#define COLOR_DARK_BROWN 0x8273  // Dark Brown
#define COLOR_MEDIUM_BROWN 0xB19D // Medium Brown
#define COLOR_LIGHTER_BROWN 0xD3C2 // Light Brown
#define COLOR_LIGHTEST_BROWN 0xEADC // Lighter Brown
#define COLOR_BLACK 0x0000          // Black

// Arc properties
#define CENTER_X 120
#define CENTER_Y 120
#define OUTER_RADIUS 120
#define ARC_WIDTH 8
#define NUM_ARCS 4

// Function declarations for drawing arcs
void drawArc(int cx, int cy, int radius, int thickness, float startAngle, float sweepAngle, uint16_t color);
void clearArc(int cx, int cy, int radius, int thickness, float startAngle, float sweepAngle);

#endif // PORT_SCREEN_H