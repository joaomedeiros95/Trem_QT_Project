#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <QPainter>
#include "sobre.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    mThread = new MyQThread(this);
    connect(mThread, SIGNAL(trem1Andou(int)), this, SLOT(onTrem1Andou(int)));
    connect(mThread, SIGNAL(trem2Andou(int)), this, SLOT(onTrem2Andou(int)));
    connect(mThread, SIGNAL(trem3Andou(int)), this, SLOT(onTrem3Andou(int)));

    ui->horizontalSlider->setEnabled(false);
    ui->horizontalSlider_2->setEnabled(false);
    ui->horizontalSlider_3->setEnabled(false);

    posicoes[0] = 1;
    posicoes[1] = 1;
    posicoes[2] = 1;

    ui->textBrowser->append("Trem 1");
    ui->textBrowser_2->append("Trem 2");
    ui->textBrowser_3->append("Trem 3");
}

MainWindow::~MainWindow()
{
    mThread->terminate();
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *)
{
    QPainter paint(this);
    QPen penblack(Qt::black);

    penblack.setWidth(6);
    penblack.setStyle(Qt::DashLine);
    paint.setPen(penblack);
    paint.drawLine (QPointF (250, 30), QPointF (650, 30));
    paint.drawLine (QPointF (650, 30), QPointF (650, 150));
    paint.drawLine (QPointF (250, 150), QPointF (650, 150));
    paint.drawLine (QPointF (250, 30), QPointF (250, 150));

    paint.drawLine (QPointF (50, 150), QPointF (450, 150));
    paint.drawLine (QPointF (450, 150), QPointF (450, 270));
    paint.drawLine (QPointF (50, 270), QPointF (450, 270));
    paint.drawLine (QPointF (50, 150), QPointF (50, 270));

    paint.drawLine (QPointF (450, 150), QPointF (850, 150));
    paint.drawLine (QPointF (850, 150), QPointF (850, 270));
    paint.drawLine (QPointF (450, 270), QPointF (850, 270));
    paint.drawLine (QPointF (450, 150), QPointF (450, 270));

    if(posicoes[0] >= 1 && posicoes[0] <= 7)
        paint.fillRect((posicoes[0] * 57) + 200, 15, 50, 30, Qt::blue);
    else if(posicoes[0] >= 8 && posicoes[0] <= 9)
        paint.fillRect(635, ((posicoes[0] - 8) * 60) + 15, 30, 50, Qt::blue);
    else if(posicoes[0] >= 10 && posicoes[0] <= 16)
        paint.fillRect((635 - (posicoes[0] - 10) * 57), 135, 50, 30, Qt::blue);
    else if (posicoes[0] >= 17 && posicoes[0] <= 18)
        paint.fillRect(235, 135 - ((posicoes[0] - 17) * 60), 30, 50, Qt::blue);

    if(posicoes[1] >= 1 && posicoes[1] <= 7)
        paint.fillRect((posicoes[1] * 57), 135, 50, 30, Qt::black);
    else if(posicoes[1] >= 8 && posicoes[1] <= 9)
        paint.fillRect(435, ((posicoes[1] - 8) * 60) + 135, 30, 50, Qt::black);
    else if(posicoes[1] >= 10 && posicoes[1] <= 16)
        paint.fillRect((435 - (posicoes[1] - 10) * 57), 255, 50, 30, Qt::black);
    else if (posicoes[1] >= 17 && posicoes[1] <= 18)
        paint.fillRect(35, 255 - ((posicoes[1] - 17) * 60), 30, 50, Qt::black);

    if(posicoes[2] >= 1 && posicoes[2] <= 7)
        paint.fillRect((posicoes[2] * 57) + 400, 135, 50, 30, Qt::red);
    else if(posicoes[2] >= 8 && posicoes[2] <= 9)
        paint.fillRect(835, ((posicoes[2] - 8) * 60) + 135, 30, 50, Qt::red);
    else if(posicoes[2] >= 10 && posicoes[2] <= 16)
        paint.fillRect((835 - (posicoes[2] - 10) * 57), 255, 50, 30, Qt::red);
    else if (posicoes[2] >= 17 && posicoes[2] <= 18)
        paint.fillRect(435, 255 - ((posicoes[2] - 17) * 60), 30, 50, Qt::red);

    update();
}

void MainWindow::onTrem1Andou(int posicao) {
    posicoes[0] = posicao;
    ui->textBrowser->append(QString::number(posicao));
}

void MainWindow::onTrem2Andou(int posicao) {
    posicoes[1] = posicao - 18;
    ui->textBrowser_2->append(QString::number(posicao));
}

void MainWindow::onTrem3Andou(int posicao) {
    ui->textBrowser_3->append(QString::number(posicao));
    posicoes[2] = posicao - 36;
}

void MainWindow::on_pushButton_clicked()
{
    if(mThread->isRunning()) {
        ui->horizontalSlider->setEnabled(false);
        ui->horizontalSlider_2->setEnabled(false);
        ui->horizontalSlider_3->setEnabled(false);
        posicoes[0] = 1;
        posicoes[1] = 1;
        posicoes[2] = 1;
        ui->pushButton->setText("Iniciar");
        mThread->terminate();
    }
    else {
        ui->horizontalSlider->setEnabled(true);
        ui->horizontalSlider_2->setEnabled(true);
        ui->horizontalSlider_3->setEnabled(true);
        ui->pushButton->setText("Parar");
        mThread->start();
        while(!mThread->isFinished())
            QCoreApplication::processEvents();
    }
}

void MainWindow::on_horizontalSlider_valueChanged(int value)
{
    mThread->mexeu = true;
    mThread->velocidade[0] = 11 - value;
}

void MainWindow::on_horizontalSlider_2_valueChanged(int value)
{
    mThread->mexeu = true;
    mThread->velocidade[1] = 11 - value;
}

void MainWindow::on_horizontalSlider_3_valueChanged(int value)
{
    mThread->mexeu = true;
    mThread->velocidade[2] = 11 - value;
}

void MainWindow::on_actionSobre_triggered()
{
    Sobre sobre;
    sobre.setModal(true);
    sobre.exec();
}
