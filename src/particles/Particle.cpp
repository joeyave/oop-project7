//
// Created by avelt on 5/3/2020.
//

#include <cmath>
#include "Particle.h"
#include "../Utils.h"

Particle::Particle(int speed, sf::Vector2f direction) {
    this->speed = speed;
    this->direction = normalize(direction);
    this->id = counter++;
    this->particleTarget = nullptr;
}

int Particle::getWidth() {
    return getGlobalBounds().width;
}

sf::Vector2f Particle::normalize(const sf::Vector2f& vector2f) {
    float vLength = sqrtf(pow(vector2f.x, 2) + pow(vector2f.y, 2));
    return sf::Vector2f(vector2f.x / vLength, vector2f.y / vLength);
}

int Particle::counter = 0;

int Particle::getId() const {
    return id;
}

Particle::Particle() {
    this->id = counter++;
    this->particleTarget = nullptr;
}

Particle::Particle(int speed) : speed(speed) {
    this->speed = speed;
    this->id = counter++;
    this->particleTarget = nullptr;
}

Particle* Particle::getParticleTarget() const {
    return particleTarget;
}


void Particle::setDirection(const sf::Vector2f& direction) {
    Particle::direction = direction;
}

void Particle::setSpeed(int speed) {
    Particle::speed = speed;
}

void Particle::setParticleTarget(Particle* particleTarget) {
    Particle::particleTarget = particleTarget;
}

void Particle::setId(int id) {
    Particle::id = id;
}

