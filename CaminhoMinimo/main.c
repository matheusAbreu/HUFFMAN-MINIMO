#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "grafo.h"
#include "dijkstra.h"
#define MAXNO 5

void main()
{
    grafo *x;
    MeuTexto *textArq;
    char nomeArq[] = "arquivo.txt";

    FILE *arquivo = fopen(nomeArq, "r+");//Abrindo o arquivo para leitura

    textArq = escrevendoMeuTexto(arquivo);
    x = ReconhendoGrafoDoTexto(textArq);

    //x = CriandoGrafoAleatorio(MAXNO);

    printf("\nGrafo Lido\n");
    ImprimindoMatrizDoGrafo(x);
    printf("\n\n\n\n\n\nGrafo do Arquivo\n");
    imprimindoMeuTexto(textArq);

    ApagarGrafo(x);
    limpandoMeuTexto(textArq);

    fclose(arquivo);//Fechando Arquivo

    ApagarGrafo(x);

}
