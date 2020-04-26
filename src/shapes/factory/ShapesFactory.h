//
// Created by avelt on 4/26/2020.
//

#ifndef PROJECT6_PART1_SHAPESFACTORY_H
#define PROJECT6_PART1_SHAPESFACTORY_H


#include "../circle/Circle.h"
#include "../square/Rectangle.h"

class ShapesFactory {
public:
    virtual Circle* createCircle() = 0;

    virtual Rectangle* createRectangle() = 0;
};


#endif //PROJECT6_PART1_SHAPESFACTORY_H
