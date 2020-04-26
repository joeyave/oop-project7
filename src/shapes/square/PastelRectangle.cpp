//
// Created by avelt on 4/26/2020.
//

#include <SFML/Graphics/RectangleShape.hpp>
#include "PastelRectangle.h"

sf::Shape* PastelRectangle::getPrimaryColorRectangle() {
    auto rectangleShape = new sf::RectangleShape();
    rectangleShape->setSize(sf::Vector2f(150, 100));
    rectangleShape->setFillColor(sf::Color(254, 200, 216));
    return rectangleShape;
}

sf::Shape* PastelRectangle::getSecondaryColorRectangle() {
    auto rectangleShape = new sf::RectangleShape();
    rectangleShape->setSize(sf::Vector2f(150, 100));
    rectangleShape->setFillColor(sf::Color(210, 145, 188));
    return rectangleShape;
}

sf::Shape* PastelRectangle::getTertiaryColorRectangle() {
    auto rectangleShape = new sf::RectangleShape();
    rectangleShape->setSize(sf::Vector2f(150, 100));
    rectangleShape->setFillColor(sf::Color(224, 187, 228));
    return rectangleShape;
}
