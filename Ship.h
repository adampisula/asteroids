#ifndef SHIP_H
#define SHIP_H

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

class Ship {
public:
    int x;
    int y;
    __int64_t lastProjectile;
    double angle;
    sf::ConvexShape shape;

    Ship(int posX, int posY);
    double rotate(sf::Vector2i mousePos);
    void move(int direction);
    void shoot();
};

#endif
