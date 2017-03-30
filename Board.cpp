/* 
 * File:   Board.cpp
 * Author: Claire McCarthy - clmccart
 * 
 * FILENAME:
 * Board.cpp
 * FUNCTIONAL DESCRIPTION:
 *    cpp file for the Board class. Defines functions used in the board class to 
 *    solve the Sudoku puzzle. Functions as the Sudoku board and interacts with
 *    the Move class by allowing moves to be made on the board. 
 *    
 * COPYRIGHT NOTICE:
 *    Copyright (C) April 24th Claire McCarthy All Rights Reserved.
 * 
 * Created on April 16, 2015, 6:38 AM
 */


#include <iostream> 
#include <fstream> 
#include <vector> 
#include <string>
#include <fstream>
#include "Board.h"
#include "Move.h"
#include "Sudoku.h"

using namespace std;

/*
 * Function Name: Board - constructor for the board class
 * Functional Description: 
 * calls the readPuzzle and printBoard functions
 * Entry Parameters: none
 * Return Values: none
 */
Board::Board() {
    this->readPuzzle(); 
    this->printBoard();
    
}
/*
 * Function Name: readPuzzle - loads the data from the file into a 2-D array
 * Functional Description: 
 * Loads the puzzle from the text file into a two dimensional array of 
 * ints. Checks to make sure that the file isn't empty.
 * Then, enters the first row of the board into the array and then enters the 
 * following rows until there are no more lines to read in the file. 
 * Entry Parameters: none
 * Return Values: void
 */
void Board::readPuzzle() {

    string fileName;
    ifstream puzzleStream;
    // read in the puzzle file name
    do {
        cout << "Enter puzzle file name: " ;
        cin >> fileName;
        puzzleStream.open(fileName, ios::in);
    } while (!puzzleStream.good());      // keep trying until this works
    // read in the digits
    for (int r = 0; r < DIMENSION; r++) {
        for (int c = 0; c < DIMENSION; c++) {
          puzzleStream >> board[r][c];
        }
    }
}
/*
 * Function Name: getValue - gets a value at a place on the board
 * Functional Description: 
 * Accesses the board at the given row and column and returns the value.
 * Entry Parameters: int r, int c - the row and the column
 * Return Values: int - the value at the given row and column
 */
int Board::getValue(int r, int c) {
    return board[r][c];
}
/*
 * Function Name: setValue - sets a value to a place on the board
 * Functional Description: 
 * Accesses the board at the given row and column and changes the value.
 * Entry Parameters: int r, int c, int val - the row, the column, and the new
 * value
 * Return Values: void
 */
void Board::setValue(int r, int c, int val) {
    board[r][c] = val;
}

/*
 * Function Name: nextMove - finds the next legal move available on the board
 * Functional Description: 
 * Finds each open space in the board and creates a move until the move is 
 * legal. Then returns that move. 
 * Entry Parameters: int nextVal - the next value to be tried in the board
 * Return Values: Move
 */
Move Board::nextMove(int nextVal) {
    Move move = Move(0, 0, 0); 
    for (int r = 0; r < DIMENSION; ++r) {
        for (int c = 0; c < DIMENSION; ++c) {
            if (board[r][c] == 0) {
                setValue(r, c, nextVal);
                return move = Move(r, c, nextVal);
                
                
            }        
        }
    }
    
    return move;
}
/*
 * Function Name: legalMove - checks to see if the move is a legal one.
 * Functional Description: 
 * checks each row and column and quadrant to see if there is a 9 present.
 * If there is, returns false. If not, then returns true.
 * Entry Parameters: Move move - the move being made
 * Return Values: boolean
 */
