//
// Created by avelt on 4/26/2020.
//

#ifndef PROJECT6_PART1_CIRCLE_H
#define PROJECT6_PART1_CIRCLE_H


#include <SFML/Graphics/CircleShape.hpp>

class Circle {
public:
    virtual sf::Shape* getPrimaryColorCircle() = 0;

    virtual sf::Shape* getSecondaryColorCircle() = 0;

    virtual sf::Shape* getTertiaryColorCircle() = 0;
};

#endif //PROJECT6_PART1_CIRCLE_H
