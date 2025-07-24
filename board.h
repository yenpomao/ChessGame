#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include <memory>
#inclde "piece.h"

using namespace std;
class Board {
private:
    vector<vector<unique_ptr<Piece>>> squares;
public:
    Board();
    void setUpBoard();
    Piece* getPiece(int row, int col) const;
    void movePiece(int fromRow, int fromCol, int toRow, int toCol);
}
#endif // BOARD_H
