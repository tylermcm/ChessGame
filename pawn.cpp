#include "pawn.h"
#include "board.h"
#include <vector>

std::vector<Position> Pawn::getMoves(const Board& board) {
   std::vector<Position> possible;
   int row = position.getRow();
   int col = position.getCol();

   if (isWhite()) {
      // Logic for white pawn
      // Forward one space
      possible.push_back(Position(row - 1, col));
      // TODO: Add more logic (like capturing, en-passant, promotion, etc.)
   }
   else {
      // Logic for black pawn
      // Forward one space
      possible.push_back(Position(row + 1, col));
      // TODO: Add more logic (like capturing, en-passant, promotion, etc.)
   }

   return possible;
}
