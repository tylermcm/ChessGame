
/***********************************************************************
 * Header File:
 *    BOARD : The chess board
 * Author:
 *    <Your Name>
 * Summary:
 *    This class will encapsulate all the functionalities related to the
 *    chess board, including utility functions to check piece colors and
 *    other board-specific functionalities.
 ************************************************************************/

#pragma once

#include <set>
#include <string>
#include "position.h" // for Position class
#include "Piece.h"    // for Piece class

class Board
{
public:
   // Constructors, destructors, and assignment operator

   // Public methods
   inline bool isWhite(const char* board, int row, int col);
   inline bool isNotWhite(const char* board, int row, int col);
   inline bool isBlack(const char* board, int row, int col);
   inline bool isNotBlack(const char* board, int row, int col);
   char getLetter(int position); // Compatibility layer for Move class

private:
   // Private methods and attributes
   Piece pieces[64];    // Array holding Piece objects
   char boardState[64]; // Array holding the current state of the board
};
