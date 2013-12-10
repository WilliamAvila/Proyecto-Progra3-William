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

using namespace std;

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



    //Open the font
    font = TTF_OpenFont("imagine_font.ttf", 20);

//    music = Mix_LoadMUS( "sounds/beat.wav" );
//    title= Mix_LoadMUS( "sounds/Title.ogg" );
//    effect = Mix_LoadWAV( "sounds/04 Palmtree Panic.ogg");

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
//    if( music == NULL )
//    {
//        return false;
//    }
//    if( effect == NULL )
//    {
//        return false;
//    }
//
//    if( title == NULL )
//    {
//        return false;
//    }

    //If everything loaded fine
    return true;
}

void agregarScore(string nombre,int puntos)
{

    ofstream out("ejemplo.txt", ios::app);
    out<<nombre<<' '<<puntos<<endl;



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



    //SCORE
//
//     agregarScore("Jose",2111);
//   agregarScore("Maria",211);
//   agregarScore("Test",20);
//
//
//
//
//    ifstream in ("ejemplo.txt");
//
//    int max =-9999;
//    string nombre_max=" ";
//
//   while(!in.eof())
//   {
//
//       string nombre;
//       int puntos;
//       in>>nombre;
//       in>>puntos;
//
//        if(max<puntos)
//        {
//            max=puntos;
//            nombre_max=nombre;
//
//        }
//
//
//
//
//   }



//      cout<<"Ganador: "<<nombre_max<<endl;

    bool quit = false;

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

     SDL_Surface*enemy1=load_image("Enemies/enemy01.png");
    SDL_Surface*enemy2=load_image("Enemies/enemy02.png");
    SDL_Surface*enemy3=load_image("Enemies/enemy03.png");
    SDL_Surface*enemy4=load_image("Enemies/enemy04.png");
    SDL_Surface*enemy5=load_image("Enemies/enemy05.png");
     SDL_Surface*enemy6=load_image("Enemies/enemy06.png");
     SDL_Surface *bul =load_image("bullet1.png");


    Character *personaje = new Character(260,400);


     Bullet *bull = new Bullet(personaje->x,personaje->y);



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
            }
        }




//         if( SDL_PollEvent( &event ) )
//        {
//            //If a key was pressed
//            if( event.type == SDL_KEYDOWN )
//            {
//                //Set the proper message surface
//                switch( event.key.keysym.sym )
//                {
//                    case SDLK_UP:
//                        personaje->y-=2;
//                          personaje->moviendose=true;
//                          personaje->score++;
//
//
//                    break;
//                    case SDLK_DOWN:
//
////                        personaje->y+=2;
//                          personaje->moviendose=true;
////                    break;
//                    case SDLK_LEFT:
//
//                        pers->x--;
//                        pers->moviendose =true;
//                    break;
//                    case SDLK_RIGHT:
//
//                        pers->x++;
//                        pers->moviendose =true;
//                    break;
//                }
//            }
//        }
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
            apply_surface( 0, 0, background, screen );
            personaje->score_img=TTF_RenderText_Solid( font, personaje->toString(personaje->score).c_str(),textColor );

            personaje->lives_img=TTF_RenderText_Solid( font, personaje->toString(personaje->lives).c_str(),textColor );
          // apply_surface( 75, 75, pers_surface, screen );




          personaje->dibujar(screen);


              apply_surface( 70, 10, enemy1, screen );
            apply_surface( 140,10, enemy2, screen );
            apply_surface( 210, 10, enemy3, screen );
            apply_surface( 280, 10, enemy4, screen );
            apply_surface( 350,10, enemy5, screen );
            apply_surface( 420,10, enemy6, screen );


              if( keystates[ SDLK_SPACE ] )
        {


            personaje->shot(screen);




        }



    if(personaje->y<=300)
     personaje->morir(screen);
//          personaje->sprites.push_back(load_image("shipleft1.png"));
//          personaje->sprites.push_back(load_image("shipleft2.png"));
//          personaje->sprites.push_back(load_image("shipleft3.png"));
//          personaje->dibujar(screen);

          //Update the screen
        if( SDL_Flip( screen ) == -1 )
        {
            return 1;
        }


    }

    clean_up();
    cout << "Hello world!" << endl;
    return 0;
}
