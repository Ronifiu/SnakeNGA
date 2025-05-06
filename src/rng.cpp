#include "rng.h"

using namespace std;

Random::Random()
    : engine(random_device{}()) {}

Random::Random(unsigned int seed)
    : engine(seed) {}

int Random::getInt(int min, int max) {
    uniform_int_distribution<int> dist(min, max);
    return dist(engine);
}

double Random::getDouble(double min, double max) {
    uniform_real_distribution<double> dist(min, max);
    return dist(engine);
}

bool Random::getBool() {
    bernoulli_distribution dist(0.5);
    return dist(engine);
}
