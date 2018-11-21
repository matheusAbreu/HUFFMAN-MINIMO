typedef struct no
{
    char simbolo;
    int freq;
    typedef struct no   *proximo;
}No

typedef struct cego
{
    int freq_total;
    No  *esquerdo;
    No  *direito;
}No_cego
