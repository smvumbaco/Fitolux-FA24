#include "AnoDial.h"

// int weightSelect;

AnoDial::AnoDial() : encoder(PIN_ENCODER_B, PIN_ENCODER_A, RotaryEncoder::LatchMode::TWO03)
{
    // set up encoder variables
    pinMode(COM_A, OUTPUT);
    digitalWrite(COM_A, LOW);
    pinMode(COM_B, OUTPUT);
    digitalWrite(COM_B, LOW);

    // set button pins
    pinMode(BUTTON_UP, INPUT_PULLUP);
    pinMode(BUTTON_DOWN, INPUT_PULLUP);
    pinMode(BUTTON_LEFT, INPUT_PULLUP);
    pinMode(BUTTON_RIGHT, INPUT_PULLUP);
    pinMode(BUTTON_IN, INPUT_PULLUP);
}

bool AnoDial::getButtonPress(buttonPress button)
{
    if (button == LEFT)
    {
        if (!digitalRead(BUTTON_LEFT)) {
            if ((millis() - lastDebounceTimeLeft) > DEBOUNCE_TIME) {
                lastDebounceTimeLeft = millis();  // Update the last debounce time
                return true;
            }
        }
    }
    else if(button == RIGHT)
    {
        if (!digitalRead(BUTTON_RIGHT)) {
            if ((millis() - lastDebounceTimeRight) > DEBOUNCE_TIME) {
                lastDebounceTimeRight = millis();  // Update the last debounce time
                return true;
            }
        }
    }
    else if(button == UP)
    {
        if (!digitalRead(BUTTON_UP)) {
            if ((millis() - lastDebounceTimeUp) > DEBOUNCE_TIME) {
                lastDebounceTimeUp = millis();  // Update the last debounce time
                return true;
            }
        }
    }
    else if(button == DOWN)
    {
        if (!digitalRead(BUTTON_DOWN)) {
            if ((millis() - lastDebounceTimeDown) > DEBOUNCE_TIME) {
                lastDebounceTimeDown = millis();  // Update the last debounce time
                return true;
            }
        }
    }
    else if(button == CENTER)
    {
        if (!digitalRead(BUTTON_IN)) {
            if ((millis() - lastDebounceTimeCenter) > DEBOUNCE_TIME) {
                lastDebounceTimeCenter = millis();  // Update the last debounce time
                return true;
            }
        }
    }
    return false;
}

void AnoDial::checkEncoder() {
    encoder.tick(); // Update the encoder state

    // Get the current position of the encoder
    currRotary = encoder.getPosition();

    // Check if the position has changed and apply debounce logic
    if (currRotary != lastRotary) {
        unsigned long currentTime = millis();
        
        // Check if enough time has passed since the last detected change
        if ((currentTime - lastDebounceTime) > debounceDelay) {
            lastDebounceTime = currentTime; // Update the debounce timer 
            lastRotary = currRotary; // Update the last known position

            // Print or handle the encoder movement
            Serial.print("New Position: ");
            Serial.println(currRotary);

            // Check the direction and handle it as needed
            if (encoder.getDirection() == RotaryEncoder::Direction::CLOCKWISE) {
                Serial.println("Direction: Clockwise");
            } else if (encoder.getDirection() == RotaryEncoder::Direction::COUNTERCLOCKWISE) {
                Serial.println("Direction: Counterclockwise");
            }
        }
    }
}

// int updateWeightSelect(int weightSelect, int last_rotary, int curr_rotary, int rotary_direction)
// {
//     if (curr_rotary != last_rotary)
//     {
//         if (rotary_direction == -1)
//         {
//         if (weightSelect+1 <= MAX_WEIGHT)
//         {
//             weightSelect++;
//         }
//         }
//         else if (rotary_direction == 1)
//         {
//         if (weightSelect-1 >= MIN_WEIGHT)
//         {
//             weightSelect--;
//         }
//         }
//         Serial.print("Select weight: ");
//         Serial.print(weightSelect);
//         Serial.println(" g");
//     }
//     return weightSelect;
// }

// // void getButtonPre


// #include "AnoDial.h"

// AnoDial* AnoDial::instance = nullptr; // Initialize static instance pointer

