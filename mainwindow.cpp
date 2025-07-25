#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "chesspiece.h"
#include "QGraphicsScene"
#include "QGraphicsRectItem"
#include <QBrush>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    QGraphicsScene *scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);

    int squareSize = 80;
    for (int row = 0; row < 8; ++row) {
        for (int col = 0; col < 8; ++col) {
            QGraphicsRectItem *rect = scene->addRect(col* squareSize, row* squareSize, squareSize, squareSize);
            rect->setBrush((row + col) % 2 ? Qt::white : Qt::gray);
        }
    }

    addPieces(scene, squareSize);

}
   \

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::addPieces(QGraphicsScene *scene, int squareSize) {
    QString pieceNames[8] = {"rook", "knight", "bishop", "queen", "king", "bishop", "knight", "rook"};

    // Black pieces (top)
    for (int col = 0; col < 8; ++col) {
        QString piece = pieceNames[col];
        addPiece(scene, ":/pieces/black_" + piece + ".png", 0, col, squareSize);
        addPiece(scene, ":/pieces/black_pawn.png", 1, col, squareSize);
    }

    // White pieces (bottom)
    for (int col = 0; col < 8; ++col) {
        QString piece = pieceNames[col];
        addPiece(scene, ":/pieces/white_" + piece + ".png", 7, col, squareSize);
        addPiece(scene, ":/pieces/white_pawn.png", 6, col, squareSize);
    }
}

void MainWindow::addPiece(QGraphicsScene *scene, const QString &imagePath, int row, int col, int squareSize) {
    QPixmap pixmap(imagePath);
    ChessPiece *item = new ChessPiece(pixmap.scaled(squareSize, squareSize, Qt::KeepAspectRatio, Qt::SmoothTransformation));
    item->setPos(col * squareSize, row * squareSize);
    item->setZValue(1);
    scene->addItem(item);
}
