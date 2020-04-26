//
// Created by avelt on 4/26/2020.
//

#ifndef PROJECT6_PART1_PASTELCIRCLE_H
#define PROJECT6_PART1_PASTELCIRCLE_H


#include "Circle.h"

class PastelCircle : public Circle {
public:
    sf::Shape* getPrimaryColorCircle() override;

    sf::Shape* getSecondaryColorCircle() override;

    sf::Shape* getTertiaryColorCircle() override;
};


#endif //PROJECT6_PART1_PASTELCIRCLE_H
