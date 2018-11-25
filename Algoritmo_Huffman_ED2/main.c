#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#if linux
#define LIMP __fpurge
#endif
#if WIN32
#define LIMP fflush
#endif

int menu();
int main()
{
    setlocale(LC_ALL, "portuguese");
    int escolha,i;
    char *texto, nome[30];
    long tam_arquivo;
    No_cego *tabela;


    escolha = menu();
    printf("Digite o nome do arquivo desejado e sua extensao:\n");
    LIMP(stdin);
    fgets(nome, 30, stdin);
    FILE *arquivo = fopen(nome, "r+");

    switch(escolha)
    {
        case 1:

            fseek( arquivo, 0L, SEEK_END );
            tam_arquivo = ftell(arquivo);// Devolve numero de bytes do arquivo
            rewind(arquivo);//retorna pro inicio do arquivo
            LIMP(arquivo);//avaliar necessidade dessa parte
            texto= (char*) malloc((tam_arquivo) * sizeof(char));
            i=fread(texto, sizeof(char), tam_arquivo, arquivo);  //retorna o numero de bytes lidos alem de registrar os dados no vetor

            if(tam_arquivo!= i)  //CORREÇÃO DOS BYTES ADICIONAIS OCASIONADOS PELA QUEBRA DE LINHA
                texto= (char*)realloc( texto, i * sizeof(char));

            texto[i] = '\0';//força a delimitação da string
            fclose(arquivo);

            tabela = analiseFrequencia( texto);
        break;



    }










}




int menu()
{
    int valor;
    printf("O ação deseja executar?\n\n");
    printf("[1]- Compactar\n");
    printf("[2]- Descompactar\n");
    scanf("%i",&valor);
    return(valor);

}

