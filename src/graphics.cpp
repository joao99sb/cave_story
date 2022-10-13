#include "graphics.h"

namespace
{
  const int kScreenWidth = 1280;
  const int kScreenHeight = 720;
  const int kBitsPerPixel = 32;

}

Graphics::Graphics()
{
  window = SDL_SetVideoMode(kScreenWidth, kScreenHeight, kBitsPerPixel,  SDL_FULLSCREEN);
}

Graphics::~Graphics()
{
  SDL_FreeSurface(window);
}
 
void Graphics::blitSurface(SDL_Surface *source,
                           SDL_Rect *source_rectangle,
                           SDL_Rect *destination_rectangle)
{
  SDL_BlitSurface(source, source_rectangle, window, destination_rectangle);
}

void Graphics::flip() 
{
  SDL_Flip(window);
}