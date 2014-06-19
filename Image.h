//
//  Image.h
//  BallGame
//

#ifndef __BasicGameEngine__Image__
#define __BasicGameEngine__Image__

#include "SDL/SDL.h"
#include <string>

namespace BGengine {
    
    class Image {
        
    public:
        Image(std::string filename, bool transparent = true); // Konstruktor
        Image(); // Defaultkonstruktor
        Image(const Image& other); // Copykonstruktor - vid t.ex Image a(b);
        const Image& operator=(const Image& other);
        ~Image();
        SDL_Surface* getSurface() const;
        
    private:
        SDL_Surface* img;
        bool isTransparent;
        
    };
    
} // namespace BGengine

#endif /* defined(__BasicGameEngine__Image__) */
