#include "agent.h"
#include "snake.h"

using namespace std;

void Agent::handleInput() {
    vector<double> inputs = getInputs();
    vector<double> outputs = nn.forward(inputs);

    int bestMove = 0;
    double bestVal = outputs[0];

    for (int i = 1; i < outputs.size(); i++) {
        if (outputs[i] > bestVal) {
            bestVal = outputs[i];
            bestMove = i;
        }
    }
    Direction nextMove = static_cast<Direction>(bestMove);

    if (!isOpposite(nextMove, dir)) dir = nextMove;
}


bool Agent::isOpposite(Direction dir1, Direction dir2) {
    return (dir1 == Direction::UP && dir2 == Direction::DOWN) ||
           (dir1 == Direction::DOWN && dir2 == Direction::UP) ||
           (dir1 == Direction::RIGHT && dir2 == Direction::LEFT) ||
           (dir1 == Direction::LEFT && dir2 == Direction::RIGHT);
}
