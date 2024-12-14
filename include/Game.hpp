#ifndef GAME_HPP
#define GAME_HPP

#include <SFML/Graphics.hpp>
#include "Snake.hpp"
#include "Fruit.hpp"
#include "Obstacle.hpp"
#include "ScoreManager.hpp"
#include <vector>

class Game {
private:
    sf::RenderWindow window;
    Snake snake;
    Fruit fruit;
    std::vector<Obstacle> obstacles;
    ScoreManager scoreManager;
    int score;
    bool gameStarted;
    bool gameOver;

public:
    Game();
    void run();
    void update();
    void render();
    void handleInput();
    void checkCollisions();
};

#endif
