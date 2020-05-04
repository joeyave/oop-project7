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
    enum ShapeType {
        Square,
        Circle,
        SHAPE_COUNT
    };

    Application();

    void run();

private:
    void loadTextures();

    void createRandomParticles();

    void joinParticles();

    void moveParticles();

    void deleteParticles();

    int getRand(int start, int end);

    sf::RenderWindow window;
    ParticleFactory* particleFactory{};
    TextureHolder<int> textureHolder;

    bool isPaused;

    std::vector<Particle*> particles;
    std::vector<Particle*> particlesToDelete;

    std::mutex mutex;

    std::vector<std::thread> threads;
};


#endif //PROJECT6_PART1_APPLICATION_H
