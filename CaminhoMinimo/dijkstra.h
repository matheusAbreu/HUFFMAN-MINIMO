#ifndef DIJKSTRA_H_INCLUDED
#define DIJKSTRA_H_INCLUDED

#include <string.h>
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include "grafo.h"

#if linux
#define LIMP __fpurge
#endif
#if WIN32
#define LIMP fflush
#endif

char *PegandoConteudoDoArquivo(FILE *arq);/*Essa função somente pega o conteudo do arquivo
o codigo não abre, e nem fecha o arquivo*/


#endif // DIJKSTRA_H_INCLUDED
