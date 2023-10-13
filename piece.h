
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
#include <set>
#include "position.h"
#include "move.h"
#include "uiDraw.h"
using std::set;

class Board;

class Piece
{
public:
	Piece(int r, int c, bool isWhite = true) :
		fWhite(isWhite), nMoves(0), position(r, c), lastMove(-1) {}
	Piece(const Piece& piece) { *this = piece; }
	virtual ~Piece() {}
	const Piece& operator = (const Piece & rhs);
	const Piece& operator = (const Position& rhs)
	{
		nMoves++;
		position = rhs;
		return *this;
	}

	bool operator == (char letter) const { return getLetter() == letter; }
	bool operator != (char letter) const { return getLetter() != letter; }
	bool isWhite() const { return fWhite; }
	bool isMoved() const { return getNMoves() != 0; }
	int getMoves() const { return nMoves; }
	const Position& getPosition() const { return nMoves; }
	bool justMoved(int currentMove) const { return (currentMove - 1 == lastMove); }

	void setLastMove(int currentMove) { lastMove = currentMove; }

	virtual char getLetter() const = 0;
	virtual void display(ogstream* pgout) const = 0;
	virtual void getMoves(set <Move>& moves, const Board& board) const = 0;

protected:
	set <Move> getMovesSlide(
		const Board& board,
		const Delta deltas[],
		int numDelta) const;
	set <Move> getMovesNoSlide(
		const Board& board,
		const Delta deltas[],
		int numDelta) const;

	int nMoves;
	bool fWhite;
	Position position;
	int lastMove;
};

/*
 * EMPTY SPACES
 */
class Space : public Piece
{
public:
	Space(int r, int c) : Piece(r,c) {}
	virtual char getLetter() const { return ' '; }
	virtual void getMoves(set <Move>& moves, const Board& board) const {}
	virtual void display(ogstream* pgout) const {}
};

/*
 * PAWN
 */
class Pawn : public Piece
{
public:
	Pawn(int r, int c, bool isWhite) : Piece (r, c, isWhite) {}
	char getLetter() const { return 'p'; }
	void getMoves(set <Move>& moves, const Board& board) const;
	virtual void display(ogstream* pgout) const
	{
		pgout->drawPawn(position, isWhite());
	}
private:
	void addPromotion(set <Move>& moves, Move& move) const;
};

/*
 * ROOK
 */
class Rook : public Piece
{
public:
	Rook(int r, int c, bool isWhite) : Piece(r, c, isWhite) {}
	char getLetter() const { return 'p'; }
	void getMoves(set <Move>& moves, const Board& board) const;
	virtual void display(ogstream* pgout) const
	{
		pgout->drawPawn(position, isWhite());
	}
};

/*
 * KNIGHT
 */
class Knight : public Piece
{
public:
	Knight(int r, int c, bool isWhite) : Piece(r, c, isWhite) {}
	char getLetter() const { return 'p'; }
	void getMoves(set <Move>& moves, const Board& board) const;
	virtual void display(ogstream* pgout) const
	{
		pgout->drawPawn(position, isWhite());
	}
};

/*
 * BISHOP
 */
class Bishop : public Piece
{
public:
	Bishop(int r, int c, bool isWhite) : Piece(r, c, isWhite) {}
	char getLetter() const { return 'p'; }
	void getMoves(set <Move>& moves, const Board& board) const;
	virtual void display(ogstream* pgout) const
	{
		pgout->drawPawn(position, isWhite());
	}
};

/*
 * QUEEN
 */
class Queen : public Piece
{
public:
	Queen(int r, int c, bool isWhite) : Piece(r, c, isWhite) {}
	char getLetter() const { return 'p'; }
	void getMoves(set <Move>& moves, const Board& board) const;
	virtual void display(ogstream* pgout) const
	{
		pgout->drawPawn(position, isWhite());
	}
};

/*
 * KING
 */
class King : public Piece
{
public:
	King(int r, int c, bool isWhite) : Piece(r, c, isWhite) {}
	char getLetter() const { return 'p'; }
	void getMoves(set <Move>& moves, const Board& board) const;
	virtual void display(ogstream* pgout) const
	{
		pgout->drawPawn(position, isWhite());
	}
};