//
// Created by avelt on 4/26/2020.
//

#ifndef PROJECT6_PART1_CONFIG_H
#define PROJECT6_PART1_CONFIG_H


#include <iostream>
#include "shapes/factory/ShapesFactory.h"
#include "shapes/factory/PastelShapesFactory.h"
#include "shapes/factory/NeonShapesFactory.h"

class Config {
public:
    void chooseColorTheme();

    [[nodiscard]] ShapesFactory* getShapesFactory() const;

    void setShapesFactory(ShapesFactory* shapesFactory);

private:
    ShapesFactory* shapesFactory;
};

#endif //PROJECT6_PART1_CONFIG_H
