//
// Created by avelt on 5/3/2020.
//

#ifndef PROJECT7_CIRCLEPARTICLE_H
#define PROJECT7_CIRCLEPARTICLE_H


#include "Particle.h"

class CircleParticle : public Particle
{
public:
    CircleParticle(ParticleType* type, int speed, sf::Vector2f direction);
};


#endif //PROJECT7_CIRCLEPARTICLE_H
