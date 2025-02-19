#ifndef WEATHERSTATION_DISPLAY_H
#define WEATHERSTATION_DISPLAY_H

#include "Adafruit_SSD1306.h"
#include <bits/stdc++.h>
#include <map>
#include <array>
#include <vector>

#include "CharTable.h"
#include "Character.h"
#include "helper.h"


class Display{
private:
    Adafruit_SSD1306* display;
    uint8_t displayAddr;
    int8_t oLedReset = -1;
    CharTable* characterTable = new CharTable();
    void drawCharacter(Character* charObject, short int x, short int y);
    void drawByStringAndPos(std::string* text, short int x, short int y);

public:
    Display(uint8_t screenWidth, uint8_t screenHeight, uint8_t addr);
    void init();
    void drawStructure();
    void drawPixel(short int x, short int y);
    void renderDisplay();
    void clearDisplay();
    void drawLine(short int x1, short int y1, short int x2, short int y2);
    void drawText(float number, short int x, short int y);
    void drawText(std::string text, short int x, short int y);
    void drawText(int, short int x, short int y);
    void drawHeadNumbers(float min, float max, float avg);
    void drawMeasurementUnit(char unit);
    void drawGraph(std::vector<std::pair<short int, short int>>* graphPositions);
    void drawGraphInfo();
};

#endif //WEATHERSTATION_DISPLAY_H
