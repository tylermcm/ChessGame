
/***********************************************************************
 * Header File:
 *    BOARD : The chess board
 * Author:
 *    <Your Name>
 * Summary:
 *    This class will encapsulate all the functionalities related to the
 *    chess board, including utility functions to check piece colors and
 *    other board-specific functionalities.
 ************************************************************************/

#pragma once
#include "move.h"
#include "position.h" // for Position class
#include "Piece.h"    // for Piece class
#include "uiDraw.h"

class Piece;

class Board
{
private:
    int currentMove;
    ogstream gout;
    void swap(Position pos1, Position pos2);
    void assertBoard();
public:
    Board();
    Board(ogstream& gout, bool reset);
    Piece* board[64]; // Array of Piece pointers
    int getCurrentMove() const { return currentMove; }
    bool whiteTurn() const { return currentMove % 2 == 0; }
    void display(ogstream& gout, Position posHover, Position posSel);
    void free();
    void reset();
    void move(Move move);
    void assign(Piece* piece);

    // Non-const version
    Piece& operator[](const Position& pos) {
        int index = pos.getRow() * 8 + pos.getCol();
        if (board[index] == nullptr) {
            // Handle null pointer situation here.
            throw std::runtime_error("Null pointer at board index");
        }
        return *board[index];
    }

    // Const version
    const Piece& operator[](const Position& pos) const {
        int index = pos.getRow() * 8 + pos.getCol();
        if (board[index] == nullptr) {
            // Handle null pointer situation here.
            throw std::runtime_error("Null pointer at board index");
        }
        return *board[index];
    }
};

/***********************************************
 * Row Column
 * Simple row/column pair
 ************************************************/
struct RC
{
    int row;
    int col;
};
