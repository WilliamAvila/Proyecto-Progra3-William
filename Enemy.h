#ifndef ENEMY_H
#define ENEMY_H

#include "Character.h"
#include "SDL/SDL_mixer.h"
class Enemy
{
    public:
        Enemy();
        int x, y;
        bool colision;
        virtual ~Enemy();
        virtual void logica(Character *player);

    protected:
    private:
};

#endif // ENEMY_H
