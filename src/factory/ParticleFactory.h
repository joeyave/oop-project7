//
// Created by avelt on 5/3/2020.
//

#ifndef PROJECT7_PARTICLEFACTORY_H
#define PROJECT7_PARTICLEFACTORY_H


#include "../particles/Particle.h"
#include "../TextureHolder.h"

class ParticleFactory {
public:
    enum ShapeType {
        Square,
        Circle,
        SHAPE_COUNT
    };

    explicit ParticleFactory(TextureHolder<int>* textureHolder);

    Particle* createShape(sf::Vector2f position);

protected:
    Particle* createRandomParticle(sf::Vector2f position);

    static int r(int lowest, int highest);

    TextureHolder<int>* textureHolder;
};


#endif //PROJECT7_PARTICLEFACTORY_H
