#include "Port_Screen_Complete.h"

// Initialize the display
// TFT_eSPI tft = TFT_eSPI(240, 240);


void drawCircle(TFT_eSPI tft, int x, int y, int radius, uint16_t color) {
    tft.fillCircle(x, y, radius, color);
}

void displayPortCompleteScreen(TFT_eSPI tft) {
    // Initialize the LCD
    tft.init();
    tft.setRotation(1); // Set orientation
    tft.fillScreen(COLOR_LIGHT_BROWN); // Set background color

    // Draw the outer circle
    drawCircle(tft, 120, 120, 120, COLOR_DARK_BROWN);

    // Draw the middle circle
    drawCircle(tft, 120, 120, 102, COLOR_MEDIUM_BROWN);

    // Draw the inner circle
    drawCircle(tft, 120, 120, 84, COLOR_LIGHTER_BROWN);

    // Display the "COMPLETE" text in the center
    tft.setFreeFont(&FreeSansBold18pt7b); // Use a bold font
    tft.setTextColor(COLOR_BLACK, COLOR_LIGHTER_BROWN); // Black text on light background
    tft.setTextDatum(MC_DATUM); // Middle center alignment
    tft.drawString("COMPLETE", 120, 120); // Centered text at (120, 120)
}
