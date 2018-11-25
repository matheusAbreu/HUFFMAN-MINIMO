#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "grafo.h";
#define MAXNO 15

void main()
{
   grafo *x;
   int i,j, randPos, randPeso, randExisCam;

    srand((unsigned)time(NULL));
    x = CriaGrafo();

    for(i=0; i< MAXNO; i++)
      InserirNo(x);

     NomeandoNos(x);

    for(i=0; i< MAXNO; i++)
        for(j=0; j< MAXNO; j++)
        {
            randExisCam = rand()%2;
            if(randExisCam == 1)
            {
                //randPos = rand() % MAXNO;
                randPeso = (rand () % 100)+1;
                InserirCaminho(x, i, j, randPeso);
            }
        }
    ImprimindoMatrizDoGrafo(x);
    //RemoverNo(x, 1);
    //RemoverCaminho(x, 1,2);
    //ImprimindoMatrizDoGrafo(x);
    ApagarGrafo(x);

}
