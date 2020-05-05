//
// Created by avelt on 5/3/2020.
//

#ifndef PROJECT7_PARTICLE_H
#define PROJECT7_PARTICLE_H


#include <SFML/Graphics.hpp>
#include <random>

class Particle : public sf::Shape {
public:
    Particle();

    explicit Particle(float speed);

    int getWidth();

    int getId() const;

    void setId(int id);

    void setSpeed(float speed);

    Particle* getTarget() const;

    void setParticleTarget(Particle* particleTarget);

    void moveToTarget();

private:
    int id;
    float speed;
    Particle* target;

    static int counter;
};


#endif //PROJECT7_PARTICLE_H
