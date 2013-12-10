#include "Enemy.h"

Enemy::Enemy()
{
    //ctor
}

Enemy::~Enemy()
{
    //dtor
}


void Enemy::logica(Character *player)
{



        if(player->x+36>this->x && player->x<this->x+45
            && player->y+40>this->y && player->y<this->y+38)
                {
            Mix_Chunk *eff ;
            Mix_OpenAudio( 22050, MIX_DEFAULT_FORMAT, 2, 4096 );
            eff = Mix_LoadWAV( "beat.wav" );
            Mix_PlayChannel( -1,eff, 0);
            this->colision=true;

                }



}
