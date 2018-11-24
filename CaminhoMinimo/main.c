#include <stdio.h>
#include <stdlib.h>
#include "grafo.h";


void main()
{
   grafo *x;
   int i;


    x = CriaGrafo();

    for(i=0; i< 25; i++)
        InserirNo(x);

    InserirCaminho(x,0,1, 10);
    InserirCaminho(x,0,2, 50);
    InserirCaminho(x,0,3, 65);
    InserirCaminho(x,1,2, 30);
    InserirCaminho(x,1,4, 4);
    InserirCaminho(x,2,3, 20);
    InserirCaminho(x,2,4, 44);
    InserirCaminho(x,3,1, 70);
    InserirCaminho(x,3,4, 23);
    InserirCaminho(x,4,0, 6);
    ImprimindoMatrizDoGrafo(x);
    //RemoverNo(x, 1);
    //RemoverCaminho(x, 1,2);
    //ImprimindoMatrizDoGrafo(x);
    ApagarGrafo(x);

}
