#include "fruit.h"


Fruit::Fruit(Random& rng, int height, int width) :
    rng(rng), height(height), width(width), pos(getRandomPos()) {}

Position Fruit::getRandomPos() {
    return Position(rng.getInt(0, width-1), rng.getInt(0, height - 1));
}

void Fruit::draw() {
    DrawCircle(pos.x * cellWidth + cellWidth/2, pos.y * cellWidth + cellWidth/2, radius, RED);
}

void Fruit::respawn() {
    pos = getRandomPos();
}
