/* 
 * File:   Sudoku.h
 * Author: Claire McCarthy - clmccart
 * 
 * FILENAME:
 * Sudoku.h
 * FUNCTIONAL DESCRIPTION:
 *    .h file contains the function protoypes for the Sudoku class and the 
 *    definition of the vector of moves that will function as our stack. 
 * COPYRIGHT NOTICE:
 *    Copyright (C) April 24th Claire McCarthy All Rights Reserved.
 * 
 * Created on April 16, 2015, 6:38 AM
 */

#ifndef SUDOKU_H
#define	SUDOKU_H

#include <cstdlib>
#include <iostream> 
#include <string>
#include <fstream>
#include <vector> 
#include "Board.h"
#include "Move.h"


using namespace std;

class Sudoku {
public:
    Sudoku();
    void solve();

private:
    vector<Move> moveStack; 
};

#endif	/* SUDOKU_H */

