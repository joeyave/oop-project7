//
// Created by avelt on 4/26/2020.
//

#ifndef PROJECT6_PART1_APPLICATION_H
#define PROJECT6_PART1_APPLICATION_H

#include <SFML/Graphics.hpp>
#include "shapes/factory/ShapesFactory.h"
#include "Config.h"

class Application {
public:
    Application(Config config);

    void run();

private:
    void processInput();

    void render();

    sf::RenderWindow window;
    ShapesFactory* shapesFactory;

    std::vector<sf::Shape*> shapes;
};


#endif //PROJECT6_PART1_APPLICATION_H
