#ifndef BULLET_H
#define BULLET_H

#include "SDL/SDL_image.h"

class Bullet
{
    public:
        Bullet(int x, int y);
        virtual ~Bullet();

        void draw(SDL_Surface* screen, int x, int y);

        bool exists;
        int x;
        int y;
        int speedX;
        int speedY;
        int damage;
        int flightType;

        SDL_Surface* image;
    protected:
    private:
};

#endif // BULLET_H
