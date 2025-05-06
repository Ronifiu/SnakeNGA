#pragma once

#include "agent.h"

class GeneticAlgorithm {
private:
	std::vector<Agent&> population;
	void evolve(std::vector<double> fitness);
	void selection();
	void crossover();
	void mutation();
};
