#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "myqthread.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    MyQThread *mThread;
    int posicoes[3];

private:
    Ui::MainWindow *ui;

public slots:
    void onTrem1Andou(int);
    void onTrem2Andou(int);
    void onTrem3Andou(int);

protected:
    void paintEvent(QPaintEvent *e);

private slots:
    void on_pushButton_clicked();
    void on_horizontalSlider_valueChanged(int value);
    void on_horizontalSlider_2_valueChanged(int value);
    void on_horizontalSlider_3_valueChanged(int value);
    void on_actionSobre_triggered();
};

#endif // MAINWINDOW_H
