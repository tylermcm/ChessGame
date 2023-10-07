
/***********************************************************************
 * Header File:
 *    PIECE : Individual chess pieces
 * Author:
 *    <Your Name>
 * Summary:
 *    This class will encapsulate all the functionalities related to individual
 *    chess pieces, including rules for their movement.
 ************************************************************************/

#pragma once

#include <set>
#include <string>
#include "position.h"  // for Position class
#include "pieceType.h" // for PieceType enum

class Piece
{
public:
   // Constructors, destructors, and assignment operator

   // Public methods
   std::set<int> getPossibleMoves(const char* board, int location, PieceType pieceType);

private:
   // Private methods and attributes
   std::set<int> getPawnMoves(const char* board, int location);
   // TODO: Add methods for other piece types
};

