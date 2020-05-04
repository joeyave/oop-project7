//
// Created by avelt on 5/4/2020.
//

#ifndef PROJECT7_RECTANGLEPARTICLE_H
#define PROJECT7_RECTANGLEPARTICLE_H


#include "Particle.h"

class RectangleParticle : public Particle {
public:
    explicit RectangleParticle(const sf::Vector2f& size = sf::Vector2f(0, 0));

    RectangleParticle(int speed, const sf::Vector2f& size);

    void setSize(const sf::Vector2f& size);

    const sf::Vector2f& getSize() const;

    std::size_t getPointCount() const override;

    sf::Vector2f getPoint(std::size_t index) const override;

private:
    sf::Vector2f size;
    Particle* target;
};


#endif //PROJECT7_RECTANGLEPARTICLE_H
