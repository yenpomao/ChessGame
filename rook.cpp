#include "rook.h"
#include "board.h"


// Rook(Color c, Board* board) : Piece(c), boardPtr(board){}


std::vector<std::pair<int, int>> Rook::possibleMoves(int row, int col) const {
    std::vector<std::pair<int, int>> moves;

    int dR[] = {1, 0, -1, 0};
    int dC[] = {0, 1, 0, -1};


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
