#include "snake.h"

void Snake::draw() {
    for (const auto& segment : body) {
        DrawRectangle(segment.x * size, segment.y * size, size, size, GREEN);
    }
}

void Snake::update() {
    Position movement = {0, 0};

    switch(dir) {
        case(Direction::UP) : movement.y = -1; break;
        case(Direction::DOWN) : movement.y = 1; break;
        case(Direction::RIGHT) : movement.x = 1; break;
        case(Direction::LEFT) : movement.x = -1; break;
    }
    
    movement += body.at(0);
    body.push_front(movement);
    if (body.size() > tailLenght) body.pop_back();
}

void Snake::grow() {
    tailLenght++;
}

bool Snake::collideWithSelf() {
    Position head = body.front();

    for (int i = 1; i < body.size(); i++) {
        if (body[i] == head) return true;
    }
    return false;
}
