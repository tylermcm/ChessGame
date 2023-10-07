#pragma once
#include "piece.h"
#include <vector>

class Pawn : public Piece {
public:
   Pawn(int r, int c, bool white) : Piece(r, c, white) {}

   char getLetter() const override {
      return isWhite() ? 'P' : 'p';
   }

   void display(ogstream& gout) override {
   }

   std::vector<Position> getMoves(const Board& board) override;  
   PieceType getPieceType() const override { return PAWN; }
};
