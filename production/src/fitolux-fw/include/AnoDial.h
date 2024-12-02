#ifndef _ANODIAL_H_
#define _ANODIAL_H_

#include <RotaryEncoder.h>
// #include <Arduino.h>
 
#define PIN_ENCODER_A 33    // ENCA
#define PIN_ENCODER_B 25    // ENCB
#define COM_A 12            // COMA                 
#define BUTTON_IN 26        // SW1
#define BUTTON_DOWN 35      // SW2
#define BUTTON_RIGHT 36     // SW3
#define BUTTON_UP 39        // SW4
#define BUTTON_LEFT 34      // SW5
#define COM_B 13            // COMB

// rotary weight limits that user can specify
#define MAX_WEIGHT 50
#define MIN_WEIGHT 0

class AnoDial
{
private:
    long currRotary = 0;
    long lastRotary = 0;
    int rotaryDirection = 0;
    unsigned long lastDebounceTime = 0;
    const unsigned long rotaryDebounceDelay = 25; // Adjust debounce time as needed

public:
    enum rotaryDirection
    {
        CLOCKWISE,
        COUNTERCLOCKWISE
    };

    int rotaryChange = 0;

    const unsigned int DEBOUNCE_TIME = 200;
    unsigned long lastDebounceTimeUp = 0;
    unsigned long lastDebounceTimeLeft = 0;
    unsigned long lastDebounceTimeDown = 0;
    unsigned long lastDebounceTimeRight = 0;
    unsigned long lastDebounceTimeCenter = 0;

    enum buttonPress
    {
        LEFT,
        RIGHT,
        UP,
        DOWN,
        CENTER
    };

    RotaryEncoder encoder;

    AnoDial();

    long getCurrRotary();
    long getLastRotary();

    void checkEncoder(); // Function to poll the encoder with debouncing

    bool getButtonPress(buttonPress button);    // function to get button press

};

#endif