#include "player.h"

void Player::handleInput() {
    if (IsKeyPressed(KEY_RIGHT) && dir != Direction::LEFT) dir = Direction::RIGHT;
    if (IsKeyPressed(KEY_DOWN) && dir != Direction::UP) dir = Direction::DOWN;
    if (IsKeyPressed(KEY_LEFT) && dir != Direction::RIGHT) dir = Direction::LEFT;
    if (IsKeyPressed(KEY_UP) && dir != Direction::DOWN) dir = Direction::UP;
}

