# Snake Game in C++

## Overview
This is a simple implementation of the classic Snake game developed in C++. The project was created as a mini project for the Object-Oriented Programming (OOP) module. The game features a snake that the player controls to eat fruits, grow in size, and avoid obstacles.

## Features
- **Snake Movement**: The snake can move in four directions (up, down, left, right).
- **Fruit Collection**: The snake grows in size when it collects fruits, and the score increases.
- **Obstacles**: The game includes obstacles that the snake must avoid to prevent game over.
- **Score Management**: The top scores are saved and displayed at the end of the game.
- **Game Over Screen**: A game over screen is displayed when the snake collides with itself or an obstacle, with options to restart or exit.

## Requirements
- C++ Compiler (e.g., g++, clang++)
- SFML (Simple and Fast Multimedia Library) for graphics

## Installation
1. Clone the repository or download the project files.
2. Ensure you have SFML installed on your system.
3. Compile the project using a C++ compiler with SFML linked. For example:
   ```bash
    make
   ```
4. Run the executable:
    ```bash
    bin/main
    ```
## Controls
- **Movement**: Use the arrow keys (↑, ↓, ←, →) to control the snake's direction.
- **Enter**: Start the game or restart after game over.
- **Escape**: Exit the game.

## File Structure
/miniPrg
│
├── src
│   ├── Game.cpp          # Main game logic
│   ├── Snake.cpp         # Snake class implementation
│   ├── Fruit.cpp         # Fruit class implementation
│   ├── Obstacle.cpp      # Obstacle class implementation
│   ├── ScoreManager.cpp   # Score management
│   └── main.cpp          # Entry point of the game
│
└── README.md             # Project documentation

## Acknowledgments
This project was developed as part of the OOP module requirements.

