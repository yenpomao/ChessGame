#ifndef PAWN_H
#define PAWN_H


#include "piece.h"
#include "board.h"

class Pawn : public Piece {
private:
    Board* boardPtr;
public:
    Pawn(Color c, Board* board) : Piece(c), boardPtr(board){}
    char symbol() const override {return 'P';}
    std::vector<std::pair<int, int>> possibleMoves(int row, int col) const override;
};
#endif // PAWN_H
