#include "king.h"
#include "board.h"

std::vector<std::pair<int, int>> King::possibleMoves(int row, int col) const {
    std::vector<std::pair<int, int>> moves;

    int dR[] = {-1, -1, 1, 1, 1, 0, -1, 0};
    int dC[] = {-1, 1, -1, 1, 0, 1, 0, -1};


    for (int i = 0; i < 8; ++i) {
        int currRow = row + dR[i];
        int currCol = col + dC[i];


        if (currRow >= 0 && currRow < 8 && currCol >= 0 && currCol < 8) {
            Piece* targetPiece = boardPtr->getPiece(currRow, currCol);

            if (targetPiece == nullptr || targetPiece->getColor() != color) {
                moves.push_back({currRow, currCol});
            }
        }
    }

    return moves;
}
