#ifndef PLAYER_H_
#define PLAYER_H_

#include <boost/scoped_ptr.hpp>
#include "sprite.h"

struct Player
{
  Player(int x, int y);
  void update(int elapsed_time_ms);
  void draw(Graphics &graphics);
  void startMovingL();
  void startMovingR();
  void stopMovingX();
  void stopMovingY();
  void startMovingUp();
  void startMovingDown();

private:
  boost::scoped_ptr<Sprite> sprite;
  int _x, _y;
  float acceleration_x, velocity_x ;
  float acceleration_y, velocity_y ;
};

#endif