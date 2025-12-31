#include <iostream>
#include <cstdlib>
#include <ctime>
#include "include/Snake.h"
#include "include/Food.h"
#include "conio.h"

#define sq(x) x*x
#define WIDTH 150
#define HEIGHT 100

using namespace std;

Snake snake({WIDTH/2, HEIGHT/2}, 1);
Food food;
int x = 10, y = 10;
int score = 0;
void board(){
    COORD snake_pos = snake.get_pos();
    COORD food_pos = food.get_pos();
    vector<COORD> snake_body = snake.get_body();
    cout << "SCORE: " << score << "\n\n";
    for (int i = 0; i < HEIGHT; i++){
        cout << "\t\t#";
        for (int j = 0; j < WIDTH; j++){
            if (i == 0 || i == HEIGHT-1) cout << '#';
            else if (i == snake_pos.Y && j == snake_pos.X) cout << '0';
            else if (i == food_pos.Y && j == food_pos.X) cout <<'*';
            else{
                bool isBodyPart = false;
                for (int k = 0; i < snake_body.size() - 1; i++){
                    if (i == snake_body[k].Y && j + 1 == snake_body[k].X){
                        cout << 'o';
                        isBodyPart = true;
                        break;
                    }
                }
                if (!isBodyPart) cout << ' ';
            }
        }
        cout << "#\n";
    }
}
using namespace std;

int main(){
    srand(time(NULL));
    bool game_over = false;
    score = 0;
    while (!game_over){
        board();
        if (kbhit()){
            switch(getch()){
                case 'w': snake.change_dir('u'); break;
                case 'a': snake.change_dir('l'); break;
                case 's': snake.change_dir('d'); break;
                case 'd': snake.change_dir('r'); break;
            }
        }
        
        if (snake.eaten(food.get_pos())){
            food.gen_food();
            snake.grow();
            score++;
        }
        if (snake.collided()) game_over = true;
        snake.move_snake();
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), {0, 0});
    }
}
