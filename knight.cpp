#include "Knight.h"
#include "board.h"
#include <vector>

std::vector<Position> Knight::getMoves(const Board& board) {
   std::vector<Position> possible;
   int row = position.getRow();
   int col = position.getCol();
   // Potential moves for the knight
   int moves[8][2] = {
       {-1,  2}, { 1,  2},
       {-2,  1}, { 2,  1},
       {-2, -1}, { 2, -1},
       {-1, -2}, { 1, -2}
   };
   // TODO: Add logic to filter out invalid moves
   for (int i = 0; i < 8; ++i) {
      possible.push_back(Position(row + moves[i][0], col + moves[i][1]));
   }

   return possible;
}
