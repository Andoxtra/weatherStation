#include "MeasurementView.h"
#include <Button.h>


Button* button1 = new Button(4); //Button usb near
Button* button2 = new Button(0); //Button middle

MeasurementView* view = new MeasurementView();

void setup() {
    Serial.begin(9600);
    view->init();
    button1->begin();
    button2->begin();
}

void loop() {
    view->show();
    if (button1->pressed()){
        view->changeCurrentUnit();
    }
    delay(50);
}
