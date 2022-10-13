#include "game.h"
#include "graphics.h"

namespace
{

  const int kFps = 60;
}

Game::Game()
{
  SDL_Init(SDL_INIT_EVERYTHING);
  SDL_ShowCursor(SDL_DISABLE);

  eventLoop();
}

Game::~Game()
{

  SDL_Quit();
}

void Game::eventLoop()
{
  /// while(runnig) ~60 Hz
  //  Handle input. Hanle timer callbacks.
  //
  //  update(). Move the Player. Move projectiles; check collisions
  //  draw() draw every thing!

  Graphics graphics;

  sprite.reset(new Sprite("content/MyChar.bmp", 0, 0, 32, 32));

  auto x = sprite.get();

  SDL_Event event;

  
  runnig = true;

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
    draw(graphics);
    const int elapsed_time_ms = SDL_GetTicks() - start_time_ms;
    // this loop last 1/60 of seconds  1000/60th ms
    const float delay = 1000 /*ms*/ / (kFps - elapsed_time_ms); /*fps*/
    SDL_Delay(delay);

    // const int fps = 1000.0 / (SDL_GetTicks() - start_time_ms);
    // printf("fps=%d\n", fps);
  }
}

void Game::update()
{
}

void Game::draw(Graphics & graphics)
{
  sprite->draw(graphics,30,240);
  graphics.flip();
}