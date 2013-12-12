#ifndef ENEMY_H
#define ENEMY_H

#include "Character.h"
#include "SDL/SDL_mixer.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_ttf.h"
#include "Bullet.h"

class Enemy
{
    public:
        Enemy( int x, int y);
        int x, y;
        bool colision;
        virtual ~Enemy();
        virtual void logica(Character *player);
        virtual void morir(SDL_Surface * screen);
        virtual void atacar(Character *player);
        virtual void render(SDL_Surface * screen);
        SDL_Surface* image;

    protected:
    private:
};

#endif // ENEMY_H
