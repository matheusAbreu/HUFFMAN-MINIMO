#include <string.h>
#include<string.h>

#include "TAD_arvore.h"


Fila* analiseFrequencia(char *palavras )
{
    int i,j, cont, f = 0;
    char *copia, sujeira, letra;
    Fila *controle = fila_cria();


    cont = strlen(palavras);
    copia = (char*) malloc (cont * sizeof(palavras));
    strcpy(copia, palavras);

    printf("espia: %c", copia[0]);
    system("pause");

    for(i = 0 ; i < (cont - 1); i++) // PARA NA PENULTIMA PARA PODER COMPARAR COM A ULTIMA
    {
        if( i == 0 )
        {
            letra = copia[i];
            f++;

            for(j = (i + 1); j < cont; j++ )
            {
                if(copia[j] == copia[i])
                {
                    f++;
                }
            }
            fila_insere(controle , f , letra );
            sujeira = copia[0];// TUDO QUE JA FOI VISITADO SERA SUJADO PARA PODER SER SALTADO;
            f = 0;
        }else if( copia[i]!= sujeira)
        {
            letra=copia[i];
            f++;
            for(j = (i + 1); j < cont; j++ )
            {
                if(copia[j] == copia[i])
                {
                    f++;
                    copia[j] = sujeira;//SUJA O QUE JA FOI VISTO;
                }
            }
            fila_insere(controle, f , letra);
            f=0;
        }
    }


    return(controle);



}


No_cego* criaNo (int fq, Elemento *menor, Elemento *maior)
{
    No_cego *p = (No_cego*) malloc (sizeof(No_cego));

     p->freq_total = fq;
     p->esq = menor;
     p->dir = maior;

     return(p);
}


No_cego* montaArvore(Fila *cabeca)
{
    int ult, pen, ceg, i;
   No_cego **reserva;
   *reserva = (No_cego**) malloc ( sizeof(No_cego*)) ;
    reserva = (No_cego*) malloc (sizeof(No_cego));

    while( cabeca->ini!= NULL)
    {
        ult = cabeca->fim->freq;
        pen= cabeca->fim->ant->freq;
        if(reserva[0] != NULL)
            ceg = reserva[i]->freq_total;
        else
            //falta juntar a arvore , formar o binario e depositar no arquivo txt



    }
}
