#ifndef GAME_H_
#define GAME_H_

#include <SDL/SDL.h>
#include <boost/scoped_ptr.hpp>
#include "sprite.h"

struct Game
{
  Game();
  ~Game();

private:
  void eventLoop();
  void update();
  void draw(Graphics &graphics);
  bool runnig;

  // to know more about scoped_ptr: https://www.boost.org/doc/libs/1_61_0/libs/smart_ptr/scoped_ptr.htm
  //basically this template class guarantees deletion of the pointer

  boost::scoped_ptr<Sprite> sprite;
};

#endif