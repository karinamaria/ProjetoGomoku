#include "Tabuleiro.h"
#include <stdio.h>
#include <stdlib.h>

void inicializarTabuleiro(Tabuleiro *tabuleiro){
	do{
		printf("Tamanho do goban (4<n<20): ");
		scanf("%d",&tabuleiro->dimensao);
	}while(tabuleiro->dimensao < 5 || tabuleiro->dimensao > 19);

	tabuleiro->matriz = inicializarMatriz(tabuleiro->dimensao);
}

/**
	A função inicializarMatriz aloca dinamicamente o espaço da matriz
	Parâmetro: A dimensão digitada pelo usuário
	Retorno: A matriz alocada dinamicamente
**/
int** inicializarMatriz(int dimensao){
	int **matriz = (int **) malloc(dimensao * sizeof(int *));

	for (int i = 0; i < dimensao; i++) {
		matriz[i] = (int *) malloc(dimensao * sizeof(int));
	}

	return matriz;
}

/**
	A função liberarMatriz libera a memória que foi alocada
	Será útil quando o jogo for finalizado
	Parâmetros: A matriz e a dimensão
**/
void liberarMatriz(int **matriz, int dimensao){

	for (int i = 0; i < dimensao; i++) {
		free(matriz[i]);
	}

	free(matriz);

}

/**
	A função imprimirTabuleiro imprime o tabuleiro com as peças escolhidas
	pelos jogadores
	Parâmetro: O tabuleiro
**/
void imprimirTabuleiro(Tabuleiro tabuleiro){
	for(int j=0; j<tabuleiro.dimensao; j++){
		printf("%-2d  ",j);
	}
	printf("\n");

	for(int j=0; j<tabuleiro.dimensao-1; j++){
		printf("%c---", caracterPeca(tabuleiro.matriz[0][j]));
	}
	printf("%c 0\n", caracterPeca(tabuleiro.matriz[0][tabuleiro.dimensao-1]));

	for (int i=1; i<tabuleiro.dimensao; i++){
		for (int j=0; j<tabuleiro.dimensao; j++){
			printf("%c   ",'|');
		}
		printf("\n");

		for (int j=0; j<tabuleiro.dimensao-1; j++){
			printf("%c---", caracterPeca(tabuleiro.matriz[i][j]));
		}
		printf("%c %d\n", caracterPeca(tabuleiro.matriz[i][tabuleiro.dimensao-1]), i);
	}
}

/**
	A função limparMatriz será útil para preencher a matriz com 
	algum valor qualquer para que saiba se o espaço da matriz está
	ocupado por uma peça ou não.
**/
void limparMatriz(int **matriz, int dimensao){
	for(int i=0; i < dimensao; i++){
		for(int j=0; j < dimensao; j++){
			matriz[i][j] = -1; 
		}
	}
}