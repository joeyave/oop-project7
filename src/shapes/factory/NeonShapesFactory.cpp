//
// Created by avelt on 4/26/2020.
//

#include "NeonShapesFactory.h"
#include "../circle/NeonCircle.h"
#include "../square/NeonRectangle.h"

Circle* NeonShapesFactory::createCircle() {
    return new NeonCircle();
}

Rectangle* NeonShapesFactory::createRectangle() {
    return new NeonRectangle();
}
