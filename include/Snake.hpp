#ifndef SNAKE_HPP
#define SNAKE_HPP

#include <SFML/Graphics.hpp>
#include <vector>

class Snake {
private:
    float blockSize; // Declared first to match the initializer list order
    sf::Vector2f direction;
    std::vector<sf::RectangleShape> body;

public:
    Snake(float blockSize);
    void move();
    void grow();
    void setDirection(const sf::Vector2f& newDirection);
    bool checkSelfCollision() const;
    sf::RectangleShape getHead() const;
    std::vector<sf::RectangleShape>& getBody();

    static const sf::Vector2f UP;
    static const sf::Vector2f DOWN;
    static const sf::Vector2f LEFT;
    static const sf::Vector2f RIGHT;
};

#endif
