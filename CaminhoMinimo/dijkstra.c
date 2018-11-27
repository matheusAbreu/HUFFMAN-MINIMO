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
    int tam;
    MeuTexto *x;
    x = criandoMeuTexto();

    //gets(temp);
    LIMP;
    x->vetor = PegandoConteudoDoArquivo(arq);

    tam = strlen(x->vetor);
    if(tam > 2)
    {
        if(x->vetor != NULL)
        {
            x->tam = tam;
            identificandoQuebraLinha(x);
            return x;
        }
        else
            printf("\nHouve um erro na alocacao - Funcao:escrevendoMeuTexto\n");
    }
    else
            printf("\nHouve um erro na alocacao - Funcao:escrevendoMeuTexto\n");

    return NULL;
}
void limpandoMeuTexto(MeuTexto *x)
{
    free(x->posEsp);
    free(x->vetor);
    x->tam =0;
    x->qntEsp = 0;
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
void AnalisandoLigacaoNoTexto(grafo *x, MeuTexto *texto)
{
    //Analisa e aloca
    const int valorDoPrimIndex = 34, DistProPeso = 7, DistProProxIndex = 15;
    int i, j, k, indexLig, valorPeso;
    char c, temp[5];
    MeuTexto *valorIndexNo, *valorPesoLig;
    valorIndexNo = criandoMeuTexto();
    valorPesoLig = criandoMeuTexto();
    for(i = 0; i < texto->qntEsp; i++)
    {
            j = (texto->posEsp[i] + valorDoPrimIndex );//Armazenando o valor do index do index do nó

            for(k = j; k < texto->posEsp[i+1]; k += DistProProxIndex )
            {
                c =texto->vetor[k];
                ImprimindoMatrizDoGrafo(x);
                if(verificandoCaracterNumero(c))
                {
                    copiandoMeuTexto(valorIndexNo, texto, k, (k+2));
                    indexLig = IdentificarIndexNo(x, texto->vetor);
                    copiandoMeuTexto(valorPesoLig, texto, (k+DistProPeso), ((k+DistProPeso)+2));
                    valorPeso = atoi(valorPesoLig->vetor);
                    InserirCaminho(x, i, indexLig,valorPeso );

                }
                else
                    break;
            }

    }
    limpandoMeuTexto(valorIndexNo);
    limpandoMeuTexto(valorPesoLig);
}
grafo *ReconhendoGrafoDoTexto(MeuTexto *texto)
{
    grafo *x;
    int index = 0, i, j;
    char c;
    if(texto->vetor != NULL)
    {
        x = CriaGrafo();
        for(i = 0; i < texto->qntEsp; i++)
        {
            /* eu já desconsidero o index zero pois
            sei que a primeira quebra é despressivel*/
            j = (texto->posEsp[i] + 17);//Armazenando o valor do index do index do nó
            c =texto->vetor[j];//Pegando o caracter referente ao primeiro numero do index
            if(verificandoCaracterNumero(c))
                InserirNo(x);
        }
        NomeandoNos(x);
        AnalisandoLigacaoNoTexto(x, texto);

    }
    return x;
}
void copiandoMeuTexto(MeuTexto *dest, MeuTexto *ori, int ini, int fim)
{
        int i;
        if(dest != NULL)
        limpandoMeuTexto(dest);

        dest->vetor = (char*)malloc(((fim-ini)+1)*sizeof(char));
        if(dest->vetor != NULL)
        {
            dest->tam = (fim-ini);
            for(i =ini; i<fim;i++)
                dest->vetor[i-ini] = ori->vetor[i];

            identificandoQuebraLinha(dest);
        }
        else
            printf("\nHouve um erro na alocacao - Funcao:escrevendoMeuTexto\n");

}
int verificandoCaracterNumero(char c)
{
    /*Retorna 1 se o caracter for um numero
      Retorna 0 caso não seja*/
    if((c == '0' || c == '1' || c == '2' ||
        c == '5' || c == '4' || c == '3' ||
        c == '6' || c == '7' || c == '8' ||
        c == '9' ))
    {
        return 1;
    }
    else
        return 0;
}


