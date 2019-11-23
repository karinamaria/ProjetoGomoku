#include "headers/Traducao.h"
#include "headers/Tabuleiro.h"
#include <stdio.h>
#include <stdlib.h>

/**
	A função inicializarTabuleiro pergunta as dimensões do tabuleiro
	e inicializa a matriz
	Parâmetro: o tabuleiro e o idioma
**/
void inicializarTabuleiro(Tabuleiro *tabuleiro, int idioma){
	do{
		printf("%s (4<n<20): ", perguntas(GOBAN, idioma));
		scanf("%d",&tabuleiro->dimensao);
	}while(tabuleiro->dimensao < 5 || tabuleiro->dimensao > 19);

	inicializarMatriz(tabuleiro);
}

/**
	A função inicializarMatriz aloca dinamicamente o espaço da matriz
	Parâmetro: O tabuleiro
**/
void inicializarMatriz(Tabuleiro *tabuleiro){
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