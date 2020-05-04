//
// Created by avelt on 4/26/2020.
//

#include "Application.h"
#include "Constants.h"
#include "factory/SingleParticleFactory.h"
#include <experimental/filesystem>
#include <iostream>

const sf::Time Application::timePerFrame = sf::seconds(1.f / 60.f);

Application::Application() {

    window.create(sf::VideoMode(settings::WINDOW_X, settings::WINDOW_Y),
                  "project 6 (part 1)",
                  sf::Style::Close);

    window.setKeyRepeatEnabled(false);
    loadTextures();
    isPaused = false;
}

void Application::run() {
    sf::Clock clockGameLoop;
    sf::Time timeSinceLastUpdate = sf::Time::Zero;

    while (window.isOpen()) {
        sf::Time elapsedTime = clockGameLoop.restart();
        timeSinceLastUpdate += elapsedTime;

        while (timeSinceLastUpdate > timePerFrame) {
            timeSinceLastUpdate -= timePerFrame;
            processInput();

            if (!isPaused) {
                update(timePerFrame);
            }
        }
        render();
    }
}

void Application::processInput() {
    sf::Event event{};
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            window.close();

        if (event.type == sf::Event::MouseButtonPressed) {
            // Get mouse position to world coordinates.
            auto mousePosition = sf::Mouse::getPosition(window);
            sf::Vector2f converted = window.mapPixelToCoords(mousePosition);

            if (event.mouseButton.button == sf::Mouse::Left) {
                particleFactory = new SingleParticleFactory(&textureHolder);
            }

            sf::Sprite sprite(textureHolder.get(2));
            sprites.push_back(sprite);

            std::vector<Particle*> newParticles = particleFactory->createParticles(settings::SPAWN_AMOUNT, converted);
            particles.insert(particles.end(), newParticles.begin(), newParticles.end());
        }

        if (event.type == sf::Event::KeyPressed) {
            if (event.key.code == sf::Keyboard::Space) {
                isPaused = true;

                for (auto particle : particles) {
                    if (!particle->getTarget()) {
                        particle->findTarget(particles);
                        std::cout << particle->getId() << "<->" << particle->getTarget()->getId() << std::endl;
                    }
                }
                for (auto particle : particles) {
                    std::cout << particle->intersectsWith(particles[0]) << std::endl;
                }
            }
        }
    }
}

void Application::render() {
    window.clear();

    for (Particle* particle : particles) {
        window.draw(*particle);
    }
    for (auto& sprite : sprites) {
        window.draw(sprite);
    }

    window.display();
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

void Application::update(sf::Time elapsedTime) {
    for (Particle* particle : particles)
        particle->update(elapsedTime.asSeconds());
}
