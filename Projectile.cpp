#include "Projectile.h"
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>

Projectile::Projectile(double ang, int x, int y) { /////////////////
      angle = ang;

    shape.setPointCount(2);

    shape.setPoint(0, sf::Vector2f(0, 0 - projectileLength / 2));
    shape.setPoint(1, sf::Vector2f(projectileThickness, 0 - projectileLength / 2));
    shape.setPoint(2, sf::Vector2f(0, projectileLength / 2));
    shape.setPoint(3, sf::Vector2f(projectileThickness, projectileLength / 2));

    shape.setFillColor(sf::Color::White);

    shape.setRotation(angle);

    ship.setPosition();
}

void Projectile::move() {

}
