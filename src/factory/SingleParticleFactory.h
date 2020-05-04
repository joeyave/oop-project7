//
// Created by avelt on 5/3/2020.
//

#ifndef PROJECT7_SINGLEPARTICLEFACTORY_H
#define PROJECT7_SINGLEPARTICLEFACTORY_H


#include "ParticleFactory.h"
#include "../TextureHolder.h"

class SingleParticleFactory : public ParticleFactory {
public:
    explicit SingleParticleFactory(TextureHolder<int>* textureHolder);

    std::vector<Particle*> createParticles(int amount, sf::Vector2f where) override;
};


#endif //PROJECT7_SINGLEPARTICLEFACTORY_H
