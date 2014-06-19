//
//  Globals.h
//  BallGame
//

#ifndef __BasicGameEngine__Globals__
#define __BasicGameEngine__Globals__

#include "SDL/SDL.h"
#include "SDL_ttf/SDL_ttf.h"

namespace BGengine {
    
    struct Globals
    {
        void init(); // I stället för konstruktor på Mac
        ~Globals();
        SDL_Surface* screen;
        const int SCREEN_WIDTH = 800;
        const int SCREEN_HEIGHT = 600;
    };
    
    extern Globals sys;
    
} // namespace BGengine

#endif /* defined(__BasicGameEngine__Globals__) */
