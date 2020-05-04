//
// Created by avelt on 5/3/2020.
//

#ifndef PROJECT7_PARTICLEFACTORY_H
#define PROJECT7_PARTICLEFACTORY_H


#include "../Particle.h"
#include "../TextureHolder.h"

class ParticleFactory {
public:
    enum ShapeType {
        Square,
        Circle,
        SHAPE_COUNT
    };

    virtual std::vector<Particle*> createParticles(int amount, sf::Vector2f where) = 0;

protected:
    explicit ParticleFactory(TextureHolder<int>* textureHolder);

    Particle* createRandomParticle(sf::Vector2f position);

    sf::Shape* createRandomSprite(sf::Vector2f position);

    static int getRand(int lowest, int highest);

private:
    Particle* createNewParticle(ParticleType::ShapeType shape, ParticleType* type, int speed, sf::Vector2f direction);
    sf::Shape* createNewParticle(ShapeType shape, int speed, sf::Vector2f direction);

protected:
    TextureHolder<int>* textureHolder;
};


#endif //PROJECT7_PARTICLEFACTORY_H
