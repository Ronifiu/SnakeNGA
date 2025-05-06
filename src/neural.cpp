#include "neural.h"

using namespace std;

NeuralNetwork::NeuralNetwork(Random& rng, int inputSize, int firstHiddenSize, int secondHiddenSize, int outputSize) : rng(rng) {
    inputToHidden = randomMatrix(inputSize, firstHiddenSize);
    hiddenToHidden = randomMatrix(firstHiddenSize, secondHiddenSize);
    hiddenToOutput = randomMatrix(secondHiddenSize, outputSize);
    firstHiddenBias = randomVector(firstHiddenSize);
    secondHiddenBias = randomVector(secondHiddenSize);
    outputBias = randomVector(outputSize);
}

vector<double> NeuralNetwork::forward(vector<double> inputs) {
    vector<double> hidden1 = activate(matrixMultiply(inputs, inputToHidden, firstHiddenBias));
    vector<double> hidden2 = activate(matrixMultiply(hidden1, hiddenToHidden, secondHiddenBias));
    vector<double> output = softmax(matrixMultiply(hidden2, hiddenToOutput, outputBias));
    return output;
}

vector<vector<double>> NeuralNetwork::randomMatrix(int rows, int cols) {
    vector<vector<double>> matrix(rows, vector<double>(cols));
    for (auto& row : matrix) {
        for (auto& val : row) {
            val = rng.getDouble(-1, 1);
        }
    }
    return matrix;
}

vector<double> NeuralNetwork::randomVector(int size) {
    vector<double> vector(size);
    for (auto& val : vector) {
        val = rng.getDouble(-1, 1);
    }
    return vector;
}

vector<double> NeuralNetwork::matrixMultiply(const vector<double>& input, const vector<vector<double>>& weights, const vector<double>& bias) {
    vector<double> output(weights[0].size(), 0.0);
    for (size_t j = 0; j < weights[0].size(); j++) {
        for (size_t i = 0; i < input.size(); i++) {
            output[j] += input[i] * weights[i][j];
        }
        output[j] += bias[j];
    }
    return output;
}

vector<double> NeuralNetwork::activate(vector<double> values) {
    for (double& val : values) {
        val = max(0.0, val);
    }
    return values;
}

vector<double> NeuralNetwork::softmax(vector<double> values) {
    double maxVal = *max_element(values.begin(), values.end()); 
    double sum = 0.0;
    for (double& val : values) {
        val = exp(val - maxVal);
        sum += val;
    }
    for (double& val : values) {
        val /= sum;
    }
    return values;
}
