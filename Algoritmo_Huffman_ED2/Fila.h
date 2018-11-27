typedef struct _elemento
{
    char simbolo;
    int freq;
    struct _elemento *ant;
    struct _elemento *prox;
} Elemento;

typedef struct _fila
{
     Elemento *ini;
     Elemento *fim;
}Fila;




int fila_vazia(Fila *f);
Fila* fila_cria(void);
void fila_insere(Fila *f, int fq, char s);
