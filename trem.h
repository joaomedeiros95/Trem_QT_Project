/*
  Classe servir� de base para o problema dos trens
  Na modelagem, um trem pode ser considerado uma
  thread.
*/

#include "thread.h"
#include "semaforo.h"
#include "trilhos.h"
#include <vector>

using namespace std;

class Trem: public Thread
{
public:
    /*Construtor
    Parametros: idTrem, vetor de semaforos, vetor de trilhos,velocidade
  */
    Trem(int,vector<Semaforo*>,vector<Trilhos*>,int);

    //Destrutor
    ~Trem(void);

    //No m�todo run, ser� implementado o loop de execu��o do trem
    void run();

    //Metodo para andar no trilho.
    void mover();

    //Metodos get e set dos atributos. Fazer o restante para os outros
    //atributos
    void setIdTrem(int);

    //Metodos const n�o podem alterar os atributos da classe
    int getIdTrem(void) const;

    //Metodo set da velocidade do trem
    void setVelocidade(int);

    //Metodos para pegar posicao 1 e posicao 2
    int getPosicao();

private:
    // Identificador do trem
    int idTrem;

    // Posicao do trem no trilho
    // posicao[0] - posicao em vetorTrilhos[]
    // posicao[1] - posicao em Trilho.caminho[]
    int posicao[2];

    // Vetor de semaforos
    vector<Semaforo*> vetorSemaforos;

    // Vetor de trilhos
    vector<Trilhos*> vetorTrilhos;

    // Velocidade
    int velocidade;
};
