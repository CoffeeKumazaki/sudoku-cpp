
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
