//
// Created by avelt on 4/26/2020.
//

#include "NeonCircle.h"

sf::Shape* NeonCircle::getPrimaryColorCircle() {
    auto circleShape = new sf::CircleShape();
    circleShape->setRadius(50);
    circleShape->setFillColor(sf::Color(0, 255, 133));
    return circleShape;
}

sf::Shape* NeonCircle::getSecondaryColorCircle() {
    auto circleShape = new sf::CircleShape();
    circleShape->setRadius(50);
    circleShape->setFillColor(sf::Color(255, 239, 0));
    return circleShape;
}

sf::Shape* NeonCircle::getTertiaryColorCircle() {
    auto circleShape = new sf::CircleShape();
    circleShape->setRadius(50);
    circleShape->setFillColor(sf::Color(236, 255, 241));
    return circleShape;
}
