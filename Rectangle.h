//
//  Rectangle.h
//  BallGame
//

#ifndef __BasicGameEngine__Rectangle__
#define __BasicGameEngine__Rectangle__

#include "SDL/SDL.h"

namespace BGengine {
    
    struct Rectangle : public SDL_Rect
    {
        Rectangle();
        Rectangle(int xx, int yy, int ww, int hh);
        bool contains(int xx, int yy) const; // Koordinataritmetik
        Rectangle centeredRect(int width, int height) const; // Returnerar en rektangel som är centrerad inuti den egna rektangeln, t.ex. för att centrera text
        bool overlaps(const Rectangle& other) const; // OBS: Endast på rektangelnivå, inte bra för kollisionsdetektering
        
    };
    
} // namespace BGengine

#endif /* defined(__BasicGameEngine__Rectangle__) */
