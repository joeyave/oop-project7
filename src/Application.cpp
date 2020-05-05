//
// Created by avelt on 4/26/2020.
//

#include "Application.h"
#include <experimental/filesystem>
#include "effolkronium/random.hpp"
#include <iostream>

using Random = effolkronium::random_static;
using namespace std::literals::chrono_literals;

Application::Application() {
    loadTextures();
    particleFactory = new ParticleFactory(&textureHolder);

    window.create(sf::VideoMode(settings::WINDOW_X, settings::WINDOW_Y),
                  "project 7",
                  sf::Style::Close);
    window.setKeyRepeatEnabled(false);

}

void Application::run() {

    // Thread to spawn random particles.
    threads.emplace_back([this]() {
        createRandomParticles();
    });

    threads.emplace_back([this]() {
        joinParticles();
    });

    threads.emplace_back([this]() {
        moveParticles();
    });

    threads.emplace_back([this]() {
        deleteParticles();
    });

    while (window.isOpen()) {
        processInput();
        render();
    }
}

void Application::processInput() {
    sf::Event event{};
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window.close();

            for (auto& thread : threads) {
                thread.join();
            }
        }
    }
}

void Application::render() {
    window.clear();

    for (Particle* particle : particles) {
        window.draw(*particle);
    }

    window.display();
}

void Application::loadTextures() {

    // Get files from folder first.
    std::map<std::string, std::string> files;
    std::string rootFolder = "media";

    for (auto& folder : std::experimental::filesystem::directory_iterator(rootFolder)) {
        if (!std::experimental::filesystem::is_regular_file(folder)) {
            std::cout << folder.path().filename() << std::endl;
        }
    }
    std::string folderWithTextures;
    std::cin >> folderWithTextures;

    folderWithTextures = rootFolder + "/" + folderWithTextures;

    //	For each file in folder.
    for (auto& p : std::experimental::filesystem::directory_iterator(folderWithTextures)) {
        // Check if not directory, stream, etc.
        if (!std::experimental::filesystem::is_regular_file(p))
            continue;

        std::string name = p.path().filename().string();
        std::string path = p.path().string();

        files.insert(std::make_pair(name, path));
    }

    if (files.empty()) {
        throw "Did not find any textures.\n"
              "Please put at least 1 texture into 'media' folder";
    }

    int counter = 0;
    for (const auto& file : files) {
        std::cout << "Loaded file '" << file.second << "' with ID " << counter << '\n';
        textureHolder.load(counter, file.second);
        counter++;
    }
}

void Application::createRandomParticles() {
    while (window.isOpen()) {
        if (particles.size() < settings::MAX_SPAWN_AMOUNT) {
            mutex.lock();
            auto particle = particleFactory->createRandomParticle();
            particles.push_back(particle);
            mutex.unlock();
        }

        std::this_thread::sleep_for(0.1s);
    }
}

void Application::joinParticles() {
    while (window.isOpen()) {
        mutex.lock();
        for (auto& particle : particles) {
            while (particle && !particle->getTarget()) {
                // Get random element from particles vector.
                auto randomTarget = *Random::get(particles);
                if (randomTarget && randomTarget != particle && !randomTarget->getTarget()) {
                    particle->setParticleTarget(randomTarget);
                    randomTarget->setParticleTarget(particle);
                } else { // There isn't any target to join to jet.
                    break;
                }
            }
        }
        mutex.unlock();
        std::this_thread::sleep_for(3s);
    }
}

void Application::moveParticles() {
    while (window.isOpen()) {
        mutex.lock();
        for (auto& particle : particles) {
            if (particle && particle->getTarget()) {
                particle->moveToTarget();
            }
        }
        mutex.unlock();
    }
}

void Application::deleteParticles() {
    while (window.isOpen()) {
        for (auto& particle : particles) {
            mutex.lock();
            if (particle->getId() == -1) {
                particles.erase(std::remove(particles.begin(),
                                            particles.end(), particle), particles.end());
            }
            mutex.unlock();
        }
    }
}

