//
// Created by avelt on 4/26/2020.
//

#include "Application.h"
#include "Constants.h"

Application::Application(Config config) {

    window.create(sf::VideoMode(settings::WINDOW_X, settings::WINDOW_Y),
                  "project 6 (part 1)",
                  sf::Style::Close);

    shapesFactory = config.getShapesFactory();
}

void Application::run() {
    while (window.isOpen()) {
        processInput();
        render();
    }
}

void Application::processInput() {
    sf::Event event{};
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            window.close();

        if (event.type == sf::Event::KeyPressed) {
            if (event.key.code == sf::Keyboard::Q) {
                auto circle = shapesFactory->createCircle();
                auto shape = circle->getPrimaryColorCircle();
                shapes.push_back(shape);
            }
        }
    }
}

void Application::render() {
    window.clear();

    for (auto shape : shapes) {
        window.draw(*shape);
    }

    window.display();
}
