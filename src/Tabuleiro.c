#include "headers/Traducao.h"
#include "headers/Tabuleiro.h"
#include "headers/Jogador.h"
#include <stdio.h>
#include <stdlib.h>

/**
	A função inicializarTabuleiro aloca dinamicamente o espaço da matriz
	Parâmetro: O tabuleiro
**/
void inicializarTabuleiro(Tabuleiro *tabuleiro){
	tabuleiro->matriz = (int **) malloc(tabuleiro->dimensao * sizeof(int *));

	for (int i = 0; i < tabuleiro->dimensao; i++) {
		tabuleiro->matriz[i] = (int *) malloc(tabuleiro->dimensao * sizeof(int));
	}
}

/**
	A função liberarMatriz libera a memória que foi alocada.
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
void imprimirTabuleiro(Tabuleiro goban, int peca){
	for(int j=0; j<goban.dimensao; j++){
		printf("%-2d  ",j);
	}
	printf("\n");

	for(int j=0; j<goban.dimensao-1; j++){
		printf("%c---", caracterePeca(goban, 0, j, goban.matriz[0][j], peca));
	}
	printf("%c 0\n",caracterePeca(goban,0,goban.dimensao-1,goban.matriz[0][goban.dimensao-1], peca));

	for (int i=1; i<goban.dimensao; i++){
		for (int j=0; j<goban.dimensao; j++){
			printf("%c   ",'|');
		}
		printf("\n");

		for (int j=0; j<goban.dimensao-1; j++){
			printf("%c---", caracterePeca(goban, i, j, goban.matriz[i][j], peca));
		}
		printf("%c %d\n",caracterePeca(goban,i,goban.dimensao-1,goban.matriz[i][goban.dimensao-1], peca),i);
	}
}

/**
	A função limparTabuleiro será útil para preencher a matriz com 
	algum valor qualquer para que saiba se o espaço da matriz está
	ocupado por uma peça ou não.
	Parâmetro: o tabuleiro
**/
void limparTabuleiro(Tabuleiro tabuleiro){
	for(int i=0; i < tabuleiro.dimensao; i++){
		for(int j=0; j < tabuleiro.dimensao; j++){
			tabuleiro.matriz[i][j] = -1; 
		}
	}
}