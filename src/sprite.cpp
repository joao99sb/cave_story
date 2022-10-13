#include "sprite.h"

Sprite::Sprite(
    const std::string &file_path,
    int source_x, int source_y,
    int width, int height)
{
  const bool black_is_transparent = true;
  sprite_sheet = SDL_LoadBMP(file_path.c_str());
  source_rect.x = source_x;
  source_rect.y = source_y;
  source_rect.w = width;
  source_rect.h = height;
}

void Sprite::draw(Graphics &graphics, int x, int y)
{
  SDL_Rect destination_rect;
  destination_rect.x = x;
  destination_rect.y = y;
  graphics.blitSurface(sprite_sheet, &source_rect, &destination_rect);
}
Sprite::~Sprite()
{
  SDL_FreeSurface(sprite_sheet);
}
