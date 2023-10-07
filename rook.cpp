#include "Rook.h"
#include "Board.h"
#include <vector>

std::vector<Position> Rook::getMoves(const Board& board) {
   std::vector<Position> possible;
   int row = position.getRow();
   int col = position.getCol();
   int moves[4][2] = {
       {0,  1},
       {-1, 0}, {1, 0},
       {0, -1}
   };
   // TODO: Add logic to filter out invalid moves
   for (int i = 0; i < 4; ++i) {
      int r = row;
      int c = col;
      while (r >= 0 && r < 8 && c >= 0 && c < 8) { //update this line with full logic (board[r * 8 + c == '')
         r += moves[i][0];
         c += moves[i][1];
         possible.push_back(Position(r, c));
      }
   }

   return possible;
}
