#ifndef DIJKSTRA_H_INCLUDED
#define DIJKSTRA_H_INCLUDED

#include <string.h>
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include "grafo.h"

#if linux
#define LIMP __fpurge(stdin)
#endif
#if WIN32
#define LIMP fflush(stdin)
#endif

struct MEUTEXTO typedef MeuTexto;

char *PegandoConteudoDoArquivo(FILE *arq);/*Essa função somente pega o conteudo do arquivo
o codigo não abre, e nem fecha o arquivo*/
MeuTexto *criandoMeuTexto();
void identificandoQuebraLinha(MeuTexto *x);
MeuTexto *escrevendoMeuTexto(FILE *arq);
void imprimindoMeuTexto(MeuTexto *x);


#endif // DIJKSTRA_H_INCLUDED
