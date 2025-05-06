#pragma once

#include "snake.h"

class Player : public Snake {
public:
	Player(Position startPos) : Snake(startPos, Direction::RIGHT) {}

	void handleInput() override;
};
