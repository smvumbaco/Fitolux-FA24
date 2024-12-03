#include "PortScreenDispensing.h"



// Arc properties
#define CENTER_X 120
#define CENTER_Y 120
#define OUTER_RADIUS 120
#define ARC_WIDTH 8
#define NUM_ARCS 4

// Colors for arcs
uint16_t arcColors[NUM_ARCS] = {COLOR_DARK_BROWN, COLOR_MEDIUM_BROWN, COLOR_LIGHTER_BROWN, COLOR_LIGHTEST_BROWN};

float arcDelays[NUM_ARCS] = {0, 0.5, 1.0, 1.5}; // Delays for staggered rotation in seconds
// Helper function to draw arcs
void drawArc(TFT_eSPI tft, int cx, int cy, int radius, int thickness, float startAngle, float sweepAngle, uint16_t color) {
    for (int r = radius - thickness; r <= radius; r++) {
        for (float angle = startAngle; angle < startAngle + sweepAngle; angle += 2) { // Increment angle for performance
            int x = cx + cos(radians(angle)) * r;
            int y = cy + sin(radians(angle)) * r;
            tft.drawPixel(x, y, color);
        }
    }
}
// Function to clear an arc
void clearArc(TFT_eSPI tft, int cx, int cy, int radius, int thickness, float startAngle, float sweepAngle) {
    drawArc(tft, cx, cy, radius, thickness, startAngle, sweepAngle, COLOR_LIGHT_BROWN);
}
void displayDispensingScreen(TFT_eSPI tft) {
    // Initialize the TFT display
    tft.init();
    tft.setRotation(1); // Landscape orientation
    tft.fillScreen(COLOR_LIGHT_BROWN); // Set background color
    // Draw static outer circle border
    tft.fillCircle(CENTER_X, CENTER_Y, OUTER_RADIUS, COLOR_DARK_BROWN);
    tft.fillCircle(CENTER_X, CENTER_Y, OUTER_RADIUS - ARC_WIDTH, COLOR_LIGHT_BROWN);
    // Add text elements
    tft.setFreeFont(&FreeSansBold18pt7b); // Smaller font for "Fitolux."
    tft.setTextColor(COLOR_BLACK, COLOR_LIGHT_BROWN);
    tft.drawString("Fitolux.", (240 - tft.textWidth("Fitolux.")) / 2, 30);
    tft.setFreeFont(&FreeSans9pt7b); // Smaller font for "Methods"
    tft.drawString("Methods", (240 - tft.textWidth("Methods")) / 2, 70);
    tft.setFreeFont(&FreeSans12pt7b); // Resize to match Figma
    tft.drawString("SELECT AMOUNT", (240 - tft.textWidth("SELECT AMOUNT")) / 2, 110);
}

void rotateArcs(TFT_eSPI tft) {
    static float rotationOffset = 0;
    // Rotate arcs
    for (int i = 0; i < NUM_ARCS; i++) {
        float startAngle = rotationOffset + (i * 90); // Offset each arc by 90 degrees
        float sweepAngle = 45.0;                      // Arc sweep of 45 degrees
        drawArc(tft, CENTER_X, CENTER_Y, OUTER_RADIUS - (i * 20), ARC_WIDTH, startAngle, sweepAngle, arcColors[i]);
        delay(arcDelays[i] * 1000); // Delay for staggered animation
        clearArc(tft, CENTER_X, CENTER_Y, OUTER_RADIUS - (i * 20), ARC_WIDTH, startAngle, sweepAngle); // Clear the arc
    }
    // Increment rotation offset
    rotationOffset = fmod((rotationOffset + 5), 360); // Ensure rotation loops back at 360
}