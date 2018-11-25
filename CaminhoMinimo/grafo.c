#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "grafo.h"

typedef struct _NO
{
    char info[10];
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
    x->info[0] = '\0';
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
grafo *CriandoGrafoAleatorio(int maxNo)
{
    int i,j, randPeso, randExisCam;
    grafo *x;

    srand((unsigned)time(NULL));
    x = CriaGrafo();

    for(i=0; i< maxNo; i++)
      InserirNo(x);

     NomeandoNos(x);

    for(i=0; i< maxNo; i++)
        for(j=0; j< maxNo; j++)
        {
            randExisCam = rand()%2;
            if(randExisCam == 1)
            {
                randPeso = (rand () % 98)+1;
                InserirCaminho(x, i, j, randPeso);
            }
        }
        return x;
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
    int i;
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
        if(QntPesaLigacao(x, posY, posZ) <= 1)
        {
            x->conteudo[posY]->liga = (no**) realloc(x->conteudo[posY]->liga, (x->conteudo[posY]->qntliga+1)*sizeof(no*));
            x->conteudo[posY]->peso = (int*) realloc(x->conteudo[posY]->peso,(x->conteudo[posY]->qntliga+1)*sizeof(int));
            x->conteudo[posY]->liga[x->conteudo[posY]->qntliga] = x->conteudo[posZ];
            x->conteudo[posY]->peso[x->conteudo[posY]->qntliga] = peso;
            x->conteudo[posY]->qntliga++;
        }else
                printf("\nJá ligação já existe uma ligacao de %d para %d\n", posY, posZ);

        if(QntPesaLigacao(x, posZ, posY) <= 1)
        {
            x->conteudo[posZ]->liga = (no**) realloc(x->conteudo[posZ]->liga,(x->conteudo[posZ]->qntliga+1)*sizeof(no*));
            x->conteudo[posZ]->peso = (int*) realloc(x->conteudo[posZ]->peso,(x->conteudo[posZ]->qntliga+1)*sizeof(int));
            x->conteudo[posZ]->liga[x->conteudo[posZ]->qntliga] = x->conteudo[posY];
            x->conteudo[posZ]->peso[x->conteudo[posZ]->qntliga] = peso;
            x->conteudo[posZ]->qntliga++;
        }else
                printf("\nJá ligação já existe uma ligacao de %d para %d\n", posZ, posY);
    }
    else
        printf("\nUm dos nos nao foi encontrado\n");
}
void InserirCaminho(grafo *x, int posY, int posZ, int peso)
{
    if(QntPesaLigacao(x, posY, posZ) <= 1)
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
        else
                printf("\nA ligação já existe\n");
}
int QntPesaLigacao(grafo *x, int posY, int posZ)
{
    int i;
    for(i = 0; i < x->conteudo[posY]->qntliga; i++)
    {
        if(x->conteudo[posY]->liga[i]->info == x->conteudo[posZ]->info)
            return (x->conteudo[posY]->peso[i]);
    }
    return 0;
}
void NomeandoNos(grafo *x)
{
    /*
        Essa função nomea o no do grafo de acordo com o seu index
    */
    int i;

    for(i =0; i < x->qnt; i++)
    {
        //if((i/26)>0)
            sprintf(x->conteudo[i]->info, "%i", (i/26));

        switch( (i%26) )
        {
            case 0://a
                strcat(x->conteudo[i]->info, "A");
            break;
            case 1://b
                strcat(x->conteudo[i]->info, "B");
            break;
            case 2://c
                strcat(x->conteudo[i]->info, "C");
            break;
            case 3://d
                strcat(x->conteudo[i]->info, "D");
            break;
            case 4://e
                strcat(x->conteudo[i]->info, "E");
            break;
            case 5://f
                strcat(x->conteudo[i]->info, "F");
            break;
            case 6://g
                strcat(x->conteudo[i]->info, "G");
            break;
            case 7://h
                strcat(x->conteudo[i]->info, "H");
            break;
            case 8://i
                strcat(x->conteudo[i]->info, "I");
            break;
            case 9://j
                strcat(x->conteudo[i]->info, "J");
            break;
            case 10://k
                strcat(x->conteudo[i]->info, "K");
            break;
            case 11://l
                strcat(x->conteudo[i]->info, "L");
            break;
            case 12://m
                strcat(x->conteudo[i]->info, "M");
            break;
            case 13://n
                strcat(x->conteudo[i]->info, "N");
            break;
            case 14://o
                strcat(x->conteudo[i]->info, "O");
            break;
            case 15://p
                strcat(x->conteudo[i]->info, "P");
            break;
            case 16://q
                strcat(x->conteudo[i]->info, "Q");
            break;
            case 17://r
                strcat(x->conteudo[i]->info, "R");
            break;
            case 18://s
                strcat(x->conteudo[i]->info, "S");
            break;
            case 19://t
                strcat(x->conteudo[i]->info, "T");
            break;
            case 20://u
                strcat(x->conteudo[i]->info, "U");
            break;
            case 21://v
                strcat(x->conteudo[i]->info, "V");
            break;
            case 22://x
                strcat(x->conteudo[i]->info, "X");
            break;
            case 23://w
                strcat(x->conteudo[i]->info, "W");
            break;
            case 24://y
                strcat(x->conteudo[i]->info, "Y");
            break;
            case 25://z
                strcat(x->conteudo[i]->info, "Z");
            break;
        }
    }
}
void ImprimindoNo(no *x)
{
    int i;

    printf("no:%s|:", x->info);
    if(x->peso != NULL)
        for(i =0; i< x->qntliga; i++)
            printf(((x->peso[i]<10)?("->|i:%s - p:0%d|"):("->|i:%s - p:%d|")), x->liga[i]->info, x->peso[i]);

    printf("->");
}
void ImprimindoMatrizDoGrafo(grafo *x)
{
    int i;
    printf("\nGrafo:");
    for(i =0; i < x->qnt;i++)
    {
        printf(((i<10)?("\nIndex no Grafo: 0%d - "):("\nIndex no Grafo: %d - ")), i);
        ImprimindoNo((x->conteudo[i]));
    }
}
