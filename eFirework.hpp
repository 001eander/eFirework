#ifndef EFIREWORK_HPP
#define EFIREWORK_HPP

#include <SFML/Graphics.hpp>
#include <cmath>
#include <cstdlib>
#include <vector>

class Particle {
 public:
  sf::CircleShape shape;
  sf::Vector2f velocity;
  sf::Vector2f acceleration;
  float lifeTime;

  Particle(float x, float y, sf::Color color, float speed, float lifetime) {
    shape.setRadius(3.f);
    shape.setFillColor(color);
    shape.setPosition(x, y);
    double theta =
        2 * M_PI * static_cast<float>(rand()) / static_cast<float>(RAND_MAX);
    speed *=
        1 - pow(static_cast<float>(rand()) / static_cast<float>(RAND_MAX), 0.7);
    velocity = sf::Vector2f(speed * cos(theta), speed * sin(theta));
    acceleration = sf::Vector2f(0.f, 100.f);
    lifeTime = lifetime;
  }

  void update(sf::Time deltaTime) {
    velocity += acceleration * deltaTime.asSeconds();
    sf::Vector2f displacement(velocity * deltaTime.asSeconds());
    shape.move(displacement);
    lifeTime -= deltaTime.asSeconds();
    if (lifeTime <= 0.f) shape.setRadius(0.f);
  }
};

#endif