//
// Created by avelt on 5/3/2020.
//

#include <effolkronium/random.hpp>
#include "ParticleFactory.h"
#include "../Constants.h"
#include "../particles/RectangleParticle.h"
#include "../particles/CircleParticle.h"

using Random = effolkronium::random_static;

ParticleFactory::ParticleFactory(TextureHolder<int>* textureHolder) {
    this->textureHolder = textureHolder;
}

Particle* ParticleFactory::createRandomParticle() {
    int randTexture = Random::get(0, textureHolder->size() - 1);
    int randShape = Random::get(0, ParticleFactory::ShapeType::SHAPE_COUNT - 1);
    int randSize = Random::get(settings::MIN_SIZE, settings::MAX_SIZE);
    float randSpeed = Random::get(settings::MIN_SPEED, settings::MAX_SPEED);
    sf::Vector2f position(Random::get(0, settings::WINDOW_X), Random::get(0, settings::WINDOW_Y));

    Particle* particle;

    if (randShape == ShapeType::Square) {
        particle = new RectangleParticle(sf::Vector2f(randSize, randSize));
        particle->setSpeed(randSpeed);
        particle->setTexture(&textureHolder->get(randTexture));
        particle->setOrigin(sf::Vector2f(randSize / 2, randSize / 2));
        particle->setPosition(position);
    } else {
        particle = new CircleParticle(randSize);
        particle->setSpeed(randSpeed);
        particle->setTexture(&textureHolder->get(randTexture));
        particle->setOrigin(sf::Vector2f(randSize, randSize));
        particle->setPosition(position);
    }

    return particle;
}

