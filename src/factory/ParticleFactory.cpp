//
// Created by avelt on 5/3/2020.
//

#include "ParticleFactory.h"
#include "../SquareParticle.h"
#include "../CircleParticle.h"
#include "../Constants.h"

ParticleFactory::ParticleFactory(TextureHolder<int>* textureHolder) {
    this->textureHolder = textureHolder;
    srand(time(nullptr));
}

Particle* ParticleFactory::createNewParticle(ParticleType::ShapeType shape, ParticleType* type, int speed,
                                             sf::Vector2f direction) {
    switch (shape) {
        case ParticleType::ShapeType::Square:
            return new SquareParticle(type, speed, direction);
        case ParticleType::ShapeType::Circle:
            return new CircleParticle(type, speed, direction);
        default:
            return nullptr;
    }
}

Particle* ParticleFactory::createRandomParticle(sf::Vector2f position) {
    int randSpeed = getRand(settings::MIN_SPEED, settings::MAX_SPEED);
    int randDirectionX = getRand(0, 1000);
    if (randDirectionX < 500) {
        randDirectionX *= -1;
    }

    int randDirectionY = getRand(0, 1000);
    if (randDirectionY < 500) {
        randDirectionY *= -1;
    }

    int randSize = getRand(settings::MIN_SIZE, settings::MAX_SIZE);
    int randTexture = getRand(0, textureHolder->size() - 1);
    int randShape = getRand(0, ParticleType::SHAPE_COUNT - 1);

    auto particleType = new ParticleType(ParticleType::ShapeType(randShape), randSize,
                                    textureHolder->get(randTexture));
    auto particle = createNewParticle(ParticleType::ShapeType(randShape), particleType, randSpeed,
                                 sf::Vector2f(randDirectionX, randDirectionY));
    particle->setPosition(position);

    return particle;
}

// TODO: change rand library.
int ParticleFactory::getRand(int start, int end) {
    return rand() % ((end - start) + 1) + start;
}

sf::Shape* ParticleFactory::createRandomSprite(sf::Vector2f position) {
    // Generate random params.
    int randSpeed = getRand(settings::MIN_SPEED, settings::MAX_SPEED);
    int randDirectionX = getRand(0, 1000);
    if (randDirectionX < 500) {
        randDirectionX *= -1;
    }

    int randDirectionY = getRand(0, 1000);
    if (randDirectionY < 500) {
        randDirectionY *= -1;
    }

    int randSize = getRand(settings::MIN_SIZE, settings::MAX_SIZE);
    int randTexture = getRand(0, textureHolder->size() - 1);
    int randShape = getRand(0, ParticleType::SHAPE_COUNT - 1);

    sf::RectangleShape sprite;
    sprite.setTexture(textureHolder->get(randTexture));

    sprite.setPosition(position);
}

sf::Shape* ParticleFactory::createNewParticle(ParticleFactory::ShapeType shape, int speed,
                                              sf::Vector2f direction) {
    switch (shape) {
        case ShapeType::Square:
            return new SquareParticle(type, speed, direction);
        case ParticleType::ShapeType::Circle:
            return new CircleParticle(type, speed, direction);
        default:
            return nullptr;
    }
}
