// ----------- PORTABLE CODE ----------- 

#include <Arduino.h>
#include <SPI.h>
#include <TFT_eSPI.h>
#include "AnoDial.h"
#include <RotaryEncoder.h>
#include "driver/i2c.h"
// #include "max17048.h"
// include screen display headers
#include "PortScreenComplete.h"
#include "PortScreenDispensing.h"
#include "PortScreenHome.h"
#include "MotorController.h"
#include "LoadCell.h"
#include "Adafruit_MAX1704X.h"


int weightSelectGrams;

TFT_eSPI tft = TFT_eSPI(TFT_WIDTH, TFT_HEIGHT);  // Create display object
AnoDial ano;
MotorController augerMotor;
LoadCell loadCell;
Adafruit_MAX17048 fuelGuage;


enum State {
    OFF,
    START,
    HOME_SCREEN,
    ADJUST_WEIGHT,
    DISPENSING,
    COMPLETE
};

static State currentState = START;

int batteryLevel;

void setup() {
  // set up serial com
  Serial.begin(115200);
  Serial.println("Begin");
  

  // init TFT screen
  // tft.init();             // Initialize the display
  // tft.setRotation(2);     // Set rotation (adjust as necessary)
  
  // digitalWrite(TFT_BL, HIGH);

  // tft.fillScreen(TFT_BROWN); // Background color

  // displayHomeScreen(tft);

  // calibration factor for weight sensor
  loadCell.setCalibration(3648000);


  // Initialize I2C communication
  if (!fuelGuage.begin()) {
    Serial.println("Could not find MAX17048 chip, check wiring!");
    while (1);
  }

  Serial.println("MAX17048 found!");
  
}

void loop() {

  // if power switch is off
  // if (digitalRead(POWER_SWITCH_PIN) == HIGH) {
  //     currentState = OFF;
  //     return;
  // } else if (currentState == OFF) {
  //     currentState = START;
  // }
  switch (currentState) {
      case START:
        // displayPortHomeScreen(tft);
        Serial.println("CURRENT STATE: START");
        delay(1000);
        currentState = HOME_SCREEN;
        Serial.println("Current State: HOME");
        batteryLevel = fuelGuage.cellPercent();
        // displayPortHomeScreen(tft);
        // tft.drawString("HS", 45, 80, 2);
        break;
      case HOME_SCREEN:
        // displayHomeScreen(tft);
        batteryLevel = fuelGuage.cellPercent();
        // Serial.println("SOC: ");
        // Serial.println(batteryLevel);
        delay(50);
        if (ano.getButtonPress(ano.CENTER))
        {
          currentState = ADJUST_WEIGHT;
          // tft.drawString("AW", 45, 80, 2);
        }
        Serial.println("CURRENT STATE: ADJUST WEIGHT");
        // break;
      case ADJUST_WEIGHT:
        // Serial.println("ADJUST WEIGHT");
        ano.checkEncoder();
        // // int newPosition = dial.getPosition();
        // if (newPosition > 0 && selectedWeight < 100) {
        //     selectedWeight++;
        //     dial.setPosition(0);
        //     updateWeightDisplay(selectedWeight);
        // } else if (newPosition < 0 && selectedWeight > 1) {
        //     selectedWeight--;
        //     dial.setPosition(0);
        //     updateWeightDisplay(selectedWeight);
        // }
        // if (digitalRead(DIAL_BUTTON_PIN) == LOW) {
        //     while (digitalRead(DIAL_BUTTON_PIN) == LOW);
        //     currentState = DISPENSING;
        // }
        if (ano.last_rotary != ano.curr_rotary)
        {
          weightSelectGrams = ano.curr_rotary;
          updateValue(tft, weightSelectGrams, batteryLevel);
          // Serial.print("Weight Select: ");
          // Serial.println(weightSelectGrams);
          
          tft.drawNumber(weightSelectGrams, 45, 100, 2);
        }
        // displayHomeScreen(tft);
        if (ano.getButtonPress(ano.RIGHT))
        {
          Serial.println("RIGHT");
          weightSelectGrams += 1;
          tft.drawNumber(weightSelectGrams, 45, 100, 2);
        }
        if (ano.getButtonPress(ano.LEFT))
        {
          Serial.println("LEFT");
        }
        if (ano.getButtonPress(ano.UP))
        {
          Serial.println("UP");
          tft.drawNumber(weightSelectGrams, 45, 100, 2);
        }
        if (ano.getButtonPress(ano.DOWN))
        {
          Serial.println("DOWN");
        }
        if (ano.getButtonPress(ano.CENTER))
        {
          currentState = DISPENSING;
          tft.drawString("D", 45, 80, 2);
        }
        break;
      case DISPENSING:
        displayDispensingScreen(tft);

        // if last state wasn't dispensing
          // set motor pins low / disable motors
          // tare loadCell (loadCell.begin())

        // if ()
        // loadCell.begin();

        // if motors off, turn vibration and stepper motors on
        if (augerMotor.getState() == 0)
        {
          augerMotor.setDirection(0);
          augerMotor.setSpeed(50);
          augerMotor.enable();
        }
        // if weightFromLoadCell >= DesiredWeight (weightSelectGrams), turn motors off (STOP DISPENSING)
        if (loadCell.readWeight() >= weightSelectGrams)
        {
          augerMotor.disable();
        }
        currentState = COMPLETE;
        // if time >= TIME_LIMIT seconds, stop
        currentState = COMPLETE;

        // TurnMotorOn();
        // SetMotorSpeed(50);
        // delay(5000);
        // TurnMotorOff();

        delay(3000);

        break;
      case COMPLETE:
        displayPortCompleteScreen(tft);
        
        if(ano.getButtonPress(ano.CENTER))
        {
          currentState = START;
        }

      case OFF:
        break;
  }


}

