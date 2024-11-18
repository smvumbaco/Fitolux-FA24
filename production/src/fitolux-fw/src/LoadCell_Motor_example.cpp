#include "MotorController.h"
#include "LoadCell.h"

MotorController motor;
LoadCell scale;

void setup() {
    Serial.begin(115200);
    scale.setCalibration(3648000);
    scale.begin();
}

void loop() {
    motor.setDirection(0);     // Set forward direction
    motor.setSpeed(100);       // Set speed (0-255)
    motor.enable();
    delay(2000);
    motor.disable();
    delay(1000);

    motor.setDirection(1);     // Set reverse direction
    motor.setSpeed(150);       // Change speed
    motor.enable();
    delay(2000);
    motor.disable();
    delay(1000);

    // Display the weight on Serial Monitor
    float weight = scale.readWeight();
    Serial.print("Weight: ");
    Serial.print(weight, 4); // Display with 4 decimal places
    Serial.println(" kg");   // Change to other units if necessary
}
