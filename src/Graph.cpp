#include "Graph.h"

Graph::Graph(short int h, short int w, short int x, short int y) {
    height = h;
    width = w;
    xStart = x;
    yStart = y;
}

std::vector<std::pair<short int, short int>>* Graph::getGraphPositions(){
    return &graphPositions;
}

void Graph::appendToGraphPoints(float graphInfo) {
    graphPoints.push_back(graphInfo);
    if (graphPoints.size() > width){
        graphPoints.erase(graphPoints.begin());
    }
}

void Graph::setMin(float newMin) {
    if (min != newMin){
        min = newMin;
    }
}

void Graph::setMax(float newMax) {
    if (max != newMax){
        max = newMax;
    }
}

void Graph::setGraphPositions() {
    graphPositions.clear();
    float range = max - min;
    float valuePerPixel = height / range;
    for (float dataPoint : graphPoints){
        auto y = (uint16_t)std::round(valuePerPixel * (dataPoint - min));
        graphPositions.emplace_back(xStart, yStart - y);
    }
}

void Graph::clearGraphPoints() {
    graphPoints.clear();
}