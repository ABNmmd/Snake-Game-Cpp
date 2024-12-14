#ifndef OBSTACLE_HPP
#define OBSTACLE_HPP

#include <SFML/Graphics.hpp>

class Obstacle {
private:
    sf::RectangleShape obstacle;

public:
    Obstacle();
    void spawn(const sf::Vector2u& windowSize);
    sf::RectangleShape getShape() const;
};

#endif
