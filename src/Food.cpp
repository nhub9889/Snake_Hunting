#include "include/Food.h"
#define WIDTH 150
#define HEIGHT 100
Food::Food(){
    gen_food();
}

void Food::gen_food(){
    pos.X = (rand()%(WIDTH) -  3) + 1;
    pos.Y = (rand()%(HEIGHT) - 3) + 1;
}

COORD Food::get_pos(){
    return pos;
}
