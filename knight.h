#ifndef KNIGHT_H
#define KNIGHT_H


#include "piece.h"
#include "board.h"
class Knight : public Piece {
private:
    Board* boardPtr;
public:
    Knight(Color c, Board* board) : Piece(c), boardPtr(board){}
    char symbol() const override {return 'P';}
    std::vector<std::pair<int, int>> possibleMoves(int row, int col) const override;
};


#endif // KNIGHT_H