bool Board::legalMove(Move move) {
    
    int col = move.getCol();
    int row = move.getRow();
    int val = move.getValue();
    int quadrant = move.getQuadrant(row, col);
    
    if (val > 9) {
        return false;
    }
    
    if (col < 0 || row < 0 || row >= DIMENSION || col >= DIMENSION) {
       
        return false; 
    
    }
    
    for (int r = 0; r < DIMENSION; ++r) {
      
        if (r != row) {
            
            if (board[r][col] == val) {
                
                return false;
            }
           
        }
        
    }
     
    for (int c = 0; c < DIMENSION; ++c) {
        if (c != col) {
            if (board[row][c] == val) {
                return false;
            }
        }
    }
    
    if (checkQuad(row, col, val, quadrant) == false) {
     
        return false; 
    }
      
    
    
    return true;
    
}
/*
 * Function Name: checkQuad - sees if there is a conflict in the quadrant
 * Functional Description: 
 * Uses nested for loops to cycle through each possible space surrounding the
 * move. If the move and the new move are in the same quadrant, it checks to see
 * if the numerical value on that board are equal. 
 * Entry Parameters: int r, int c, int val, int quadrant - the row and column 
 *  and value representing the position and value of the move that needs to be 
 * checked as well as the quadrant that it is in.
 * Return Values: bool - whether or not it is legal in the quadrant 
 */
bool Board::checkQuad(int r, int c, int val, int quadrant) {
    for (int row = -2; row < 2; row++) {
        for (int col = -2; col < 2; col++) {
            if (c + col < DIMENSION && r + row < DIMENSION && c + col >= 0 &&
                    r + row >= 0 && getQuad(row + r, col + c) == quadrant) {
                if (row != 0 || col != 0) {
                    if (board[r + row][c + col] == val) {
                        return false;
                    }
                }
                   
            }
            
        }
    }
    return true;   
}
/*
 * Function Name: getQuad - returns the quadrant that you are in
 * Functional Description: 
 * Uses 3 sets of nested if statements to return a numerical value representing
 * which quadrant on the sudoku board you are currently in.  
 * Entry Parameters: int r, int c - the row and column representing the position
 * who's quadrant you want to get.
 * Return Values: int - the numerical value of the quadrant 
 */
int Board::getQuad(int r, int c) {
    int dimension = 9;
    if (r < 0 || c < 0 || r >= dimension || c >= dimension) {
        return 0;
    }
    if (r <= 2) {
        if (c <= 2){
            return 1;
        }
        if (c > 2 && c <= 5) {
            return 2;
        }
        if (c > 5) {
            return 3;
        }
    }
    if (r > 2 && r <= 5) {
        if (c <= 2){
            return 4;
        }
        if (c > 2 && c <= 5) {
            return 5;
        }
        if (c > 5) {
            return 6;
        }   
    }
    if (r > 5) {
        if (c <= 2){
            return 7;
        }
        if (c > 2 && c <= 5) {
            return 8;
        }
        if (c > 5) {
            return 9;
        }    
    }
    return 0; 
}
/*
 * Function Name: success - checks whether or not the board is completed
 * Functional Description: 
 * Uses a nested for loop to search for any zeros in the board array. If any
 * zeros are present, it returns false indicating that the board isn't complete.
 * If no zeros are found, it returns true.
 * Entry Parameters: none
 * Return Values: boolean
 */
bool Board::success(Move move) {
    for (int r = 0; r < DIMENSION; ++r) {
        for (int c = 0; c < DIMENSION; ++c) {
            if (board[r][c] == 0) {
                return false;
            }
        }
    }
    
    if (this->legalMove(move) == false) {
        return false;
    }
    return true;
}

/*
 * Function Name: printBoard - prints the puzzle board
 * Functional Description: 
 * Uses a for loop to print out each individual character stored in the two 
 * dimensional array. Changes the characters stored in the array from lower case
 * to upper case letters.
 * Entry Parameters: none
 * Return Values: void
 */
void Board::printBoard() {

    for (int r = 0; r < DIMENSION; r++) {
        cout << "\n"; 
        for (int c = 0; c < DIMENSION; c++) {
            int number = board[r][c];
            if (number == 0) {
                cout << "_ ";
            }
            else {
                cout << number << " ";
            }
        }  
    }
    cout << "\n" << endl;
    
}    
/*
 * Function Name: anotherMoveExist - finds the next move available on the board
 * Functional Description: 
 * Finds each open space in the board and returns true if one exists.
 * Entry Parameters: none
 * Return Values: bool - whether or not another move exists
 */
bool Board::anotherMoveExists() {
    for (int r = 0; r < DIMENSION; ++r) {
        for (int c = 0; c < DIMENSION; ++c) {
            if (board[r][c] == 0) {
                return true;
            }
        }
    }
    return false;
}


