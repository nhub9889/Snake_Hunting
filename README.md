# Snake Hunting (Console Version)
A classic Snake game built in C++ specifically for the Windows Console. This project focuses on core game logic, including coordinate management, snake growth, and collision detection without the need for external graphics libraries.

Note: This codebase is inspired by and based on the "Creating Simple Snake Game in C++" tutorial by ProgrammingKnowledge.

## 🎮 Features
Dynamic Growth: The snake grows longer every time it consumes a "building" (food).

Score Tracking: Real-time score updates displayed at the top of the console.

Classic Mechanics: Traditional "Game Over" triggers when the snake's own body.

Flicker-Free Rendering: Optimized console drawing using SetConsoleCursorPosition instead of system("cls").

## 🛠 Prerequisites
Operating System: Windows (uses windows.h for console cursor control).

Compiler: Any C++ compiler (MinGW, Visual Studio, etc.).

Libraries: Standard C++ libraries (iostream, vector, ctime, conio.h).

## ⌨️ Controls
Use the following keys to guide the snake:

W: Move Up

S: Move Down

A: Move Left

D: Move Right

## 🚀 How to Run
You can play by running Snake_Hunting.exe, or by cloning this repository and using the source files.

Ensure you have the include/Snake.h and include/Food.h headers in the correct directory.

Compile the project using your preferred IDE or command line:

Bash

g++ main.cpp src/Snake.cpp src/Food.cpp -I include -o SnakeHunting.exe
Run the generated .exe file.

## 🏗 Project Structure
main.cpp: Contains the game loop, input handling, and rendering logic.

Snake.h / Snake.cpp: Manages snake coordinates, movement, and body growth logic.

Food.h / Food.cpp: Handles random spawning of food (buildings) within the board boundaries.

## 📝 Technical Notes
Coordinate System: The game uses the COORD structure where (WIDTH/2, HEIGHT/2) is the middle of board.

Rendering: Instead of clearing the whole screen every frame (which causes flickering), the cursor is reset to the top-left position after each update.

Macros: WIDTH and HEIGHT are defined as macros for easy board resizing.

🌟 Acknowledgments
Special thanks to the ProgrammingKnowledge YouTube channel for the foundational logic and tutorials on C++ game development.
