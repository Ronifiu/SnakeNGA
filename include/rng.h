#pragma once
#include <random>

class Random {
public:
    Random();
    // Constructor with fixed seed (for reproducibility)
    Random(unsigned int seed);

    // Random integer in [min, max]
    int getInt(int min, int max);

    // Random double in [min, max]
    double getDouble(double min, double max);

    // Random boolean
    bool getBool();

private:
    std::mt19937 engine;
};
