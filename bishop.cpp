#include "bishop.h"
#include "board.h"

std::vector<std::pair<int, int>> Bishop::possibleMoves(int row, int col) const {
    std::vector<std::pair<int, int>> moves;

    int dR[] = {-1, -1, 1, 1};
    int dC[] = {-1, 1, -1, 1};


    for (int i = 0; i < 4; ++i) {
        int currRow = row + dR[i];
        int currCol = col + dC[i];


        while (currRow >= 0 && currRow < 8 && currCol >= 0 && currCol < 8) {
            Piece* targetPiece = boardPtr->getPiece(currRow, currCol);

            if (targetPiece == nullptr) {

                moves.push_back({currRow, currCol});
            } else {

                if (targetPiece->getColor() != color) {

                    moves.push_back({currRow, currCol});
                }

                break;
            }


            currRow += dR[i];
            currCol += dC[i];
        }
    }


    return moves;
}
