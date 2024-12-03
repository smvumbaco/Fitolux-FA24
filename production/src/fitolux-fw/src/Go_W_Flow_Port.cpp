#include <Arduino.h>
#include <RotaryEncoder.h>
#include "port_screen.h"

// Define states for the FSM
enum State {
    OFF,
    START,
    HOME_SCREEN,
    ADJUST_WEIGHT,
    DISPENSING,
    COMPLETE
};

// Global Variables
int selectedWeight = 1;
bool centerButtonPressed = false;

// Rotary Encoder Setup
#define DIAL_PIN_A 2
#define DIAL_PIN_B 3
#define DIAL_BUTTON_PIN 4
#define POWER_SWITCH_PIN 5
RotaryEncoder dial(DIAL_PIN_A, DIAL_PIN_B);

void setup() {
    pinMode(DIAL_BUTTON_PIN, INPUT_PULLUP);
    pinMode(POWER_SWITCH_PIN, INPUT_PULLUP);
    dial.begin();
    dial.setup([] { dial.tick(); });
    tft.init();
    tft.fillScreen(COLOR_BROWN);
}

void loop() {
    static State currentState = OFF;

    if (digitalRead(POWER_SWITCH_PIN) == HIGH) {
        currentState = OFF;
        return;
    } else if (currentState == OFF) {
        currentState = START;
    }

    switch (currentState) {
        case START:
            displayStartScreen();
            currentState = HOME_SCREEN;
            break;

        case HOME_SCREEN:
            drawHomeScreen();
            currentState = ADJUST_WEIGHT;
            break;

        case ADJUST_WEIGHT:
            dial.tick();
            int newPosition = dial.getPosition();
            if (newPosition > 0 && selectedWeight < 100) {
                selectedWeight++;
                dial.setPosition(0);
                updateWeightDisplay(selectedWeight);
            } else if (newPosition < 0 && selectedWeight > 1) {
                selectedWeight--;
                dial.setPosition(0);
                updateWeightDisplay(selectedWeight);
            }

            if (digitalRead(DIAL_BUTTON_PIN) == LOW) {
                while (digitalRead(DIAL_BUTTON_PIN) == LOW);
                currentState = DISPENSING;
            }
            break;

        case DISPENSING:
            drawDispensingScreen();
            TurnMotorOn();
            SetMotorSpeed(50);
            delay(5000);
            TurnMotorOff();
            currentState = COMPLETE;
            break;

        case COMPLETE:
            drawCompleteScreen();
            if (digitalRead(DIAL_BUTTON_PIN) == LOW) {
                while (digitalRead(DIAL_BUTTON_PIN) == LOW);
                currentState = START;
            }
            break;

        case OFF:
            break;
    }
}

// Placeholder motor functions
void TurnMotorOn() {}
void TurnMotorOff() {}
void SetMotorSpeed(int speed) {}