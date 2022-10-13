#include "input.h"

void Input::beginNewFrame()
{
  pressed_keys.clear();
  released_keys.clear();
}

void Input::keyUpEvent(const SDL_Event &event)
{
  pressed_keys[event.key.keysym.sym] = true;
  held_keys[event.key.keysym.sym] = true;
}
void Input::keyDownEvent(const SDL_Event &event)
{
  released_keys[event.key.keysym.sym] = true;
  held_keys[event.key.keysym.sym] = false;
}

bool Input::wasKeyPressed(SDLKey key)
{
  return pressed_keys[key];
}
bool Input::wasKeyReleased(SDLKey key)
{
  return released_keys[key];
}
bool Input::isKeyHeld(SDLKey key)
{
  return held_keys[key];
}