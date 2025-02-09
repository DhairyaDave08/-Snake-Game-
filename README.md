🐍 Snake Game
Welcome to the Snake Game! This is a C++ console-based game for Windows users. Your mission is to guide the snake to eat food and grow, all while avoiding obstacles and walls.

📌 Features
Smooth Movement: Use W, A, S, D for directional control.
Scoring System: Earn 100 points per food item eaten.
Difficulty Levels: Choose from Easy, Medium, Hard, or Expert.
Obstacles: Increasing obstacles with higher difficulty.
Colorful Console Output: Enjoy vibrant colors with ANSI escape sequences.
Dynamic Terminal Support: Adjusts to your terminal size.
Windows Compatibility: Built with conio.h and windows.h for Windows users.
📥 Installation Guide
Prerequisites:
Ensure you have a C++ compiler (e.g., MinGW, MSVC) installed.

Steps to Install:
Clone the repository:

bash
Copy
Edit
git clone https://github.com/YourUsername/Snake_Game.git
Navigate to the project directory:

bash
Copy
Edit
cd Snake_Game
Compile the game:

bash
Copy
Edit
g++ Snake_Game.cpp -o Snake_Game.exe -static-libstdc++ -static-libgcc
Run the game:

bash
Copy
Edit
Snake_Game.exe
🎮 How to Play
Enter your player name at the beginning.
Choose a difficulty level:
1: Easy
2: Medium
3: Hard
4: Expert
Control the snake using W, A, S, D.
Eat food (*) to grow the snake and increase your score.
Avoid colliding with the walls or your own body.
Check your score at the top.
After a game over, you can choose to restart or quit.
🛠️ Technical Details
Data Structures:
Point Class: Stores x and y coordinates of snake, food, and obstacles.
Snake Class: Handles the snake's movement and growth.
Input Handling: Uses conio.h for real-time input handling.
🤝 Contributing
We welcome contributions! Here’s how you can contribute:

Fork the repository.
Create a new branch for your feature.
Commit your changes.
Push your branch to the repository.
Open a pull request.
📜 License
This project is licensed under the MIT License.

📌 Reference
Check out the project on GitHub
