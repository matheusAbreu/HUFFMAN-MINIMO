#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "grafo.h"
#define MAXNO 15

void main()
{
   grafo *x;
   int i,j, randPeso, randExisCam;

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
                randPeso = (rand () % 98)+1;
                InserirCaminho(x, i, j, randPeso);
            }
        }
    ImprimindoMatrizDoGrafo(x);


    ApagarGrafo(x);

}
