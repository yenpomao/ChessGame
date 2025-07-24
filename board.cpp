#include "board.h"
#include "pawn.h"
#include "rook.h"
#include "knight.h"
#include "bishop.h"
#include "queen.h"
#include "king.h"


Board::Board() {
    squares.resize(8, vector<unqiue_ptr<Piece>>(8, nullptr));
    setUpBoard();
}

void Board::setUpBoard() {
    for(int i = 0; i < 8; ++i) {
        squares[1][i] = make_unique<Pawn>(Color::WHITE);
        squares[6][i] = make_unique<Pawn>(Color::BLACK);
    }
    // TODO: add others
}

Piece* Board::getPiece(int row, int col) const {
    return squares[row][col];
}

void Board::movePiece(int fromRow, int fromCol, int toRow, int toCol) {
    squares[toRow][toCol] = move(squares[fromRow][fromCol]);
}
