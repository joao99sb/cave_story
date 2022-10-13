#include <cmath>
#include "player.h"
#include "game.h"
#include "animated_sprite.h"

namespace
{
  const float walkingAcceleration = 0.00000015f; // pixels/ms²
  const float maxSpeed = 0.00325f;
  const float slowDownFactor = 0.6f;
}

Player::Player(int x, int y) : _x(x), _y(y), velocity_x(0)
{
  sprite.reset(new AnimatedSprite("content/MyChar.bmp",
                                  0, 0,
                                  Game::Tile_size, Game::Tile_size,
                                  15, 11));
}

void Player::update(int elapsed_time_ms)
{
  sprite->update(elapsed_time_ms);
  _x += round(velocity_x * elapsed_time_ms);
  _y += round(velocity_y * elapsed_time_ms);
  velocity_x += acceleration_x * elapsed_time_ms;
  velocity_y += acceleration_y * elapsed_time_ms;

  if (acceleration_x < 0.0f)
  {
    velocity_x = std::max(velocity_x, -maxSpeed);
  }
  else if (acceleration_x > 0.0f)
  {
    velocity_x = std::min(velocity_x, maxSpeed);
  }
  else
  {
    velocity_x *= slowDownFactor;
  }

  if (acceleration_y < 0.0f)
  {
    velocity_y = std::max(velocity_y, -maxSpeed);
  }
  else if (acceleration_y > 0.0f)
  {
    velocity_y = std::min(velocity_y, maxSpeed);
  }
  else
  {
    velocity_y *= slowDownFactor;
  }
}

void Player::draw(Graphics &graphics)
{
  sprite->draw(graphics, _x, _y);
}

void Player::startMovingL()
{
  acceleration_x = -walkingAcceleration;
}
void Player::startMovingR()
{
  acceleration_x = +walkingAcceleration;
}

void Player::startMovingUp()
{
  acceleration_y = -walkingAcceleration;
}

void Player::startMovingDown()
{
  acceleration_y = +walkingAcceleration;
}

void Player::stopMovingX()
{
  acceleration_x = 0.0f;
}
void Player::stopMovingY()
{
  acceleration_y = 0.0f;
}