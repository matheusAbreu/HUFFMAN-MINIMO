#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "grafo.h"
#include "dijkstra.h"
#define MAXNO 5

void main()
{
    grafo *x;
    char *arq, nomeArq[] = "arquivo.txt";

    FILE *arquivo = fopen(nomeArq, "r+");//Abrindo o arquivo para leitura

    arq = PegandoConteudoDoArquivo(arquivo);

    x = escrevendoMeuTexto(MAXNO);

    ImprimindoMatrizDoGrafo(x);

    free(arq);

    fclose(arquivo);//Fechando Arquivo

    ApagarGrafo(x);

}
