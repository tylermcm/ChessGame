
/***********************************************************************
 * Source File:
 *    PIECE : Individual chess pieces
 * Author:
 *    <Your Name>
 * Summary:
 *    This class will encapsulate all the functionalities related to individual
 *    chess pieces, including rules for their movement.
 ************************************************************************/

#include <cassert>
#include <iostream>

#include "Piece.h"
#include "board.h"


void Space::getMoves(set<Move>& moves, const Board& board) const
{
	std::cout << "this working?" << std::endl;
}


void Pawn::addPromotion(set<Move>& moves, Move& move) const
{
	move.setPromote(QUEEN);
	moves.insert(move);
}

void Pawn::getMoves(set<Move>& moves, const Board& board) const
{
	{
		Position posMove(getPosition(), isWhite() ? ADD_R : SUB_R);

		if (posMove.isValid() && board[posMove] == ' ')
		{
			Move move;
			move.setSrc(getPosition());
			move.setDes(posMove);
			move.setWhiteMove(isWhite());

			if (posMove.getRow() == (isWhite() ? 7 : 0))
				addPromotion(moves, move);
			else
				moves.insert(move);
		}

	}

	if (!isMoved())
	{
		assert(position.getRow() == (isWhite() ? 1 : 6));
		Position posMove(isWhite() ? 3 : 4, getPosition().getCol());
		Position posCheck(isWhite() ? 2 : 5, getPosition().getCol());

		if (board[posMove] == ' ' && board[posCheck] == ' ')
		{
			Move move;
			move.setSrc(getPosition());
			move.setDes(posMove);
			move.setWhiteMove(isWhite());
			moves.insert(move);
		}
	}

	const int cDelta[] = { 1, -1 };
	for (int i = 0; i < 2; i++)
	{
		Position posMove(position.getRow() + (isWhite() ? 1 : -1),
			position.getCol() + cDelta[i]);
		if (posMove.isValid() && 
			board[posMove] != ' ' && 
			board[posMove].isWhite() != isWhite())
		{
			Move move;
			move.setSrc(getPosition());
			move.setDes(posMove);
			move.setWhiteMove(isWhite());
			move.setCapture(board[posMove].getLetter());

			if (posMove.getRow() == (isWhite() ? 7 : 0))
				addPromotion(moves, move);
			else
				moves.insert(move);
		}
	}

	//en passant
	for (int i = 0; i < 2; i++)
	{
		Position posMove(position.getRow() + (isWhite() ? 1 : -1),
			position.getCol() + cDelta[i]);
		Position posKill(position.getRow(),
			position.getCol() + cDelta[i]);

		if (posMove.isValid() &&
			position.getRow() == (isWhite() ? 4 : 3) &&
			board[posMove] == ' ' &&
			board[posKill] == 'p' &&
			board[posKill].isWhite() != isWhite() &&
			board[posKill].getNMoves() == 1 &&
			board[posKill].justMoved(board.getCurrentMove()))
		{
			Move move;
			move.setSrc(getPosition());
			move.setDes(posMove);
			move.setWhiteMove(isWhite());
			move.setCapture(board[posMove].getLetter());
			move.setEnPassant();
			moves.insert(move);
		}
	}
}

