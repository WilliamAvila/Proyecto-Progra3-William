#ifndef ENEMY_H
#define ENEMY_H


#include "SDL/SDL_mixer.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_ttf.h"
#include "Bullet.h"
#include "Character.h"

using namespace std;
 class Enemy
{
    public:
        Enemy();
        Enemy( int x, int y);
        int x, y;
        bool murio;
        vector<Bullet*>bullets;
        bool colision;
        virtual ~Enemy();
        virtual bool logica(Character *player);
        virtual void morir(SDL_Surface * screen);
        virtual void atacar(Character *player);
        virtual void render(SDL_Surface * screen);
        virtual void shot(SDL_Surface * screen);
        virtual void movement();
        virtual void apply_surface( int x, int y, SDL_Surface* source, SDL_Surface* destination, SDL_Rect* clip=NULL );
        SDL_Surface* image;

        SDL_Surface*explo_img;
    protected:
    private:
};

#endif // ENEMY_H
