#include "Character.h"

Character::Character(int x, int y)
{
    this->x=x;
    this->y=y;
    this->duracion_animacion=10;
    this->iteracion=0;
    this->cuadro_actual=0;
    this->score=0;
    this->lives=3;
    this->bull=new Bullet(x,y);
    this->colision=false;

    this->sprites.push_back(IMG_Load("ship2.png"));
    this->sprites.push_back(IMG_Load("ship1.png"));

    this->sprites.push_back(IMG_Load("ship3.png"));

    this->explo_img = IMG_Load("explosion.png");

    // this->bullets.push_back(new Bullet(this->x,this->y));


    //ctor
}

Character::~Character()
{
    //dtor
}

Character::Character()
{
    //dtor
}


 void Character :: dibujar(SDL_Surface *screen)
 {
      this->apply_surface(0,0,score_img,screen);
      this->apply_surface(620,0,lives_img,screen);
      if(this->moviendose){
                this->apply_surface(this->x,this->y,this->sprites[cuadro_actual],screen);

            }else{
                this->apply_surface(this->x,this->y,this->sprites[0],screen);
            }

        this->iteracion++;
       if(this->iteracion==this->duracion_animacion)
        {
            this->cuadro_actual++;
            if(this->cuadro_actual>=sprites.size())
                this->cuadro_actual=0;
                this->iteracion=0;
                this->moviendose=false;
        }
 }

 void Character ::apply_surface( int x, int y, SDL_Surface* source, SDL_Surface* destination, SDL_Rect* clip )
{
    //Holds offsets
    SDL_Rect offset;

    //Get offsets
    offset.x = x;
    offset.y = y;

    //Blit
    SDL_BlitSurface( source, clip, destination, &offset );
}


void Character :: morir(SDL_Surface * screen)
{
         Mix_Chunk *exp ;
            Mix_OpenAudio( 22050, MIX_DEFAULT_FORMAT, 2, 4096 );
            exp = Mix_LoadWAV( "sounds/bomb.wav" );
            Mix_PlayChannel( -1,exp, 0);

this->apply_surface(this->x,this->y,explo_img,screen);
//
this->x=260;
this->y=400;


this->lives-=1;

}



void Character :: shot(SDL_Surface * screen)
{
    // bull->draw(screen,bull->x,bull->y);
//    bull->y-=2;


    for(int i=0;i<bullets.size();i++){



    this->bullets[i]->draw(screen,bullets[i]->x,bullets[i]->y);
    this->bullets[i]->y-=6;

    this->bullets2[i]->draw(screen,bullets[i]->x+35,bullets[i]->y+9);
    this->bullets2[i]->y-=12;


    }


 //this->bullets.push_back(new Bullet(this->x,this->y));
}



string Character:: toString(int number)
{
    if (number == 0)
        return "0";
    string temp="";
    string returnvalue="";
    while (number>0)
    {
        temp+=number%10+48;
        number/=10;
    }
    for (int i=0;i<(int)temp.length();i++)
        returnvalue+=temp[temp.length()-i-1];
    return returnvalue;
}
