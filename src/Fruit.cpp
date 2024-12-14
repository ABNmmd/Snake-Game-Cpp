#include "Fruit.hpp"

Fruit::Fruit(float radius) {
    fruit.setRadius(radius);
    fruit.setFillColor(sf::Color::Red);
    fruit.setOrigin(radius, radius);
}

void Fruit::spawn(const sf::Vector2u& windowSize) {
    float x = static_cast<float>(rand() % (windowSize.x / 20) * 20);
    float y = static_cast<float>(rand() % (windowSize.y / 20) * 20);
    fruit.setPosition(x, y);
}

sf::CircleShape Fruit::getShape() const {
    return fruit;
}
