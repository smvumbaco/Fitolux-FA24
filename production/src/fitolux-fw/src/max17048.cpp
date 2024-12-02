#include "max17048.h"



const uint8_t MAX17048::i2cAddress = 0x36;

// registers in the MAX17048
// 0x02 - VCELL_REG
// 0x04 - SOC_REG

MAX17048::MAX17048() : I2CDevice::I2CDevice(i2cAddress), socReg(0x04), battVReg(0x02) {};



// read battery voltage
uint8_t MAX17048::readLipoVoltage()
{
    
    uint8_t lipoV = readRegister(i2cAddress);
    if (lipoV != 0)
    {
        return lipoV;
    }
    else
    {
        Serial.println("Wire not available... return 0");
        return lipoV;
    }
}

// get battery SOC
uint8_t MAX17048::readLipoSOC()
{
    uint8_t lipoSOC = readRegister(i2cAddress);
    if (lipoSOC != 0)
    {
        return lipoSOC;
    }
    else
    {
        Serial.println("Wire not available... return 0");
        return lipoSOC;
    }
}