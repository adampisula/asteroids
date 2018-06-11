#ifndef PROJECTILE_H
#define PROJECTILE_H

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

class Projectile {
private:
  int projectileLength;
  int projectileThickness;
public:
    int x;
    int y;
    double angle;
    sf::ConvexShape shape;

    Projectile(double ang);
    void move();
};

#endif
