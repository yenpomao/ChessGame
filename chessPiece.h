#ifndef CHESSPIECE_H
#define CHESSPIECE_H


#include <QGraphicsPixmapItem>
#include <QGraphicsSceneMouseEvent>

class ChessPiece: public QGraphicsPixmapItem {
public:
    ChessPiece(const QPixmap &pixmap);

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;

private:
    QPointF offset;
};

#endif // CHESSPIECE_H
