#include <Arduino.h>
#include <SPI.h>
#include <TFT_eSPI.h>
#include "AnoDial.h"
#include <RotaryEncoder.h>
#include "driver/i2c.h"


int weightSelectGrams;

TFT_eSPI tft = TFT_eSPI(TFT_WIDTH, TFT_HEIGHT);  // Create display object
AnoDial ano;


void setup() {
  // set up serial com
  Serial.begin(115000);
  Serial.println("THIS. IS. FITOLUX.");
  Serial.print("MOSI: ");
  Serial.println(TFT_MOSI);

  // init TFT screen
  tft.init();             // Initialize the display
  tft.setRotation(1);     // Set rotation (adjust as necessary)

  tft.fillScreen(TFT_BLUE);  // Clear screen to black
  
}

void loop() {

  ano.checkEncoder();

  if (ano.getButtonPress(ano.LEFT))
  {
    Serial.println("left button clicked");
    tft.fillScreen(TFT_GREEN);  // Clear screen to black
    tft.setTextColor(TFT_BLACK);  // White text on a black background
    tft.drawNumber(weightSelectGrams, 50, 50, 4);
  }
  if (ano.getButtonPress(ano.RIGHT))
  {
    Serial.println("right button clicked");
    tft.fillScreen(TFT_YELLOW);  // Clear screen to black
    tft.setTextColor(TFT_BLACK);  // White text on a black background
    tft.drawNumber(weightSelectGrams, 50, 50, 4);
  }
  if (ano.getButtonPress(ano.UP))
  {
    Serial.println("up button clicked");
    tft.fillScreen(TFT_PURPLE);  // Clear screen to black
    tft.setTextColor(TFT_BLACK);  // White text on a black background
    tft.drawNumber(weightSelectGrams, 50, 50, 4);
  }
  if (ano.getButtonPress(ano.DOWN))
  {
    Serial.println("down button clicked");
    tft.fillScreen(TFT_SILVER);  // Clear screen to black
    tft.setTextColor(TFT_BLACK);  // White text on a black background
    tft.drawNumber(weightSelectGrams, 50, 50, 4);
  }
  if (ano.getButtonPress(ano.CENTER))
  {
    Serial.println("center button clicked");
    tft.fillScreen(TFT_GOLD);  // Clear screen to black
    tft.setTextColor(TFT_BLACK);  // White text on a black background
    tft.drawNumber(weightSelectGrams, 50, 50, 4);
  }

}

// // put function definitions here:
// int myFunction(int x, int y) {
//   // return x + y;
// }