#include "board.h"

#include <cassert>
using namespace std; 



void Board::display(const Position& posHover, const Position& posSelect) const
{
    gout->drawBoard();

    const int hover = posHover.getLocation();
    const int select = posHover.getLocation();
    // draw the hover and select stuff
    gout->drawHover(hover);
    gout->drawSelected(select);

    // draw the possible moves
    if (posSelect.isValid())
    {
        set <Move> possible;
        board[posSelect.getRow()][posSelect.getCol()]->getMoves(possible, *this);
        set <Move>::iterator it;
        for (it = possible.begin(); it != possible.end(); ++it)
        {
            Position pos(it->getDes());;
        }
    }

    // draw the pieces
    for (int r = 0; r < 8; r++)
    {
        for (int c = 0; c < 8; c++)
        {
            board[r][c]->display(gout);
        }
    }
}

// Free resources (if any)
void Board::free()
{
    for (int r = 0; r < 8; r++)
        for (int c = 0; c < 8; c++)
            delete board[r][c];
}

// Reset the board to its initial state
void Board::reset(bool fFree)
{
    if (fFree)
        free();

    for (int r = 2; r < 6; r++)
        for (int c = 0; c < 8; c++)
            board[r][c] = new Space(r, c);

    for (int c = 0; c < 8; c++)
    {
        board[1][c] = new Pawn(1, c, true);
        board[6][c] = new Pawn(6, c, false);
    }

    //white
    board[0][0] = new Rook(0, 0, true /*isWhite*/);
    board[0][1] = new Knight(0, 1, true /*isWhite*/);
    board[0][2] = new Bishop(0, 2, true /*isWhite*/);
    board[0][3] = new King(0, 3, true /*isWhite*/);
    board[0][4] = new Queen(0, 4, true /*isWhite*/);
    board[0][5] = new Bishop(0, 5, true /*isWhite*/);
    board[0][6] = new Knight(0, 6, true /*isWhite*/);
    board[0][7] = new Rook(0, 7, true /*isWhite*/);

    // Black
    board[7][0] = new Rook(7, 0, false /*isWhite*/);
    board[7][1] = new Knight(7, 1, false /*isWhite*/);
    board[7][2] = new Bishop(7, 2, false /*isWhite*/);
    board[7][3] = new Queen(7, 3, false /*isWhite*/);
    board[7][4] = new King(7, 4, false /*isWhite*/);
    board[7][5] = new Bishop(7, 5, false /*isWhite*/);
    board[7][6] = new Knight(7, 6, false /*isWhite*/);
    board[7][7] = new Rook(7, 7, false /*isWhite*/);

    // reset the moves
    currentMove = 0;

    assertBoard();

}


void Board::operator-=(const Position& pos)
{
    if (pos.isInvalid())
        return;

    delete board[pos.getRow()][pos.getCol()];
    board[pos.getRow()][pos.getCol()] = new Space(pos.getRow(), pos.getCol());
}

void Board::remove(const Position& pos)
{
    if (pos.isInvalid())
        return;

    delete board[pos.getRow()][pos.getCol()];
    board[pos.getRow()][pos.getCol()] = NULL;
}

const Piece* Board::operator = (Piece* pRhs)
{
    delete board[pRhs->getPosition().getRow()][pRhs->getPosition().getCol()];
    board[pRhs->getPosition().getRow()][pRhs->getPosition().getCol()] = pRhs;
    return pRhs; 
}

void Board::operator-=(const Move& move)
{
    Position src = move.getSrc();
    Position des = move.getDes();

    // Castle king side
    if (move.getCastleK())
    {
        assert(false);
    }
    // Castle queen side
    else if (move.getCastleQ())
    {
        assert(false);
    }
    // en-passant
    else if (move.getEnPassant())
    {
        assert(false);
    }
    // promotion
    else if (move.getPromotion() != PIECE_EMPTY)
    {
        assert(false);
    }
    // capture?
    else if (move.getCapture() != PIECE_EMPTY)
    {
        assert(false);
    }
    // standard move
    else
    {
        swap(src, des);
    }
}


// Assert the board's integrity
void Board::assertBoard()
{
    for (int r = 0; r < 8; r++)
        for (int c = 0; c < 8; c++)
        {
            Position pos = board[r][c]->getPosition();
            assert(pos.getRow() == r);
            assert(pos.getCol() == c);
        }
    assert(currentMove >= 0);
}

