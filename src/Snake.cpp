#include "Snake.hpp"
#include <iostream>

// Define the direction constants
const sf::Vector2f Snake::UP(0, -20); // Move up
const sf::Vector2f Snake::DOWN(0, 20); // Move down
const sf::Vector2f Snake::LEFT(-20, 0); // Move left
const sf::Vector2f Snake::RIGHT(20, 0); // Move right

Snake::Snake(float blockSize) : blockSize(blockSize), direction(RIGHT) {
    sf::RectangleShape segment(sf::Vector2f(blockSize, blockSize));
    segment.setFillColor(sf::Color::Blue);
    segment.setPosition(100.f, 100.f); // Initial position
    body.push_back(segment);
}

void Snake::move() {
    for (size_t i = body.size() - 1; i > 0; --i) {
        body[i].setPosition(body[i - 1].getPosition());
    }
    
    body[0].move(direction.x, direction.y);
}

void Snake::grow() {
    sf::RectangleShape segment(sf::Vector2f(blockSize, blockSize));
    segment.setFillColor(sf::Color::Blue);
    
    // Position it at the last segment's position
    segment.setPosition(body.back().getPosition());
    
    // Offset the new segment slightly to avoid overlap
    if (direction.x > 0) { // Moving right
        segment.move(-blockSize, 0);
    } else if (direction.x < 0) { // Moving left
        segment.move(blockSize, 0);
    } else if (direction.y > 0) { // Moving down
        segment.move(0, -blockSize);
    } else if (direction.y < 0) { // Moving up
        segment.move(0, blockSize);
    }
    
    body.push_back(segment);
}

void Snake::setDirection(const sf::Vector2f& newDirection) {
    if ((newDirection.x != 0 && direction.x != 0) || (newDirection.y != 0 && direction.y != 0)) {
        return;
    }
    direction = newDirection;
    std::cout << "Direction changed to: " << direction.x << ", " << direction.y << std::endl;
}

bool Snake::checkSelfCollision() const {
    sf::FloatRect headBounds = body[0].getGlobalBounds();
    for (size_t i = 1; i < body.size(); ++i) {
        if (headBounds.intersects(body[i].getGlobalBounds())) {
            return true;
        }
    }
    return false;
}

sf::RectangleShape Snake::getHead() const {
    return body[0];
}

std::vector<sf::RectangleShape>& Snake::getBody() {
    return body;
}
