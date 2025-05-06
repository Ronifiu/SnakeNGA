#pragma once

#include <raylib.h>
#include "position.h"
#include "rng.h"

class Fruit {
private:
	static constexpr int cellWidth = 30;
	static constexpr int radius = 10;
	Random& rng;
	int height, width;
	Position pos;
	Position getRandomPos();
public:
	Fruit(Random& rng, int height, int width);
	void draw();
	void respawn();
	Position getPos() const {return pos;}
};


