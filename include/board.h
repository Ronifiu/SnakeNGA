#pragma once

#include <vector>
#include <raylib.h>

enum class CellType {
	SNAKE,
	FRUIT,
	EMPTY
};

class Board {
private:
	int width, height;
	std::vector<std::vector<CellType>> grid;
	static constexpr int cellWidth = 30;
public:
	Board(int width, int height);
	void update();
	void draw();
};

