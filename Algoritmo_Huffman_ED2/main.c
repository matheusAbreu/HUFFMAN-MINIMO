#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int b= 4, c;
    char vetor[80];
    FILE *arquivo = fopen("arquivo.txt", "a+");

    fread(vetor, sizeof(char), 80, arquivo);





        b=strlen(arquivo);

    printf("%c", vetor[2]);

    system("pause");
}
