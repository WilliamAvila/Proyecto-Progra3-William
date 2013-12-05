#include <iostream>
#include "SDL/SDL_image.h"
#include "SDL/SDL_ttf.h"

#include "Character.h"
using namespace std;



const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;
const int SCREEN_BPP = 32;

SDL_Surface *screen = NULL;
SDL_Surface *background = NULL;

SDL_Event event;


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
    SDL_WM_SetCaption( "Spaceship Game", NULL );

    //If everything initialized fine
    return true;
}

bool load_files()
{  //Load the background image
    background = load_image("space.png");

    //If there was a problem in loading the background
    if( background == NULL )
    {
        return false;
    }

    //If everything loaded fine
    return true;
}

void clean_up()
{
    //Free the surfaces
    SDL_FreeSurface( background );

    //Quit SDL
    SDL_Quit();
}


int main(int argc, char* args[])
{
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
    SDL_Surface*pers_surface =load_image("char1.png");
    Character *pers = new Character(240,240);
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

           //Apply the background
          apply_surface( 0, 0, background, screen );
          // apply_surface( 75, 75, pers_surface, screen );
          pers->sprites.push_back(load_image("char1.png"));
          pers->dibujar(screen);

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
