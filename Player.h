#ifndef PLAYER_H
#define PLAYER_H
#include "Character.h"
#include "Bullet.h"
#include <vector>

using namespace std;

class Player: Character
{
    public:
    int x,y;
    bool moviendose;
    vector<Bullet> *bullet;
        Player(int x,int y);

        virtual ~Player();
    protected:
    private:
};

#endif // PLAYER_H
