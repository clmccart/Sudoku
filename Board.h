/* 
 * File:   Board.h
 * Author: Claire McCarthy - clmccart
 * 
 * FILENAME:
 * Board.h
 * FUNCTIONAL DESCRIPTION:
 *    .h file for the Board class. Defines function prototypes and private
 *    variables for the Board class. Defines the Board itself, a 2-D array
 *    of ints. Includes the Move.h file so that the two classes can interact. 
 * COPYRIGHT NOTICE:
 *    Copyright (C) April 24th Claire McCarthy All Rights Reserved.
 * 
 * Created on April 16, 2015, 6:38 AM
 */

#ifndef BOARD_H
#define	BOARD_H

#include "Move.h" 
#include "Board.h"
#include "Sudoku.h"

using namespace std;

class Board {
public:
    Board();
    void readPuzzle();
    int getValue(int r, int c);
    void setValue(int r, int c, int val);
    Move nextMove(int nextVal);  
    bool legalMove(Move move1);
    bool success(Move move);
    void printBoard();
    bool checkQuad(int r, int c, int val, int quadrant);
    int getQuad(int r, int c);
    bool anotherMoveExists();
private:
    static const int DIMENSION = 9;
    int board[DIMENSION][DIMENSION];
};

#endif	/* BOARD_H */