// // put function definitions here:
// int myFunction(int x, int y) {
//   // return x + y;
// }






// ----------- COUNTERTOP CODE ----------- 




























// #include <Arduino.h>
// #include <SPI.h>
// #include <TFT_eSPI.h>
// #include "AnoDial.h"
// #include <RotaryEncoder.h>
// #include "driver/i2c.h"
// int weightSelectGrams;
// TFT_eSPI tft = TFT_eSPI(TFT_WIDTH, TFT_HEIGHT);  // Create display object
// AnoDial ano;
// void setup() {
//   // set up serial com
//   Serial.begin(115000);
//   Serial.println("THIS. IS. FITOLUX.");
//   Serial.print("MOSI: ");
//   Serial.println(TFT_MOSI);
//   // // init TFT screen
//   // tft.init();             // Initialize the display
//   // tft.setRotation(1);     // Set rotation (adjust as necessary)
//   // tft.fillScreen(TFT_BLUE);  // Clear screen to black
  
// }
// void loop() {
//   ano.checkEncoder();
//   if (ano.getButtonPress(ano.LEFT))
//   {
//     Serial.println("left button clicked");
//     // tft.fillScreen(TFT_GREEN);  // Clear screen to black
//     // tft.setTextColor(TFT_BLACK);  // White text on a black background
//     // tft.drawNumber(weightSelectGrams, 50, 50, 4);
//   }
//   if (ano.getButtonPress(ano.RIGHT))
//   {
//     Serial.println("right button clicked");
//     // tft.fillScreen(TFT_YELLOW);  // Clear screen to black
//     // tft.setTextColor(TFT_BLACK);  // White text on a black background
//     // tft.drawNumber(weightSelectGrams, 50, 50, 4);
//   }
//   if (ano.getButtonPress(ano.UP))
//   {
//     Serial.println("up button clicked");
//     // tft.fillScreen(TFT_PURPLE);  // Clear screen to black
//     // tft.setTextColor(TFT_BLACK);  // White text on a black background
//     // tft.drawNumber(weightSelectGrams, 50, 50, 4);
//   }
//   if (ano.getButtonPress(ano.DOWN))
//   {
//     Serial.println("down button clicked");
//     // tft.fillScreen(TFT_SILVER);  // Clear screen to black
//     // tft.setTextColor(TFT_BLACK);  // White text on a black background
//     // tft.drawNumber(weightSelectGrams, 50, 50, 4);
//   }
//   if (ano.getButtonPress(ano.CENTER))
//   {
//     Serial.println("center button clicked");
//     // tft.fillScreen(TFT_GOLD);  // Clear screen to black
//     // tft.setTextColor(TFT_BLACK);  // White text on a black background
//     // tft.drawNumber(weightSelectGrams, 50, 50, 4);
//   }
// }