
/***********************************************************************
 * Header File:
 *    PIECE : Individual chess pieces
 * Author:
 *    <Your Name>
 * Summary:
 *    This class will encapsulate all the functionalities related to individual
 *    chess pieces, including rules for their movement.
 ************************************************************************/

#pragma once

#include "Position.h"  // Assuming Position is defined in a separate header file
#include "Board.h"  // Assuming Board is defined in a separate header file
#include "uiDraw.h"  // Assuming ogstream is a type you've defined or imported
#include <vector>  // For the getMoves method

class Piece {
protected:
   Position position;  // The position of the piece on the board
   bool isWhite;  // Whether the piece is white or not
   int nMoves;  // Number of moves made by this piece
   int lastMove;  // The last move number on which this piece was moved

public:
   // Constructors
   Piece(int r, int c, bool white);

   // Public Methods
   void assign(Position position);  // Assign a new position to the piece
   void assign(Piece piece);  // Assign properties from another piece
   bool isWhite() const;  // Check if the piece is white
   bool isMove() const;  // Check if the piece has moved
   int getNMoves() const;  // Get the number of moves made by this piece
   Position getPosition() const;  // Get the current position of the piece
   bool justMoved() const;  // Check if the piece just moved

   // Virtual Methods
   virtual char getLetter() const = 0;  // Get the letter representation of the piece
   virtual void display(ogstream& gout) = 0;  // Display the piece
   virtual std::vector<Position> getMoves(const Board& board) = 0;  // Get possible moves
   virtual std::vector<Move> getMovesSlide(const Board& board, const std::vector<Position>& delta);
};