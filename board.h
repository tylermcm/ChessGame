
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

#include "move.h"
#include "position.h" // for Position class
#include "Piece.h"    // for Piece class

class Board
{
private:
	Piece* board[64];
	int currentMove;
	ogstream gout;
	void swap(Position pos1, Position pos2);
	void assertBoard();
public:
	Board(ogstream& gout, bool reset);

	int getCurrentMove() const;
	bool whiteTurn() const;
	void display(Position posHover, Position posSel);
	Piece* get(Position pos) const;
	void free();
	void reset();
	void move(Move move);
	void assign(Piece* piece);
};

/***********************************************
 * Row Column
 * Simple row/column pair
 ************************************************/
struct RC
{
	int row;
	int col;
};
