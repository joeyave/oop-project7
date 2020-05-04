//
// Created by avelt on 5/3/2020.
//

#include "SingleParticleFactory.h"

SingleParticleFactory::SingleParticleFactory(TextureHolder<int>* textureHolder)
        : ParticleFactory{textureHolder} {
}

std::vector<Particle*> SingleParticleFactory::createParticles(int amount, sf::Vector2f where) {
    std::vector<Particle*> particles;
    Particle* particle;

    for (int i = 0; i < amount; i++) {
        particle = createRandomParticle(where);
        particles.push_back(particle);
    }


    return particles;
}