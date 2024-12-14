#ifndef FRUIT_HPP
#define FRUIT_HPP

#include <SFML/Graphics.hpp>

class Fruit {
private:
    sf::CircleShape fruit;

public:
    Fruit(float radius);
    void spawn(const sf::Vector2u& windowSize);
    sf::CircleShape getShape() const;
};

#endif
