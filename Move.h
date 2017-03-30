/* 
 * File:   Move.h
 * Author: Claire McCarthy - clmccart
 * 
 * FILENAME:
 * Move.h
 * FUNCTIONAL DESCRIPTION:
 *    .h file for the Move class. Defines function protoypes, in line functions
 *    and private variables. 
 * COPYRIGHT NOTICE:
 *    Copyright (C) April 24th Claire McCarthy All Rights Reserved.
 * 
 * Created on April 16, 2015, 6:38 AM
 */

#ifndef MOVE_H
#define	MOVE_H



class Move {
    public:
        Move(int r, int c, int val);
        int getRow();
        int getCol();
        int getValue();
        int getQuadrant(int r, int c);
    private:
        int row;
        int column;
        int value;
};

#endif	/* MOVE_H */

