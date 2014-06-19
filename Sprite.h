//
//  Sprite.h
//  BallGame
//

#ifndef __BasicGameEngine__Sprite__
#define __BasicGameEngine__Sprite__

#include "SDL/SDL.h"
#include "Rectangle.h"
#include "Image.h"
#include <vector>
#include <string>

namespace BGengine {
    
    class Sprite {
        
    public:
        static Sprite* getInstance(int x, int y);
        virtual void draw();
        virtual void tick(std::vector<Sprite*> sprites);
        virtual ~Sprite();
        virtual void handle_events(SDL_Event* event);
        virtual void setImage(std::string filename, bool transparent = true);
        virtual void setPosition(int x, int y);
        int getX();
        int getY();
        Image getImage();
        void setHitbox(int x = 0, int y = 0, int w = 0, int h = 0);
        Rectangle getHitbox();
    protected:
        Sprite(int x, int y);
        Rectangle hitbox;
        Image image;
    private:
        int x, y;
        Sprite(const Sprite&); // Förbjud tilldelningar med copy-konstruktorn
        const Sprite& operator=(const Sprite&); // Förbjud automatisk tilldening med tilldelningsoperator
    };
    
} // namespace BGengine

#endif /* defined(__BasicGameEngine__Sprite__) */
