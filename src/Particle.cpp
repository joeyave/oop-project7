//
// Created by avelt on 5/3/2020.
//

#include <cmath>
#include <iostream>
#include "Particle.h"
#include "Constants.h"
#include "Utils.h"

Particle::Particle(ParticleType* type, int speed, sf::Vector2f direction) {
    this->type = type;
    this->speed = speed;
    this->direction = normalize(direction);
    this->id = counter++;
    this->target = nullptr;
}

void Particle::update(float dt) {
    sf::Vector2f position;
    float shapeRadius = getWidth() / 2;

    move(sf::Vector2f(speed * direction.x * dt, speed * direction.y * dt));

    position = getPosition();

    // Check if particle has hit window border.
    if (position.x + shapeRadius >= settings::WINDOW_X) {
        direction.x *= -1;
        setPosition(settings::WINDOW_X - shapeRadius, getPosition().y);
    }
    if (position.x <= 0) {
        direction.x *= -1;
        setPosition(0, getPosition().y);
    }
    if (position.y + shapeRadius >= settings::WINDOW_Y) {
        direction.y *= -1;
        setPosition(getPosition().x, settings::WINDOW_Y - shapeRadius);
    }
    if (position.y <= 0) {
        direction.y *= -1;
        setPosition(getPosition().x, 0);
    }
}

int Particle::getWidth() {
    return type->shape->getGlobalBounds().width;
}

ParticleType* Particle::getType() const {
    return type;
}

void Particle::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    // Apply transform of current node.
    states.transform *= getTransform();
    type->draw(target, states);
}

sf::Vector2f Particle::normalize(const sf::Vector2f& vector2f) {
    float vLength = sqrtf(pow(vector2f.x, 2) + pow(vector2f.y, 2));
    return sf::Vector2f(vector2f.x / vLength, vector2f.y / vLength);
}

int Particle::counter = 0;

bool Particle::findTarget(const std::vector<Particle*>& particles) {
    if (particles.size() < 2 || this->target) {
        return false;
    }

    while (!this->target) {
        // Get random element from particles vector.
        auto randomTarget = *utils::select_randomly(particles.begin(), particles.end());

        if (randomTarget && randomTarget != this && !randomTarget->target) {
            this->target = randomTarget;
            randomTarget->target = this;
            return true;
        }
    }

    return false;
}

int Particle::getId() const {
    return id;
}

Particle* Particle::getTarget() const {
    return target;
}

void Particle::moveToTarget() {
    if (this->getPosition().x < target->getPosition().x) {
        this->move(sf::Vector2f(0.1, 0));
    } else if (this->getPosition().x > target->getPosition().x) {
        this->move(sf::Vector2f(-0.1, 0));
    }
    if (this->getPosition().y < target->getPosition().y) {
        this->move(sf::Vector2f(0, 0.1));
    } else if (this->getPosition().y > target->getPosition().y) {
        this->move(sf::Vector2f(0, -0.1));
    }
}

bool Particle::intersectsWith(Particle* particle) {
    std::cout << getWidth() << "-" << target->getWidth() << std::endl;
    std::cout << getPosition().x << "-" << target->getPosition().x << std::endl;
    std::cout << getPosition().y << "-" << target->getPosition().y << std::endl;
    std::cout << type->shape->getGlobalBounds().left << "-" << particle->type->shape->getGlobalBounds().left
              << std::endl;

    if (getPosition().x - target->getPosition().x < getWidth() - target->getWidth()) {
        if (getPosition().y - target->getPosition().y < getWidth() - target->getWidth()) {
            return true;
        }
    }

    return false;
}
