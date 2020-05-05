//
// Created by avelt on 5/3/2020.
//

#include "Particle.h"

Particle::Particle() {
    this->id = counter++;
    this->speed = 0;
    this->target = nullptr;
}

int Particle::getWidth() {
    return getGlobalBounds().width;
}

int Particle::counter = 0;

int Particle::getId() const {
    return id;
}

Particle::Particle(float speed) {
    this->speed = speed;
    this->id = counter++;
    this->target = nullptr;
}

Particle* Particle::getTarget() const {
    return target;
}

void Particle::setSpeed(float speed) {
    Particle::speed = speed;
}

void Particle::setParticleTarget(Particle* particleTarget) {
    Particle::target = particleTarget;
}

void Particle::setId(int id) {
    Particle::id = id;
}

void Particle::moveToTarget() {
    if (target) {
        auto particlePosition = getPosition();
        auto targetPosition = target->getPosition();

        if (particlePosition.x < targetPosition.x) {
            move(speed, 0.0f);
        } else if (particlePosition.x > targetPosition.x) {
            move(-speed, 0.0f);
        }
        if (particlePosition.y < targetPosition.y) {
            move(0.0f, speed);
        } else if (particlePosition.y > targetPosition.y) {
            move(0.0f, -speed);
        }

        if (getGlobalBounds().intersects(getTarget()->getGlobalBounds())) {
            setId(-1);
        }
    }
}

