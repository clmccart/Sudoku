/* 
 * File:   main.cpp
 * Author: Claire McCarthy - clmccart
 * 
 * FILENAME:
 * main.cpp
 * FUNCTIONAL DESCRIPTION:
 *    Creates a Sudoku board. 
 * COPYRIGHT NOTICE:
 *    Copyright (C) April 24th Claire McCarthy All Rights Reserved.
 * 
 * Created on April 16, 2015, 6:38 AM
 */

#include <cstdlib>
#include "Board.h"
#include "Move.h"
#include "Sudoku.h"
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    
    Sudoku sudoku = Sudoku();
  
    sudoku.solve(); 
    
    return (EXIT_SUCCESS);
}

