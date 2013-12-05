#include "Character.h"

Character::Character(int x, int y)
{
    this->x=x;
    this->y=y;
    this->duracion_animacion=0;
    this->iter=0;

    //ctor
}

Character::~Character()
{
    //dtor
}


void Character::dibujar(SDL_Surface*screen)
{

    //Holds offsets
    SDL_Rect offset;

    //Get offsets
    offset.x = x;
    offset.y = y;

    if(duracion_animacion>5){
        iter++;
        duracion_animacion=0;
    }
    if(iter>= sprites.size())
        iter=0;

    //Blit
    SDL_BlitSurface( sprites[iter], NULL, screen, &offset );
    duracion_animacion++;


}

