#include "Ship.h"
#include <math.h>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>

#define PI 3.14159265

Ship::Ship(int posX, int posY) {
    //SHIP SHAPE
    int shipSize = 20;
    sf::Color color = sf::Color::White;

    int a = 0.643 * shipSize / 2;
    int b = 0.77 * shipSize / 2;

    shape.setPointCount(4);

    shape.setPoint(0, sf::Vector2f(b - b, 0 - (shipSize + a) / 2));
    shape.setPoint(1, sf::Vector2f(2 * b - b, shipSize + a - (shipSize + a) / 2));
    shape.setPoint(2, sf::Vector2f(b - b, shipSize - (shipSize + a) / 2));
    shape.setPoint(3, sf::Vector2f(0 - b, shipSize + a - (shipSize + a) / 2));

    shape.setFillColor(color);

    x = posX - b;
    y = posY - shipSize;

    shape.setPosition(x, y);
}

double Ship::rotate(sf::Vector2i mousePos) {
    double degrees;

    if(mousePos.x - x < 0 && mousePos.y - y < 0)
        degrees = atan((float) abs(mousePos.y - y) / (float) abs(mousePos.x - x)) * 180 / PI + 270;

    else if(mousePos.x - x > 0 && mousePos.y - y > 0)
        degrees = atan((float) abs(mousePos.y - y) / (float) abs(mousePos.x - x)) * 180 / PI + 90;

    else if(mousePos.x - x < 0 && mousePos.y - y > 0)
        degrees = atan((float) abs(mousePos.x - x) / (float) abs(mousePos.y - y)) * 180 / PI + 180;

    else if(mousePos.x - x > 0 && mousePos.y - y < 0)
        degrees = atan((float) abs(mousePos.x - x) / (float) abs(mousePos.y - y)) * 180 / PI;

    return degrees;
}

void Ship::move(int direction) {
    std::cout << "Move: " << direction << std::endl;

    if(direction == -3)
        x -= 1;
    else if(direction == -1)
        y -= 1;
    else if(direction == 1)
        y += 1;
    else if(direction == 3)
        x += 1;
    else if(direction == -4) {
        x -= 1;
        y -= 1;
    }
    else if(direction == -2) {
        x -= 1;
        y += 1;
    }
    else if(direction == 2) {
        x += 1;
        y -= 1;
    }
    else if(direction == 4) {
        x += 1;
        y += 1;
    }

    shape.setPosition(x, y);
}
