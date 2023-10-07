#pragma once
#include "Piece.h"

class King : public Piece {
public:
   King(int r, int c, bool white) : Piece(r, c, white) {}

   char getLetter() const override {
      return isWhite() ? 'K' : 'k';
   }

   void display(ogstream& gout) override {
      // Implement king-specific display logic
   }

   std::vector<Position> getMoves(const Board& board) override;
};
