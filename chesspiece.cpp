#include "chessPiece.h"

ChessPiece::ChessPiece(const QPixmap &pixmap)
    : QGraphicsPixmapItem(pixmap)

{
    setFlags(QGraphicsItem::ItemIsMovable | QGraphicsItem:: ItemIsSelectable);
    setAcceptHoverEvents(true);
}

void ChessPiece::mousePressEvent(QGraphicsSceneMouseEvent *event) {
    offset = event->pos();
    QGraphicsPixmapItem::mousePressEvent(event);
}

void ChessPiece::mouseMoveEvent(QGraphicsSceneMouseEvent *event) {
    setPos(mapToScene(event->pos() - offset));
}

void ChessPiece::mouseReleaseEvent(QGraphicsSceneMouseEvent *event) {

    int squareSize = 80;
    int col = static_cast<int>(pos().x() / squareSize);
    int row = static_cast<int>(pos().y() / squareSize);

    setPos(col * squareSize, row * squareSize);

    QGraphicsPixmapItem::mouseReleaseEvent(event);
}
