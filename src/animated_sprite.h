#ifndef ANIMATED_SPRITE_H
#define ANIMATED_SPRITE_H

#include "sprite.h"

struct AnimatedSprite : public Sprite
{
  AnimatedSprite(const std::string &file_path,
                 int source_x, int source_y,
                 int width, int height,
                 int fps, int frames_num);
  void update(int elapsed_time_ms);

private:
  const int frame_time;
  const int frames_num;
  int current_frame;
  int elapsed_time; // elapsed time since the last frame change
};

#endif