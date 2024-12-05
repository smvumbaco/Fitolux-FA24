#ifndef PORT_SCREEN_DISPENSING_H // Include guard to prevent multiple inclusions
#define PORT_SCREEN_DISPENSINF_H
#include <Arduino.h>
#include <TFT_eSPI.h> // Include TFT library
#include "colors.h"
#include "driver/i2c.h"   // For trigonometric calculations
#include <math.h>  
#include <RotaryEncoder.h>
#include "PortScreenHome.h"
// Declare the TFT_eSPI object as external


// Arc properties
#define CENTER_X 120
#define CENTER_Y 120
#define OUTER_RADIUS 120
#define ARC_WIDTH 8
#define NUM_ARCS 4
#define INNER_RADIUS 80 // Radius for the inner circle
#define OUTER_RADIUS 120
// Function declarations for drawing arcs
void drawArc(TFT_eSPI &tft, int cx, int cy, int radius, int thickness, float startAngle, float sweepAngle, uint16_t color);
void clearArc(TFT_eSPI &tft, int cx, int cy, int radius, int thickness, float startAngle, float sweepAngle);
void displayDispensingScreen(TFT_eSPI &tft);
void rotateArcs(TFT_eSPI &tft);
#endif // PORT_SCREEN_H