#include "Tabuleiro.h"
#include <stdio.h>
#include <stdlib.h>

Tabuleiro inicializarTabuleiro(){
	Tabuleiro goban;

	printf("Tamanho do goban (4<n<20): ");
	scanf("%d",&goban.dimensao);

	goban.matriz = inicializarMatriz(int goban.dimensao);


	return goban;
}

int** inicializarMatriz(int dimensao){
	int **matriz = (int **) malloc(dimensao * sizeof(int *));

	for (int i = 0; i < n; i++) {
		matriz[i] = (int *) malloc(dimensao * sizeof(int));
	}

	preencherMatriz(matriz, dimensao);

	return matriz;
}

void liberarMatriz(int **matriz){

	for (int i = 0; i < n; i++) {
		free(matriz[i]);
	}

	free(matriz);

}

void imprimirTabuleiro(Tabuleiro tabuleiro){
	for(int i=0; i<(tabuleiro.dimensao); i++){
		for(int j=0; j<(tabuleiro.dimensao); j++){

		}
	}
}

void preencherMatriz(int **matriz, int dimensao){
	for(int i=0; i < dimensao; i++){
		for(int j=0; j < dimensao; j++){
			matriz[i][j] = -1; 
		}
	}
}