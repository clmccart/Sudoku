/* 
 * File:   Move.cpp
 * Author: Claire McCarthy - clmccart
 * 
 * FILENAME:
 * Move.cpp
 * FUNCTIONAL DESCRIPTION:
 *    cpp file for the Move class. Defines functions including the constructor,
 *    and getQuadrant. This class is called when a new move is to be made 
 *    which allows us to create a vector of moves.
 * COPYRIGHT NOTICE:
 *    Copyright (C) April 24th Claire McCarthy All Rights Reserved.
 * 
 * Created on April 16, 2015, 6:38 AM
 */

#include "Move.h"
#include "Board.h"
#include "Sudoku.h"

using namespace std;

/*
 * Function Name: Move - the constructor for the move class
 * Functional Description: 
 * Sets the given row, column, and value of a move ot the private variables in
 * the move class.   
 * Entry Parameters: int r, int c, int val - the row and column representing the
 * position of the move and the number you want ot put in that place. 
 * Return Values: none 
 */
Move::Move(int r, int c, int val) {
    row = r;
    column = c;
    value = val; 
}
/*
 * Function Name: getQuadrant - returns the quadrant that you are in
 * Functional Description: 
 * Uses 3 sets of nested if statements to return a numerical value representing
 * which quadrant on the sudoku board you are currently in.  
 * Entry Parameters: int r, int c - the row and column representing the position
 * who's quadrant you want to get.
 * Return Values: int - the numerical value of the quadrant 
 */
int Move::getQuadrant(int r, int c) {
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

int Move::getRow() {
    return row;
}

int Move::getCol() {
    return column;
}

int Move::getValue() {
    return value; 
}


