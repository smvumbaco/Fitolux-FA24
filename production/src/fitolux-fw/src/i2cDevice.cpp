#include "i2cDevice.h"


I2CDevice::I2CDevice(uint8_t address) : deviceAddress(address)
{
    Wire.begin();
}

void I2CDevice::scanI2CDevices()
{
    Serial.println("Scanning I2C devices...");
    for (uint8_t address = 1; address < 127; ++address) {
        Wire.beginTransmission(address);
        uint8_t error = Wire.endTransmission();
        if (error == 0) {
            Serial.print("I2C device found at address 0x");
            if (address < 16) Serial.print("0");
            Serial.println(address, HEX);
        }
    }
    Serial.println("Scan complete.");
}

uint8_t I2CDevice::readRegister(uint8_t regAddress)
{
    Wire.beginTransmission(deviceAddress);
    Wire.write(regAddress);
    Wire.endTransmission();
    Wire.requestFrom(deviceAddress, (uint8_t)1);
    if (Wire.available()) {
        return Wire.read();
    }
    return 0;
}

void I2CDevice::writeRegister(uint8_t regAddress, uint8_t value)
{
    Wire.beginTransmission(deviceAddress);
    Wire.write(regAddress);
    Wire.write(value);
    Wire.endTransmission();
}

// void I2CDevice::readMultipleRegisters(byte deviceAddress, byte startRegister, byte* buffer, int length)
// {
//     Wire.beginTransmission(deviceAddress);
//     Wire.write(startRegister);
//     Wire.endTransmission();
//     Wire.requestFrom(deviceAddress, (byte)length);
//     for (int i = 0; i < length; ++i)
//     {
//         if (Wire.available())
//         {
//             buffer[i] = Wire.read();
//         }
//     }
// }

// void I2CDevice::writeMultipleRegisters(byte deviceAddress, byte startRegister, byte* values, int length)
// {
//     Wire.beginTransmission(deviceAddress);
//     Wire.write(startRegister);
//     for (int i = 0; i < length; ++i)
//     {
//         Wire.write(values[i]);
//     }
//     Wire.endTransmission();
// }