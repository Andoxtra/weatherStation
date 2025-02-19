#ifndef WEATHERSTATION_RGBLED_H
#define WEATHERSTATION_RGBLED_H

#include "Adafruit_NeoPixel.h"


class RGBLed {
public:
    RGBLed(short int PIN);
    void setColor(short int r, short int g, short int b);
    void clear();
    void init();
    void setColorByMeasurementData(float current, float max, float min);
private:
    Adafruit_NeoPixel* object;
};


#endif
