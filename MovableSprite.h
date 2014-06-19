//
//  MovableSprite.h
//  BallGame
//

#ifndef __BasicGameEngine__MovableSprite__
#define __BasicGameEngine__MovableSprite__

#include "SDL/SDL.h"
#include "Sprite.h"
#include <vector>
#include <string>

// Flytta getInstance till Sprite? tick?

namespace BGengine {
    
    class MovableSprite : virtual public Sprite {
        
    public:
        static MovableSprite* getInstance(int x, int y);
        virtual void move();
        virtual void handle_events(SDL_Event* event);
        virtual ~MovableSprite();
        virtual void tick(std::vector<Sprite*> sprites);
        virtual void setVelocity(int newVel);
        void setXVel(int newVel);
        void setYVel(int newVel);
        int getXVel();
        int getYVel();
        void check_collision(std::vector<Sprite*> sprites);
        virtual void handle_collision(Sprite* other);
    protected:
        MovableSprite(int x, int y);
        int xVel, yVel;
    private:
        //int direction;
    };
    
} // namespace BGengine

#endif /* defined(__BasicGameEngine__MovableSprite__) */
