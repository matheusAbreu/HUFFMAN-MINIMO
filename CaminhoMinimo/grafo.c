#include <stdio.h>
#include <stdlib.h>
#include "grafo.h";

typedef struct _NO
{
    char info;
    struct _NO **liga;
    int *peso, qntliga;
}no;
typedef struct _GRAFO
{
    no **conteudo;
    int qnt;
} grafo;

void LimpaNo(no *x)
{
    x->info = '\0';
    x->liga = NULL;
    x->peso = NULL;
    x->qntliga = 0;

}
void LimpaGrafo(grafo *x)
{
    x->conteudo = NULL;
    x->qnt = 0;
}
void EscreveNo(no *x)
{
    /*tem que estruturar
     *leitura de arquivo pra depois bolar a escrita do nó cuzão*/

}
no *CriaNo()
{
    no *x;
    x = (no*)malloc(1*sizeof(no));
    if(x == NULL)
    {
        printf("\ndeu ruim...\n");
        return NULL;
    }
    else
    {
        LimpaNo(x);
        return x;
    }
}
grafo *CriaGrafo()
{
     grafo *x;
    x = (grafo*)malloc(1*sizeof(grafo));
    if(x == NULL)
    {
        printf("\ndeu ruim...\n");
        return NULL;
    }
    else
    {
        LimpaGrafo(x);
        return x;
    }
}
void InserirNo(grafo *x)
{
    no *novo;
    novo = CriaNo();
    LimpaNo(novo);
    //EscreveNo(novo);

    if(x->conteudo == NULL)
    {
        x->conteudo = (no**)malloc(1*sizeof(no*));
        if(x->conteudo == NULL)
            printf("\nDeu ruim\n");
    }
    else
    {
        x->conteudo = (no**)realloc(x->conteudo,(x->qnt+1)*sizeof(no*));
        if(x->conteudo == NULL)
            printf("\nDeu ruim\n");
    }
    x->conteudo[x->qnt] = novo;
            x->qnt++;
}
void RemoverNo(grafo *x, int posY)
{
    /*int i;
    if(posY <= x->qnt)
    {
        for(i =0;i<x->qnt;i++)
        {
            if(i != posY)
            RemoverCaminho(x, i, posY);

            if(i < posY)
            {
                x->conteudo[i-1] = x->conteudo[i];
            }
        }
        free(x->conteudo[posY]);
        x->qnt--;
        x->conteudo =(no**)realloc(x->conteudo,x->qnt*sizeof(no*));
    }else
        printf("\nno nao encontrado\n");*/
}
void RemoverCaminho(grafo *x, int posY, int posZ)
{
    int  j, onj = 0;

    if(posY <= x->qnt && posZ <= x->qnt)
    {
        for(j = 0; j < x->conteudo[posY]->qntliga; j++)
        {
            if(x->conteudo[posY]->liga[j] == x->conteudo[posZ])
                onj = 1;
            if(onj != 0)
            {
                x->conteudo[posY]->liga[j] = x->conteudo[posY]->liga[j+1];
                x->conteudo[posY]->peso[j] = x->conteudo[posY]->peso[j+1];
            }
        }
         if(onj != 0)
            {
                x->conteudo[posY]->qntliga --;
                x->conteudo[posY]->liga = (no**)realloc(x->conteudo[posY]->liga,(x->conteudo[posY]->qntliga)*sizeof(no*));
                x->conteudo[posY]->peso = (int*)realloc(x->conteudo[posY]->peso,(x->conteudo[posY]->qntliga)*sizeof(int));

            }
    }else
        printf("\nUm dos nos nao foi encontrado\n");
}
void ApagarGrafo(grafo *x)
{
    int i,j;
    for(i =0; i < x->qnt; i++)
    {
        free((x->conteudo[i]->peso));
        free((x->conteudo[i]->liga));
        free((x->conteudo[i]));
    }
    free(x->conteudo);
    LimpaGrafo(x);
}
void InserirCaminhoDuplo(grafo *x, int posY, int posZ, int peso)
{
    if(posY < x->qnt && posZ < x->qnt)
    {
        x->conteudo[posY]->liga = (no**) realloc(x->conteudo[posY]->liga, (x->conteudo[posY]->qntliga+1)*sizeof(no*));
        x->conteudo[posY]->peso = (int*) realloc(x->conteudo[posY]->peso,(x->conteudo[posY]->qntliga+1)*sizeof(int));
        x->conteudo[posY]->liga[x->conteudo[posY]->qntliga] = x->conteudo[posZ];
        x->conteudo[posY]->peso[x->conteudo[posY]->qntliga] = peso;
        x->conteudo[posY]->qntliga++;

        x->conteudo[posZ]->liga = (no**) realloc(x->conteudo[posZ]->liga,(x->conteudo[posZ]->qntliga+1)*sizeof(no*));
        x->conteudo[posZ]->peso = (int*) realloc(x->conteudo[posZ]->peso,(x->conteudo[posZ]->qntliga+1)*sizeof(int));
        x->conteudo[posZ]->liga[x->conteudo[posZ]->qntliga] = x->conteudo[posY];
        x->conteudo[posZ]->peso[x->conteudo[posZ]->qntliga] = peso;
        x->conteudo[posZ]->qntliga++;
    }
    else
        printf("\nUm dos nos nao foi encontrado\n");
}
void InserirCaminho(grafo *x, int posY, int posZ, int peso)
{
    if(posY < x->qnt && posZ < x->qnt)
    {
        x->conteudo[posY]->liga = (no**) realloc(x->conteudo[posY]->liga, (x->conteudo[posY]->qntliga+1)*sizeof(no*));
        x->conteudo[posY]->peso = (int*) realloc(x->conteudo[posY]->peso,(x->conteudo[posY]->qntliga+1)*sizeof(int));
        x->conteudo[posY]->liga[x->conteudo[posY]->qntliga] = x->conteudo[posZ];
        x->conteudo[posY]->peso[x->conteudo[posY]->qntliga] = peso;
        x->conteudo[posY]->qntliga++;
    }
    else
        printf("\nUm dos nos nao foi encontrado\n");
}
void NomeandoNo(no *x, int index)
{
    /*
        Essa função nomea o no do grafo de acordo com o seu index
    */
}
void ImprimindoNo(no *x)
{
    int i;
    printf("|no:%c|:", x->info);
    if(x->peso != NULL)
        for(i =0; i< x->qntliga; i++)
            printf("->|i:%c|p:%d|", x->liga[i]->info, x->peso[i]);

    printf("->");
}
void ImprimindoMatrizDoGrafo(grafo *x)
{
    int i;
    printf("\nGrafo:");
    for(i =0; i < x->qnt;i++)
    {
        printf("\n%d:", i);
        ImprimindoNo((x->conteudo[i]));
    }
}
