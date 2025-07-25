#ifndef KING_H
#define KING_H


#include "piece.h"
#include "board.h"
class King : public Piece {
private:
    Board* boardPtr;
public:
    King(Color c, Board* board) : Piece(c), boardPtr(board) {}
    char symbol() const override {return 'P';}
    std::vector<std::pair<int, int>> possibleMoves(int row, int col) const override;
};

#endif // KING_H
