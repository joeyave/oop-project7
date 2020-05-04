//
// Created by avelt on 4/26/2020.
//

#include "Application.h"
#include "Constants.h"
#include "particles/RectangleParticle.h"
#include "particles/CircleParticle.h"
#include "Utils.h"
#include <experimental/filesystem>
#include <iostream>

Application::Application() {
    window.create(sf::VideoMode(settings::WINDOW_X, settings::WINDOW_Y),
                  "project 7",
                  sf::Style::Close);

    window.setKeyRepeatEnabled(false);

    loadTextures();
    isPaused = false;
}

void Application::run() {
    threads.emplace_back([this]() {
        srand(time(nullptr));
        createRandomParticles();
    });

    threads.emplace_back([this]() {
        joinParticles();
    });

    threads.emplace_back([this]() {
        srand(time(nullptr));
        moveParticles();
    });

    threads.emplace_back([this]() {
        deleteParticles();
    });

    while (window.isOpen()) {
        sf::Event event{};
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                isPaused = true;
                for (auto& thread : threads) {
                    thread.join();
                }
                window.close();
            }
        }

        window.clear();

        for (Particle* particle : particles) {
            window.draw(*particle);
        }

        window.display();
    }
}

void Application::loadTextures() {

    // Get files from folder first.
    std::map<std::string, std::string> files;
    std::string folderPath = "media";

    //	For each file in folder.
    for (auto& p : std::experimental::filesystem::directory_iterator(folderPath)) {
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

            int randTexture = getRand(0, textureHolder.size() - 1);
            int randShape = getRand(0, ParticleFactory::ShapeType::SHAPE_COUNT - 1);
            int randSize = getRand(settings::MIN_SIZE, settings::MAX_SIZE);
            int randSpeed = getRand(1, settings::MAX_SPEED);
            sf::Vector2f position(getRand(0, settings::WINDOW_X), getRand(0, settings::WINDOW_Y));

            Particle* particle;

            if (randShape == ShapeType::Square) {
                particle = new RectangleParticle(randSpeed, sf::Vector2f(randSize, randSize));
                particle->setTexture(&textureHolder.get(randTexture));
                particle->setOrigin(sf::Vector2f(randSize / 2, randSize / 2));
                particle->setPosition(position);
            } else {
                particle = new CircleParticle(randSpeed, randSize);
                particle->setTexture(&textureHolder.get(randTexture));
                particle->setOrigin(sf::Vector2f(randSize, randSize));
                particle->setPosition(position);
            }

            particles.push_back(particle);
            mutex.unlock();
        }

    }

}

void Application::joinParticles() {
    while (window.isOpen()) {
        mutex.lock();

        for (auto& particle : particles) {
            while (particle && !particle->getParticleTarget()) {
                // Get random element from particles vector.
                auto randomTarget = *utils::select_randomly(particles.begin(), particles.end());

                if (randomTarget && randomTarget != particle && !randomTarget->getParticleTarget()) {
                    particle->setParticleTarget(randomTarget);
                    randomTarget->setParticleTarget(particle);
                } else {
                    break;
                }
            }
        }
        mutex.unlock();
    }
}

void Application::moveParticles() {
    while (window.isOpen()) {
        for (auto& particle : particles) {
            if (particle && particle->getParticleTarget()) {
                if (particle->getPosition().x < particle->getParticleTarget()->getPosition().x) {
                    particle->move(0.0001f, 0.0f);
                } else if (particle->getPosition().x > particle->getParticleTarget()->getPosition().x) {
                    particle->move(-0.0001f, 0.0f);
                }
                if (particle->getPosition().y < particle->getParticleTarget()->getPosition().y) {
                    particle->move(0.0f, 0.0001f);
                } else if (particle->getPosition().y > particle->getParticleTarget()->getPosition().y) {
                    particle->move(0.0f, -0.0001f);
                }

                mutex.lock();

                if (particle->getGlobalBounds().intersects(particle->getParticleTarget()->getGlobalBounds())) {
                    particle->setId(-1);
                }
                mutex.unlock();
            }
        }
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

int Application::getRand(int start, int end) {
    return rand() % ((end - start) + 1) + start;
}

