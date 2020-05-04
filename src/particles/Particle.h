//
// Created by avelt on 5/3/2020.
//

#ifndef PROJECT7_PARTICLE_H
#define PROJECT7_PARTICLE_H


#include <SFML/Graphics.hpp>
#include <random>

class Particle : public sf::Shape {
public:
    explicit Particle(int speed);

    int getWidth();

    int getId() const;

    void setDirection(const sf::Vector2f& direction);

    void setSpeed(int speed);

    Particle* getParticleTarget() const;

    void setParticleTarget(Particle* particleTarget);

    void setId(int id);

protected:
    Particle();

    Particle(int speed, sf::Vector2f direction);

private:

    sf::Vector2f normalize(const sf::Vector2f& vector2f);


private:
    int id;
    int speed;
    sf::Vector2f direction;
    Particle* particleTarget;

    static int counter;
};


#endif //PROJECT7_PARTICLE_H
