#include "board.h"
#include "pawn.h"
#include "rook.h"
#include "knight.h"
#include "bishop.h"
#include "queen.h"
#include "king.h"
#include <memory>
#include <utility>
#include <string>

using namespace std;

Board::Board() {
    squares.resize(8, vector<unique_ptr<Piece>>(8, nullptr));
    setUpBoard();
}

unique_ptr<Piece> Board::createPiece(const string& name, Color color) {
    if (name == "pawn") return make_unique<Pawn>(color, this);
    if (name == "rook") return make_unique<Rook>(color, this);
    if (name == "knight") return make_unique<Knight>(color, this);
    if (name == "bishop") return make_unique<Bishop>(color, this);
    if (name == "queen") return make_unique<Queen>(color, this);
    if (name == "king") return make_unique<King>(color, this);
    return nullptr;
}
void Board::setUpBoard() {
    vector<string> order = {"rook", "knight", "bishop", "queen", "king", "bishop", "knight", "rook"};
    for(int i = 0; i < 8; ++i) {
        squares[0][i] = createPiece(order[i], Color::BLACK);
        squares[1][i] = createPiece("pawn", Color::BLACK);
    }

    for (int i = 0; i < 8; ++i) {
        squares[7][i] = createPiece(order[i], Color::WHITE);
        squares[6][i] = createPiece("pawn", Color::WHITE);
    }
}

Piece* Board::getPiece(int row, int col) const {
    return squares[row][col].get();
}

void Board::movePiece(int fromRow, int fromCol, int toRow, int toCol) {
    squares[toRow][toCol] = std::move(squares[fromRow][fromCol]);

}

