#pragma once


struct Position {
    int x;
    int y;

    Position(int x, int y) : x(x), y(y) {}

    bool operator==(const Position& other) const {
        return x == other.x && y == other.y;
    }

    bool operator!=(const Position& other) const {
        return !(*this == other);
    }

    Position operator+(const Position& other) const {
        return {x + other.x, y + other.y};
    }

    Position& operator+=(const Position& other) {
        x += other.x;
        y += other.y;
        return *this;
    }
};
