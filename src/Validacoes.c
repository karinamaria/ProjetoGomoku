#include "Validacoes.h"

/**
	A função verificarFimDeJogo analisa linhas, colunas e diagonais procurando
	um ganhador.
	Parâmetros: O jogo e uma peca(que armazenará a peça ganhadora).
	Retorno: Será 0(Se o jogo não tiver finalizado) e 1(se o jogo acabou).
**/
int verificarFimDeJogo(Jogo *jogo, Peca *peca, int *vitoriaPorCaptura) {
	return    verificarQntCapturas(jogo, peca, vitoriaPorCaptura)
	       || verificarLinhas(jogo, peca, vitoriaPorCaptura)
		   || verificarColunas(jogo, peca, vitoriaPorCaptura)
		   || verificarDiagPrincipalBaixo(jogo, peca, vitoriaPorCaptura)
		   || verificarDiagPrincipalCima(jogo, peca, vitoriaPorCaptura)
		   || verificarDiagSecundariaCima(jogo, peca, vitoriaPorCaptura)
		   || verificarDiagSecundariaBaixo(jogo, peca, vitoriaPorCaptura)
		   || verificarEmpate(jogo, peca);
}

/**

**/
int verificarQntCapturas(Jogo *jogo, Peca *peca, int *vitoriaPorCaptura) {
	if (jogo->jogador1.capturas == 1) {
		*peca = jogo->jogador1.peca;
		*vitoriaPorCaptura = 1;
		return 1;
	}

	else if (jogo->jogador2.capturas == 1) {
		*peca = jogo->jogador2.peca;
		*vitoriaPorCaptura = 1;
		return 1;
	}

	return 0;
}

/**
	A função verificarLinhas verifica as linhas em busca de um ganhador
	Parâmetro: O jogo e uma peca(armazenará peça ganhadora, caso o jogo tenha um ganhador)
	Retorno: 0(se não houver ganhador pelas linhas) ou 1(caso haja ganhador por uma linha)
**/ 
int verificarLinhas(Jogo *jogo, Peca *peca, int *vitoriaPorCaptura) {
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
				*vitoriaPorCaptura = 0;
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
int verificarColunas(Jogo *jogo, Peca *peca, int *vitoriaPorCaptura) {
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
				*vitoriaPorCaptura = 0;
				return 1;
			}
		}
		cont = 1;
	}

	return 0;
}

/**
	A função verificarDiagPrincipalBaixo verifica o tabuleiro da diagonal principal
	para baixo em busca busca de um ganhador
	Parâmetro: O jogo e uma peca(que armazenará peça ganhadora, caso o jogo tenha um ganhador)
	Retorno: 0(se não houve ganhador) ou 1(ganhador encontrado)
**/
int verificarDiagPrincipalBaixo(Jogo *jogo, Peca *peca, int *vitoriaPorCaptura) {
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
				*vitoriaPorCaptura = 0;
				return 1;
			}
		}
		cont = 1;
	}

	return 0;
}

/**
	A função verificarDiagPrincipalCima verifica o tabuleiro da diagonal principal
	para cima em busca busca de um ganhador
	Parâmetro: O jogo e uma peca(que armazenará peça ganhadora, caso o jogo tenha um ganhador)
	Retorno: 0(se não houve ganhador) ou 1(ganhador encontrado)
**/
int verificarDiagPrincipalCima(Jogo *jogo, Peca *peca, int *vitoriaPorCaptura) {
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
				*vitoriaPorCaptura = 0;
				return 1;
			}
		}
		cont = 1;
	}

	return 0;
}

/**
	A função verificarDiagSecundariaCima verifica o tabuleiro da diagonal secundária
	para cima em busca busca de um ganhador
	Parâmetro: O jogo e uma peca(que armazenará peça ganhadora, caso o jogo tenha um ganhador)
	Retorno: 0(se não houve ganhador) ou 1(ganhador encontrado)
**/
int verificarDiagSecundariaCima(Jogo *jogo, Peca *peca, int *vitoriaPorCaptura) {
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
				*vitoriaPorCaptura = 0;
				return 1;
			}
		}
		cont = 1;
	}

	return 0;
}

/**
	A função verificarDiagSecundariaBaixo verifica o tabuleiro da diagonal secundária
	para baixo em busca busca de um ganhador
	Parâmetro: O jogo e uma peca(que armazenará peça ganhadora, caso o jogo tenha um ganhador)
	Retorno: 0(se não houve ganhador) ou 1(ganhador encontrado)
**/
int verificarDiagSecundariaBaixo(Jogo *jogo, Peca *peca, int *vitoriaPorCaptura) {
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
				*vitoriaPorCaptura = 0;
				return 1;
			}
		}
		cont = 1;
	}

	return 0;
}

/**
	A função verificarEmpate analisa o tabuleiro a fim de descobrir
	se o jogo foi finalizado por empate
	Parâmetro: O jogo e uma peca(que armazenará -1, se houver empate)
	Retorno: 0(não há empate) ou 1(jogo finalizado por empate)
**/
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