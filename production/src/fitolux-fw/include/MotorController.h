#ifndef MOTORCONTROLLER_H
#define MOTORCONTROLLER_H

#include <Arduino.h>

class MotorController {
public:
    MotorController();
    void setDirection(bool direction);
    void setSpeed(int speed);
    void enable();
    void disable();

private:
    int standbyPin;
    int pwmPin;
    int in1Pin;
    int in2Pin;
    bool direction;
    int speed;
};

#endif
