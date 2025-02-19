#include "Display.h"

Display::Display(uint8_t screenWidth, uint8_t screenHeight, uint8_t addr) {
    display = new Adafruit_SSD1306(screenWidth, screenHeight, &Wire, oLedReset);
    displayAddr = addr;
}

void Display::drawPixel(short int x, short int y){
    display->drawPixel(x,y,1);
}

void Display::init(){
    if (!display->begin(SSD1306_SWITCHCAPVCC, displayAddr)) {
        Serial.print("SSD1306 allocation failed");
    }
    display->clearDisplay();
    display->setRotation(2);
}

void Display::renderDisplay(){
    display->display();
}

void Display::clearDisplay(){
    display->clearDisplay();
}

void Display::drawLine(short int x1, short int y1, short int x2, short int y2){
    display->drawLine(x1, y1, x2, y2, 1);
}

void Display::drawCharacter(Character* charObject, short int x, short int y){
    for (const std::pair<short int, short int>& i : *charObject->getPosMap()){
        drawPixel(x + std::get<0>(i), y + std::get<1>(i));
    }
}

void Display::drawText(std::string text,  short int x, short int y){
    drawByStringAndPos(&text, x, y);
}

void Display::drawText(float number, short int x, short int y){
    std::stringstream s;
    s << number;
    std::string text = s.str();
    drawByStringAndPos(&text, x, y);
}

void Display::drawText(int number, short int x, short int y){
    std::stringstream s;
    s << number;
    std::string text = s.str();
    drawByStringAndPos(&text, x, y);
}

void Display::drawByStringAndPos(std::string* text, short int x, short int y){
    for (char character : *text){
        Character* charObject = characterTable->getCharacterObject(character);
        drawCharacter(charObject, x ,y);
        x = x + charObject->getWidth() + 1;
    }
}

void Display::drawStructure(){
    drawLine(17, 0, 17, 12);
    drawLine(0, 13, 127, 13);
    drawLine(16, 16, 16, 61);
    drawLine(17, 61, 119, 61);
    drawText("MAX", 26, 5);
    drawText("MIN", 67, 5);
    drawText("AVG", 105, 5);
    drawText("t", 121, 62);
}

void Display::drawHeadNumbers(float min, float max, float avg){
    drawText(max, 22, 11);
    drawText(min, 63, 11);
    drawText(roundTwoDecimal(avg), 101, 11);
}

void Display::drawMeasurementUnit(char unit){
    if(unit == 't'){
        drawText("TEM", 3, 8);
    }
    else if(unit == 'h'){
        drawText("HUM", 3, 8);
    }
    else if(unit == 'p'){
        drawText("BAR", 3, 8);
    }
}

void Display::drawGraph(std::vector<std::pair<short int, short int>>* graphPositions) {
    if (graphPositions->empty()) return;
    short int i = 0;
    std::pair<int16_t, int16_t> lastPos = (*graphPositions)[0];
    for (std::pair<int16_t, int16_t> pos : *graphPositions){
        short int yDiff = pos.second - lastPos.second;
        if (yDiff > 0) {
            drawLine(lastPos.first + i, lastPos.second, lastPos.first + i, pos.second -1);
        } else if (yDiff < 0) {
            drawLine(pos.first + i, pos.second, pos.first + i, lastPos.second -1);
        }
        drawPixel(pos.first + i, pos.second);
        lastPos = pos;
        i++;
    }
}

void Display::drawGraphInfo() {
    drawText("MAX", 1, 21);
    drawText("MID", 1, 41);
    drawText("MIN", 1, 61);
}
