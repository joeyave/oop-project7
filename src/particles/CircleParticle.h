//
// Created by avelt on 5/4/2020.
//

#ifndef PROJECT7_CIRCLEPARTICLE_H
#define PROJECT7_CIRCLEPARTICLE_H


#include <cstddef>
#include <SFML/Graphics.hpp>
#include "Particle.h"

class CircleParticle : public Particle {
public:
    explicit CircleParticle(float radius = 0, std::size_t pointCount = 30);

    CircleParticle(int speed, float radius, size_t pointCount = 30);

    void setRadius(float radius);

    float getRadius() const;

    void setPointCount(std::size_t count);

    std::size_t getPointCount() const override;

    sf::Vector2f getPoint(std::size_t index) const override;

private:
    float radius;
    std::size_t pointCount;
    Particle* target;
};


#endif //PROJECT7_CIRCLEPARTICLE_H
