#include "Regra3.h"

/**
	A função verificarFimDeJogo analisa linhas, colunas e diagonais procurando
	um ganhador.
	Parâmetro: O jogo, peca(peça ganhadora), vitoriaPorCaptura(informa se o jogo foi vencido dessa forma)
	Retorno: Será 0(Se o jogo não tiver finalizado) e 1(se o jogo acabou).
**/
int verificarFimDeJogo(Jogo *jogo, Peca *peca, int *vitoriaPorCaptura) {
	if (verificarQntCapturas(jogo, peca)) {
		*vitoriaPorCaptura = 1;
		return 1;
	}
	else if (
		       verificarLinhas(jogo->goban, peca, jogo->ganhando)
		     + verificarColunas(jogo->goban, peca, jogo->ganhando)
		     + verificarDiagPrincipalBaixo(jogo->goban, peca, jogo->ganhando)
		     + verificarDiagPrincipalCima(jogo->goban, peca, jogo->ganhando)
		     + verificarDiagSecundariaCima(jogo->goban, peca, jogo->ganhando)
		     + verificarDiagSecundariaBaixo(jogo->goban, peca, jogo->ganhando)
	) {
		if (jogo->ganhando == *peca) {
			*vitoriaPorCaptura = 0;
			return 1;
		}
		else {
			jogo->ganhando = *peca;
			return 0;
		}
	}

	if (verificarEmpate(jogo, peca)) {
		return 1;
	}

	jogo->ganhando = -1;
	return 0;
}

/**
	A função verificarQntCapturas verifica se houve vitória por qnt de capturas
	Parâmetro: O jogo e peca(peça ganhadora)
	Retorno: 0(se não houver ganhador por capturas) ou 1(caso haja ganhador por capturas)
**/
int verificarQntCapturas(Jogo *jogo, Peca *peca) {
	if (jogo->jogador1.capturas > 4) {
		*peca = jogo->jogador1.peca;
		return 1;
	}

	else if (jogo->jogador2.capturas > 4) {
		*peca = jogo->jogador2.peca;
		return 1;
	}

	return 0;
}

/**
	A função verificarLinhas verifica as linhas em busca de um ganhador
	Parâmetro: O goban, peca(peça ganhadora), vitoriaPorCaptura
	Retorno: 0(se não houver ganhador pelas linhas) ou 1(caso haja ganhador por uma linha)
**/ 
int verificarLinhas(Tabuleiro goban, Peca *peca, int ganhando) {
	int cont = 1;
	int retorno = 0;

	for (int i = 0; i < goban.dimensao; i++) {
		for (int j = 1; j < goban.dimensao; j++) {
			if (goban.matriz[i][j] != -1 && goban.matriz[i][j] == goban.matriz[i][j-1]) {
				cont++;
			}else {
				cont = 1;
			}

			if (cont > 4 && (*peca == -1 || goban.matriz[i][j] == ganhando)) {
				*peca = goban.matriz[i][j];
				retorno = 1;
			}
		}
		cont = 1;
	}

	return retorno;
}

/**
	A função verificarColunas verifica as colunas em busca de um ganhador
	Parâmetro: O jogo, peca(peça ganhadora), vitoriaPorCaptura
	Retorno: 0(se não houver ganhador pelas colunas) ou 1(caso haja ganhador por uma coluna)
**/ 
int verificarColunas(Tabuleiro goban, Peca *peca, int ganhando) {
	int cont = 1;
	int retorno = 0;

	for (int j = 0; j < goban.dimensao; j++) {
		for (int i = 1; i < goban.dimensao; i++) {
			if (goban.matriz[i][j] != -1 && goban.matriz[i][j] == goban.matriz[i-1][j]) {
				cont++;
			}else {
				cont = 1;
			}

			if (cont > 4 && (*peca == -1 || goban.matriz[i][j] == ganhando)) {
				*peca = goban.matriz[i][j];
				retorno = 1;
			}
		}
		cont = 1;
	}

	return retorno;
}

