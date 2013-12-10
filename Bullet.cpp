#include "Bullet.h"

Bullet::Bullet(int x,int y)
{
    this->x=x;
    this->y=y;
    this->image=IMG_Load("bullet1.png");
    //ctor
}

Bullet::~Bullet()
{
    //dtor
}
void Bullet::draw(SDL_Surface* screen,int x,int y) {
    //Holds offsets
    SDL_Rect offset;

    //Get offsets
    offset.x = x;
    offset.y = y;



    //Blit
    SDL_BlitSurface( image, NULL, screen, &offset );

}