// // Constructor
// AnoDial::AnoDial() : encoder(PIN_ENCODER_B, PIN_ENCODER_A, RotaryEncoder::LatchMode::TWO03) {
//     // Set up encoder and button pins
//     pinMode(PIN_ENCODER_A, INPUT_PULLUP);
//     pinMode(PIN_ENCODER_B, INPUT_PULLUP);
//     pinMode(BUTTON_UP, INPUT_PULLUP);
//     pinMode(BUTTON_DOWN, INPUT_PULLUP);
//     pinMode(BUTTON_LEFT, INPUT_PULLUP);
//     pinMode(BUTTON_RIGHT, INPUT_PULLUP);
//     pinMode(BUTTON_IN, INPUT_PULLUP);
// }

// // Begin method to set up interrupts
// void AnoDial::begin() {
//     instance = this; // Set the static instance pointer to this object

//     // Attach interrupts for the encoder
//     attachInterrupt(digitalPinToInterrupt(PIN_ENCODER_A), encoderISR, CHANGE);
//     attachInterrupt(digitalPinToInterrupt(PIN_ENCODER_B), encoderISR, CHANGE);

//     // Attach interrupts for buttons
//     attachInterrupt(digitalPinToInterrupt(BUTTON_UP), buttonISR_UP, FALLING);
//     attachInterrupt(digitalPinToInterrupt(BUTTON_DOWN), buttonISR_DOWN, FALLING);
//     attachInterrupt(digitalPinToInterrupt(BUTTON_LEFT), buttonISR_LEFT, FALLING);
//     attachInterrupt(digitalPinToInterrupt(BUTTON_RIGHT), buttonISR_RIGHT, FALLING);
//     attachInterrupt(digitalPinToInterrupt(BUTTON_IN), buttonISR_CENTER, FALLING);
// }

// // Encoder ISR
// void IRAM_ATTR AnoDial::encoderISR() {
//     instance->encoderChanged = true; // Update encoder flag
// }

// // Button ISRs
// void IRAM_ATTR AnoDial::buttonISR_UP() {
//     unsigned long currentTime = millis();
//     if (currentTime - instance->lastDebounceTime[UP] > instance->DEBOUNCE_DELAY) {
//         instance->lastDebounceTime[UP] = currentTime;
//         instance->buttonPressed[UP] = true;
//     }
// }

// void IRAM_ATTR AnoDial::buttonISR_DOWN() {
//     unsigned long currentTime = millis();
//     if (currentTime - instance->lastDebounceTime[DOWN] > instance->DEBOUNCE_DELAY) {
//         instance->lastDebounceTime[DOWN] = currentTime;
//         instance->buttonPressed[DOWN] = true;
//     }
// }

// void IRAM_ATTR AnoDial::buttonISR_LEFT() {
//     unsigned long currentTime = millis();
//     if (currentTime - instance->lastDebounceTime[LEFT] > instance->DEBOUNCE_DELAY) {
//         instance->lastDebounceTime[LEFT] = currentTime;
//         instance->buttonPressed[LEFT] = true;
//     }
// }

// void IRAM_ATTR AnoDial::buttonISR_RIGHT() {
//     unsigned long currentTime = millis();
//     if (currentTime - instance->lastDebounceTime[RIGHT] > instance->DEBOUNCE_DELAY) {
//         instance->lastDebounceTime[RIGHT] = currentTime;
//         instance->buttonPressed[RIGHT] = true;
//     }
// }

// void IRAM_ATTR AnoDial::buttonISR_CENTER() {
//     unsigned long currentTime = millis();
//     if (currentTime - instance->lastDebounceTime[CENTER] > instance->DEBOUNCE_DELAY) {
//         instance->lastDebounceTime[CENTER] = currentTime;
//         instance->buttonPressed[CENTER] = true;
//     }
// }

// // Check if a button was pressed
// bool AnoDial::isButtonPressed(buttonPress button) {
//     if (buttonPressed[button]) {
//         buttonPressed[button] = false; // Reset the flag after reading
//         return true;
//     }
//     return false;
// }

// // Encoder check (optional fallback)
// void AnoDial::checkEncoder() {
//     if (encoderChanged) {
//         encoderChanged = false;
//         encoder.tick(); // Update encoder state
//         long newRotary = encoder.getPosition();

//         if (newRotary != currRotary) {
//             rotaryDirection = (newRotary > currRotary) ? 1 : -1;
//             lastRotary = currRotary;
//             currRotary = newRotary;

//             Serial.print("Encoder Position: ");
//             Serial.println(currRotary);
//             Serial.print("Direction: ");
//             Serial.println(rotaryDirection == 1 ? "Clockwise" : "Counterclockwise");
//         }
//     }
// }

// int AnoDial::getCurrRotary()
// {
//     return currRotary;
// }

// int AnoDial::getLastRotary()
// {
//     return lastRotary;
// }