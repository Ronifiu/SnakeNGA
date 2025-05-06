#pragma once

#include <vector>
#include <algorithm>
#include "rng.h"

class NeuralNetwork {
private:
	Random& rng;
	std::vector<std::vector<double>> inputToHidden;
	std::vector<std::vector<double>> hiddenToHidden;
	std::vector<std::vector<double>> hiddenToOutput;
	std::vector<double> firstHiddenBias;
	std::vector<double> secondHiddenBias;
	std::vector<double> outputBias;
	
	std::vector<std::vector<double>> randomMatrix(int rows, int cols);
	std::vector<double> randomVector(int size);
	std::vector<double> matrixMultiply(const std::vector<double>& input, const std::vector<std::vector<double>>& weights, const std::vector<double>& bias);
	std::vector<double> activate(std::vector<double> values);
	std::vector<double> softmax(std::vector<double> values);
public:
	NeuralNetwork(Random& rng, int inputSize, int firstHiddenSize, int secondHiddenSize, int outputSize);
	std::vector<double> forward(std::vector<double> inputs);
};

