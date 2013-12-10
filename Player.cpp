#include "Player.h"

Player:: Player(int x, int y)
{
    this->sprites.push_back(IMG_Load("ship2.png"));
    this->sprites.push_back(IMG_Load("ship3.png"));
    this->sprites.push_back(IMG_Load("ship1.png"));
    this->duracion_animacion=10;
    this->iteracion=0;
    this->cuadro_actual=0;
    this->score=0;

    this->x=x;
    this->y=y;
    this->moviendose=false;

    //ctor
}

Player::~Player()
{
    //dtor
}
