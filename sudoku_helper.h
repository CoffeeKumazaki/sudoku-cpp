#pragma once

static const int PANEL_SIZE = 9;

enum eBLOCK {
    eBLOCK_START = 0,
    eBLOCK_LT = eBLOCK_START,
    eBLOCK_CT,
    eBLOCK_RT,
    eBLOCK_LM,
    eBLOCK_CM,
    eBLOCK_RM,
    eBLOCK_LB,
    eBLOCK_CB, 
    eBLOCK_RB,
    eBLOCK_NUM,
};

bool IsValid( const int _cell[PANEL_SIZE][PANEL_SIZE]);                     // answerが正しいかを判定する
bool IsValidRow( const int _cell[PANEL_SIZE][PANEL_SIZE], int _row);        // answerの行要素が正しいか判定する.
bool IsValidColumn( const int _cell[PANEL_SIZE][PANEL_SIZE], int _col);     // answerの列要素が正しいか判定する.
bool IsValidBlock( const int _cell[PANEL_SIZE][PANEL_SIZE], eBLOCK _block); // answerのブロック要素が正しいか判定する.


void PrintCells( const int _cell[PANEL_SIZE][PANEL_SIZE]); 