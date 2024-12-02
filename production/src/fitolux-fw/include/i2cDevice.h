#ifndef I2CDEVICE_H
#define I2CDEVICE_H

#include <Wire.h>
#include <Arduino.h>

// void scanI2CDevices();


class I2CDevice {
public:
    I2CDevice(uint8_t deviceAddress);

    void scanI2CDevices();
    uint8_t readRegister(uint8_t regAddress);
    void writeRegister(uint8_t regAddress, uint8_t value);

private:
    uint8_t deviceAddress;
};


#endif