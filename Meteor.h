#ifndef METEOR_H
#define METEOR_H

#include "Enemy.h"

class Meteor : public Enemy
{
    public:
    int x,y;
        Meteor(int x,int y);

        virtual ~Meteor();
        void move();
    protected:
    private:
};

#endif // METEOR_H
