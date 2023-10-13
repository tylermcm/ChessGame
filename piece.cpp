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


//void Space::getMoves(set<Move>& moves, const Board& board) const
//{
//	
//}

set<Move> Piece::getMovesSlide(const Board& board, const Delta deltas[], int numDelta) const
{
	set<Move> moves;
	for (int i = 0; i < numDelta; i++)
	{
		Position posMove = getPosition();
		while (true)
		{
			posMove += deltas[i];
			if (!posMove.isValid() || board[posMove].isWhite() == isWhite())
				break;

			Move move;
			move.setSrc(getPosition());
			move.setDes(posMove);
			move.setWhiteMove(isWhite());
			if (board[posMove] != ' ')
			{
				move.setCapture(board[posMove].getLetter());
				moves.insert(move);
				break;
			}
			moves.insert(move);
		}
	}
	return moves;
}

set<Move> Piece::getMovesNoSlide(const Board& board, const Delta deltas[], int numDelta) const
{
	set<Move> moves;
	for (int i = 0; i < numDelta; i++)
	{
		Position posMove(getPosition(), deltas[i]);
		if (posMove.isValid() && board[posMove].isWhite() != isWhite())
		{
			Move move;
			move.setSrc(getPosition());
			move.setDes(posMove);
			move.setWhiteMove(isWhite());
			if (board[posMove] != ' ')
			{
				move.setCapture(board[posMove].getLetter());
			}
			moves.insert(move);
		}
	}
	return moves;
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

	const int cDelta[] = {1, -1};
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

void Rook::getMoves(set<Move>& moves, const Board& board) const
{
	// Define the directions in which a rook can move
	const Delta movesDelta[4] = {
		Delta{0, 1}, // Right
		Delta{-1, 0}, // Up
		Delta{1, 0}, // Down
		Delta{0, -1} // Left
	};

	moves = getMovesSlide(board, movesDelta,
		sizeof(movesDelta) / sizeof(movesDelta[0]));
}


void Bishop::getMoves(set<Move>& moves, const Board& board) const
{
	// Define the diagonal directions in which a bishop can move
	const Delta movesDelta[] = {
		{-1, 1},  // Up-Right
		{1, 1},   // Down-Right
		{-1, -1}, // Up-Left
		{1, -1}   // Down-Left
	};

	moves = getMovesSlide(board, movesDelta,
		sizeof(movesDelta) / sizeof(movesDelta[0]));
}

void Queen::getMoves(set<Move>& moves, const Board& board) const
{
	// Define the 8 directions in which a queen can move
	const Delta movesDelta[] = {
		{-1, 1},  // Up-Right 
		{0, 1},   // Right    
		{1, 1},   // Down-Right 
		{-1, 0},  // Up      
		{1, 0},   // Down    
		{-1, -1}, // Up-Left 
		{0, -1},  // Left    
		{1, -1}   // Down-Left 
	};
	moves = getMovesSlide(board, movesDelta,
				sizeof(movesDelta) / sizeof(movesDelta[0]));
}


void King::getMoves(set<Move>& moves, const Board& board) const
{
	// Define the 8 directions in which a king can move
	const Delta movesDelta[] = {
		{-1, 1},  // Up-Right
		{0, 1},   // Right
		{1, 1},   // Down-Right
		{-1, 0},  // Up
		{1, 0},   // Down
		{-1, -1}, // Up-Left
		{0, -1},  // Left
		{1, -1}   // Down-Left
	};

	moves = getMovesNoSlide(board, movesDelta,
		sizeof(movesDelta) / sizeof(movesDelta[0]));

	// Castling logic
	if (!isMoved())
	{
		int row = getPosition().getRow();
		int col = getPosition().getCol();

		// For white pieces
		if (isWhite() && row == 0)
		{
			// Queenside castling
			if (board[0 * 8 + 0] == 'R')
			{
				bool emptyPath = true;
				for (int i = 1; i < 4; i++)
				{
					if (board[row * 8 + i] != ' ')
					{
						emptyPath = false;
						break;
					}
				}
				if (emptyPath)
				{
					Position posCastle(row, 2);
					Move move;
					move.setSrc(getPosition());
					move.setDes(posCastle);
					move.setWhiteMove(isWhite());
					move.setCastle(true);
					moves.insert(move);
				}
			}
			// Kingside castling
			if (board[0 * 8 + 7] == 'R')
			{
				bool emptyPath = true;
				for (int i = 5; i < 7; i++)
				{
					if (board[row * 8 + i] != ' ')
					{
						emptyPath = false;
						break;
					}
				}
				if (emptyPath)
				{
					Position posCastle(row, 6);
					Move move;
					move.setSrc(getPosition());
					move.setDes(posCastle);
					move.setWhiteMove(isWhite());
					move.setCastle(true);
					moves.insert(move);
				}
			}
		}

		// For black pieces
		if (!isWhite() && row == 7)
		{
			// Queenside castling
			if (board[7 * 8 + 0] == 'r')
			{
				bool emptyPath = true;
				for (int i = 1; i < 4; i++)
				{
					if (board[row * 8 + i] != ' ')
					{
						emptyPath = false;
						break;
					}
				}
				if (emptyPath)
				{
					Position posCastle(row, 2);
					Move move;
					move.setSrc(getPosition());
					move.setDes(posCastle);
					move.setWhiteMove(isWhite());
					move.setCastle(true);
					moves.insert(move);
				}
			}
			// Kingside castling
			if (board[7 * 8 + 7] == 'r')
			{
				bool emptyPath = true;
				for (int i = 5; i < 7; i++)
				{
					if (board[row * 8 + i] != ' ')
					{
						emptyPath = false;
						break;
					}
				}
				if (emptyPath)
				{
					Position posCastle(row, 6);
					Move move;
					move.setSrc(getPosition());
					move.setDes(posCastle);
					move.setWhiteMove(isWhite());
					move.setCastle(true);
					moves.insert(move);
				}
			}
		}
	}
}

void Knight::getMoves(set<Move>& moves, const Board& board) const
{
	// Define the 8 possible moves for a knight
	const Delta movesDelta[] = {
		{-1, 2},  // Up 1, Right 2
		{1, 2},   // Down 1, Right 2
		{-2, 1},  // Up 2, Right 1
		{2, 1},   // Down 2, Right 1
		{-2, -1}, // Up 2, Left 1
		{2, -1},  // Down 2, Left 1
		{-1, -2}, // Up 1, Left 2
		{1, -2}   // Down 1, Left 2
	};

	moves = getMovesNoSlide(board, movesDelta,
		sizeof(movesDelta) / sizeof(movesDelta[0]));
}
