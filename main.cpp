#include "eFirework.hpp"

int main() {
  srand(time(NULL));
  sf::RenderWindow window(sf::VideoMode(800, 600), "Firework!");
  sf::Clock clock;
  std::vector<Particle> particles;

  while (window.isOpen()) {
    sf::Event event;
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed) window.close();
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
      int numParticles = 200;
      sf::Vector2f position(400.f, 200.f);

      sf::Color color = sf::Color(
          255.f,
          255.f * static_cast<float>(rand()) / static_cast<float>(RAND_MAX),
          0.f);
      for (int i = 0; i < numParticles; ++i)
        particles.emplace_back(position.x, position.y, color, 175.f, 4.f);
    }

    window.clear(sf::Color::White);
    sf::Time dt = clock.restart();
    for (auto it = particles.begin(); it != particles.end();) {
      (*it).update(dt);
      window.draw(it->shape);
      if (it->shape.getRadius() == 0.f)
        it = particles.erase(it);
      else
        ++it;
    }
    window.display();
  }

  return 0;
}