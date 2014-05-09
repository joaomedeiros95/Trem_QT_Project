#ifndef MYQTHREAD_H
#define MYQTHREAD_H

#include <QThread>

class MyQThread : public QThread
{
    Q_OBJECT
public:
    explicit MyQThread(QObject *parent = 0);
    void run();
    bool pause;
    bool mexeu;
    int velocidade[3];

signals:
    void trem1Andou(int);
    void trem2Andou(int);
    void trem3Andou(int);
};

#endif // MYQTHREAD_H
