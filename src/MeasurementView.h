#ifndef WEATHERSTATION_MEASUREMENTVIEW_H
#define WEATHERSTATION_MEASUREMENTVIEW_H

#define TEMPERATUR 't'
#define HUMIDITY 'h'
#define PRESSURE 'p'


#include "Display.h"
#include "BME280Sensor.h"
#include "Graph.h"
#include "RGBLed.h"

class MeasurementView {
private:
    ~MeasurementView();
    Display* display;
    BME280Sensor* sensor;
    Graph* graph;
    RGBLed* led;
    const std::vector<char> allUnits = {TEMPERATUR, HUMIDITY, PRESSURE};
    char currentUnit = allUnits[0];

public:
    MeasurementView();
    void init();
    void show();
    void changeCurrentUnit();
};


#endif //WEATHERSTATION_MEASUREMENTVIEW_H
