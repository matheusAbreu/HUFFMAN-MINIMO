#ifndef GRAFO_H_INCLUDED
#define GRAFO_H_INCLUDED

/* Desta forma, declando a estrutura em seu respectivo codigo e
    passando a assinatura da estrutura no header, é impossivel
    acessar as variaveis das estruturas no main. Sendo desta forma
    somos obrigados a usar as funções estipuladas aqui.
    Dito isso fica cabivel ao programador executar funções funcionais
    Uma vez que a estrutura do projeto inviabiliza adaptações e/ou
    gambiarras de qualquer forma que necessite de acesso dentro da estrutura construida
    Estipula-se que os modulos cuidaram de tudo.
    */

typedef struct _NO no;
typedef struct _GRAFO grafo;

void LimpaNo(no *x);//nao libera memoria, apenas altera o conteudo para nulo
void LimpaGrafo(grafo *x);//nao libera memoria, apenas altera o conteudo para nulo
void EscreveNo(no *x);
no *CriaNo();
grafo *CriaGrafo();
void InserirNo(grafo *x);
void RemoverNo(grafo *x, int posY);//Nao funciona
void RemoverCaminho(grafo *x, int posY, int posZ);//Y é onde apagara, e Z é o no destino no qual deseja-se que se apague o caminho
void ApagarGrafo(grafo *x);
void InserirCaminhoDuplo(grafo *x, int posY, int posZ, int peso);//Insere o caminho entre os dois nós, ido e voltando
void InserirCaminho(grafo *x, int posY, int posZ, int peso);//Insere o caminho do nó, posY para posZ
void ImprimindoNo(no *x);
void ImprimindoMatrizDoGrafo(grafo *x);
void NomeandoNos(grafo *x);

#endif // GRAFO_H_INCLUDED
