#include "game.h"
#include "animated_sprite.h"
#include "input.h"
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

// static
int Game::Tile_size = 32;

void Game::eventLoop()
{
  /// while(runnig) ~60 Hz
  //  Handle input. Hanle timer callbacks.
  //
  //  update(). Move the Player. Move projectiles; check collisions
  //  draw() draw every thing!

  Graphics graphics;

  Input input;
  sprite.reset(new AnimatedSprite("content/MyChar.bmp", 0, 0, Tile_size, Tile_size, 15, 3));

  auto x = sprite.get();

  SDL_Event event;

  runnig = true;

  int last_updated_time = SDL_GetTicks();
  while (runnig)
  {
    input.beginNewFrame();
    const int start_time_ms = SDL_GetTicks();
    while (SDL_PollEvent(&event))
    {
      switch (event.type)
      {
      case SDL_KEYDOWN:
        input.keyDownEvent(event);
        break;
      case SDL_KEYUP:
        input.keyUpEvent(event);
        break;
      default:
        break;
      }
    }
    if (input.wasKeyPressed(SDLK_ESCAPE))
    {
      runnig = false;
    }
    const int current_time_ms = SDL_GetTicks();

    update(current_time_ms - last_updated_time);

    draw(graphics);
    const int elapsed_time_ms = SDL_GetTicks() - start_time_ms;

    // this loop last 1/60 of seconds  1000/60th ms
    const float delay = 1000 /*ms*/ / (kFps - elapsed_time_ms); /*fps*/
    SDL_Delay(delay);
  }
}

void Game::update(int elapsed_time_ms)
{
  sprite->update(elapsed_time_ms);
}

void Game::draw(Graphics &graphics)
{
  sprite->draw(graphics, 30, 240);
  graphics.flip();
}