/**
	A função verificarDiagPrincipalBaixo verifica o tabuleiro da diagonal principal
	para baixo em busca busca de um ganhador
	Parâmetro: O jogo, peca(peça ganhadora), vitoriaPorCaptura
	Retorno: 0(se não houve ganhador) ou 1(ganhador encontrado)
**/
int verificarDiagPrincipalBaixo(Tabuleiro goban, Peca *peca, int ganhando) {
	int cont = 1;
	int retorno = 0;

	for(int lin=0; lin < goban.dimensao; lin++){
		for(int i=lin+1, j=1; i < goban.dimensao; i++, j++){
			if (goban.matriz[i][j] != -1 && goban.matriz[i][j] == goban.matriz[i-1][j-1]) {
				cont++;
			}else{
				cont = 1;
			}

			if (cont > 4 && (*peca == -1 || goban.matriz[i][j] == ganhando)) {
				*peca = goban.matriz[i][j];
				retorno = 1;
			}
		}
		cont = 1;
	}

	return retorno;
}

/**
	A função verificarDiagPrincipalCima verifica o tabuleiro da diagonal principal
	para cima em busca busca de um ganhador
	Parâmetro: O jogo, peca(peça ganhadora), vitoriaPorCaptura
	Retorno: 0(se não houve ganhador) ou 1(ganhador encontrado)
**/
int verificarDiagPrincipalCima(Tabuleiro goban, Peca *peca, int ganhando) {
	int cont = 1;
	int retorno = 0;

	for(int col=1; col < goban.dimensao; col++){
		for(int j=col+1, i=1; j < goban.dimensao; j++, i++){
			if (goban.matriz[i][j] != -1 && goban.matriz[i][j] == goban.matriz[i-1][j-1]) {
				cont++;
			}else{
				cont = 1;
			}

			if (cont > 4 && (*peca == -1 || goban.matriz[i][j] == ganhando)) {
				*peca = goban.matriz[i][j];
				retorno = 1;
			}
		}
		cont = 1;
	}

	return retorno;
}

/**
	A função verificarDiagSecundariaCima verifica o tabuleiro da diagonal secundária
	para cima em busca busca de um ganhador
	Parâmetro: O jogo, peca(peça ganhadora), vitoriaPorCaptura
	Retorno: 0(se não houve ganhador) ou 1(ganhador encontrado)
**/
int verificarDiagSecundariaCima(Tabuleiro goban, Peca *peca, int ganhando) {
	int cont = 1;
	int retorno = 0;

	for(int lin=goban.dimensao-1; lin>=0; lin--){
		for(int i=lin-1, j=1; i>=0; i--, j++){
			if (goban.matriz[i][j] != -1 && goban.matriz[i][j] == goban.matriz[i+1][j-1]) {
				cont++;
			}else{
				cont = 1;
			}

			if (cont > 4 && (*peca == -1 || goban.matriz[i][j] == ganhando)) {
				*peca = goban.matriz[i][j];
				retorno = 1;
			}
		}
		cont = 1;
	}

	return retorno;
}

/**
	A função verificarDiagSecundariaBaixo verifica o tabuleiro da diagonal secundária
	para baixo em busca busca de um ganhador
	Parâmetro: O jogo, peca(peça ganhadora), vitoriaPorCaptura
	Retorno: 0(se não houve ganhador) ou 1(ganhador encontrado)
**/
int verificarDiagSecundariaBaixo(Tabuleiro goban, Peca *peca, int ganhando) {
	int cont = 1;
	int retorno = 0;

	for(int col=1; col < goban.dimensao; col++){
		for(int j=col+1, i=goban.dimensao-2; j < goban.dimensao; j++, i--){
			if (goban.matriz[i][j] != -1 && goban.matriz[i][j] == goban.matriz[i+1][j-1]) {
				cont++;
			}else{
				cont = 1;
			}

			if (cont > 4 && (*peca == -1 || goban.matriz[i][j] == ganhando)) {
				*peca = goban.matriz[i][j];
				retorno = 1;
			}
		}
		cont = 1;
	}

	return retorno;
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
			if (jogo->goban.matriz[i][j] == -1 && !verificarFormacao3x3(jogo->goban, i, j, jogo->proximoJogador)){
				return 0;
			}
		}
	}

	*peca = -1;
	return 1;
}