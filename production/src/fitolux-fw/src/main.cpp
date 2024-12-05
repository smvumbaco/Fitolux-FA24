// ----------- PORTABLE CODE ----------- 

#include <Arduino.h>
#include <SPI.h>
#include <TFT_eSPI.h>
#include "AnoDial.h"
#include <RotaryEncoder.h>
#include "driver/i2c.h"
// include screen display headers
#include "PortScreenComplete.h"
#include "PortScreenDispensing.h"
#include "PortScreenHome.h"
#include "MotorController.h"
#include "LoadCell.h"


int weightSelectGrams;

TFT_eSPI tft = TFT_eSPI(TFT_WIDTH, TFT_HEIGHT);  // Create display object
AnoDial ano;
MotorController augerMotor;
LoadCell loadCell;


enum State {
    OFF,
    START,
    HOME_SCREEN,
    ADJUST_WEIGHT,
    DISPENSING,
    COMPLETE
};

static State currentState = START;


void setup() {
  // set up serial com
  Serial.begin(115000);
  Serial.println("Begin");
  

  // init TFT screen
  tft.init();             // Initialize the display
  tft.setRotation(0);     // Set rotation (adjust as necessary)
  
  digitalWrite(TFT_BL, HIGH);

  tft.fillScreen(TFT_BROWN); // Background color

  

  //displayPortCompleteScreen(tft);


  // calibration factor for weight sensor
  loadCell.setCalibration(3648000);
  
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
        displayHomeScreen(tft);
        Serial.println("CURRENT STATE: START");
        delay(3000);
        currentState = HOME_SCREEN;
        break;
      case HOME_SCREEN:
        displayHomeScreen(tft);
        delay(2000);
        displayPortCompleteScreen(tft);
        delay(2000);
        currentState = ADJUST_WEIGHT;
        Serial.println("CURRENT STATE: HOME");
        break;
      case ADJUST_WEIGHT:
        Serial.println("start (3 sec)");
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
        }
        // displayHomeScreen(tft);

        if (ano.getButtonPress(ano.CENTER))
        {
          currentState = DISPENSING;
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
