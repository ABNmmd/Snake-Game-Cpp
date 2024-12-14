#include "Game.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <filesystem>
#include <SFML/Graphics.hpp>

Game::Game() : window(sf::VideoMode(800, 600), "Snake Game"), snake(20), fruit(10), score(0), gameStarted(false), gameOver(false)
{
    srand(static_cast<unsigned>(time(nullptr)));
    fruit.spawn(window.getSize());
    obstacles.emplace_back();
    obstacles.emplace_back();
    obstacles[0].spawn(window.getSize());
    obstacles[1].spawn(window.getSize());

    scoreManager.loadScores();
}

void Game::run()
{
    sf::Clock clock;
    const float snakeSpeed = 0.12f;

    while (window.isOpen())
    {
        handleInput();

        if (gameOver)
        {
            // Handle game over state
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
            {
                // Restart the game
                score = 0;
                gameStarted = false;
                gameOver = false;
                snake = Snake(20);
                fruit.spawn(window.getSize());
                obstacles.clear();
                obstacles.emplace_back();
                obstacles.emplace_back();
                obstacles[0].spawn(window.getSize());
                obstacles[1].spawn(window.getSize());
            }
        }
        else
        {
            if (gameStarted && clock.getElapsedTime().asSeconds() >= snakeSpeed)
            {
                update();
                clock.restart(); // Reset the clock
            }
        }

        render();
    }
}

void Game::handleInput()
{
    sf::Event event;
    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            window.close();
    }

    if (!gameStarted && sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
    {
        gameStarted = true;
        snake.setDirection({20, 0});
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
    {
        window.close();
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && snake.getHead().getPosition().y > 0)
        snake.setDirection(Snake::UP);
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        snake.setDirection(Snake::DOWN);
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        snake.setDirection(Snake::LEFT);
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        snake.setDirection(Snake::RIGHT);
}

void Game::update()
{
    snake.move();

    sf::Vector2f headPosition = snake.getHead().getPosition();

    if (headPosition.x < 0)
    {
        headPosition.x = window.getSize().x - 20; // Wrap to the right
    }
    else if (headPosition.x >= window.getSize().x)
    {
        headPosition.x = 0; // Wrap to the left
    }

    if (headPosition.y < 0)
    {
        headPosition.y = window.getSize().y - 20; // Wrap to the bottom
    }
    else if (headPosition.y >= window.getSize().y)
    {
        headPosition.y = 0; // Wrap to the top
    }

    snake.getBody()[0].setPosition(headPosition);

    checkCollisions();
}

void Game::checkCollisions()
{
    // Check collision with fruit
    if (snake.getHead().getGlobalBounds().intersects(fruit.getShape().getGlobalBounds()))
    {
        fruit.spawn(window.getSize());
        snake.grow();
        score += 10;

        for (auto &obstacle : obstacles)
        {
            obstacle.spawn(window.getSize());
        }
    }

    if (snake.checkSelfCollision())
    {
        scoreManager.addScore(score);
        gameOver = true;
        return;
    }

    // Check collision with obstacles
    for (const auto &obstacle : obstacles)
    {
        if (snake.getHead().getGlobalBounds().intersects(obstacle.getShape().getGlobalBounds()))
        {
            scoreManager.addScore(score);
            gameOver = true;
            return;
        }
    }
}

void Game::render()
{
    window.clear();
    
    for (const auto &segment : snake.getBody())
    {
        window.draw(segment);
    }

    window.draw(fruit.getShape());

    for (const auto &obstacle : obstacles)
    {
        window.draw(obstacle.getShape());
    }

    sf::Font font;
    font.loadFromFile("assets/Font/Lato-Regular.ttf");

    sf::Text scoreCnt("Score:\t" + std::to_string(score), font, 20);
    scoreCnt.setFillColor(sf::Color::White);
    scoreCnt.setPosition(10, 10);
    window.draw(scoreCnt);

    if (gameOver)
    {
        window.clear();
        // Display game over message
        sf::Text gameOverText("\t\t\tGame Over!\n\nPress Enter to Restart\nPress Escape to Close", font, 32);
        gameOverText.setFillColor(sf::Color::White);
        gameOverText.setPosition(250, 400);
        window.draw(gameOverText);

        // Display top scores
        sf::Text scoreText("Top Scores:", font, 20);
        scoreText.setFillColor(sf::Color::White);
        scoreText.setPosition(15, 15);
        window.draw(scoreText);

        std::vector<int> topScores = scoreManager.getTopScores(5); // Get top 5 scores
        for (size_t i = 0; i < topScores.size(); ++i)
        {
            sf::Text scoreLine(std::to_string(i + 1) + "-\t" + std::to_string(topScores[i]), font, 20);
            scoreLine.setFillColor(sf::Color::White);
            scoreLine.setPosition(20, 45 + i * 30); // Adjust position for each score
            window.draw(scoreLine);
        }

    }

    window.display();
}
