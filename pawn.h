#ifndef PAWN_H
#define PAWN_H


#include "piece.h"

class Pawn : public Piece {
public:
    Pawn(Color c) : Piece(c) {}
    char symbol() const override {return 'P';}
    std::vector<std::pair<int, int>> possibleMoves(int row, int col) const override;
};
#endif // PAWN_H
