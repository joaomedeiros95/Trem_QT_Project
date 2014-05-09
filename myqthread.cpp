#include "myqthread.h"
#include <QtCore>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "trem.h"
#include "mainwindow.h"

MyQThread::MyQThread(QObject *parent) :
    QThread(parent)
{
    mexeu = false;
    velocidade[0] = 1;
    velocidade[1] = 1;
    velocidade[2] = 1;
}

void MyQThread::run() {
    //  Criando os caminhos dos trilhos
    // Trem 1
    const int aux_caminho1[] = {1,2,3,4,5,6,7};
    const int aux_caminho2[] = {8,9};
    const int aux_caminho3[] = {10,11,12,13,14,15,16};
    const int aux_caminho4[] = {17,18};

    // Trem 2
    const int aux_caminho5[] = {19, 20, 21, 22, 23, 24, 25};
    const int aux_caminho6[] = {26, 27};
    const int aux_caminho7[] = {28, 29, 30, 31, 32, 33, 34};
    const int aux_caminho8[] = {35, 36};

    // Trem 3
    const int aux_caminho9[] = {37, 38, 39, 40, 41, 42, 43};
    const int aux_caminho10[] = {44, 45};
    const int aux_caminho11[] = {46, 47, 48, 49, 50, 51, 52};
    const int aux_caminho12[] = {53, 54};

    vector<int> caminho1(aux_caminho1,aux_caminho1+7);
    vector<int> caminho2(aux_caminho2,aux_caminho2+2);
    vector<int> caminho3(aux_caminho3,aux_caminho3+7);
    vector<int> caminho4(aux_caminho4,aux_caminho4+2);
    vector<int> caminho5(aux_caminho5,aux_caminho5+7);
    vector<int> caminho6(aux_caminho6,aux_caminho6+2);
    vector<int> caminho7(aux_caminho7,aux_caminho7+7);
    vector<int> caminho8(aux_caminho8,aux_caminho8+2);
    vector<int> caminho9(aux_caminho9,aux_caminho9+7);
    vector<int> caminho10(aux_caminho10,aux_caminho10+2);
    vector<int> caminho11(aux_caminho11,aux_caminho11+7);
    vector<int> caminho12(aux_caminho12,aux_caminho12+2);

    Trilhos *trilho1 = new Trilhos(caminho1,1);
    Trilhos *trilho2 = new Trilhos(caminho2,2);
    Trilhos *trilho3 = new Trilhos(caminho3,3);
    Trilhos *trilho4 = new Trilhos(caminho4,4);
    Trilhos *trilho5 = new Trilhos(caminho5,5);
    Trilhos *trilho6 = new Trilhos(caminho6,6);
    Trilhos *trilho7 = new Trilhos(caminho7,7);
    Trilhos *trilho8 = new Trilhos(caminho8,8);
    Trilhos *trilho9 = new Trilhos(caminho9,9);
    Trilhos *trilho10 = new Trilhos(caminho10,10);
    Trilhos *trilho11 = new Trilhos(caminho11,11);
    Trilhos *trilho12 = new Trilhos(caminho12,12);

    //Fim da cria��o dos trilhos

    // Criando os semaforo usados no programa
    Semaforo *sem1 = new Semaforo(1234,1,IPC_CREAT|0600);
    Semaforo *sem2 = new Semaforo(1235,1,IPC_CREAT|0600);
    Semaforo *sem3 = new Semaforo(1236,1,IPC_CREAT|0600);

    // VARIAVEIS DO TREM

    // vetor de semaforos
    vector<Semaforo*> vetorSemaforo;
    vetorSemaforo.push_back(sem1);
    vetorSemaforo.push_back(sem2);
    vetorSemaforo.push_back(sem3);

    // vetor de trilhos
    vector<Trilhos*> vetorTrilhos1;
    vetorTrilhos1.push_back(trilho1);
    vetorTrilhos1.push_back(trilho2);
    vetorTrilhos1.push_back(trilho3);
    vetorTrilhos1.push_back(trilho4);

    vector<Trilhos*> vetorTrilhos2;
    vetorTrilhos2.push_back(trilho5);
    vetorTrilhos2.push_back(trilho6);
    vetorTrilhos2.push_back(trilho7);
    vetorTrilhos2.push_back(trilho8);

    vector<Trilhos*> vetorTrilhos3;
    vetorTrilhos3.push_back(trilho9);
    vetorTrilhos3.push_back(trilho10);
    vetorTrilhos3.push_back(trilho11);
    vetorTrilhos3.push_back(trilho12);

    //Criando um Trem
    Trem *trem1 = new Trem(1,vetorSemaforo,vetorTrilhos1,1);
    Trem *trem2 = new Trem(2,vetorSemaforo, vetorTrilhos2, 1);
    Trem *trem3 = new Trem(3,vetorSemaforo, vetorTrilhos3, 1);

    //Inicializando o trem
    trem1->start();
    trem2->start();
    trem3->start();

    while (1) {
        if(mexeu) {
            trem1->setVelocidade(velocidade[0]);
            trem2->setVelocidade(velocidade[1]);
            trem3->setVelocidade(velocidade[2]);
            mexeu = false;
        }
        emit trem1Andou(trem1->getPosicao());
        emit trem2Andou(trem2->getPosicao());
        emit trem3Andou(trem3->getPosicao());
        sleep(1);
    }

    pthread_exit(NULL);
}
