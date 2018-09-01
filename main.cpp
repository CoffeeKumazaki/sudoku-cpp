#include <iostream>
#include "sudoku_generator.h"

int main (int argc, char **argv) {

    CSudokuGenerator generator;
    int cell[PANEL_SIZE][PANEL_SIZE];

    generator.generate(1);
    generator.getAnswer(cell);

    PrintCells(cell);
    return 0;

}