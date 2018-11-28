#include "Fila.h"

typedef struct cego
{
    int freq_total;
    Elemento  *esq;
    Elemento  *dir;
}No_cego;




Fila* analiseFrequencia(char *palavras );

No_cego* montaArvore(Fila *cabeca);

No_cego* criaNo( int fq, Elemento *menor, Elemento *maior);
