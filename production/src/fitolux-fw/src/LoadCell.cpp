#include "LoadCell.h"

LoadCell::LoadCell() {
    sckPin = 27;
    doutPin = 26;
}

void LoadCell::begin() {
    scale.begin(doutPin, sckPin);
    scale.set_scale(calibrationFactor);  // Set initial calibration factor
    scale.tare();  // Reset the scale to 0
}

void LoadCell::tare() {
    scale.tare();
}

float LoadCell::readWeight() {
    return scale.get_units(5); 
}

void LoadCell::setCalibration(float _calibrationFactor) {
    calibrationFactor = _calibrationFactor;
}

void LoadCell::adjustCalibration(float adjustment) {
    calibrationFactor += adjustment;
    scale.set_scale(calibrationFactor);
}

float LoadCell::getCalibrationFactor() const {
    return calibrationFactor;
}
