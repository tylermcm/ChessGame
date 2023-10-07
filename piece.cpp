
/***********************************************************************
 * Source File:
 *    PIECE : Individual chess pieces
 * Author:
 *    <Your Name>
 * Summary:
 *    This class will encapsulate all the functionalities related to individual
 *    chess pieces, including rules for their movement.
 ************************************************************************/

#include "Piece.h"
#include "board.h"

 // Constructor
Piece::Piece(int r, int c, bool white) : position(r, c), isWhite(white), nMoves(0), lastMove(-1) {}

std::vector<Move> Piece::getMovesSlide(const Board& board, const std::vector<Position>& delta) {
   std::vector<Move> moves;
   for (const auto& d : delta) {
      Position posMove = position + d;
      Move move;
      while (posMove.isValid() && board.get(posMove).getLetter() == ' ') { // Assuming SPACE is represented by ' '
         move.setSrc(getPosition());
         move.setDes(posMove);
         move.setWhiteMove(isWhite());
         moves.push_back(move);
         posMove += d;
      }
      if (posMove.isValid() && (board.get(posMove).isWhite() != isWhite() || board.get(posMove).getLetter() == ' ')) {
         move.setSrc(getPosition());
         move.setDes(posMove);
         move.setWhiteMove(isWhite());
         if (board.get(posMove).getLetter() != ' ') {
            move.setCapture(board.get(posMove).getLetter());
         }
         moves.push_back(move);
      }
   }
   return moves;
}
// Assign a new position to the piece
void Piece::assign(Position newPosition) {
   position = newPosition;
}

// Assign properties from another piece
void Piece::assign(Piece piece) {
   position = piece.getPosition();
   isWhite = piece.isWhite();
   nMoves = piece.getNMoves();
   lastMove = piece.justMoved() ? piece.getNMoves() : -1; 
}

// Check if the piece is white
bool Piece::isWhite() const {
   return isWhite;
}

// Check if the piece has moved
bool Piece::isMove() const {
   return nMoves > 0;
}

// Get the number of moves made by this piece
int Piece::getNMoves() const {
   return nMoves;
}

// Get the current position of the piece
Position Piece::getPosition() const {
   return position;
}

// Check if the piece just moved
bool Piece::justMoved() const {
   return lastMove == nMoves;
}