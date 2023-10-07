#pragma once
#include "piece.h"

class Bishop : public Piece {
public:
   Bishop(int r, int c, bool white) : Piece(r, c, white) {}

   char getLetter() const override {
      return isWhite() ? 'B' : 'b';
   }

   void display(ogstream& gout) override {
      // Implement bishop-specific display logic
   }

   std::vector<Position> getMoves(const Board& board) override;
};

