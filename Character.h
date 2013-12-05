#ifndef CHARACTER_H
#define CHARACTER_H
#include <vector>

#include "SDL/SDL_image.h"
#include "SDL/SDL_ttf.h"
using namespace std;
class Character
{
    public:

        int x,y,iter,duracion_animacion;
        vector<SDL_Surface*>sprites;
        SDL_Surface*img;
        void dibujar(SDL_Surface*screen);
        Character(int x, int y);
        virtual ~Character();
    protected:
    private:
};

#endif // CHARACTER_H
