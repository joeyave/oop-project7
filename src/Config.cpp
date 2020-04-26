//
// Created by avelt on 4/26/2020.
//

#include "Config.h"

void Config::chooseColorTheme() {
    std::cout << "Choose color theme: " << std::endl;
    std::cout << "1. Pastel." << std::endl;
    std::cout << "2. Neon." << std::endl;

    while (true) {
        std::string answer;
        std::cin >> answer;

        if (answer[0] == '1') {
            shapesFactory = new PastelShapesFactory();
            break;
        } else if (answer[0] == '2') {
            shapesFactory = new NeonShapesFactory();
            break;
        } else {
            std::cout << "Try again." << std::endl;
        }
    }
}

ShapesFactory* Config::getShapesFactory() const {
    return shapesFactory;
}

void Config::setShapesFactory(ShapesFactory* shapesFactory) {
    Config::shapesFactory = shapesFactory;
}
