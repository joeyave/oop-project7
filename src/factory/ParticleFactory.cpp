//
// Created by avelt on 5/3/2020.
//

#include "ParticleFactory.h"
#include "../Constants.h"
#include "../particles/RectangleParticle.h"
#include "../particles/CircleParticle.h"

ParticleFactory::ParticleFactory(TextureHolder<int>* textureHolder) {
    this->textureHolder = textureHolder;
    srand(time(nullptr));
}

// TODO: change rand library.
int ParticleFactory::r(int start, int end) {
    return rand() % ((end - start) + 1) + start;
}

Particle* ParticleFactory::createRandomParticle(sf::Vector2f position) {
    int randTexture = r(0, textureHolder->size() - 1);
    int randShape = r(0, SHAPE_COUNT - 1);
    int randSize = r(settings::MIN_SIZE, settings::MAX_SIZE);

    int randSpeed = r(1, settings::MAX_SPEED);

    switch (randShape) {
        case ShapeType::Square: {
            auto shape = new RectangleParticle(randSpeed, sf::Vector2f(randSize, randSize));
            shape->setTexture(&textureHolder->get(randTexture));
            shape->setOrigin(sf::Vector2f(randSize / 2, randSize / 2));
            shape->setPosition(position);
            return shape;
        }
        case ShapeType::Circle: {
            auto shape = new CircleParticle(randSpeed, randSize);
            shape->setTexture(&textureHolder->get(randTexture));
            shape->setOrigin(sf::Vector2f(randSize, randSize));
            shape->setPosition(position);
            return shape;
        }
        default:
            return nullptr;
    }
}

Particle* ParticleFactory::createShape(sf::Vector2f position) {
    return createRandomParticle(position);
}

