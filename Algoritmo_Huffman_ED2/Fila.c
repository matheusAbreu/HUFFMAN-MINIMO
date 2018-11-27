#include "Fila.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int fila_vazia(Fila *f)
{
    if(f->ini == NULL)
        return(1);
    return(0);
}

Fila* fila_cria(void)
{
    Fila* f = (Fila*) malloc(sizeof(Fila));
    f->ini= f->fim = NULL;
    return(f);
}


void fila_insere(Fila *f, int fq, char s)
{

    Elemento *novo = (Elemento *) malloc(sizeof(Elemento));
    Elemento *p;
    novo->freq= fq; //armazena informação
    novo->simbolo = s;

    if(f->fim == NULL)
    {
        f->ini = novo;
        f->fim = novo;
        novo->ant = NULL;
        novo->prox = NULL;

    }else if(f->fim->freq >= fq)
    {
        novo->ant = f->fim;
        novo->prox = NULL;
        f->fim->prox = novo;
        f->fim = novo;
    }else{

        for(p = f->ini ; p!= NULL; p = p->prox)
        {
            if(p->freq <= fq )
            {
                novo->prox = p;
                novo->ant = p->ant;
                if(p->ant!= NULL) //EXCEÇÃO PARA QUANDO ENTRA NA FRENTE DA FILA
                    p->ant->prox = novo;
                else
                    f->ini = novo;
                p->ant = novo;
                break;
            }
        }
    }

    //3 passos: 1-Testa se esta vazio; 2-testa se o ultimo elemento já é o maior(decrescente); 3 - procura onde encaixar de forma descrescente

}
