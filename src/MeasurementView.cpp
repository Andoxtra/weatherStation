#include "MeasurementView.h"
#include "RGBLed.h"

#define SCREEN_ADDRESS 0x3c
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define BME280_ADDRESS 0x76

#define GRAPH_HEIGHT 44
#define GRAPH_WIDTH 101
#define GRAPH_START_X 18
#define GRAPH_START_Y 60

#define LED_PIN 38


MeasurementView::MeasurementView(){
    display = new Display(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_ADDRESS);
    sensor = new BME280Sensor(BME280_ADDRESS);
    graph = new Graph(GRAPH_HEIGHT, GRAPH_WIDTH, GRAPH_START_X, GRAPH_START_Y);
    led = new RGBLed(LED_PIN);
}

void MeasurementView::init(){
    sensor->init();
    display->init();
    led->init();
    sensor->setUnit(currentUnit);
    sensor->measureByUnit();
    sensor->setAllValuesCurrentMeasurement();
}

void MeasurementView::show(){
    display->clearDisplay();
    display->drawStructure();
    sensor->measureByUnit();
    sensor->setAllValues();

    float minVal = sensor->getMinValue();
    float maxVal = sensor->getMaxValue();
    float currentVal = sensor->getCurrentValue();

    graph->setMin(minVal);
    graph->setMax(maxVal);

    graph->appendToGraphPoints(currentVal);
    graph->setGraphPositions();

    led->setColorByMeasurementData(currentVal, maxVal, minVal);

    display->drawHeadNumbers(minVal, maxVal, sensor->getAvgValue());
    display->drawMeasurementUnit(currentUnit);
    display->drawGraphInfo();
    display->drawGraph(graph->getGraphPositions());

    display->renderDisplay();
}

void MeasurementView::changeCurrentUnit() {
    int indexOfCurrentUnit = getIndexFromItemInVector(&allUnits, &currentUnit);
    uint8_t lengthOfAllUnits = allUnits.size();
    uint8_t newIndexOfCurrentUnit = (indexOfCurrentUnit + 1) % lengthOfAllUnits;
    currentUnit = allUnits[newIndexOfCurrentUnit];
    sensor->setUnit(currentUnit);
    graph->clearGraphPoints();
    sensor->measureByUnit();
    sensor->setAllValuesCurrentMeasurement();
}
