#include "Enemy.h"

Enemy::Enemy(int x,int y)
{
    this->x=x;
    this->y=y;
    this->colision=false;
     this->explo_img = IMG_Load("explosion.png");


    //ctor
}

Enemy::~Enemy()
{
    //dtor
}


bool Enemy::logica(Character *player)
{
//      this->y+=2;
//
//        if(this->y>480)
//            this->y=-200;
        this->movement();



        if(player->x+40>this->x && player->x<this->x+50
            && player->y+45>this->y && player->y<this->y+70)
                {

//            Mix_Chunk *eff ;
//            Mix_OpenAudio( 22050, MIX_DEFAULT_FORMAT, 2, 4096 );
//            eff = Mix_LoadWAV( "beat.wav" );
//            Mix_PlayChannel( -1,eff, 0);
            this->colision=true;
            return colision;
                }


            for(int i=0;i<bullets.size();i++)
            {
                if(player->x+40>bullets[i]->x && player->x<bullets[i]->x+5
                   && player->y+45>bullets[i]->y && player->y<bullets[i]->y+9){

                    this->colision=true;
                    return colision;


                   }



            }


        this->colision=false;

        return colision;


}



void Enemy :: render(SDL_Surface * screen)
{
        //Holds offsets
    SDL_Rect offset;

    //Get offsets
    offset.x = x;
    offset.y = y;

    //Blit
    SDL_BlitSurface( image, NULL, screen, &offset );




}

void Enemy :: movement()
{



}


void Enemy :: shot(SDL_Surface * screen)
{

    for(int i=0;i<bullets.size();i++){



    this->bullets[i]->draw(screen,bullets[i]->x,bullets[i]->y);
    this->bullets[i]->y+=1;

    }


}

void Enemy :: morir(SDL_Surface * screen)
{
             Mix_Chunk *exp ;
            Mix_OpenAudio( 22050, MIX_DEFAULT_FORMAT, 2, 4096 );
            exp = Mix_LoadWAV( "sounds/bomb.wav" );
            Mix_PlayChannel( -1,exp, 0);

                this->apply_surface(this->x,this->y,explo_img,screen);
                //
                this->x=x;
                this->y=-400;
}


void Enemy :: atacar(Character *player)
{

}

void Enemy ::apply_surface( int x, int y, SDL_Surface* source, SDL_Surface* destination, SDL_Rect* clip )
{
    //Holds offsets
    SDL_Rect offset;

    //Get offsets
    offset.x = x;
    offset.y = y;

    //Blit
    SDL_BlitSurface( source, clip, destination, &offset );
}
