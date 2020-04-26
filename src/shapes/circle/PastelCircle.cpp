//
// Created by avelt on 4/26/2020.
//

#include "PastelCircle.h"

sf::Shape* PastelCircle::getPrimaryColorCircle() {
    auto circleShape = new sf::CircleShape();
    circleShape->setRadius(50);
    circleShape->setFillColor(sf::Color(224, 187, 228));
    return circleShape;
}

sf::Shape* PastelCircle::getSecondaryColorCircle() {
    auto circleShape = new sf::CircleShape();
    circleShape->setRadius(50);
    circleShape->setFillColor(sf::Color(149, 125, 173));
    return circleShape;
}

sf::Shape* PastelCircle::getTertiaryColorCircle() {
    auto circleShape = new sf::CircleShape();
    circleShape->setRadius(50);
    circleShape->setFillColor(sf::Color(255, 223, 211));
    return circleShape;
}
