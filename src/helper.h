#ifndef WEATHERSTATION_HELPER_H
#define WEATHERSTATION_HELPER_H

#include <vector>

float roundTwoDecimal(float number);
template <typename T>
int getIndexFromItemInVector(const std::vector<T>* vector, T* item){
    for(int i = 0; i < vector->size(); i++){
        if((*vector)[i] == (*item)){
            return i;
        }
    }
    return -1;
}

#endif //WEATHERSTATION_HELPER_H
