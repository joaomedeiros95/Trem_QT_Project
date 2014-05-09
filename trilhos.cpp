/*
  Classe que implementa os Trilhos
*/


#include "trilhos.h"


/*
  Construtor
  trilho = caminho que ser� percorrido pelo trem
*/

Trilhos::Trilhos ( vector<int> trilho, int id )
{
  caminho = trilho;
  idTrilho = id;
}

/*
 Destrutor
*/
Trilhos::~Trilhos()
{}

/*
  Retorna o identificador dos trilhos
*/
int
Trilhos::getIdTrilho() const
{
  return idTrilho;
}

/*
  Retorna o caminho onde o trem ira percorrer
*/

vector<int>
Trilhos::getCaminho() const
{
  return caminho;
}
