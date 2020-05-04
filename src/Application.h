//
// Created by avelt on 4/26/2020.
//

#ifndef PROJECT6_PART1_APPLICATION_H
#define PROJECT6_PART1_APPLICATION_H

#include <SFML/Graphics.hpp>
#include "TextureHolder.h"
#include "factory/ParticleFactory.h"

class Application {
public:
    Application();

    void run();

private:
    void processInput();

    void render();

    void loadTextures();

    void update(sf::Time elapsedTime);

    static const sf::Time timePerFrame;

    sf::RenderWindow window;
    ParticleFactory* particleFactory;
    TextureHolder<int> textureHolder;

    bool isPaused;

    std::vector<Particle*> particles;
    std::vector<sf::Sprite> sprites;
};


#endif //PROJECT6_PART1_APPLICATION_H
