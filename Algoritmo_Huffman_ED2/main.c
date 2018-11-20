#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int b= 4,i, c;
    char *vetor;
    FILE *arquivo = fopen("arquivo.txt", "r");

    fseek( arquivo, 0L, SEEK_END );
    long tam_arquivo = ftell(arquivo);// Devolve numero de bytes do arquivo
    rewind(arquivo);//retorna pro inicio do arquivo

    fflush(arquivo);//avaliar necessidade dessa parte
    vetor= (char*) malloc((tam_arquivo) * sizeof(char));
    i=fread(vetor, sizeof(char), tam, arquivo);  //retorna o numero de bytes lidos alem de registrar os dados no vetor
    if(tam_arquivo!= i)  //CORREÇÃO DOS BYTES ADICIONAIS OCASIONADOS PELA QUEBRA DE LINHA
        vetor= (char*)realloc( vetor, i * sizeof(char));

    vetor[i] = '\0';//força a delimitação da string


}
