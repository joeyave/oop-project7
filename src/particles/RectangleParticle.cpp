//
// Created by avelt on 5/4/2020.
//

#include "RectangleParticle.h"
#include "../Utils.h"

RectangleParticle::RectangleParticle(const sf::Vector2f& size) {
    this->size = size;
    this->target = nullptr;
    update();
}

RectangleParticle::RectangleParticle(int speed, const sf::Vector2f& size) : Particle(speed) {
    this->size = size;
    this->target = nullptr;
    update();
}

std::size_t RectangleParticle::getPointCount() const {
    return 4;
}

sf::Vector2f RectangleParticle::getPoint(std::size_t index) const {
    switch (index) {
        default:
        case 0:
            return sf::Vector2f(0, 0);
        case 1:
            return sf::Vector2f(size.x, 0);
        case 2:
            return sf::Vector2f(size.x, size.y);
        case 3:
            return sf::Vector2f(0, size.y);
    }
}

const sf::Vector2f& RectangleParticle::getSize() const {
    return size;
}

void RectangleParticle::setSize(const sf::Vector2f& size) {
    this->size = size;
    update();
}



