#include "Obstacle.hpp"

Obstacle::Obstacle() {
    obstacle.setSize(sf::Vector2f(20.f, 20.f));
    obstacle.setFillColor(sf::Color::Yellow);
}

void Obstacle::spawn(const sf::Vector2u& windowSize) {
    float x = static_cast<float>(rand() % (windowSize.x / 20) * 20);
    float y = static_cast<float>(rand() % (windowSize.y / 20) * 20);
    obstacle.setPosition(x, y);
}

sf::RectangleShape Obstacle::getShape() const {
    return obstacle;
}
