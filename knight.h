#pragma once
#include "piece.h"

class Knight : public Piece {
public:
   Knight(int r, int c, bool white) : Piece(r, c, white) {}

   char getLetter() const override {
      return isWhite() ? 'N' : 'n';
   }

   void display(ogstream& gout) override {
      // Implement knight-specific display logic
   }

   std::vector<Position> getMoves(const Board& board) override;
};
