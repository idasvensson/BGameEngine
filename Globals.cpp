//
//  Globals.cpp
//  BallGame
//

#include "Globals.h"
#include "SDL/SDL.h"

namespace BGengine {
    
    void Globals::init()
    {
        SDL_Init(SDL_INIT_EVERYTHING); // Innan main anropas
        screen = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, 32, SDL_SWSURFACE | SDL_DOUBLEBUF);
    }
    
    Globals::~Globals()
    {
        SDL_Quit(); // Efter att programmet avslutats
    }
    
    Globals sys;
    
} // namespace basicgame

