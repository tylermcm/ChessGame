#pragma once

#include "piece.h"

class Pawn : public Piece {
public:
   Pawn(int r, int c, bool white) : Piece(r, c, white) {}

   char getLetter() const override {
      return isWhite() ? 'P' : 'p';
   }

   void display(ogstream& gout) override {
      // Implement pawn-specific display logic
   }

   std::vector<Position> getMoves(const Board& board) override;  // Just the declaration
};
