//
// Created by avelt on 5/3/2020.
//

#ifndef PROJECT7_PARTICLETYPE_H
#define PROJECT7_PARTICLETYPE_H

#include <SFML/Graphics.hpp>

class ParticleType : sf::Drawable {
public:
    enum ShapeType {
        Square,
        Circle,
        SHAPE_COUNT
    };

public:
    ParticleType(ShapeType shapeType, int size, sf::Texture& texture);

private:
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

private:
    // Share private data only with Particle class.
    friend class Particle;

    sf::Shape* shape;
};


#endif //PROJECT7_PARTICLETYPE_H
