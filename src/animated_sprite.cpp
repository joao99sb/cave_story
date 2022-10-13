#include "animated_sprite.h"
#include "game.h"
AnimatedSprite::AnimatedSprite(
    const std::string &file_path,
    int source_x, int source_y,
    int width, int height,
    int fps, int frames_num) : Sprite(file_path, source_x, source_y, width, height),
                               frame_time(1000 / fps),
                               frames_num(frames_num),
                               current_frame(0),
                               elapsed_time(0)
{
}

void AnimatedSprite::update(int elapsed_time_ms)
{
  elapsed_time += elapsed_time_ms;
  if (elapsed_time > frame_time)
  {
    ++current_frame;
    elapsed_time = 0;
    if (current_frame < frames_num)
    {
      source_rect.x += Game::Tile_size;
    }
    else
    {
      source_rect.x -= Game::Tile_size * (frames_num - 1);
      current_frame = 0;
    }
  }
}
