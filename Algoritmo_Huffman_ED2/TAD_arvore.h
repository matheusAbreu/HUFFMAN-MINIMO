typedef struct _no
{
    char simbolo;
    int freq;
    typedef struct no   *proximo;
}no

typedef struct cego
{
    int freq_total;
    no  *esquerdo;
    no  *direito;
}No_cego

typedef struct _controle
{
    no *primeiro;
    no *ultimo;
}controle


No_cego analiseFrequencia(char *palavras );
