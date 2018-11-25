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

    FILE *arquivo = fopen("arquivo.txt", "r+");

    arq = PegandoConteudoDoArquivo(arquivo);

    x = CriandoGrafoAleatorio(MAXNO);

    ImprimindoMatrizDoGrafo(x);

    free(arq);

    fclose(arquivo);

    ApagarGrafo(x);

}
