#ifndef GRAPHICS_H_
#define GRAPHICS_H_
#include <SDL/SDL.h>
#include <iostream>
#include <map>

struct Graphics
{
  Graphics();
  ~Graphics();

  void blitSurface(SDL_Surface *source,
                   SDL_Rect *source_rectangle,
                   SDL_Rect *destination_rectangle);
  void clear();
  void flip();

private:
  SDL_Surface *window;
};

#endif // GRAPHICS_H_