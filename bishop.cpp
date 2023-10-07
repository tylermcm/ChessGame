#include "Bishop.h"
#include "Board.h"
#include <vector>

std::vector<Position> Bishop::getMoves(const Board& board) {
   std::vector<Position> possible;
   int row = position.getRow();
   int col = position.getCol();
   int moves[4][2] = {
       {-1,  1}, {1,  1},
       {-1, -1}, {1, -1}
   };
   // TODO: Add logic to filter out invalid moves
   for (int i = 0; i < 4; ++i) {
      int r = row;
      int c = col;
      while (/* condition to check if (r, c) is a valid board position */) {
         r += moves[i][0];
         c += moves[i][1];
         possible.push_back(Position(r, c));
      }
   }

   return possible;
}