#pragma once

#include "player.h"
#include "board.h"
#include "fruit.h"
#include "rng.h"

class Game {
private:
	Random& rng;
	int height, width;
	static constexpr int cellWidth = 30;
	Board board;
	Fruit fruit;
	Player snake;
	bool gameOver;

	void handleInput();
	void update();
	void checkCollision();
	void draw();
public:
	Game(Random& rng, int height, int width);
	void run();
};
