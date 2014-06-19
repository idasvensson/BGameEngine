//
//  GameEngine.cpp
//  BallGame
//

#include "GameEngine.h"
#include "SDL/SDL.h"
#include "Globals.h"
#include <vector>
#include <iostream>

namespace BGengine {
    
    GameEngine::GameEngine(const unsigned short int MAX_FRAME_RATE) : MAX_FRAME_RATE(MAX_FRAME_RATE){}
    
    void GameEngine::add(Sprite* ny){
        sprites.push_back(ny);
    }
    
    void GameEngine::remove(Sprite* toRemove) {
        
        for(int i=0; i < sprites.size(); i++)
            if (sprites[i] == toRemove)
            {
                sprites.erase(sprites.begin() + i);
                delete toRemove;
            }
        
    }
    
    void GameEngine::run() {
        for (int i = 0; i < sprites.size(); i++)
            sprites[i]->draw();
        
        SDL_Flip(sys.screen);
        
        SDL_EnableKeyRepeat(1, 200);
        
        // Händelseloop
        bool quit = false;
        while(!quit) {
            
            // Starta timern
			timer.start();
            
            SDL_Event event;
            
            while (SDL_PollEvent(&event)) {
                
                switch (event.type) {
                        
                    case SDL_QUIT:
                        quit = true;
                        break;
                        
                } // switch
                
                for(int i=0; i<sprites.size(); i++)
                {
                    sprites[i]->handle_events(&event);
                }
                
            } // while SDL_PollEvent
            
            // Skicka möjlighet att välja bakgrund till Game här, som render graphics?
            Uint32 green = SDL_MapRGB(sys.screen->format, 39, 68, 75);
            //Uint32 bg_color = SDL_MapRGB(sys.screen->format, 39, 68, 75);
            SDL_FillRect(sys.screen, NULL, green); // Fyll hela skärmen vit
            
            for(int i=0; i<sprites.size(); i++)
            {
                sprites[i]->tick(sprites);
                sprites[i]->draw();
                
            }
            
            SDL_Flip(sys.screen);
            
            frameCounter++;
            
			// Om vår timer har gått mindre än tiden det ska ta för varje frame
			if ((timer.getTicks() < 1000 / MAX_FRAME_RATE))
			{
				// Då väntar vi den tiden som återstår
				SDL_Delay((1000 / MAX_FRAME_RATE) - timer.getTicks());
			}
            
        } // while !quit (running)
    }
    
    GameEngine::~GameEngine() {
    }
    
}
