
#include <list>
#include <iostream>
#include "sudoku_helper.h"

bool IsValid(const int _cell[PANEL_SIZE][PANEL_SIZE]) {

    bool bRet = true;

    // 行チェック.
    for (int row = 0; row < PANEL_SIZE; ++row) {
        bRet &= IsValidRow( _cell, row);
    }

    // 列チェック.
    for (int col = 0; col < PANEL_SIZE; ++col) {
        bRet &= IsValidColumn( _cell, col);
    }

    // ブロックチェック.
    for ( int block = eBLOCK_START; block < eBLOCK_NUM; ++block) {
        bRet &= IsValidBlock( _cell, (eBLOCK)block);
    }

    return bRet;

}

bool IsValidRow( const int _cell[PANEL_SIZE][PANEL_SIZE], int _row) {

    std::list<int> ilist;
    for (int i = 0; i < PANEL_SIZE; ++i) {
        ilist.push_back(i+1);
    }

    for (int col = 0; col < PANEL_SIZE; ++col) {
        int value = _cell[_row][col];
        ilist.remove(value);
    }

    return ilist.empty();
}

bool IsValidColumn( const int _cell[PANEL_SIZE][PANEL_SIZE], int _col) {

    std::list<int> ilist;
    for (int i = 0; i < PANEL_SIZE; ++i) {
        ilist.push_back(i+1);
    }

    for (int row = 0; row < PANEL_SIZE; ++row) {
        int value = _cell[row][_col];
        ilist.remove(value);
    }

    return ilist.empty();
}

bool IsValidBlock( const int _cell[PANEL_SIZE][PANEL_SIZE], eBLOCK _block) {

    struct SBlockStat {
        int lower_row;
        int upper_row;
        int lower_col;
        int upper_col;
    };

    static const SBlockStat blocksts[PANEL_SIZE] = {
        //              upper_row,   lower_row,  upper_col,  lower_col,
        /*left   top*/  { 0, 2, 0, 2 },
        /*center top*/  { 0, 2, 3, 5 },
        /*right  top*/  { 0, 2, 6, 8 },
        /*left   mid*/  { 3, 5, 0, 2 },
        /*center mid*/  { 3, 5, 3, 5 },
        /*right  mid*/  { 3, 5, 6, 8 },
        /*left   bot*/  { 6, 8, 0, 2 },
        /*center bot*/  { 6, 8, 3, 5 },
        /*right  bot*/  { 6, 8, 6, 8 },
    };

    std::list<int> ilist;
    for (int i = 0; i < PANEL_SIZE; ++i) {
        ilist.push_back(i+1);
    }

    SBlockStat block = blocksts[_block];
    for (int row = block.lower_row; row <= block.upper_row; ++row) {
        for (int col = block.lower_col; col <= block.upper_col; ++col) {
            int value = _cell[row][col];
            ilist.remove(value);
        }
    }
    
    return ilist.empty();
}

void PrintHLine() {
    for (int col = 0; col < PANEL_SIZE; ++col) {
        if (col % 3 == 0) std::cout << " ";
        std::cout << "-";
    }
    std::cout << std::endl;
}

void PrintCells( const int _cell[PANEL_SIZE][PANEL_SIZE]){

    PrintHLine();
    for (int row = 0; row < PANEL_SIZE; ++row) {
        std::cout << "|";
        for (int col = 0; col < PANEL_SIZE; ++col) {
            std::cout << _cell[row][col];
            if (col % 3 == 2) std::cout << "|";
        }
        std::cout << std::endl;
        if (row % 3 != 2) continue;
        PrintHLine();
    }

}