//
// Created by avelt on 4/26/2020.
//

#ifndef PROJECT6_PART1_RECTANGLE_H
#define PROJECT6_PART1_RECTANGLE_H

#include <SFML/Graphics/CircleShape.hpp>

class Rectangle {
public:
    virtual sf::Shape* getPrimaryColorRectangle() = 0;

    virtual sf::Shape* getSecondaryColorRectangle() = 0;

    virtual sf::Shape* getTertiaryColorRectangle() = 0;
};

#endif //PROJECT6_PART1_RECTANGLE_H
