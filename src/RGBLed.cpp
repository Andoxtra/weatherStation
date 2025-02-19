#include "RGBLed.h"

#define NUMPIXELS 1


RGBLed::RGBLed(short int PIN) {
    RGBLed::object = new Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB);
    RGBLed::object->setBrightness(20);
}

void RGBLed::setColor(short r, short g, short b) {
    RGBLed::object->setPixelColor(0, Adafruit_NeoPixel::Color(r, g, b));
    RGBLed::object->show();
}

void RGBLed::clear() {
    RGBLed::setColor(0, 0, 0);
}

void RGBLed::init() {
    RGBLed::object->begin();
}

void RGBLed::setColorByMeasurementData(float current, float max, float min) {
    float red, green, blue;
    float difference = max - min;
    float unitPerRGB = difference / 510;
    int rgbValue = (current - min) / unitPerRGB;

    blue = 255 - rgbValue;
    green = (blue <= 0) ? 255 + blue : 255 - blue;
    red = (blue <= 0) ? 255 - green : 0;

    blue = (blue > 0) ? blue : 0;

    RGBLed::setColor((int)red, (int)green, (int)blue);
}
