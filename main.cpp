#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "Ship.h"

int main() {
    const int width = 850;
    const int height = 500;
    int mouseX = 0, mouseY = 0;
    double angle = 0;

    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;

    sf::RenderWindow window(sf::VideoMode(width, height), "SFML", sf::Style::Titlebar | sf::Style::Close, settings);

    Ship ship(width / 2, height / 2);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color(14, 0, 36));

        window.draw(ship.shape);

        window.display();

        //MOUSE
        if(sf::Mouse::getPosition(window).x != mouseX || sf::Mouse::getPosition(window).y != mouseY) {
            if((sf::Mouse::getPosition(window).x >= 0 && sf::Mouse::getPosition(window).x <= width) && (sf::Mouse::getPosition(window).y >= 0 && sf::Mouse::getPosition(window).y <= height)) {
                mouseX = sf::Mouse::getPosition(window).x;
                mouseY = sf::Mouse::getPosition(window).y;

                ship.shape.setRotation(angle);

                if(ship.rotate(sf::Mouse::getPosition(window)) > 0.01)
                    angle = ship.rotate(sf::Mouse::getPosition(window));
            }
        }

        //KEYS
        int direction = 0;

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
            direction += -3;

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
            direction += 3;

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
            direction += -1;

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
            direction += 1;

        ship.move(direction);
    }

    return 0;
}
