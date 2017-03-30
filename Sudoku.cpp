/* 
 * File:   Sudoku.cpp
 * Author: Claire McCarthy - clmccart
 * 
 * FILENAME:
 * Sudoku.cpp
 * FUNCTIONAL DESCRIPTION:
 *    cpp file for the Sudoku class. Contains the function definitions for the 
 *    Sudoku constructor and solve method. Uses the Board and the Move classes
 *    in the solve function in order to complete the sudoku board. 
 * COPYRIGHT NOTICE:
 *    Copyright (C) April 24th Claire McCarthy All Rights Reserved.
 * 
 * Created on April 16, 2015, 6:38 AM
 */

#include "Sudoku.h"
#include "Board.h"
#include "Move.h"
#include <vector>
#include <iostream>
using namespace std;

/*
 * Function Name: Sudoku - constructor for the Sudoku class
 * Functional Description: 
 * Calls upon the solve method in the Sudoku class 
 * Entry Parameters: none
 * Return Values: none
 */
Sudoku::Sudoku() {
   
}
/*
 * Function Name: solve - solves the sudoku puzzle
 * Functional Description: 
 * While the board is incomplete, a new move will be created. If the move is
 * legal, it will be pushed onto the stack. If the move is not legal, the move
 * will be popped off the stack and a new move will be tried.  
 * Entry Parameters: none
 * Return Values: void
 */
void Sudoku::solve() {
    Board board = Board();
    Move move1 = board.nextMove(1);
    int r = move1.getRow();
    int c = move1.getCol();
    int val = move1.getValue();
    while (board.legalMove(move1) == false) {
        r = move1.getRow();
        c = move1.getCol();
        val = move1.getValue();
        val = val + 1;
        board.setValue(r, c, 0);
        move1 = board.nextMove(val);
        
    }
    moveStack.push_back(move1);
    
   
    while (board.success(move1) == false) {
       
        if (board.anotherMoveExists() == true) {   
            move1 = board.nextMove(1);
            while (board.legalMove(move1) == false) {
                r = move1.getRow();
                c = move1.getCol();
                val = move1.getValue();
                val = val + 1;
                board.setValue(r, c, 0);
                move1 = board.nextMove(val);
                
            }
            moveStack.push_back(move1);
        }
        else {
                //while needs to backtrack...
                while (board.legalMove(move1) == false) {

                    move1 = moveStack.back();
                    r = move1.getRow();
                    c = move1.getCol();
                    val = move1.getValue();

                    moveStack.pop_back(); 
                    board.setValue(r, c, 0);
                    move1 = board.nextMove(val + 1);

                    if (board.legalMove(move1)) {

                        moveStack.push_back(move1); 
                        break;
                    }
                }
        }
        
    }
    
    cout << "The Solution:" << endl;

    board.printBoard();     
}

