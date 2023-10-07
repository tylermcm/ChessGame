#pragma once
#include "Piece.h"

class Queen : public Piece {
public:
   Queen(int r, int c, bool white) : Piece(r, c, white) {}

   char getLetter() const override {
      return isWhite() ? 'Q' : 'q';
   }

   void display(ogstream& gout) override {
      // Implement queen-specific display logic
   }

   std::vector<Position> getMoves(const Board& board) override;
};