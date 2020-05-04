//
// Created by avelt on 5/3/2020.
//

#include "ParticleType.h"

ParticleType::ParticleType(ShapeType shapeType, int size, sf::Texture& texture) {
    if (shapeType == Square) {
        shape = new sf::RectangleShape(sf::Vector2f(size, size));
        shape->setTexture(&texture);
    } else if (shapeType == Circle) {
        shape = new sf::CircleShape((float) size);
        shape->setTexture(&texture);
    }
}

void ParticleType::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(*shape, states);
}
