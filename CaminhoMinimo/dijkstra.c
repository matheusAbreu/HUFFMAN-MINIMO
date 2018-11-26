#include "dijkstra.h"

struct MEUTEXTO
{
    int tam, qntEsp, *posEsp;
    char *vetor;

}typedef MeuTexto;

MeuTexto *criandoMeuTexto()
{
    MeuTexto *x;

    x = (MeuTexto*)malloc(1*sizeof(MeuTexto));

    if(x ==NULL)
        printf("\nHouve um erro na alocacao - CriandoMeuTexto\n");

    return x;
}

void identificandoQuebraLinha(MeuTexto *x)
{
    int temp[x->tam], i, qntEsp =0;

    for(i =0; i<x->tam;i++)
        if(x->vetor[i] == '\n')
            temp[qntEsp++] = i;

    free(x->posEsp);
    x->posEsp = (int*)malloc(qntEsp*sizeof(int));

    if(x->posEsp != NULL)
    {
        for(i=0;i < qntEsp;i++)
            x->posEsp[i] = temp[i];

        x->qntEsp = qntEsp ;
    }
    else
        printf("\nHouve um erro na alocacao - Funcao:criandoEspaco\n");


}
MeuTexto *escrevendoMeuTexto(FILE *arq)
{
    int tam,i;
    MeuTexto *x;
    x = criandoMeuTexto();

    //gets(temp);
    LIMP;
    x->vetor = PegandoConteudoDoArquivo(arq);

    tam = strlen(x->vetor);
    if(tam > 2)
    {
        limpandoMeuTexto(x);
        x->vetor = (char*)malloc((tam+1)*sizeof(char));

        if(x->vetor != NULL)
        {
            x->tam = tam;
            identificandoQuebraLinha(x);
        }
        else
            printf("\nHouve um erro na alocacao - Funcao:escrevendoMeuTexto\n");
    }
    else
            printf("\nHouve um erro na alocacao - Funcao:escrevendoMeuTexto\n");
}

char *PegandoConteudoDoArquivo(FILE *arq)
{
    char *texto;
    long tam_arquivo;
    int i;

    fseek(arq, 0L, SEEK_END);
    tam_arquivo = ftell(arq);// Devolve numero de bytes do arquivo
    rewind(arq);//retorna pro inicio do arquivo
    texto= (char*) malloc((tam_arquivo) * sizeof(char));
    i = fread(texto, sizeof(char), tam_arquivo, arq);  //retorna o numero de bytes lidos alem de registrar os dados no vetor

    if(tam_arquivo != i)  //CORREÇÃO DOS BYTES ADICIONAIS OCASIONADOS PELA QUEBRA DE LINHA
        texto= (char*)realloc( texto, i * sizeof(char));


    //printf("\n%s\n", texto);

    return texto;
}
void imprimindoMeuTexto(MeuTexto *x)
{
    int i;
    printf("\n\nTamanho da String: %d\nA String armazenada e: \"%s\"\nContendo %d Quebras de linha",x->tam, x->vetor,x->qntEsp);
    if(x->qntEsp > 0)
    {
        printf(", nas casas:");
        for(i = 0;i<x->qntEsp;i++)
            printf((i==(x->qntEsp-1))?(" %d.\n\n"):(" %d,"),x->posEsp[i]);
    }
}
grafo *ReconhendoGrafoDoTexto(char *texto)
{

}

