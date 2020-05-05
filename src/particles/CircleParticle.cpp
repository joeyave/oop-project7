//
// Created by avelt on 5/4/2020.
//

#include "CircleParticle.h"

CircleParticle::CircleParticle(float radius, std::size_t pointCount) {
    this->radius = radius;
    this->pointCount = pointCount;
    update();
}

void CircleParticle::setRadius(float radius) {
    this->radius = radius;
    update();
}

float CircleParticle::getRadius() const {
    return radius;
}

void CircleParticle::setPointCount(std::size_t count) {
    pointCount = count;
    update();
}

std::size_t CircleParticle::getPointCount() const {
    return pointCount;
}

sf::Vector2f CircleParticle::getPoint(std::size_t index) const {
    static const float pi = 3.141592654f;

    float angle = index * 2 * pi / pointCount - pi / 2;
    float x = std::cos(angle) * radius;
    float y = std::sin(angle) * radius;

    return sf::Vector2f(radius + x, radius + y);
}

