#include "mainwindow.h"
#include "./ui_mainwindow.h"
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

}
   \

MainWindow::~MainWindow()
{
    delete ui;
}
