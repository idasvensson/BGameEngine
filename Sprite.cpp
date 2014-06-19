//
//  Sprite.cpp
//  BallGame
//

#include "Sprite.h"
#include "Globals.h"
#include <iostream>
using namespace std;

namespace BGengine {
    
    Sprite::Sprite(int x, int y)
    {
        this->x = x;
        this->y = y;
        
        // Initialize hitbox
        hitbox.x = x;
        hitbox.y = y;
    }
    
    Sprite::~Sprite()
    {
        
    }
    
    Sprite* Sprite::getInstance(int x, int y)
    {
        return new Sprite(x, y);
    }
    
    void Sprite::draw()
    {
        
        if( image.getSurface() )
        {
            SDL_BlitSurface( image.getSurface(), NULL, sys.screen, &hitbox );
        }
        else
        {
            cout << "Could not draw: No image or hitbox." << endl;
        }
        
    }
    
    void Sprite::setPosition(int x, int y)
    {
        hitbox.x = x;
        hitbox.y = y;
    }

    void Sprite::setImage(string filename, bool transparent)
    {
        image = Image(filename, transparent);
        if (!hitbox.w) {
            setHitbox();
        }
    }
    
    Image Sprite::getImage()
    {
        return image;
    }
    
    void Sprite::setHitbox(int x, int y, int w, int h)
    {
        // Om inget annat angivits, sätt bredd och höjd till bildens (om bild existerar)
        if(image.getSurface() && w == 0 && h == 0) {
            w = image.getSurface()->w;
            h = image.getSurface()->h;
        }
        
        hitbox = Rectangle(this->x, this->y, w, h);
        
    }
    
    Rectangle Sprite::getHitbox()
    {
        return hitbox;
    }
    
    int Sprite::getX()
    {
        return hitbox.x;
    }
    
    int Sprite::getY()
    {
        return hitbox.y;
    }
    
    void Sprite::handle_events(SDL_Event* event)
    {
    }
    
    void Sprite::tick(std::vector<Sprite*> sprites)
    {
    }
    
} // namespace basicgame