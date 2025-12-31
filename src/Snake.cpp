#include "../include/Snake.h"

Snake::Snake(COORD pos, int vel)
{
    this->pos = pos;
    this->vel = vel;

    dir = 'n';
    len = 1;

    body.push_back(pos);
}

void Snake::direction(char dir) {
    if (this->dir == 'u' && dir == 'd') return;
    if (this->dir == 'd' && dir == 'u') return;
    if (this->dir == 'l' && dir == 'r') return;
    if (this->dir == 'r' && dir == 'l') return;
    
    this->dir = dir;
}
void Snake::grow() { len++; }
COORD Snake::get_pos() { return pos; }

vector<COORD> Snake::get_body() { return body; }

void Snake::move_snake() {
    switch(dir) {
        case 'u': pos.Y -= vel; break;
        case 'd': pos.Y += vel; break;
        case 'l': pos.X -= vel; break;
        case 'r': pos.X += vel; break;
    }

    if (pos.X < 0) pos.X = WIDTH - 1;
    else if (pos.X >= WIDTH) pos.X = 0;
    if (pos.Y < 0) pos.Y = HEIGHT - 1;
    else if (pos.Y >= HEIGHT) pos.Y = 0;

    body.push_back(pos);

    if (body.size() > len) {
        body.erase(body.begin());
    }
}

bool Snake::collided()
{
    // if(pos.X < 0 || pos.X >= WIDTH || pos.Y < 0 || pos.Y >= HEIGHT) return true;

    for(int i = 0; i < (int)body.size() - 1; i++)
    {
        if(pos.X == body[i].X && pos.Y == body[i].Y) {
            return true;
        }
    }
    return false;
}

bool Snake::eaten(COORD food)
{
    if(pos.X == food.X && pos.Y == food.Y) return true;
    return false;
}