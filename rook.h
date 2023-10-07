#pragma once
#include "piece.h"
#include <vector>

class Rook : public Piece {
public:
   Rook(int r, int c, bool white) : Piece(r, c, white) {}

   char getLetter() const override {
      return isWhite() ? 'R' : 'r';
   }

   void display(ogstream& gout) override {
      // Implement rook-specific display logic here
   }

   std::vector<Position> getMoves(const Board& board) override;
   PieceType getPieceType() const override { return ROOK; }

};
