#pragma once


class Game {
private:
	Board& board;
	Fruit& fruit;
	Snake& snake;
	void update();
	void checkCollision();
	void draw();
public:
	void run();
};

class Board {
private:
	int width, height;
	std::vector<std::vector<CellType>> grid;
};

class Fruit {
	Position pos;
	void respawn(Board&);
};

class Snake {
protected:
	std::deque<Position> body;
	Direction dir;
public:
	virtual void update(Board&, Fruit&) = 0;
};

class Agent : public Snake {
private:
	NeuralNetwork nn;
public:
	void update(Board&, Fruit&) override;
	double fitness;
};

class NeuralNetwork {
private:
	std::vector<std::vector<double>> inputToHidden;
	std::vector<std::vector<double>> hiddenToHidden;
	std::vector<double> firstHiddenBias;
	std::vector<double> secondHiddenBias;
	std::vector<double> outputBias;
	
	std::vector<double> forward(std::vector<double> inputs);
	std::vector<std::vector>> randomMatrix(int rows, int cols);
	std::vector<double> randomVector(int size);
	std::vector<double> matrixMultiply(const std::vector<double>& input, const std::vector<std::vector<double>>& weights, const std::vector<double>& bias);
	std::vector<double> activate(std::vector<double> values);
	std::vector<double> softmax(std::vector<double> values);
public:
	NeuralNetwork(int inputSize, int firstHiddenSize, int secondHiddenSize, int outputSize);
};

class GeneticAlgorithm {
private:
	std::vector<Agent&> population;
	void evolve(std::vector<double> fitness);
	void selection();
	void crossover();
	void mutation();
}
