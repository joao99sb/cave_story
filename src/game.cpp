#include "game.h"

Game::Game()
{
  SDL_Init(SDL_INIT_EVERYTHING);
  screen = SDL_CreateWindow("My Game ",
                            SDL_WINDOWPOS_CENTERED,
                            SDL_WINDOWPOS_CENTERED,
                            0, 0,
                            SDL_WINDOW_FULLSCREEN);
  eventLoop();
}

Game::~Game()
{
  SDL_DestroyWindow(screen);
  SDL_Quit();
}

void Game::eventLoop()
{
  SDL_Event event;
  /// while(runnig) ~60 Hz
  //  Handle input. Hanle timer callbacks.
  //
  //  update(). Move the Player. Move projectiles; check collisions
  //  draw() draw every thing!

  bool runnig = true;
  while (runnig)
  {
    const int start_time_ms = SDL_GetTicks();
    while (SDL_PollEvent(&event))
    {
      switch (event.type)
      {
      case SDL_KEYDOWN:
        if (event.key.keysym.sym == SDLK_ESCAPE)
        {
          runnig = false;
        }
        break;
      default:
        break;
      }
    }

    update();
    draw();
    const int elapsed_time_ms = SDL_GetTicks() - start_time_ms;
    // this loop last 1/60 of seconds  1000/60th ms
    SDL_Delay(1000 /*ms*/ / 60 - elapsed_time_ms /*fps*/);
  }
}

void Game::update()
{
}

void Game::draw()
{
}