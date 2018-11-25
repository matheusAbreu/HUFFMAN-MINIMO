#include "dijkstra.h"

char *PegandoConteudoDoArquivo(FILE *arq)
{
    char *texto;
    long tam_arquivo;
    int i;

    fseek(arq, 0L, SEEK_END);
    tam_arquivo = ftell(arq);// Devolve numero de bytes do arquivo
    rewind(arq);//retorna pro inicio do arquivo
    //LIMP(arq);//avaliar necessidade dessa parte
    texto= (char*) malloc((tam_arquivo) * sizeof(char));
    i = fread(texto, sizeof(char), tam_arquivo, arq);  //retorna o numero de bytes lidos alem de registrar os dados no vetor

    if(tam_arquivo != i)  //CORREÇÃO DOS BYTES ADICIONAIS OCASIONADOS PELA QUEBRA DE LINHA
        texto= (char*)realloc( texto, i * sizeof(char));

    //texto[i] = '\0';//força a delimitação da string
    printf("\n%s\n", texto);

    return texto;
}

