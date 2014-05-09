/*
  Classe que simular� os trilhos do trem. Cada
  trilho pode ser visto como um vetor de inteiros.
  A cada instante o trem anda um posso no trilho.
        _ _ _ _ _ _ _
       |             |
       |_ _ _ _ _ _ _|
  Nesse exemplo, temos 4 trilhos (cima,baixo,esq,dir).
  Para esse exemplo seria necess�rio 4 objetos Trilhos

*/

#include <vector>
using namespace std;

class Trilhos
{
public:
  //Construtor
  //vetor de inteiro representando o trilho e o id
  Trilhos (vector<int>, int);

  //Destrutor
  ~Trilhos();

  //Retorna o trilho
  int getIdTrilho() const;

  //Retorna o caminho
  vector<int> getCaminho() const;

  void setIdTrilho(int);

private:

  //Identificador dos trilhos
  int idTrilho;

  //Trilho que ser� percorrido pelos trens
  vector<int> caminho;

};
