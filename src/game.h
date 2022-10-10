#ifndef GAME_H_
#define GAME_H_
#include <SDL2/SDL.h>

struct SDL_Window;

struct Game
{
  Game();
  ~Game();

private:
  void eventLoop();
  void update();
  void draw();

  SDL_Window *screen;
};

#endif