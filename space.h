#pragma once
#include "Piece.h"

class Space : public Piece {
public:
   Space(int r, int c) : Piece(r, c, false) {}  // Space doesn't need a color, so we can set it to false

   char getLetter() const override {
      return ' ';
   }

   void display(ogstream& gout) override {
      // Implement space-specific display logic
   }

   std::vector<Position> getMoves(const Board& board) override;
};

