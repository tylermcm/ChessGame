#include "King.h"
#include "Board.h"
#include <vector>

std::vector<Position> King::getMoves(const Board& board) {
   std::vector<Position> possible;
   int row = position.getRow();
   int col = position.getCol();
   // Potential moves for the king
   int moves[8][2] = {
       {-1,  1}, {0,  1}, {1,  1},
       {-1,  0},          {1,  0},
       {-1, -1}, {0, -1}, {1, -1}
   };
   // TODO: Add logic to filter out invalid moves
   for (int i = 0; i < 8; ++i) {
      possible.push_back(Position(row + moves[i][0], col + moves[i][1]));
   }

   return possible;
}
