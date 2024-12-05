#ifndef _ANODIAL_H_
#define _ANODIAL_H_

#include <RotaryEncoder.h>
#include <Arduino.h>
 
// #define PIN_ENCODER_A 13
// #define PIN_ENCODER_B 12
// #define COM_A    14
// #define COM_B    4
// #define BUTTON_UP 33
// #define BUTTON_LEFT 32
// #define BUTTON_DOWN 26
// #define BUTTON_RIGHT 25
// #define BUTTON_IN 27

#define PIN_ENCODER_A 33
#define PIN_ENCODER_B 25
#define COM_A    13
#define COM_B    12
#define BUTTON_UP 39
#define BUTTON_LEFT 34
#define BUTTON_DOWN 35
#define BUTTON_RIGHT 36
#define BUTTON_IN 32

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


// #ifndef _ANODIAL_H_
// #define _ANODIAL_H_

// #include <Arduino.h>
// #include <RotaryEncoder.h>

// // Pin definitions
// #define PIN_ENCODER_A 33
// #define PIN_ENCODER_B 25
// #define BUTTON_UP 39
// #define BUTTON_LEFT 34
// #define BUTTON_DOWN 35
// #define BUTTON_RIGHT 36
// #define BUTTON_IN 32

// // Rotary weight limits
// #define MAX_WEIGHT 50
// #define MIN_WEIGHT 0

// class AnoDial
// {
// private:
//     volatile long currRotary = 0; // Current rotary encoder position
//     volatile long lastRotary = 0; // Current rotary encoder position
//     volatile int rotaryDirection = 0; // -1 for CCW, 1 for CW
//     volatile bool encoderChanged = false; // Flag for encoder state change
//     volatile bool buttonPressed[5] = {false}; // Flags for button press states

//     unsigned long lastDebounceTime[5] = {0}; // Last debounce times for buttons
//     const unsigned long DEBOUNCE_DELAY = 50; // Debounce delay in ms

//     static AnoDial* instance; // Static pointer to the current instance

// public:
//     enum buttonPress
//     {
//         UP,
//         DOWN,
//         LEFT,
//         RIGHT,
//         CENTER
//     };

//     RotaryEncoder encoder;

//     AnoDial();
//     void begin(); // Initialize pins and interrupts
//     void checkEncoder(); // Poll encoder if not using interrupts
//     bool isButtonPressed(buttonPress button); // Check button press flag
//     int getCurrRotary();
//     int getLastRotary();

//     // Static Interrupt handlers
//     static void encoderISR();
//     static void buttonISR_UP();
//     static void buttonISR_DOWN();
//     static void buttonISR_LEFT();
//     static void buttonISR_RIGHT();
//     static void buttonISR_CENTER();
// };

// #endif
