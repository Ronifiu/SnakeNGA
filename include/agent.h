#pragma once

#include "snake.h"
#include "neural.h"

class Agent : public Snake {
private:
	Random& rng;
	NeuralNetwork nn;
	double fitness;

	void updateFitness();
	std::vector<double> getInputs();
	bool isOpposite(Direction dir1, Direction dir2);
	std::vector<double> distFruit();
public:
	Agent(Random& rng, Position startPos) : Snake(startPos, Direction::RIGHT), rng(rng), nn(rng, 24, 16, 16, 4), fitness(0) {}

	void handleInput() override;
	double getFitness() const {return fitness;}
};

