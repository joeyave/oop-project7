//
// Created by avelt on 4/26/2020.
//

#include "PastelShapesFactory.h"
#include "../circle/PastelCircle.h"
#include "../square/PastelRectangle.h"

Circle* PastelShapesFactory::createCircle() {
    return new PastelCircle();
}

Rectangle* PastelShapesFactory::createRectangle() {
    return new PastelRectangle();
}
