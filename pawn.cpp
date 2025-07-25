#include "pawn.h"
#include "board.h" // ADD THIS: You need the full definition of Board here
// because you are calling boardPtr->getPiece() and other Board methods.

// No changes needed here, as the constructor is inline in the header for now.
// Pawn::Pawn(Color c, Board* board) : Piece(c), boardPtr(board) {}


std::vector<std::pair<int, int>> Pawn::possibleMoves(int row, int col) const {
    std::vector<std::pair<int, int>> moves;
    // Assuming 'color' is a member of Piece and accessible here.
    int direction = (color == Color::WHITE) ? -1 : 1; // White moves up (decreasing row), Black moves down (increasing row)
    int nextRow = row + direction;

    // Move forward one step if empty
    // USE boardPtr HERE:
    if (nextRow >= 0 && nextRow < 8 && boardPtr->getPiece(nextRow, col) == nullptr) {
        moves.push_back({nextRow, col});

        // Two-step move from starting position
        int startRow = (color == Color::WHITE) ? 6 : 1;
        int twoStepRow = row + 2 * direction;
        // USE boardPtr HERE:
        if (row == startRow && boardPtr->getPiece(twoStepRow, col) == nullptr) {
            moves.push_back({twoStepRow, col});
        }
    }

    // Captures (diagonals)
    for (int dCol : {-1, 1}) {
        int newCol = col + dCol;
        if (nextRow >= 0 && nextRow < 8 && newCol >= 0 && newCol < 8) {
            // USE boardPtr HERE:
            Piece* target = boardPtr->getPiece(nextRow, newCol);
            if (target != nullptr && target->getColor() != color) {
                moves.push_back({nextRow, newCol});
            }
        }
    }

    // You will also need to implement en passant and promotion rules for Pawns
    // This current implementation does not include them.

    return moves;
}
