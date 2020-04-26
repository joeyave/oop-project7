//
// Created by avelt on 4/26/2020.
//

#ifndef PROJECT6_PART1_NEONRECTANGLE_H
#define PROJECT6_PART1_NEONRECTANGLE_H


#include "Rectangle.h"

class NeonRectangle : public Rectangle {
public:
    sf::Shape* getPrimaryColorRectangle() override;

    sf::Shape* getSecondaryColorRectangle() override;

    sf::Shape* getTertiaryColorRectangle() override;
};


#endif //PROJECT6_PART1_NEONRECTANGLE_H
