#include <stdio.h>
#include "TAD_arvore_binaria_aloc_enc.h"

//TAD árvore binária com alocação encadeada
//cria uma árvore binária vazia
void CriaArvoreBinariaVazia(TipoArvore **arvore)
{
    *arvore = NULL;
}

//testa se a árvore binária é vazia
int TestaArvoreBinariaVazia(TipoArvore **arvore)
{
    return (*arvore == NULL);
}

//cria uma árvore binária
void CriaArvoreBinaria(TipoItem item, TipoArvore **arvore, TipoArvore **esquerda, TipoArvore **direita)
{
    *arvore = (TipoArvore *)malloc(sizeof(TipoArvore));
    (*arvore)->item = item;
    (*arvore)->esquerda = esquerda;
    (*arvore)->direita = direita;
}

//libera a árvore binária
TipoArvore * LiberaArvoreBinaria(TipoArvore **arvore)
{
    if (!TestaArvoreBinariaVazia(arvore))
    {
        LiberaArvoreBinaria((*arvore)->esquerda);
        LiberaArvoreBinaria((*arvore)->direita);
        free(arvore);
    }
    return NULL;
}

//verifica se um elemento pertence à árvore binária
int PertenceArvoreBinaria(TipoArvore **arvore, TipoItem item)
{
    if (TestaArvoreBinariaVazia(arvore))
        return 0;
    else
        return (*arvore)->item.chave == item.chave ||
            PertenceArvoreBinaria((*arvore)->esquerda, item) ||
            PertenceArvoreBinaria((*arvore)->direita, item);
}

//imprime os elementos da árvore binária
void ImprimeArvoreBinaria(TipoArvore **arvore, int l)
{
    int i;

    if(!TestaArvoreBinariaVazia(arvore))
    {
        ImprimeArvoreBinaria((*arvore)->esquerda, l + 1);
        for (i = 0; i < l; i++)
            printf("   ");
        printf("%c\n", (*arvore)->item.chave);
        ImprimeArvoreBinaria((*arvore)->direita, l + 1);
    }
}

//percorre os elementos da árvore binária em pré-ordem
void PercorreArvoreBinariaPreOrdem(TipoArvore **arvore)
{
    if (!TestaArvoreBinariaVazia(arvore))
    {
        printf("%c ", (*arvore)->item.chave);
        PercorreArvoreBinariaPreOrdem((*arvore)->esquerda);
        PercorreArvoreBinariaPreOrdem((*arvore)->direita);
    }
}

//percorre os elementos da árvore binária em ordem simétrica
void PercorreArvoreBinariaOrdemSimetrica(TipoArvore **arvore)
{
    if (!TestaArvoreBinariaVazia(arvore))
    {
        PercorreArvoreBinariaOrdemSimetrica((*arvore)->esquerda);
        printf("%c ", (*arvore)->item.chave);
        PercorreArvoreBinariaOrdemSimetrica((*arvore)->direita);
    }
}

//percorre os elementos da árvore binária em pós-ordem
void PercorreArvoreBinariaPosOrdem(TipoArvore **arvore)
{
    if (!TestaArvoreBinariaVazia(arvore))
    {
        PercorreArvoreBinariaPosOrdem((*arvore)->esquerda);
        PercorreArvoreBinariaPosOrdem((*arvore)->direita);
        printf("%c ", (*arvore)->item.chave);
    }
}

//percorre os elementos da árvore binária em largura
void PercorreArvoreBinariaLargura(TipoArvore **arvore)
{
    TipoArvore **sub_arvore;

    TipoFila *fila = (TipoFila *)malloc(sizeof(TipoFila));
    CriaFilaVazia(fila);
    InsereFila(fila, arvore);

    while (!TestaFilaVazia(fila))
    {
        RemoveFila(fila, &sub_arvore);
        printf("%c ", (*sub_arvore)->item.chave);
        if (!TestaArvoreBinariaVazia((*sub_arvore)->esquerda))
            InsereFila(fila, (*sub_arvore)->esquerda);
        if (!TestaArvoreBinariaVazia((*sub_arvore)->direita))
            InsereFila(fila, (*sub_arvore)->direita);
    }
}

//percorre os elementos da árvore binária em profundidade
void PercorreArvoreBinariaProfundidade(TipoArvore **arvore)
{
    TipoArvore **sub_arvore;

    TipoPilha *pilha = (TipoPilha *)malloc(sizeof(TipoPilha));
    CriaPilhaVazia(pilha);
    InserePilha(pilha, arvore);

    while (!TestaPilhaVazia(pilha))
    {
        RemovePilha(pilha, &sub_arvore);
        printf("%c ", (*sub_arvore)->item.chave);
        if (!TestaArvoreBinariaVazia((*sub_arvore)->direita))
            InserePilha(pilha, (*sub_arvore)->direita);
        if (!TestaArvoreBinariaVazia((*sub_arvore)->esquerda))
            InserePilha(pilha, (*sub_arvore)->esquerda);
    }
}
