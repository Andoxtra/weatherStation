#ifndef WEATHERSTATION_GRAPH_H
#define WEATHERSTATION_GRAPH_H

#include <vector>
#include "helper.h"
#include <bits/stdc++.h>

class Graph {
private:
    short int height;
    short int width;
    short int xStart;
    short int yStart;
    float min{};
    float max{};
    std::vector<float> graphPoints{};
    std::vector<std::pair<short int, short int>> graphPositions{};
public:
    Graph(short int h, short int w, short int x, short int y);
    void appendToGraphPoints(float graphInfo);
    void setMin(float newMin);
    void setMax(float newMax);
    void setGraphPositions();
    std::vector<std::pair<short int, short int>>* getGraphPositions();
    void clearGraphPoints();
};


#endif //WEATHERSTATION_GRAPH_H
