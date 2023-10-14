#include "board.h"
#include "piece.h"
#include <cassert>
#include <iostream>

Board::Board()
{
    char initialBoard[64] = {
       'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r',
       'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p',
       ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
       ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
       ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
       ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
       'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P',
       'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'
    };


    for (int i = 0; i < 64; ++i) {
        int row = i / 8;
        int col = i % 8;
        bool isWhite = row >= 6;

        switch (initialBoard[i]) {
        case 'r':
            board[i] = new Rook(row, col, false);
            break;
        case 'n':
            board[i] = new Knight(row, col, false);
            break;
        case 'b':
            board[i] = new Bishop(row, col, false);
            break;
        case 'q':
            board[i] = new Queen(row, col, false);
            break;
        case 'k':
            board[i] = new King(row, col, false);
            break;
        case 'p':
            board[i] = new Pawn(row, col, false);
            break;

        case 'R':
            board[i] = new Rook(row, col, true);
            break;
        case 'N':
            board[i] = new Knight(row, col, true);
            break;
        case 'B':
            board[i] = new Bishop(row, col, true);
            break;
        case 'Q':
            board[i] = new Queen(row, col, true);
            break;
        case 'K':
            board[i] = new King(row, col, true);
            break;
        case 'P':
            board[i] = new Pawn(row, col, true);
            break;

        case ' ':
            board[i] = new Space(row, col);
            break;

        default:
            board[i] = nullptr;
        }
    }
}

Board::Board(ogstream& gout, bool reset) {
    if (reset) {
        // Initialize all squares to 'SPACE' objects
        for (int i = 0; i < 64; ++i) {
            int row = i / 8;
            int col = i % 8;
            board[i] = new Space(row, col);  // Or however you create a SPACE object
        }
    }
    else {
        char initialBoard[64] = {
            'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r',
            'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p',
            ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
            ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
            ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
            ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
            'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P',
            'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'
        };
        for (int i = 0; i < 64; ++i) {
            int row = i / 8;
            int col = i % 8;
            bool isWhite = (row >= 6);  // Assuming rows 6 and 7 are for white pieces

            switch (initialBoard[i]) {
            case 'r':
                board[i] = new Rook(row, col, false);
                break;
            case 'n':
                board[i] = new Knight(row, col, false);
                break;
            case 'b':
                board[i] = new Bishop(row, col, false);
                break;
            case 'q':
                board[i] = new Queen(row, col, false);
                break;
            case 'k':
                board[i] = new King(row, col, false);
                break;
            case 'p':
                board[i] = new Pawn(row, col, false);
                break;

            case 'R':
                board[i] = new Rook(row, col, true);
                break;
            case 'N':
                board[i] = new Knight(row, col, true);
                break;
            case 'B':
                board[i] = new Bishop(row, col, true);
                break;
            case 'Q':
                board[i] = new Queen(row, col, true);
                break;
            case 'K':
                board[i] = new King(row, col, true);
                break;
            case 'P':
                board[i] = new Pawn(row, col, true);
                break;

            case ' ':
                board[i] = new Space(row, col);
                break;

            default:
                board[i] = nullptr;  // Or throw an error
                break;
            }
        }
    }
}

// Constructor
//Board::Board(ogstream& gout, bool reset) {
//   char initialBoard[64] = {
//       'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r',
//       'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p',
//       ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
//       ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
//       ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
//       ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
//       'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P',
//       'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'
//   };
//
//
//   for (int i = 0; i < 64; ++i) {
//      int row = i / 8;
//      int col = i % 8;
//      bool isWhite = row >= 6;
//
//      switch (initialBoard[i]) {
//      case 'r':
//         board[i] = new Rook(row, col, false);
//         break;
//      case 'n':
//         board[i] = new Knight(row, col, false);
//         break;
//      case 'b':
//         board[i] = new Bishop(row, col, false);
//         break;
//      case 'q':
//         board[i] = new Queen(row, col, false);
//         break;
//      case 'k':
//         board[i] = new King(row, col, false);
//         break;
//      case 'p':
//         board[i] = new Pawn(row, col, false);
//         break;
//
//      case 'R':
//         board[i] = new Rook(row, col, true);
//         break;
//      case 'N':
//         board[i] = new Knight(row, col, true);
//         break;
//      case 'B':
//         board[i] = new Bishop(row, col, true);
//         break;
//      case 'Q':
//         board[i] = new Queen(row, col, true);
//         break;
//      case 'K':
//         board[i] = new King(row, col, true);
//         break;
//      case 'P':
//         board[i] = new Pawn(row, col, true);
//         break;
//
//      case ' ':
//         board[i] = new Space(row, col);
//         break;
//
//      default:
//         board[i] = nullptr;
//      }
//   }
//}


// Display the board
void Board::display(ogstream& gout, Position posHover, Position posSel) 
{
      // draw the checkerboard
    gout.drawBoard();
    int hover = posHover.getLocation();
    int select = posSel.getLocation();
    // draw any selections
    gout.drawHover(hover);
    gout.drawSelected(select);

    // draw the possible moves
    //set <int> ::iterator it;
    //for (it = possible.begin(); it != possible.end(); ++it)
    //    gout.drawPossible(*it);

    // draw the pieces
    for (int i = 0; i < 64; i++)
    {
        if (board[i] != nullptr)
            board[i]->display(&gout);
    }
}

// Free resources (if any)
void Board::free() {
   for (int i = 0; i < 64; ++i) {
      delete board[i];
      board[i] = nullptr;
   }
}

// Reset the board to its initial state
void Board::reset() {
   // TODO: Implement this method
}

// Move a piece
void Board::move(Move move) 
//bool move(char* board, int positionFrom, int positionTo)
{
   // do not move if a move was not indicated
   // Position positionFrom = move.getSrc();
   // Position positionTo = move.getDes();
   // if (positionFrom == -1 || positionTo == -1)
   //     return;
   //assert(positionFrom >= 0 && positionFrom < 64);
   //assert(positionTo >= 0 && positionTo < 64);


   //// find the set of possible moves from our current location
   ////set <int> possiblePrevious = getPossibleMoves(board, positionFrom);

   //// only move there is the suggested move is on the set of possible moves
   //if (possiblePrevious.find(positionTo) != possiblePrevious.end())
   //{
   //   board[positionTo] = board[positionFrom];
   //   board[positionFrom] = ' ';
   //   return true;
   //}

   //return false;

}

// Assign a piece to a position
void Board::assign(Piece* piece) {
   int index = piece->getPosition().getRow() * 8 + piece->getPosition().getCol();
   board[index] = piece;
}

// Swap two positions on the board
void Board::swap(Position pos1, Position pos2) {
   int index1 = pos1.getRow() * 8 + pos1.getCol();
   int index2 = pos2.getRow() * 8 + pos2.getCol();
   std::swap(board[index1], board[index2]);
}

// Assert the board's integrity
void Board::assertBoard() {
   // TODO: Implement this method
}
