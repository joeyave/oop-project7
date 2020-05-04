//
// Created by avelt on 5/3/2020.
//

#ifndef PROJECT7_PARTICLE_H
#define PROJECT7_PARTICLE_H


#include <SFML/Graphics.hpp>
#include <random>
#include "ParticleType.h"

class Particle : public sf::Transformable, public sf::Drawable, public sf::NonCopyable {
public:
    void update(float dt);

    int getWidth();

    bool findTarget(const std::vector<Particle*>& particles);

    int getId() const;

    Particle* getTarget() const;

    void moveToTarget();

    ParticleType* getType() const;

    bool intersectsWith(Particle* particle);
protected:
    Particle(ParticleType* type, int speed, sf::Vector2f direction);

private:
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

    sf::Vector2f normalize(const sf::Vector2f& vector2f);


private:
    int id;
    int speed;
    Particle* target;
    sf::Vector2f direction;

    ParticleType* type;

    static int counter;
};


#endif //PROJECT7_PARTICLE_H