void Board::swap(const Position& pos1, const Position& pos2)
{
    assertBoard();
    //assert(pos1.isValid());
    //assert(pos2.isValid());

    //// perform the swap from the board's perspective
    //Piece *p = board[pos1.getRow()][pos1.getCol()];
    //board[pos1.getRow()][pos1.getCol()] = board[pos2.getRow()][pos2.getCol()];
    //board[pos2.getRow()][pos2.getCol()] = p;

    //// update the position of the piece so the piece is where 
    //// it thinks it is. Otherwise, it is lost!
    //(*this)[pos1] = pos1;
    //(*this)[pos2] = pos2;

    //// mark that this piece has moved
    //(*this)[pos1].setLastMove(currentMove);
    //(*this)[pos2].setLastMove(currentMove);

    //// make sure everything worked correctly
    //assertBoard();
}

void Board::move(const Move& move)
{
    Position src = move.getSrc();
    Position des = move.getDes();
    assert(board[src.getRow()][src.getCol()]->getLetter() != ' ');
    assert(src.isValid());
    assert(des.isValid());

    // Castle King side
    if (move.getCastleK())
    {
        int row = (move.getWhiteMove() ? 0 : 7);

        // King and rook better be in his position
        assert(board[row][4]->getLetter() == 'K');
        assert(board[row][5]->getLetter() == ' ');
        assert(board[row][6]->getLetter() == ' ');
        assert(board[row][7]->getLetter() == 'R');

        // move the king
        src.set(row, 4);
        des.set(row, 6);
        swap(src, des);

        // move the rook
        src.set(row, 7);
        des.set(row, 5);
        swap(src, des);
    }
    // Castle Queen side
    else if (move.getCastleQ())
    {
        int row = (move.getWhiteMove() ? 0 : 7);

        // King and rook better be in his position
        assert(board[row][4]->getLetter() == 'K');
        assert(board[row][3]->getLetter() == ' ');
        assert(board[row][2]->getLetter() == ' ');
        assert(board[row][0]->getLetter() == 'R');

        // move the king
        src.set(row, 4);
        des.set(row, 2);
        swap(src, des);

        // move the rook
        src.set(row, 0);
        des.set(row, 3);
        swap(src, des);
    }
    // En-Passant
    else if (move.getEnPassant())
    {
        // target location of the pawn better be empty
        //assert(board[des.getRow()][des.getCol()]->getLetter() == ' ');
        //assert(board[src.getRow()][src.getCol()]->getLetter() == 'P');
        //assert(board[src.getRow()][des.getCol()]->getLetter() == 'P');

        //// move the pawn
        //swap(src, des);

        //// kill the opponent
        //Position posKill(src.getRow(), des.getCol());
        //*this = posKill;
    }
    // promotion
    else if (move.getPromotion() != PIECE_EMPTY)
    {
        //assert(board[src.getRow()][src.getCol()]->getLetter() == 'P');
        //assert(move.getPromotion() == 'Q' || move.getPromotion() == 'R' || move.getPromotion() == 'B' || move.getPromotion() == 'N');
        //*this = src;
        //remove(des);
        //assert(board[des.getRow()][des.getCol()] == NULL);
        //switch (move.getPromotion())
        //{
        //case 'Q':
        //    *this = new Queen(des.getRow(), des.getCol(), move.getWhiteMove());
        //    break;
        //case 'R':
        //    *this = new Rook(des.getRow(), des.getCol(), move.getWhiteMove());
        //    break;
        //case 'B':
        //    *this = new Bishop(des.getRow(), des.getCol(), move.getWhiteMove());
        //    break;
        //case 'N':
        //    *this = new Knight(des.getRow(), des.getCol(), move.getWhiteMove());
        //    break;
        //default:
        //    *this = new Pawn(des.getRow(), des.getCol(), move.getWhiteMove());
        //    assert(false);
        //}
        //assert(board[des.getRow()][des.getCol()] != NULL);
    }
    // capture
    else if (move.getCapture() != PIECE_EMPTY)
    {
        //assert(board[des.getRow()][des.getCol()]->getLetter() != ' ');
        //assert(board[src.getRow()][src.getCol()]->getLetter() != ' ');
        //assert(board[src.getRow()][src.getCol()]->isWhite() == move.getWhiteMove());
        //assert(board[des.getRow()][des.getCol()]->isWhite() != move.getWhiteMove());

        //// delete the piece
        //*this = des;

        //// swap the piece
        //swap(src, des);
    }

    // otherwise, a normal piecemove
    else
    {
        assert(board[des.getRow()][des.getCol()]->getLetter() == ' ');
        assert(board[src.getRow()][src.getCol()]->getLetter() != ' ');
        assert(board[src.getRow()][src.getCol()]->isWhite() == move.getWhiteMove());

        // swap the piece
        swap(src, des);
    }

    assertBoard();

    // advance by one move
    currentMove++;

}
