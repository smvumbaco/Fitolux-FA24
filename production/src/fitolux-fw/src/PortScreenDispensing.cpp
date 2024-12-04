#include "PortScreenDispensing.h"



// Arc properties
#define CENTER_X 120
#define CENTER_Y 120
#define OUTER_RADIUS 120
#define ARC_WIDTH 8
#define NUM_ARCS 4



// Colors for arcs
uint16_t arcColors[NUM_ARCS] = {COLOR_DARK_BROWN, COLOR_MEDIUM_BROWN, COLOR_LIGHTER_BROWN, COLOR_LIGHTEST_BROWN};

// Delays for staggered rotation in milliseconds
float arcDelays[NUM_ARCS] = {0, 500, 1000, 1500};

// Helper function to draw arcs
void drawArc(TFT_eSPI &tft, int cx, int cy, float radius, float thickness, float startAngle, float sweepAngle, uint16_t color) {
    for (float r = radius - thickness; r <= radius; r++) {
        for (float angle = startAngle; angle < startAngle + sweepAngle; angle += 0.5) { // Finer resolution for smoother arcs
            int x = cx + cos(radians(angle)) * r;
            int y = cy + sin(radians(angle)) * r;
            tft.drawPixel(x, y, color);
        }
    }
}

// Function to clear an arc
void clearArc(TFT_eSPI &tft, int cx, int cy, float radius, float thickness, float startAngle, float sweepAngle) {
    drawArc(tft, cx, cy, radius, thickness, startAngle, sweepAngle, COLOR_LIGHT_BROWN);
}

// Function to display the dispensing screen
void displayDispensingScreen(TFT_eSPI &tft) {
    tft.setRotation(0);     // Set rotation (adjust as necessary)
    tft.fillScreen(COLOR_LIGHT_BROWN);

    // Draw static outer circle border
    tft.fillCircle(CENTER_X, CENTER_Y, OUTER_RADIUS, COLOR_DARK_BROWN);
    tft.fillCircle(CENTER_X, CENTER_Y, OUTER_RADIUS - ARC_WIDTH, COLOR_LIGHT_BROWN);

    // Add text elements
    tft.setFreeFont(&FreeSans9pt7b);
    tft.setTextColor(COLOR_BLACK, COLOR_LIGHT_BROWN);
    tft.setTextDatum(MC_DATUM);

    // Draw main text
    tft.drawString("DISPENSING...", CENTER_X, CENTER_Y - 10);

    // Draw battery percentage below the text
    String batteryText = "Battery: " + String(batteryLevel) + "%";
    tft.drawString(batteryText, CENTER_X, CENTER_Y + 20);
}

// Function to rotate arcs
void rotateArcs(TFT_eSPI &tft) {
    static float rotationOffset = 0;

    // Rotate arcs
    for (int i = 0; i < NUM_ARCS; i++) {
        float startAngle = rotationOffset + (i * 90); // Offset each arc by 90 degrees
        float sweepAngle = 45.0;                      // Arc sweep of 45 degrees
        drawArc(tft, CENTER_X, CENTER_Y, OUTER_RADIUS - (i * 20), ARC_WIDTH, startAngle, sweepAngle, arcColors[i]);

        // Delay for staggered animation
        delay(arcDelays[i]);

        // Clear the arc
        clearArc(tft, CENTER_X, CENTER_Y, OUTER_RADIUS - (i * 20), ARC_WIDTH, startAngle, sweepAngle);
    }

    // Increment rotation offset
    rotationOffset = fmod((rotationOffset + 5), 360); // Loop rotation at 360 degrees
}