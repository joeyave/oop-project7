//
// Created by avelt on 4/26/2020.
//

#include <SFML/Graphics/RectangleShape.hpp>
#include "NeonRectangle.h"

sf::Shape* NeonRectangle::getPrimaryColorRectangle() {
    auto rectangleShape = new sf::RectangleShape();
    rectangleShape->setSize(sf::Vector2f(150, 100));
    rectangleShape->setFillColor(sf::Color(255, 250, 141));
    return rectangleShape;
}

sf::Shape* NeonRectangle::getSecondaryColorRectangle() {
    auto rectangleShape = new sf::RectangleShape();
    rectangleShape->setSize(sf::Vector2f(150, 100));
    rectangleShape->setFillColor(sf::Color(0, 255, 205));
    return rectangleShape;
}

sf::Shape* NeonRectangle::getTertiaryColorRectangle() {
    auto rectangleShape = new sf::RectangleShape();
    rectangleShape->setSize(sf::Vector2f(150, 100));
    rectangleShape->setFillColor(sf::Color(159, 255, 158));
    return rectangleShape;
}
