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
  virtual ~Sprite();
  virtual void update(int /*elapsed_time_ms*/) {}
  void draw(Graphics &graphics, int x, int y);

private:
  SDL_Surface *sprite_sheet;

protected:
  SDL_Rect source_rect;
};

#endif