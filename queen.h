#ifndef QUEEN_H
#define QUEEN_H


#include "piece.h"
#include "board.h"
class Queen : public Piece {
private:
    Board* boardPtr;
public:
    Queen(Color c, Board* board) : Piece(c), boardPtr(board){}
    char symbol() const override {return 'P';}
    std::vector<std::pair<int, int>> possibleMoves(int row, int col) const override;
};
#endif // QUEEN_H
