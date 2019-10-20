#include "Tabuleiro.h"
#include <stdio.h>
#include <stdlib.h>

Tabuleiro inicializarTabuleiro(){
	Tabuleiro goban;

	printf("Tamanho do goban (4<n<20): ");
	scanf("%d",&goban.dimensao);

	goban.matriz = inicializarMatriz(goban.dimensao);


	return goban;
}

/**
	A função inicializarMatriz aloca dinamicamente o espaço da matriz
	Parâmetro: A dimensão digitada pelo usuário
**/
int** inicializarMatriz(int dimensao){
	int **matriz = (int **) malloc(dimensao * sizeof(int *));

	for (int i = 0; i < dimensao; i++) {
		matriz[i] = (int *) malloc(dimensao * sizeof(int));
	}

	preencherMatriz(matriz, dimensao);

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

void imprimirTabuleiro(Tabuleiro tabuleiro){
	for(int i=0; i<tabuleiro.dimensao; i++){
		printf("%-2d  ",i);
	}
	printf("\n");

	for(int i=0; i<tabuleiro.dimensao-1; i++){
		printf("%c---", '-');
	}
	printf("%c 0\n", '-');

	for (int i=1; i<tabuleiro.dimensao; i++){
		for (int j=0; j<tabuleiro.dimensao; j++){
			printf("%c   ",'|');
		}
		printf("\n");

		for (int j=0; j<tabuleiro.dimensao-1; j++){
			printf("%c---", '-');
		}
		printf("%c %d\n", '-', i);
	}
}

/**
**/
void preencherMatriz(int **matriz, int dimensao){
	for(int i=0; i < dimensao; i++){
		for(int j=0; j < dimensao; j++){
			matriz[i][j] = -1; 
		}
	}
}