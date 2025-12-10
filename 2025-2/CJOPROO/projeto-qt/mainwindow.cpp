#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QRandomGenerator>
#include <QPixmap>
#include <QString>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_rollButton_clicked()
{
    int rollResult = QRandomGenerator::global()->bounded(6) + 1;

    QString imagePath = QString(":/dados/dado%1.png").arg(rollResult);

    QPixmap dicePixmap(imagePath);

    if (dicePixmap.isNull()) {
        ui->resultLabel->setText("ERRO: Imagem não encontrada!");
        return;
    }

    int w = ui->resultLabel->width();
    int h = ui->resultLabel->height();
    QPixmap scaledPixmap = dicePixmap.scaled(w, h, Qt::KeepAspectRatio, Qt::SmoothTransformation);

    ui->resultLabel->setPixmap(scaledPixmap);
}
