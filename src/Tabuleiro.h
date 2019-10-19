#ifndef TABULEIRO_H
#define TABULEIRO_H

typedef struct{
	int **matriz;
	int dimensao;
}Tabuleiro;

Tabuleiro inicializarTabuleiro();
int** inicializarMatriz(int dimensao);
void liberarMatriz(Tabuleiro tabuleiro);
void imprimirTabuleiro(Tabuleiro tabuleiro);
void preencherMatriz(int **matriz, int dimensao);


#endif