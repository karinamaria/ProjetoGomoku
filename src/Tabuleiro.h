#ifndef TABULEIRO_H
#define TABULEIRO_H

#include "Jogador.h"

typedef struct{
	int **matriz;
	int dimensao;
}Tabuleiro;

Tabuleiro inicializarTabuleiro();
int** inicializarMatriz(int dimensao);
void liberarMatriz(int **matriz, int dimensao);
void imprimirTabuleiro(Tabuleiro tabuleiro);
void preencherMatriz(int **matriz, int dimensao);


#endif