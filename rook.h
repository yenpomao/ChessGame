#ifndef ROOK_H
#define ROOK_H


#include "piece.h"
#include "board.h"

class Rook : public Piece {
    Board* boardPtr;
public:
    Rook(Color c, Board* board) : Piece(c), boardPtr(board){}
    char symbol() const override {return 'P';}
    std::vector<std::pair<int, int>> possibleMoves(int row, int col) const override;
};


#endif // ROOK_H
