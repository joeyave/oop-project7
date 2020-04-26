//
// Created by avelt on 4/26/2020.
//

#ifndef PROJECT6_PART1_PASTELSHAPESFACTORY_H
#define PROJECT6_PART1_PASTELSHAPESFACTORY_H


#include "ShapesFactory.h"

class PastelShapesFactory : public ShapesFactory {
public:
    Circle* createCircle() override;

    Rectangle* createRectangle() override;
};


#endif //PROJECT6_PART1_PASTELSHAPESFACTORY_H
