#ifndef CHARACTER_H
#define CHARACTER_H

#include <vector>
#include <string>
#include "SDL/SDL_mixer.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_ttf.h"
#include "Bullet.h"



using namespace std;

class Character
{
    public:

        int x,y,iteracion,duracion_animacion,cuadro_actual,score,lives;

        vector<SDL_Surface*>sprites;
        vector<Bullet*>bullets;
        vector<Bullet*>bullets2;
        Bullet *bull;
        SDL_Surface*score_img;
        SDL_Surface*lives_img;
        SDL_Surface*explo_img;
        SDL_Surface*img;
        bool moviendose;
        bool colision;
        virtual void dibujar(SDL_Surface*screen);
        virtual void morir(SDL_Surface * screen);
        virtual void shot(SDL_Surface*screen);
        Character(int x, int y);
        Character();
        void apply_surface( int x, int y, SDL_Surface* source, SDL_Surface* destination, SDL_Rect* clip= NULL );
        string toString(int number);
        virtual ~Character();
    protected:
    private:
};

#endif // CHARACTER_H
