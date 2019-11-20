#ifndef TABULEIRO_H
#define TABULEIRO_H

#include "Jogador.h"

typedef struct{
	int **matriz;
	int dimensao;
}Tabuleiro;

typedef struct{
	int lin;
	int col;
}Casa;

void inicializarTabuleiro(Tabuleiro *tabuleiro);
int** inicializarMatriz(int dimensao);
void liberarMatriz(int **matriz, int dimensao);
void imprimirTabuleiro(Tabuleiro tabuleiro);
void limparTabuleiro(Tabuleiro tabuleiro);


#endif