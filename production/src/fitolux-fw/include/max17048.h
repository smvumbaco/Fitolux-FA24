#ifndef _MAX17408_H_
#define _MAX17048_H_

#include <Adafruit_MAX1704X.h>
#include "i2cDevice.h"

class MAX17048 : public I2CDevice
{
private:
    static const uint8_t i2cAddress;
    const uint8_t socReg;
    const uint8_t battVReg;

public:
    // functions

    MAX17048(); // Constructor

    // address related funcs
    void displayI2CAddress();
    void getI2CAddress();

    // read battery voltage
    uint8_t readLipoVoltage();

    // get battery SOC
    uint8_t readLipoSOC();



};


#endif