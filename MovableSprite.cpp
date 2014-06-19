//
//  MovableSprite.cpp
//  BallGame
//

#include "MovableSprite.h"
#include "SDL/SDL.h"
#include "Globals.h"
#include <iostream>
#include <vector>
using namespace std;

namespace BGengine {
    
    MovableSprite::MovableSprite(int x, int y) :
    Sprite(x, y)
    {
        // Initialize hitboxs
        hitbox.x = x;
        hitbox.y = y;
    }
    
    MovableSprite* MovableSprite::getInstance(int x, int y)
    {
        return new MovableSprite(x, y);
    }
    
    void MovableSprite::handle_events(SDL_Event* event)
    {
        
        // Överlagringsbar för specifika tillämpningar, men förberedd med velocity.
        // MovableSprite kan alltså vara både AI Players och Användarkontrollerade players.
        
    }
    
    void MovableSprite::move() // (int dir) som argument?
    {
        // Faktiskt rörelse av spriten i x-led. hitboxens x-position låts påverkas av x-vel
		hitbox.x += getXVel();
        
        // Hantera väggkollision för alla MovableSprites
		if ((hitbox.x < 0) || (hitbox.x + hitbox.w > sys.SCREEN_WIDTH))
			setXVel(-this->getXVel());
        
        // Samma som ovan fast y-led
		hitbox.y += getYVel();
        
        if ((hitbox.y < 0) || (hitbox.y + hitbox.h > sys.SCREEN_HEIGHT))
			setYVel(-this->getYVel());
    }
    
    void MovableSprite::tick(std::vector<Sprite*> sprites) // Använda hitbox.x och hitbox.y eller x och y?
    {
        check_collision(sprites);
        move();
    }
    
    void MovableSprite::check_collision(std::vector<Sprite*> sprites)
    {
        
        // Söker igenom alla sprites för varje tick
        for (int i = 0; i < sprites.size(); i++)
        {
            // Tittar om den aktuella spriten är den vi är. Om vi stöter på oss själva så gör vi inget.
            if (sprites[i] != this)
                // Annars så undersöker vi om någon av spritesen överlappar.
                if (this->getHitbox().overlaps(sprites[i]->getHitbox()))
                {
                    // Skicka med pekare till sprite den kolliderat med för att kunna hantera dem enskilt.
                    this->handle_collision(sprites[i]);
                }
        }
    }
    
    void MovableSprite::handle_collision(Sprite* other)
    {
        // Do nothing. Överlagringsbar funktion för specialiserad typ.
        cout << "Default collision called." << endl;
        return;
    }
    
    // För initiering eller nollställning av hastighet i både x- och y-led
    void MovableSprite::setVelocity(int newVel)
    {
        xVel = newVel;
        yVel = newVel;
    }
    
    // Ändra enbart hastighet i x-led
    void MovableSprite::setXVel(int newVel)
	{
		xVel = newVel;
	}
    
	void MovableSprite::setYVel(int newVel)
	{
		yVel = newVel;
	}
    
	int MovableSprite::getXVel()
	{
		return xVel;
	}
    
	int MovableSprite::getYVel()
	{
		return yVel;
	}
    
    
    MovableSprite::~MovableSprite() {
		
	}
    
}
