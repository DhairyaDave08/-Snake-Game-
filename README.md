
# 🐍 Snake Game in C++

This is a classic *Snake Game* built using C++ with basic console graphics. The game provides a user-friendly interface, allowing the player to control a snake, eat food to grow, and avoid obstacles or collisions with walls and its own body. The game features different difficulty levels and high score tracking.

## 📝 Table of Contents

1. [Game Overview](#game-overview)
2. [Features](#features)
3. [Setup Instructions](#setup-instructions)
4. [Game Rules](#game-rules)
5. [OOP Concepts Used](#oop-concepts-used)
6. [Data Structures Used](#data-structures-used)
7. [Gameplay Instructions](#gameplay-instructions)
8. [Licence](#License)

---

## 🎮 Game Overview

In this Snake game:
- The snake moves in a **2D grid environment**.
- The goal is to **eat food** (represented by `+`) and grow the snake’s length.
- Players control the snake using **arrow keys** (or **W, A, S, D**).
- The snake must avoid hitting:
  - **Walls**
  - **Obstacles**
  - **Its own body**
- The game offers multiple **difficulty levels** (Easy, Medium, High, Expert) with varying speeds and obstacle density.

---

## 🌟 Features

- **Boundary Wall:** The snake can’t cross the game boundary.
- **Food Collection:** Eating food grows the snake and increases the score.
- **Obstacles:** Increasing obstacles with higher difficulty levels.
- **High Score Tracking:** Keeps track of the highest score in the current session.
- **Difficulty Levels:** Multiple difficulty levels with varying speed and obstacles.
- **User Input:** Supports keyboard input for controlling the snake.

---

## 🛠 Setup Instructions

1. **Clone the Repository:**

   To run this game locally, first, clone this repository.

   ```bash
   git clone https://github.com/DhairyaDave08/Snake-Game
   cd Snake-Game
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

1. Use the **W, A, S, D** keys (or the arrow keys) to control the snake:
   - **W / Up Arrow**: Move Up
   - **S / Down Arrow**: Move Down
   - **A / Left Arrow**: Move Left
   - **D / Right Arrow**: Move Right
2. The snake moves continuously in the current direction until you change it.
3. The snake grows longer when it eats food (indicated by `+`).
4. Avoid hitting:
   - **The walls**
   - **The snake's own body**
   - **Obstacles**
5. Each game round gets harder as you level up.
6. The game keeps track of your **current score** and **highest score**.

---

## 🛠 OOP Concepts Used

### 1. **Classes and Objects**: 
   - The `Snake` class encapsulates the snake’s attributes (body, length, direction) and behaviors (moving, changing direction, eating food).

### 2. **Encapsulation**: 
   - The internal state (snake's body and direction) is hidden within the `Snake` class, with public methods (`move()`, `changeDirection()`, etc.) to interact with it.

### 3. **Abstraction**: 
   - The complex logic of moving the snake and handling collisions is abstracted away, allowing the game loop to focus on high-level functionality.


---

## Data Structures Used
The game utilizes several data structures to manage the game state, including:

1. **Point Struct**: 
   - Represents a 2D coordinate (`x`, `y`) on the screen. Used for the snake's body, food, and obstacles.

2. **Array of Points**: 
   - The snake's body is represented as an array of `Point` structures. The array grows as the snake eats food.

3. **Vector of Points**: 
   - Obstacles are stored dynamically in a `vector` of `Point` structures. Obstacles are generated randomly within the console window.

4. **Class Snake**: 
   - Manages the snake's movement, length, and direction. It also handles collision detection with walls, itself, and obstacles.

5. **Input Handling**: 
   - The `_kbhit()` and `_getch()` functions (from `<conio.h>`) are used to detect player input for controlling the snake's direction.



---

## 🕹 Gameplay Instructions

1. **Start Screen**: When the game begins, you'll be prompted to enter your name.
2. **Difficulty Level**: Choose a difficulty level from 1 (Easy) to 4 (Expert).
3. **Movement**: Use arrow keys or **W, A, S, D** to move the snake.
4. **Score**: Your score will be displayed on the top-left. Eating food increases the score.
5. **Game Over**: If the snake hits the wall, its own body, or an obstacle, the game ends.

---

## License

This project is open-source and available under the [MIT License](LICENSE).



