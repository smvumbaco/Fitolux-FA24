// #ifndef _SCREENS_H
// #define _SCREENS_H

// #include <TFT_eSPI.h>
// #include <Arduino.h>
// #include <SPI.h>
// // Screen dimensions
// #define SCREEN_WIDTH 320
// #define SCREEN_HEIGHT 240

// // Define colors in RGB565 format
// #define COLOR_LIGHT_BROWN 0xF7DE // Light Brown in RGB565
// #define COLOR_BROWN 0x8A22      // Brown in RGB565
// #define COLOR_BLACK 0x0000      // Black color in RGB565

// TFT_eSPI tft = TFT_eSPI();


// void displayStartScreen();
// Serial.begin(115200);
//   tft.init();
//   tft.setRotation(1); // Landscape mode

//   // Draw the Thinner Brown Border
//   int borderWidth = 10; // Border thickness
//   tft.fillScreen(COLOR_BROWN); // Fill entire screen with brown
//   tft.fillRect(borderWidth, borderWidth, SCREEN_WIDTH - 2 * borderWidth, SCREEN_HEIGHT - 2 * borderWidth, COLOR_LIGHT_BROWN);

//   // Header Section
//   tft.setFreeFont(&FreeSansBold24pt7b);
//   tft.setTextColor(COLOR_BLACK, COLOR_LIGHT_BROWN);
//   tft.drawString("Fitolux.", (SCREEN_WIDTH - tft.textWidth("Fitolux.")) / 2, 20);

//   tft.setFreeFont(&FreeSans12pt7b);
//   tft.drawString("Methods", (SCREEN_WIDTH - tft.textWidth("Methods")) / 2, 60);

//   // Main Section - "SELECT AMOUNT"
//   tft.setFreeFont(&FreeSans12pt7b); // Resize to match Figma
//   tft.drawString("SELECT AMOUNT", (SCREEN_WIDTH - tft.textWidth("SELECT AMOUNT")) / 2, 110);

//   // Input Box
//   int boxWidth = 200; // Adjusted width to match Figma
//   int boxHeight = 50; // Adjusted height
//   int boxX = (SCREEN_WIDTH - boxWidth) / 2;
//   int boxY = 160;
//   tft.fillRoundRect(boxX, boxY, boxWidth, boxHeight, 10, COLOR_BROWN);

//   // Jar Icon Placeholder (You can replace this with an actual bitmap or custom drawing code)
//   int jarWidth = 24, jarHeight = 24; // Adjusted size
//   int jarX = boxX + 10;
//   int jarY = boxY + (boxHeight - jarHeight) / 2;
//   tft.fillRect(jarX, jarY, jarWidth, jarHeight, COLOR_BLACK); // Simplified jar drawing (black placeholder)

//   // Input Text
//   tft.setTextColor(COLOR_BLACK, COLOR_BROWN);
//   tft.drawString("Value", boxX + (boxWidth / 2) - (tft.textWidth("Value") / 2), boxY + (boxHeight - 16) / 2);

//   // Unit Text ("G")
//   tft.setTextColor(COLOR_BLACK, COLOR_BROWN);
//   tft.drawString("G", boxX + boxWidth - 30, boxY + (boxHeight - 16) / 2);
// }

// void loop() {
//   // Add interactivity or animations
// }




// #endif