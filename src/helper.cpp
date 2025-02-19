#include "helper.h"

float roundTwoDecimal(float number){
    float value = (int)(number * 100 + 0.5);
    return (float)value / 100;
}
