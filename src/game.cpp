#include "game.h"

namespace
{
  const int kScreenWidth = 1280;
  const int kScreenHeight = 720;
  const int kBitsPerPixel = 32;
  const int kFps = 60;
}

Game::Game()
{
  SDL_Init(SDL_INIT_EVERYTHING);
  SDL_ShowCursor(SDL_DISABLE);
  screen = SDL_CreateWindow("My Game ",
                            SDL_WINDOWPOS_CENTERED,
                            SDL_WINDOWPOS_CENTERED,
                            kScreenWidth, kScreenHeight,
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
    const int start_time_ms = SDL_GetTicks64();
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
    const int elapsed_time_ms = SDL_GetTicks64() - start_time_ms;
    // this loop last 1/60 of seconds  1000/60th ms
    const float delay = 1000 /*ms*/ / (kFps - elapsed_time_ms); /*fps*/
    SDL_Delay(delay);

    const int fps = 1000.0 / (SDL_GetTicks64() - start_time_ms);
    printf("fps=%d\n", fps);
  }
}

void Game::update()
{
}

void Game::draw()
{
}