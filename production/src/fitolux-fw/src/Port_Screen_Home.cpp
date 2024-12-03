#include <Arduino.h>
#include <SPI.h>
#include <TFT_eSPI.h>
#include <RotaryEncoder.h>
#include "driver/i2c.h"


TFT_eSPI tft = TFT_eSPI(240, 240);  // Adjusted dimensions for 1.28-inch module

// Define colors in RGB565 format
#define COLOR_LIGHT_BROWN 0xF7DE // Light Brown in RGB565
#define COLOR_BROWN 0x8A22      // Brown in RGB565
#define COLOR_BLACK 0x0000      // Black color in RGB565

// Global variable for dynamic value
int currentValue = 0;
int lastValue = -1; // Tracks the last value to avoid unnecessary redraws

void setup() {
    // Set up serial communication
    Serial.begin(115200);
    Serial.println("THIS. IS. FITOLUX.");
    Serial.print("MOSI: ");
    Serial.println(TFT_MOSI);

    // Initialize the TFT screen
    tft.init();
    tft.setRotation(1); // Landscape mode
    tft.fillScreen(COLOR_LIGHT_BROWN); // Background color

    // Draw the Brown Circular Border
    int outerRadius = 120;  // Outer radius of the circle
    int innerRadius = 110;  // Reduced inner radius for a thicker border
    tft.fillCircle(120, 120, outerRadius, COLOR_BROWN); // Draw the outer circle
    tft.fillCircle(120, 120, innerRadius, COLOR_LIGHT_BROWN); // Cut out the inner circle

    // Header Section
    tft.setFreeFont(&FreeSansBold18pt7b); // Smaller font for "Fitolux."
    tft.setTextColor(COLOR_BLACK, COLOR_LIGHT_BROWN);
    tft.drawString("Fitolux.", (240 - tft.textWidth("Fitolux.")) / 2, 30);

    tft.setFreeFont(&FreeSans9pt7b); // Smaller font for "Methods"
    tft.drawString("Methods", (240 - tft.textWidth("Methods")) / 2, 70);

    // Main Section - "SELECT AMOUNT"
    tft.setFreeFont(&FreeSans12pt7b); // Resize to match Figma
    tft.drawString("SELECT AMOUNT", (240 - tft.textWidth("SELECT AMOUNT")) / 2, 110);

    // Input Box
    int boxWidth = 160; // Adjusted width
    int boxHeight = 40; // Adjusted height
    int boxX = (240 - boxWidth) / 2;
    int boxY = 160;
    tft.fillRoundRect(boxX, boxY, boxWidth, boxHeight, 20, COLOR_BROWN); // Fully rounded rectangle

    // Unit Text ("G")
    tft.setTextColor(COLOR_BLACK, COLOR_BROWN);
    tft.setFreeFont(&FreeSans12pt7b);
    tft.drawString("G", boxX + boxWidth - 30, boxY + (boxHeight - 16) / 2);
}

void updateValue(int value) {
    int boxWidth = 160;
    int boxHeight = 40;
    int boxX = (240 - boxWidth) / 2;
    int boxY = 160;

    // Clear the previous value
    tft.fillRect(boxX + 20, boxY + (boxHeight - 16) / 2, 120, 20, COLOR_BROWN); // Clear value area

    // Draw the new value
    tft.setTextColor(COLOR_BLACK, COLOR_BROWN);
    tft.setFreeFont(&FreeSans12pt7b);
    tft.drawString(String(value), boxX + (boxWidth / 2) - (tft.textWidth(String(value)) / 2), boxY + (boxHeight - 16) / 2);
}

void loop() {
    // Simulate value changes
    currentValue = (currentValue + 1) % 100; // Increment value and loop back to 0 after 99

    if (currentValue != lastValue) {
        updateValue(currentValue); // Update only the value area
        lastValue = currentValue;  // Track the last value to avoid redundant updates
    }

    delay(100); // Small delay for smooth updates
}