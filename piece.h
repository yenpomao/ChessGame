#ifndef PIECE_H
#define PIECE_H


#include <vector>
#include <utility>

enum class Color {WHITE, BLACK};

class Piece {
public:
    Piece(Color c) : color(c) {}
    virtual ~Piece() {}
    virtual char symbol() const = 0;
    virtual std::vector<std::pair<int, int>> possibleMoves(int row, int col) const = 0;
    Color getColor() const {return color;}
protected:
    Color color;
};

#endif // PIECE_H
