#ifndef INPUT_H_
#define INPUT_H_

#include<map>
#include<SDL/SDL.h>

struct Input
{
  void beginNewFrame();

  void keyUpEvent(const SDL_Event& event);
  void keyDownEvent(const SDL_Event& event);

  bool wasKeyPressed(SDLKey key);
  bool wasKeyReleased(SDLKey key);
  bool isKeyHeld(SDLKey key);

  private:
  std::map<SDLKey,bool> held_keys;
  std::map<SDLKey,bool> pressed_keys;
  std::map<SDLKey,bool> released_keys;
};


#endif