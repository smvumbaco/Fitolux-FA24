#include "PortScreenComplete.h"

// Initialize the display
// TFT_eSPI tft = TFT_eSPI(240, 240);
void drawCircle(TFT_eSPI &tft, int x, int y, int radius, uint16_t color) {
    tft.fillCircle(x, y, radius, color);
}

void displayPortCompleteScreen(TFT_eSPI &tft) {
    // Initialize the LCD
    tft.init();
    tft.setRotation(180); // Set rotation (adjust as necessary)

    // Set the background color
    tft.fillScreen(COLOR_LIGHT_BROWN);

    // Draw concentric circles with adjusted outer line thickness
    drawCircle(tft, 120, 120, 110, COLOR_DARK_BROWN);     // Outer circle (thinner by reducing radius)
    drawCircle(tft, 120, 120, 100, COLOR_MEDIUM_BROWN);   // Middle circle
    drawCircle(tft, 120, 120, 80, COLOR_LIGHT_BROWN);     // Inner circle

    // Display the "COMPLETE" text with a smaller font
    tft.setFreeFont(&FreeSans9pt7b);                    // Use smaller font for "COMPLETE" text
    tft.setTextColor(COLOR_BLACK, COLOR_LIGHT_BROWN);   // Black text on light background
    tft.setTextDatum(MC_DATUM);                        // Middle-center alignment
    tft.drawString("COMPLETE", 120, 115);              // Centered text with slight adjustment

    // Display battery percentage below the "COMPLETE" text
    tft.setFreeFont(&FreeSans9pt7b);                   // Keep battery text small
    String batteryText = "Battery: " + String(batteryLevel) + "%";
    tft.drawString(batteryText, 120, 140);             // Adjusted y-position for spacing
}