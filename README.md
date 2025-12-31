# 🐍 Snake Hunting (SFML Version)
A modern take on the classic Snake game developed in C++ using the SFML (Simple and Fast Multimedia Library). This version upgrades the traditional console experience with 2D sprites, fluid movement, and a graphical user interface.

## 🎨 Visual Assets
Sprites: The high-quality 2D snake and food textures are sourced from OpenGameArt.org - Snake Sprites 2D.

Theme: A dark-themed hunting ground with smooth green snake segments and building/apple targets.

## 🛠 Prerequisites
Compiler: GCC/MinGW (32-bit recommended for your current setup).

Library: SFML v2.5.1.

OS: Windows.

## 🚀 Installation & Compilation
1. Project Structure
Ensure your directory looks like this:
```
Snake_Hunting/
├── main.cpp
├── src/
│   ├── Snake.cpp
│   └── Food.cpp
├── include/
│   ├── Snake.h
│   └── Food.h
├── UI/
│   └── png/ (Your sprite files here)
└── SFML-2.5.1/ (Library folder)
```
2. Compilation
Run the following command in your terminal to compile the game. This command links the SFML headers and libraries correctly:

```
g++ main.cpp src/Snake.cpp src/Food.cpp -o main.exe \
-I"C:/Users/Lenovo/Desktop/Snake_Hunting/SFML-2.5.1/include" \
-L"C:/Users/Lenovo/Desktop/Snake_Hunting/SFML-2.5.1/lib" \
-lsfml-graphics -lsfml-window -lsfml-system
```
3. Running the Game
Before launching main.exe, copy the following DLLs from SFML-2.5.1/bin to the folder where your main.exe is located:
```
sfml-graphics-2.dll

sfml-window-2.dll

sfml-system-2.dll
```
🕹 Controls
```
W / Up: Move Up

A / Left: Move Left

S / Down: Move Down

D / Right: Move Right

R: Restart game (after Game Over)
```
## ✨ Key Features
Graphic Rendering: Uses sf::Sprite and sf::Texture for all game objects.

Coordinate Logic: Smooth mapping between the logic grid and pixel-based screen coordinates.

Game Over State: A dedicated game-over screen with a restart mechanic.

Collision Physics: Accurate head-to-body and boundary detection.

## 📜 Credits
Game Logic: Inspired by ProgrammingKnowledge's Snake Tutorial.

Graphics: Snake Sprites 2D by various artists on OpenGameArt.

Library: SFML Team.