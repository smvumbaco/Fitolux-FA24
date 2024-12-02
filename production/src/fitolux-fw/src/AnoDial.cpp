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

long AnoDial::getCurrRotary()
{
    return currRotary;
}

long AnoDial::getLastRotary()
{
    return lastRotary;
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
        if ((currentTime - lastDebounceTime) > rotaryDebounceDelay) {
            lastDebounceTime = currentTime; // Update the debounce timer 
            lastRotary = currRotary; // Update the last known position

            // // Print or handle the encoder movement
            // Serial.print("New Position: ");
            // Serial.println(currRotary);

            // Check the direction and handle it as needed
            if (encoder.getDirection() == RotaryEncoder::Direction::CLOCKWISE) {
                rotaryDirection = CLOCKWISE;
                rotaryChange = CLOCKWISE;
            } else if (encoder.getDirection() == RotaryEncoder::Direction::COUNTERCLOCKWISE) {
                rotaryDirection = COUNTERCLOCKWISE;
                rotaryChange = COUNTERCLOCKWISE;
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

// void getButtonPre