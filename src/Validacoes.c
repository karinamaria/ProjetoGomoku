#include "Validacoes.h"
#include <stdio.h>

/**
	A função verificarFimDeJogo analisa linhas, colunas e diagonais procurando
	um ganhador.
	Parâmetros: O jogo e uma peca(que armazenará a peça ganhadora).
	Retorno: Será 0(Se o jogo não tiver finalizado) e 1(se o jogo acabou).
**/
int verificarFimDeJogo(Jogo *jogo, Peca *peca) {
	return    verificarLinhas(jogo, peca)
		   || verificarColunas(jogo, peca)
		   || verificarDiagPrincipalBaixo(jogo, peca)
		   || verificarDiagPrincipalCima(jogo, peca)
		   || verificarDiagSecundariaCima(jogo, peca)
		   || verificarDiagSecundariaBaixo(jogo, peca)
		   || verificarEmpate(jogo, peca);
}

/**
	A função verificarLinhas verifica as linhas em busca de um ganhador
	Parâmetro: O jogo e uma peca(armazenará peça ganhadora, caso o jogo tenha um ganhador)
	Retorno: 0(se não houver ganhador pelas linhas) ou 1(caso haja ganhador por uma linha)
**/ 
int verificarLinhas(Jogo *jogo, Peca *peca) {
	int cont = 1;

	for (int i = 0; i < jogo->goban.dimensao; i++) {
		for (int j = 1; j < jogo->goban.dimensao; j++) {
			if (jogo->goban.matriz[i][j] != -1 && jogo->goban.matriz[i][j] == jogo->goban.matriz[i][j-1]) {
				cont++;
			}else {
				cont = 1;
			}

			if (cont == 5) {
				*peca = jogo->goban.matriz[i][j];
				return 1;
			}
		}
		cont = 1;
	}

	return 0;
}

/**
	A função verificarColunas verifica as colunas em busca de um ganhador
	Parâmetro: O jogo e uma peca(que armazenará peça ganhadora, caso o jogo tenha um ganhador)
	Retorno: 0(se não houver ganhador pelas colunas) ou 1(caso haja ganhador por uma coluna)
**/ 
int verificarColunas(Jogo *jogo, Peca *peca) {
	int cont = 1;

	for (int j = 0; j < jogo->goban.dimensao; j++) {
		for (int i = 1; i < jogo->goban.dimensao; i++) {
			if (jogo->goban.matriz[i][j] != -1 && jogo->goban.matriz[i][j] == jogo->goban.matriz[i-1][j]) {
				cont++;
			}else {
				cont = 1;
			}

			if (cont == 5) {
				*peca = jogo->goban.matriz[i][j];
				return 1;
			}
		}
		cont = 1;
	}

	return 0;
}

// Verificar diagonal principal para baixo
int verificarDiagPrincipalBaixo(Jogo *jogo, Peca *peca) {
	int cont = 1;

	for(int lin=0; lin < jogo->goban.dimensao; lin++){
		for(int i=lin+1, j=1; i < jogo->goban.dimensao; i++, j++){
			if (jogo->goban.matriz[i][j] != -1 && jogo->goban.matriz[i][j] == jogo->goban.matriz[i-1][j-1]) {
				cont++;
			}else{
				cont = 1;
			}

			if (cont == 5) {
				*peca = jogo->goban.matriz[i][j];
				return 1;
			}
		}
		cont = 1;
	}

	return 0;
}

// Verificar diagonal principal para cima
int verificarDiagPrincipalCima(Jogo *jogo, Peca *peca) {
	int cont = 1;

	for(int col=1; col < jogo->goban.dimensao; col++){
		for(int j=col+1, i=1; j < jogo->goban.dimensao; j++, i++){
			if (jogo->goban.matriz[i][j] != -1 && jogo->goban.matriz[i][j] == jogo->goban.matriz[i-1][j-1]) {
				cont++;
			}else{
				cont = 1;
			}

			if (cont == 5) {
				*peca = jogo->goban.matriz[i][j];
				return 1;
			}
		}
		cont = 1;
	}

	return 0;
}

// Verificar diagonal secundária para cima
int verificarDiagSecundariaCima(Jogo *jogo, Peca *peca) {
	int cont = 1;

	for(int lin=jogo->goban.dimensao-1; lin>=0; lin--){
		for(int i=lin-1, j=1; i>=0; i--, j++){
			if (jogo->goban.matriz[i][j] != -1 && jogo->goban.matriz[i][j] == jogo->goban.matriz[i+1][j-1]) {
				cont++;
			}else{
				cont = 1;
			}

			if (cont == 5) {
				*peca = jogo->goban.matriz[i][j];
				return 1;
			}
		}
		cont = 1;
	}

	return 0;
}

// Verificar diagonal secundária para baixo
int verificarDiagSecundariaBaixo(Jogo *jogo, Peca *peca) {
	int cont = 1;

	for(int col=1; col < jogo->goban.dimensao; col++){
		for(int j=col+1, i=jogo->goban.dimensao-2; j < jogo->goban.dimensao; j++, i--){
			if (jogo->goban.matriz[i][j] != -1 && jogo->goban.matriz[i][j] == jogo->goban.matriz[i+1][j-1]) {
				cont++;
			}else{
				cont = 1;
			}

			if (cont == 5) {
				*peca = jogo->goban.matriz[i][j];
				return 1;
			}
		}
		cont = 1;
	}

	return 0;
}

int verificarEmpate(Jogo *jogo, Peca *peca) {
	for (int i = 0; i < jogo->goban.dimensao; i++) {
		for (int j = 0; j < jogo->goban.dimensao; j++) {
			if (jogo->goban.matriz[i][j] == -1){
				return 0;
			}
		}
	}

	*peca = -1;
	return 1;
}