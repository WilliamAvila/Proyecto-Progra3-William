#include <iostream>
#include "SDL/SDL_image.h"
#include "SDL/SDL_ttf.h"

#include "SDL/SDL_mixer.h"
#include "Character.h"
#include <fstream>
#include  "Bullet.h"
#include "Player.h"
#include "Timer.h"
#include <sstream>
#include "Background.h"
#include  "Enemy.h"
using namespace std;
bool down=false;
//The frames per second
const int FRAMES_PER_SECOND = 60;

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;
const int SCREEN_BPP = 32;
int backx=0;
int backy =0;
SDL_Surface *screen = NULL;
SDL_Surface *background = NULL;


Mix_Music *music ;
Mix_Music *title ;
Mix_Chunk *effect;
SDL_Event event;

SDL_Color textColor = { 0, 0, 255,0 };
TTF_Font *font = NULL;


SDL_Surface *load_image( std::string filename )
{
    return IMG_Load( filename.c_str() );
}



string  toString(int number)
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

void apply_surface( int x, int y, SDL_Surface* source, SDL_Surface* destination, SDL_Rect* clip = NULL )
{
    //Holds offsets
    SDL_Rect offset;

    //Get offsets
    offset.x = x;
    offset.y = y;

    //Blit
    SDL_BlitSurface( source, clip, destination, &offset );
}


bool init()
{
    //Initialize all SDL subsystems
    if( SDL_Init( SDL_INIT_EVERYTHING ) == -1 )
    {
        return false;
    }

    //Set up the screen
    screen = SDL_SetVideoMode( SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_SWSURFACE );

    //If there was an error in setting up the screen
    if( screen == NULL )
    {
        return false;
    }

    //Initialize SDL_ttf
    if( TTF_Init() == -1 )
    {
        return false;
    }

    //Set the window caption
   // SDL_WM_SetCaption( "Spaceship Game", NULL );

    //If everything initialized fine
    return true;
}

bool load_files()
{  //Load the background image
    background = load_image("space.png");

    Mix_OpenAudio( 22050, MIX_DEFAULT_FORMAT, 2, 4096 );

    //Open the font
    font = TTF_OpenFont("imagine_font.ttf", 20);

    music = Mix_LoadMUS( "sounds/Music.ogg" );
    title= Mix_LoadMUS( "sounds/Title.ogg" );
    effect = Mix_LoadWAV( "sounds/laser.wav");

    //If there was a problem in loading the background
    if( background == NULL )
    {
        return false;
    }

     if( font == NULL )
    {
        return false;
    }

    //If there was a problem loading the music
    if( music == NULL )
    {
        return false;
    }
    if( effect == NULL )
    {
        return false;
    }

    if( title == NULL )
    {
        return false;
    }

    //If everything loaded fine
    return true;
}

void agregarScore(int puntos)
{

    ofstream out("high Score.txt", ios::app);
    out<<puntos<<endl;



}

void clean_up()
{
    //Free the surfaces
    SDL_FreeSurface( background );

    //Close the font
    TTF_CloseFont( font );

    Mix_FreeMusic( music );
    Mix_FreeChunk( effect);
    Mix_FreeMusic( title );

    //Quit SDL
    SDL_Quit();

}


