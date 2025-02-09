

# 🐍 Snake Game in C++

This is a classic **Snake Game** built using C++ with basic console graphics. The game provides a user-friendly interface, allowing the player to control a snake, eat food to grow, and avoid obstacles or collisions with walls and its own body. The game features different difficulty levels and high score tracking.

## 📝 Table of Contents

1. [Game Overview](#game-overview)
2. [Features](#features)
3. [Setup Instructions](#setup-instructions)
4. [Game Rules](#game-rules)
5. [OOP Concepts Used](#oop-concepts-used)
6. [Gameplay Instructions](#gameplay-instructions)
7. [Contributing](#contributing)

---

## 🎮 Game Overview

In this Snake game:
- The snake moves in a 2D grid environment.
- The goal is to eat food represented by `*` and grow the snake’s length.
- Players control the snake using arrow keys (or `W`, `A`, `S`, `D`).
- The snake must avoid hitting walls, obstacles, and itself.
- The game has multiple difficulty levels (Easy, Medium, High, and Expert) with varying speeds and obstacle density.

---

## 🌟 Features

- **Boundary Wall:** The snake can’t cross the game boundary.
- **Food Collection:** Eating food grows the snake and increases the score.
- **Obstacles:** Increasing obstacles with higher difficulty levels.
- **High Score Tracking:** Keeps track of the highest score in the current session.
- **Difficulty Levels:** Multiple difficulty levels with varying speed and obstacles.
- **User Input:** Supports keyboard input for controlling the snake.

---

## 🛠️ Setup Instructions

1. **Clone the Repository:**

   To run this game locally, first, clone this repository.

   ```bash
   git clone https://github.com/DhairyaDave08/-Snake-Game-
   cd -Snake-Game-
   ```

2. **Requirements:**
   - C++ Compiler (e.g., `g++` or `clang++`)
   - Windows environment for console-specific functions.

3. **Compile the Code:**
   Run the following command to compile the game:

   ```bash
   g++ snake_game.cpp -o snake_game
   ```

4. **Run the Game:**
   After compiling, you can run the game with:

   ```bash
   ./snake_game
   ```

---

## 📜 Game Rules

1. Use the **W**, **A**, **S**, **D** keys (or the arrow keys) to control the snake:
   - **W / Up Arrow**: Move Up
   - **S / Down Arrow**: Move Down
   - **A / Left Arrow**: Move Left
   - **D / Right Arrow**: Move Right
2. The snake moves continuously in the current direction until you change it.
3. The snake grows longer when it eats food (indicated by `*`).
4. Avoid hitting:
   - **The walls**
   - **The snake's own body**
   - **Obstacles**
5. Each game round gets harder as you level up.
6. The game keeps track of your **current score** and **highest score**.

---

## 🛠️ OOP Concepts Used

### **1. Classes and Objects**
   - **Snake Class**: Handles the snake’s body, direction, and movement. The `Snake` class defines methods for controlling the snake and checking for collisions.
   - **Point Class**: Represents coordinates on the grid (used for snake body, food, and obstacles).

### **2. Encapsulation**
   - The snake’s movement, length, and direction are encapsulated within the `Snake` class. The game’s logic interacts with the class without exposing its internal details.

### **3. Abstraction**
   - The complexity of the snake’s behavior (like collision detection and movement) is abstracted into methods within the `Snake` class, providing a clean interface for interaction in the main game loop.

### **4. Polymorphism**
   - While the game does not fully implement polymorphism, its modular structure allows for future extensions, like adding different types of snakes with varied behaviors using polymorphism.

### **5. Modularity**
   - The game logic is divided into modular functions and classes, making it scalable for future features like adding more power-ups or different obstacles.

---

## 🕹️ Gameplay Instructions

1. **Start Screen**: When the game begins, you'll be prompted to enter your name.
2. **Difficulty Level**: Choose a difficulty level from 1 (Easy) to 4 (Expert).
3. **Movement**: Use arrow keys or `W`, `A`, `S`, `D` to move the snake.
4. **Score**: Your score will be displayed on the top-left. Eating food increases the score.
5. **Game Over**: If the snake hits the wall, its own body, or an obstacle, the game ends.

---

## 🤝 Contributing

Feel free to open issues, fork the repository, and contribute enhancements or fixes. For large changes, please open an issue first to discuss what you would like to change.

---

### License

This project is open-source and available under the [MIT License](LICENSE).

---
