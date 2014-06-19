//
//  Image.cpp
//  BallGame
//

#include "Image.h"
#include "SDL_image/SDL_image.h"
#include <string>
#include <iostream>
using namespace std;

namespace BGengine {
    
    Image::Image() :img(NULL)
    {
        cout << "Image skapad med defaultkonstruktor." << endl;
    }
    
    Image::Image(std::string filename, bool transparent) : isTransparent(transparent)
    {
        cout << "Image skapad med argument." << endl;
        
        // Temporära ytor
        SDL_Surface* loadedImage = NULL;
        SDL_Surface* optimizedImage = NULL;
        
        // Läs in bilden från den angivna filen
        loadedImage = IMG_Load( filename.c_str() );
        
        // Om bilden laddades
        if( loadedImage != NULL )
        {
            // Konvertera bilden till skärmens format
            // NOTE: SDL_ConvertSurface används internt inom SDL_DisplayFormat
            optimizedImage = SDL_DisplayFormat( loadedImage );
            
            // Frigör den gamla ytan
            SDL_FreeSurface( loadedImage );
            
            // Om ytan optimerades - HA MED?
            if( optimizedImage != NULL )
            {
                // Color key surface
                SDL_SetColorKey( optimizedImage, SDL_SRCCOLORKEY, SDL_MapRGB( optimizedImage->format, 0, 0xFF, 0xFF ) );
            }
            
            // Addera transparens till bildens grå pixlar
            Uint32 grey = SDL_MapRGB(optimizedImage->format, 242, 242, 242);
            SDL_SetColorKey(optimizedImage, SDL_SRCCOLORKEY|SDL_RLEACCEL, grey);
            
            // Ändra senare till övre vänstra pixelns färg...
            // Uint32 pixel = pixel = *((Uint32*)optimizedImage->pixels);
            
        }
        // Om inte angiven fil finns
        else
        {
            // Generera ett undantag
            // std::exception? try-catch?
            cout << "Problem med att ladda bild." << endl;
            return;
        }
        
        // Tilldela den optimerade bilden
        img = optimizedImage;
        
        cout << "Tilldelad optimerad bild. refcount=" << img->refcount << endl;
        
    }
    
    Image::Image(const Image& other)
    {
        cout << "Image skapad som kopia." << endl;
        
        img = other.img;
        isTransparent = other.isTransparent;
        
        img->refcount++;
    }
    
    const Image& Image::operator=(const Image& other)
    {
        cout << "Image skapad via tilldelning." << endl;
        
        if (img != other.img){
            SDL_FreeSurface(img);
            img = other.img;
            isTransparent = other.isTransparent;
            if (img != NULL)
                img->refcount++;
        }
        // Returnera objektpekare, för att möjliggöra kedjad tilldelning
        return *this;
    }
    
    SDL_Surface* Image::getSurface() const
    {
        return img;
    }
    
    Image::~Image()
    {
        cout << "Destructor called. Refcount: " << img->refcount << endl;
        
        if (img != NULL) {
            SDL_FreeSurface(img);
        }
        
        
    } // ~Image()
    
}
