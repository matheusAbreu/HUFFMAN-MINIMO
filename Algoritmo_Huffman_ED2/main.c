#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "Fila.h"
#if linux
#define LIMP __fpurge
#endif
#if WIN32
#define LIMP fflush
#endif

int menu();
void main()
{
    setlocale(LC_ALL, "portuguese");
    int escolha,i;
    char *texto, nome[30];
    long tam_arquivo;
    Fila *tabela;Elemento *p;


    escolha = menu();
    printf("Digite o nome do arquivo desejado e sua extensao:\n");
    LIMP(stdin);
    scanf("%s", nome);
    FILE *arquivo = fopen(nome, "r+");

    switch(escolha)
    {
        case 1:

            fseek( arquivo, 0L, SEEK_END);
            tam_arquivo = ftell(arquivo);// Devolve numero de bytes do arquivo
            rewind(arquivo);//retorna pro inicio do arquivo
            LIMP(arquivo);//avaliar necessidade dessa parte
            texto= (char*) malloc((tam_arquivo) * sizeof(char));
            i = fread(texto, sizeof(char), tam_arquivo, arquivo);  //retorna o numero de bytes lidos alem de registrar os dados no vetor

            if(tam_arquivo != i)  //CORRE��O DOS BYTES ADICIONAIS OCASIONADOS PELA QUEBRA DE LINHA
                texto= (char*)realloc( texto, i * sizeof(char));

            texto[i] = '\0';//for�a a delimita��o da string
            fclose(arquivo);

            tabela = analiseFrequencia(texto);




            system("pause");

        break;



    }

}




int menu()
{
    int valor;
    printf("O a��o deseja executar?\n\n");
    printf("[1]- Compactar\n");
    printf("[2]- Descompactar\n");
    scanf("%i",&valor);
    return(valor);

}

