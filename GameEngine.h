//
//  GameEngine.h
//  BallGame
//

#ifndef __BasicGameEngine__GameEngine__
#define __BasicGameEngine__GameEngine__

#include "Sprite.h"
#include <vector>
#include "Timer.h"

namespace BGengine {
    
    class GameEngine {
    public:
        GameEngine(const unsigned short int MAX_FRAME_RATE);
        ~GameEngine();
        void add(Sprite* ny);
        void remove(Sprite* ny);
        void run();
    private:
		Timer timer;
		int frameCounter = 0;
        std::vector<Sprite*> sprites;
        const unsigned short int MAX_FRAME_RATE;
    };
    
} // namespace BGengine

#endif /* defined(__BasicGameEngine__GameEngine__) */
