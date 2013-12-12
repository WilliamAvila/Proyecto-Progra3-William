#include "Background.h"

Background::Background(SDL_Surface *screen)
{
    this->screen = screen;
    this->image = IMG_Load( "space.png" );
    this->y = 0;
}

Background::~Background()
{
    SDL_FreeSurface( image );
}

void Background::logic()
{
    y--;
}

void Background::render()
{
    SDL_Rect offset;

    if(y<-image->h)
        y=0;
    offset.x = 0;
    offset.y = y;

    SDL_BlitSurface( image, NULL, screen, &offset );

    offset.y = y+image->h;
    offset.x = 0;

    SDL_BlitSurface( image, NULL, screen, &offset );
}
