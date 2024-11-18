#include "MotorController.h"

MotorController::MotorController(){
    standbyPin = 2;
    pwmPin = 17;
    in1Pin = 4;
    in2Pin = 16;

    pinMode(standbyPin, OUTPUT);
    pinMode(pwmPin, OUTPUT);
    pinMode(in1Pin, OUTPUT);
    pinMode(in2Pin, OUTPUT);
}

void MotorController::setDirection(bool direction) {
    digitalWrite(in1Pin, !direction);
    digitalWrite(in2Pin, direction);
}

void MotorController::setSpeed(int speed) {
    analogWrite(pwmPin, speed);
}

void MotorController::enable() {
    digitalWrite(standbyPin, HIGH);
}

void MotorController::disable() {
    digitalWrite(standbyPin, LOW);
}
