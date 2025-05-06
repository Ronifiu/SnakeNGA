#include "game.h"
#include <raylib.h>

void Game::run() {
	InitWindow(width * cellWidth, height * cellWidth, "SnakeGA");
	SetTargetFPS(10);

	// game loop:
	while (!WindowShouldClose() && !gameOver) {
		// update:
		handleInput();
		update();
		checkCollision();

		// render:
		BeginDrawing();
		ClearBackground(BLACK);
		draw();
		EndDrawing();
	}

	CloseWindow();
}

Game::Game(Random& rng, int height, int width) : 
	rng(rng), height(height), width(width), board(Board(height, width)), fruit(Fruit(rng, height, width)), snake(Player(Position(10, 15))), gameOver(false) {}

void Game::handleInput() {
	snake.handleInput();
}

void Game::update() {
	snake.update();
}

void Game::checkCollision() {
	Position head = snake.getHead();
	Position fruitPos = fruit.getPos();

	if (head == fruitPos) {
		snake.grow();
		fruit.respawn();
	}
	if (head.x < 0 || head.x >= width || head.y < 0 || head.y >= height) gameOver = true;
	if (snake.collideWithSelf()) gameOver = true;
}


void Game::draw() {
	board.draw();
	snake.draw();
	fruit.draw();
}
