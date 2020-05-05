//
// Created by avelt on 4/26/2020.
//

#ifndef PROJECT6_PART1_APPLICATION_H
#define PROJECT6_PART1_APPLICATION_H

#include <SFML/Graphics.hpp>
#include <chrono>
#include <thread>
#include "TextureHolder.h"
#include "factory/ParticleFactory.h"
#include "Constants.h"

class Application {
public:
    Application();

    void run();

private:
    void loadTextures();

    void createRandomParticles();

    void joinParticles();

    void moveParticles();

    void deleteParticles();

    sf::RenderWindow window;
    ParticleFactory* particleFactory{};
    TextureHolder<int> textureHolder;

    std::vector<Particle*> particles;

    std::mutex mutex;
    std::vector<std::thread> threads;

    void render();

    void processInput();
};


#endif //PROJECT6_PART1_APPLICATION_H
