/*
  Classe servir� de base para o problema dos trens
  Na modelagem, um trem pode ser considerado uma
  thread.
*/

#include "trem.h"
#include <stdio.h>
#include <iostream>
#include <unistd.h>
#include "myqthread.h"

/*
  O construtor da classe Trem
  Parametros:
  identificador  - id do trem
  vetorSemaforos - vetor com os semaforos utilizados pelo trem
  vetorTrilhos
*/
Trem::Trem( int id,
            vector<Semaforo*> vetorSem,
            vector<Trilhos*> vetorTr,
            int speed
            )
{
    idTrem = id;
    vetorSemaforos = vetorSem;
    vetorTrilhos = vetorTr;
    posicao[0] = 0;
    posicao[1] = 0;
    velocidade = speed;
}

/*
  Destrutor n�o faz nada. Colocar alguma a��o se necess�rio
*/
Trem::~Trem()
{}

/*
  Metodo utilizado para deslocar o trem sobre os trilhos
*/

void
Trem::mover()
{
    // Verificar se j� atingiu o limite do caminho dentro do Trilho atual
    if (posicao[1] == ( ( vetorTrilhos.at(posicao[0]) )->getCaminho() ).capacity() -1)
    {
        //Verificar se j� foi dado uma volta completa
        if (posicao[0] == vetorTrilhos.capacity() - 1)
        {
            posicao[0] = 0;
            posicao[1] = 0;
        }
        //Se uma volta ainda n�o foi dada, incrementa para o inicio do proximo trilho
        else
        {
            posicao[0]++;
            posicao[1] = 0;
        }
    }
    //Apenas incrementa o caminho atual
    else
    {
        posicao[1]++;
    }
}


/*
  Metodo que implementara o loop de execu��o da thread
*/
void
Trem::run()
{
    while(true)
    {
        if(((vetorTrilhos.at(posicao[0]) )->getCaminho() ).at(posicao[1]) == 9 || ((vetorTrilhos.at(posicao[0]) )->getCaminho() ).at(posicao[1]) == 54)
            vetorSemaforos[0]->P();
        if(((vetorTrilhos.at(posicao[0]) )->getCaminho() ).at(posicao[1]) == 25 || ((vetorTrilhos.at(posicao[0]) )->getCaminho() ).at(posicao[1]) == 52)
            vetorSemaforos[1]->P();
        if(((vetorTrilhos.at(posicao[0]) )->getCaminho() ).at(posicao[1]) == 13 || ((vetorTrilhos.at(posicao[0]) )->getCaminho() ).at(posicao[1]) == 20)
            vetorSemaforos[2]->P();
        mover();
        if((((vetorTrilhos.at(posicao[0]) )->getCaminho() ).at(posicao[1]) == 14 || ((vetorTrilhos.at(posicao[0]) )->getCaminho() ).at(posicao[1]) == 42) && vetorSemaforos[0]->getContador() <= 0)
            vetorSemaforos[0]->V();
        if((((vetorTrilhos.at(posicao[0]) )->getCaminho() ).at(posicao[1]) == 28 || ((vetorTrilhos.at(posicao[0]) )->getCaminho() ).at(posicao[1]) == 37) && vetorSemaforos[1]->getContador() <= 0)
            vetorSemaforos[1]->V();
        if((((vetorTrilhos.at(posicao[0]) )->getCaminho() ).at(posicao[1]) == 17 || ((vetorTrilhos.at(posicao[0]) )->getCaminho() ).at(posicao[1]) == 26) && vetorSemaforos[2]->getContador() <= 0)
            vetorSemaforos[2]->V();
        sleep(velocidade);
    }
}

/*
  M�todos get e set. S�o utilizados para alterar e retornar
  os atributos private da classe. Isso garente o encapsulamento
  mantendo as boas pr�ticas de programa��o
*/

int
Trem::getIdTrem() const
{
    return idTrem;
}

void
Trem::setIdTrem(int id)
{
    idTrem = id;
}

void Trem::setVelocidade(int vel) {
    velocidade = vel;
}

int Trem::getPosicao() {
    return ((vetorTrilhos.at(posicao[0]) )->getCaminho() ).at(posicao[1]);
}
