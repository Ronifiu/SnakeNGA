#include "board.h"

using namespace std;

Board::Board(int width, int height) : width(width), height(height), grid(height, vector<CellType>(width, CellType::EMPTY)) {}

void Board::draw() {
    for (int i = 0; i < width; i++) {
        DrawLine(i*cellWidth, 0, i*cellWidth, height*cellWidth, GRAY);
    }
    for (int i = 0; i < height; i++) {
        DrawLine(0, i*cellWidth, width*cellWidth, i*cellWidth, GRAY);
    }
}
