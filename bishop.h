#ifndef BISHOP_H
#define BISHOP_H


#include "piece.h"
#include "board.h"
class Bishop : public Piece {
private:
    Board* boardPtr;
public:
    Bishop(Color c, Board* board) : Piece(c), boardPtr(board) {}
    char symbol() const override {return 'P';}
    std::vector<std::pair<int, int>> possibleMoves(int row, int col) const override;
};

#endif // BISHOP_H
