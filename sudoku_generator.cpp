
#include <list>
#include "sudoku_generator.h"

CSudokuGenerator::CSudokuGenerator()
{
    reset();
}

void CSudokuGenerator::reset() {
    
    for (int row = 0; row < PANEL_SIZE; ++row) {
        for (int col = 0; col < PANEL_SIZE; ++col) {
            puzzle[row][col] = 0;
            answer[row][col] = (row + col ) % PANEL_SIZE + 1;
        }
    }
}

void CSudokuGenerator::generate(int _seed) {

    reset();
    std::swap(answer[1], answer[3]);
    std::swap(answer[2], answer[6]);
    std::swap(answer[5], answer[7]);

}

void CSudokuGenerator::getPuzzle(int _cell[PANEL_SIZE][PANEL_SIZE]) {

    for (int row = 0; row < PANEL_SIZE; ++row) {
        for (int col = 0; col < PANEL_SIZE; ++col) {
            _cell[row][col] = puzzle[row][col];
        }
    }
}

void CSudokuGenerator::getAnswer( int _cell[PANEL_SIZE][PANEL_SIZE]) {

    for (int row = 0; row < PANEL_SIZE; ++row) {
        for (int col = 0; col < PANEL_SIZE; ++col) {
            _cell[row][col] = answer[row][col];
        }
    }
}
