#include <iostream>
#include <conio.h>
#include <ctime>
#include <SFML/Graphics.hpp>

#include "include/Snake.h"
#include "include/Food.h"
const int TILE_SIZE = 32;
#define WIDTH 20
#define HEIGHT 25

using namespace std;

Snake snake({WIDTH/2, HEIGHT/2}, 1);
Food food;

int score;

int main() {
    sf::RenderWindow window(sf::VideoMode(WIDTH * TILE_SIZE, HEIGHT * TILE_SIZE), "Snake Hunting");
    window.setFramerateLimit(10);
    bool isGameOver = false;

    sf::Font font;
    font.loadFromFile("PlayfulTime-BLBB8.ttf");

    sf::Text gameOverText;
    gameOverText.setFont(font);
    gameOverText.setString("GAME OVER\nPress R to Restart");
    gameOverText.setCharacterSize(40);
    gameOverText.setFillColor(sf::Color::Red);
    gameOverText.setStyle(sf::Text::Bold);
    sf::FloatRect textRect = gameOverText.getLocalBounds();
    gameOverText.setOrigin(textRect.left + textRect.width/2.0f, textRect.top  + textRect.height/2.0f);
    gameOverText.setPosition(sf::Vector2f((WIDTH * TILE_SIZE) / 2.0f, (HEIGHT * TILE_SIZE) / 2.0f));
    sf::Texture headTex, bodyTex, foodTex;
    headTex.loadFromFile("UI/png/snake_green_head_32.png");
    bodyTex.loadFromFile("UI/png/snake_green_blob_32.png");
    foodTex.loadFromFile("UI/png/apple_alt_32.png");

    sf::Sprite sHead(headTex), sBody(bodyTex), sFood(foodTex);

    while (window.isOpen()) {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) window.close();

        if (isGameOver && event.type == sf::Event::KeyPressed) {
            if (event.key.code == sf::Keyboard::R) {
                isGameOver = false;
                score = 0;
                snake = Snake({WIDTH/2, HEIGHT/2}, 1);
                food.gen_food();
            }
        }

        if (!isGameOver && event.type == sf::Event::KeyPressed) {
            if (event.key.code == sf::Keyboard::W) snake.direction('u');
            if (event.key.code == sf::Keyboard::A) snake.direction('l');
            if (event.key.code == sf::Keyboard::S) snake.direction('d');
            if (event.key.code == sf::Keyboard::D) snake.direction('r');
        }
    }

    if (!isGameOver) {
        snake.move_snake();
        if(snake.eaten(food.get_pos())) {
            food.gen_food();
            snake.grow();
            score += 10;
        }
        if(snake.collided()) {
            isGameOver = true;
        }
    }

    window.clear(sf::Color(50, 50, 50));

    if (!isGameOver) {
        COORD fPos = food.get_pos();
        sFood.setPosition(fPos.X * TILE_SIZE, fPos.Y * TILE_SIZE);
        window.draw(sFood);
        vector<COORD> current_body = snake.get_body(); 
        for(int i = 0; i < (int)current_body.size() - 1; i++) {
            sBody.setPosition(current_body[i].X * TILE_SIZE, current_body[i].Y * TILE_SIZE);
            window.draw(sBody);
        }
        COORD hPos = snake.get_pos();
        sHead.setPosition(hPos.X * TILE_SIZE, hPos.Y * TILE_SIZE);
        window.draw(sHead);
    } else {
        window.draw(gameOverText);
    }

    window.display();
}
    return 0;
}