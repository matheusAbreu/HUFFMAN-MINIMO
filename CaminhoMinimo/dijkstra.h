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
void limpandoMeuTexto(MeuTexto *x);//Libera o conteudo malocado
void copiandoMeuTexto(MeuTexto *dest, MeuTexto *ori, int ini, int fim);//Copia trecho do texto original para o texto destino
int verificandoCaracterNumero(char c);

#endif // DIJKSTRA_H_INCLUDED
