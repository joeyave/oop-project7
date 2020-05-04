//
// Created by avelt on 5/3/2020.
//

#ifndef PROJECT7_SQUAREPARTICLE_H
#define PROJECT7_SQUAREPARTICLE_H


#include "Particle.h"

class SquareParticle : public Particle {
public:
    SquareParticle(ParticleType* type, int speed, sf::Vector2f direction);
};


#endif //PROJECT7_SQUAREPARTICLE_H
