#pragma once

#include "position.h"
#include <deque>
#include <raylib.h>

enum class Direction {
	UP,
	DOWN,
	RIGHT,
	LEFT
}; 

class Snake {
protected:
	static constexpr int size = 30;
	std::deque<Position> body;
	Direction dir;
	int tailLenght;

	Snake(Position startPos, Direction startDir) : dir(startDir), tailLenght(1) {
		body.push_front(startPos);
	}
public:
	virtual ~Snake() = default;
	virtual void update();
	virtual void handleInput() = 0;
	virtual void draw();
	virtual void grow();
	virtual bool collideWithSelf();

	const std::deque<Position>& getBody() const {return body;}
	Position getHead() const {return body.front();}
};

