#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int b= 4,i, c;
    char *vetor;
    FILE *arquivo = fopen("arquivo.txt", "a+");


    vetor= (char*) malloc(sizeof(char));

    while(vetor[i]!= EOF)
    {
        vetor[i]= fgetc(arquivo);
        if(vetor[i]!= EOF)
            vetor= (char*) realloc(vetor, (++i)* sizeof(char));
        i++;
    }

    printf("%s", vetor);



        b=strlen(arquivo);

    printf("%s", vetor);

    system("pause");
}
