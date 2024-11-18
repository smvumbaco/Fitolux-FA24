#ifndef LOADCELL_H
#define LOADCELL_H

#include "HX711.h"
#include <Arduino.h>

class LoadCell {
public:
    LoadCell();
    void begin();
    void tare();
    float readWeight();
    void setCalibration(float _calibrationFactor);
    void adjustCalibration(float adjustment);
    float getCalibrationFactor() const;

private:
    HX711 scale;
    int doutPin;
    int sckPin;
    float calibrationFactor;
};

#endif
