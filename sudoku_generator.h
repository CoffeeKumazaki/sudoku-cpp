#pragma once


#include "sudoku_helper.h"

class CSudokuGenerator {

public:

public:
    CSudokuGenerator();
    ~CSudokuGenerator(){};

    void reset();
    void generate( int _seed);
    void getPuzzle( int _cell[PANEL_SIZE][PANEL_SIZE]);
    void getAnswer( int _cell[PANEL_SIZE][PANEL_SIZE]);

private:


private:
    int answer[PANEL_SIZE][PANEL_SIZE];
    int puzzle[PANEL_SIZE][PANEL_SIZE];

};