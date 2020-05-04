#include "src/Application.h"

int main() {

    Application application;
    application.run();

//    sf::RenderWindow renderWindow(sf::VideoMode(640, 480), "Demo Game");
//
//    sf::Event event;
//
//    sf::Texture texture;
//    texture.loadFromFile("media/emerald.png");
//
//    sf::Sprite sprite(texture);
//
//    while (renderWindow.isOpen()) {
//        while (renderWindow.pollEvent(event)) {
//            if (event.type == sf::Event::EventType::Closed)
//                renderWindow.close();
//        }
//
//        renderWindow.clear();
//        renderWindow.draw(sprite);
//        renderWindow.display();
//    }
}
