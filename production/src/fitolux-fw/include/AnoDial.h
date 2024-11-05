#ifndef _ANODIAL_H_
#define _ANODIAL_H_

#include <RotaryEncoder.h>
#include <Arduino.h>
 
#define PIN_ENCODER_A 13
#define PIN_ENCODER_B 12
#define COM_A    14
#define COM_B    4
#define BUTTON_UP 33
#define BUTTON_LEFT 32
#define BUTTON_DOWN 26
#define BUTTON_RIGHT 25
#define BUTTON_IN 27

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
    const unsigned long debounceDelay = 50; // Adjust debounce time as needed

public:
    int curr_rotary = 0;
    int rotary_direction = 0;
    int last_rotary = 0;

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

    void checkEncoder(); // Function to poll the encoder with debouncing

    bool getButtonPress(buttonPress button);    // function to get button press

};

#endif