#ifndef SPRITE_H_
#define SPRITE_H_
#include <string>
#include <SDL/SDL.h>
#include "graphics.h"

struct Graphics;

struct Sprite
{
  Sprite(
      const std::string &file_path,
      int source_x, int source_y,
      int width, int height);
  ~Sprite();

  void draw(Graphics &graphics, int x, int y);

private:
  SDL_Surface *sprite_sheet;

protected:
  SDL_Rect source_rect;
};

#endif