int main(int argc, char* args[])
{
    int cont=0;
    int score=0;
    int max1=-9999;

 SDL_Surface * gameover = load_image("GameOver.png");
  SDL_Surface * win = load_image("win.png");

  bool go=false;
  bool wn=false;



    SDL_Surface*back_hs=load_image("black.png");
    bool high_Score=false;
    bool quit = false;
    bool quit2 =false;
    bool is_pressed=false;

    SDL_Surface*menu =IMG_Load("image1.png");
    SDL_Surface*enter = IMG_Load("start.png");
    SDL_Surface*hs = IMG_Load("highScore.png");
    SDL_Surface*ins = IMG_Load("instructions.png");
    SDL_Surface*exit = IMG_Load("exit.png");
    Uint8 *keystates1 = SDL_GetKeyState( NULL );

    SDL_Surface*ins_screen = IMG_Load("ins.png");
    SDL_Surface*in1 = IMG_Load("in1.png");
    SDL_Surface*in2 = IMG_Load("in2.png");



    //Initialize
    if( init() == false )
    {
        return 1;
    }

    //Load the files
    if( load_files() == false )
    {
        return 1;
    }
    SDL_Surface*cursor=load_image("cursor.png");
     int cursor_x=270;
    int cursor_y=80;
    SDL_Surface *hs_highscore=TTF_RenderText_Solid( font, "High Score",textColor );




Mix_PlayMusic( title, -1 );
    while(quit2 ==false){



        while( SDL_PollEvent( &event ) )
        {
            //If the user has Xed out the window
            if( event.type == SDL_QUIT )
            {
                //Quit the program
                high_Score=false;
                quit2= true;
                quit= true;
                is_pressed=false;
                 go=true;
            }
        }






        apply_surface( 0, 0, menu, screen );
        apply_surface( 270, 80, enter, screen );
        apply_surface( 120, 180, hs, screen );
        apply_surface( 420, 180, ins, screen );
        apply_surface( 270, 280, exit, screen );
        apply_surface( cursor_x, cursor_y, cursor, screen );

        if(keystates1[SDLK_RETURN]&&(cursor_x==270)&&(cursor_y==80)){
            quit2=true;

        }

        if(keystates1[SDLK_RETURN]&&(cursor_x==270)&&(cursor_y==280)){
                high_Score=false;
                quit2= true;
                quit= true;
                is_pressed=false;
                 go=true;

        }

        if(keystates1[SDLK_RETURN]&&(cursor_x==420)&&(cursor_y==180)){

               is_pressed=true;
               quit2=true;

        }


          if(keystates1[SDLK_RETURN]&&(cursor_x==120)&&(cursor_y==180)){

               high_Score=true;
               quit2=true;

                if(keystates1[SDLK_BACKSPACE]){
                    high_Score=false;
                    quit2= true;
                    quit= true;
                    is_pressed=false;
                }

        }



        if(keystates1[SDLK_DOWN])
        {
            cursor_x=270;
            cursor_y=280;


        }

         if(keystates1[SDLK_UP])
        {
            cursor_x=270;
            cursor_y=80;

        }

           if(keystates1[SDLK_LEFT])
        {
            cursor_x=120;
            cursor_y=180;

        }


           if(keystates1[SDLK_RIGHT])
        {
            cursor_x=420;
            cursor_y=180;

        }




      if( SDL_Flip( screen ) == -1 )
        {
            return 1;
        }


 }



  while(high_Score){



        while( SDL_PollEvent( &event ) )
        {
            //If the user has Xed out the window
            if( event.type == SDL_QUIT )
            {
                //Quit the program
                high_Score=false;
                quit2= true;
                quit= true;
                is_pressed=false;
                 go=true;
            }
        }

            //SCORE

    ifstream in ("high Score.txt");

    int max =-9999;

   while(!in.eof())
   {
       int puntos;
       in>>puntos;

        if(max<puntos)
            max=puntos;


    }








        apply_surface( 0, 0, back_hs, screen );
        apply_surface( 270, 80, hs_highscore, screen );
        SDL_Surface *hs_highscoreMax=TTF_RenderText_Solid( font, toString(max).c_str(),textColor );
        apply_surface( 270, 180, hs_highscoreMax, screen );

         if(keystates1[SDLK_BACKSPACE]){
                  high_Score=false;
                  quit2=true;
                  quit=true;
                  is_pressed=false;
                  go=true;
         }

          if( SDL_Flip( screen ) == -1 )
        {
            return 1;
        }


  }

  while(is_pressed){



        while( SDL_PollEvent( &event ) )
        {
            //If the user has Xed out the window
            if( event.type == SDL_QUIT )
            {
                //Quit the program
                high_Score=false;
                quit2= true;
                quit= true;
                is_pressed=false;
                 go=true;
            }
        }
        apply_surface( 0, 0, ins_screen, screen );
        apply_surface( 220, 80, in1, screen );
         apply_surface( 220, 280, in2, screen );

         if(keystates1[SDLK_BACKSPACE]){
                  is_pressed=false;
                  high_Score=false;
                  quit2=true;
                  quit=true;
                  go=true;
         }

          if( SDL_Flip( screen ) == -1 )
        {
            return 1;
        }


  }


     SDL_Surface*enemy1=load_image("Enemies/enemy01.png");
    SDL_Surface*enemy2=load_image("Enemies/enemy02.png");
    SDL_Surface*enemy3=load_image("Enemies/enemy03.png");
    SDL_Surface*enemy4=load_image("Enemies/enemy04.png");
    SDL_Surface*enemy5=load_image("Enemies/enemy05.png");
     SDL_Surface*enemy6=load_image("Enemies/enemy06.png");
     SDL_Surface*enemy7=load_image("Enemies/meteor.png");
     SDL_Surface *bul =load_image("bullet1.png");



    Character *personaje = new Character(260,400);
    Enemy *enemigo =new Enemy(260,200);
    Background back(screen);

     Bullet *bull = new Bullet(personaje->x,personaje->y);

    enemigo->image=load_image("Enemies/enemy01.png");
    Mix_PlayMusic(music,-1);
     while( quit == false )
    {
        //While there's events to handle
        while( SDL_PollEvent( &event ) )
        {
            //If the user has Xed out the window
            if( event.type == SDL_QUIT )
            {
                //Quit the program
                quit = true;
                 go=true;
            }
        }





        Uint8 *keystates = SDL_GetKeyState( NULL );

        //If up is pressed
        if( keystates[ SDLK_UP ] )
        {
          //  apply_surface( ( SCREEN_WIDTH - up->w ) / 2, ( SCREEN_HEIGHT / 2 - up->h ) / 2, up, screen );
            personaje->y-=2;
            personaje->moviendose=true;
            personaje->score++;
        }

        //If down is pressed
        if( keystates[ SDLK_DOWN ] )
        {
       //     apply_surface( ( SCREEN_WIDTH - down->w ) / 2, ( SCREEN_HEIGHT / 2 - down->h ) / 2 + ( SCREEN_HEIGHT / 2 ), down, screen );
            personaje->y+=2;
            personaje->moviendose=true;

        }


        //If left is pressed
        if( keystates[ SDLK_LEFT ] )
        {
//            apply_surface( ( SCREEN_WIDTH / 2 - left->w ) / 2, ( SCREEN_HEIGHT - left->h ) / 2, left, screen );
             personaje->x-=2;
             personaje->moviendose=true;


        }

        //If right is pressed
        if( keystates[ SDLK_RIGHT ] )
        {
//            apply_surface( ( SCREEN_WIDTH / 2 - right->w ) / 2 + ( SCREEN_WIDTH / 2 ), ( SCREEN_HEIGHT - right->h ) / 2, right, screen );
            personaje->x+=2;
            personaje->moviendose=true;
        }


           //Apply the background
            back.logic();
            back.render();

            personaje->score_img=TTF_RenderText_Solid( font, personaje->toString(personaje->score).c_str(),textColor );

            personaje->lives_img=TTF_RenderText_Solid( font, personaje->toString(personaje->lives).c_str(),textColor );
          // apply_surface( 75, 75, pers_surface, screen );




          personaje->dibujar(screen);
          enemigo->render(screen);
          enemigo->shot(screen);

           enemigo->shot(screen);
            if(cont%100==0)
            {
             enemigo->bullets.push_back(new Bullet(enemigo->x,enemigo->y));
            }





              apply_surface( 70, 10, enemy1, screen );
            apply_surface( 140,10, enemy2, screen );
            apply_surface( 210, 10, enemy3, screen );
            apply_surface( 280, 10, enemy4, screen );
            apply_surface( 350,10, enemy5, screen );
            apply_surface( 420,10, enemy6, screen );
            apply_surface( 490,10, enemy7, screen );


              if( keystates[ SDLK_c ] && cont%25==0)
        {
            Mix_PlayChannel(-1,effect,0);
                personaje->bullets2.push_back(new Bullet(personaje->x,personaje->y));
           personaje->bullets.push_back(new Bullet(personaje->x,personaje->y));

            down=true;
            personaje->bull->exists=true;






        }
        personaje->shot(screen);

//        if(down){
//        personaje->shot(screen);
//
//        }
        if(bull->y<0)
        down=false;
//         if( SDL_PollEvent( &event ) )
//        {
//           // If a key was pressed
//            if( event.type == SDL_KEYDOWN )
//            {
//              //  Set the proper message surface
//                switch( event.key.keysym.sym )
//                {
//
//                     case SDLK_SPACE:
//
//                        personaje->shot(screen);
//                    break;
//                }
//            }
//        }


    if(enemigo->logica(personaje))
     personaje->morir(screen);
//          personaje->sprites.push_back(load_image("shipleft1.png"));
//          personaje->sprites.push_back(load_image("shipleft2.png"));
//          personaje->sprites.push_back(load_image("shipleft3.png"));
//          personaje->dibujar(screen);


        if(personaje->lives==0){
            score = personaje->score;

            agregarScore(score);

            quit=true;
            go=false;

        }

          //Update the screen
        if( SDL_Flip( screen ) == -1 )
        {
            return 1;
        }

        cont++;


    }


      while(go==false){



        while( SDL_PollEvent( &event ) )
        {
            //If the user has Xed out the window
            if( event.type == SDL_QUIT )
            {
                //Quit the program
                high_Score=false;
                quit2= true;
                quit= true;
                is_pressed=false;
                go=true;
            }
        }

        apply_surface( 0, 0, gameover, screen );

          if( SDL_Flip( screen ) == -1 )
        {
            return 1;
        }

      }

    clean_up();


    cout << "Hello world!" << endl;
    return 0;
}



