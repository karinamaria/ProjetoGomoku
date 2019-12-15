#include "headers/Regra3.h"
#include "headers/Regra2.h"

/**
	A função verificarFimDeJogo verifica se houve vitória por
	captura ou por sequência e se houve empate.
	Parâmetros: O jogo, peca(ganhadora) e vitoriaPorCaptura(0 ou 1)
	Retorno: Será 0(Se o jogo não tiver finalizado) e 1(se o jogo acabou).
**/
int verificarFimDeJogo(Jogo *jogo, Peca *peca, int *vitoriaPorCaptura) {
	*peca = -1;

	if (verificarQntCapturas(jogo, peca)) {
		*vitoriaPorCaptura = 1;
		return 1;
	}
	
	if (verificarVitoria(jogo, peca)) {
		if (jogo->ganhando == *peca) {
			*vitoriaPorCaptura = 0;
			return 1;
		}
		else {
			jogo->ganhando = *peca;
			return 0;
		}
	}

	if (verificarEmpate(jogo->goban, jogo->proximoJogador, peca)) {
		return 1;
	}

	jogo->ganhando = -1;
	return 0;
}

/**
	A função verificarQntCapturas verifica se houve vitória por qnt de capturas
	Parâmetros: O jogo e peca(ganhadora)
	Retorno: 0(se não houver ganhador por capturas) ou 1(caso haja)
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
	A função verificarVitoria verifica se existe uma sequência de 5
	ou mais peças em uma linha, coluna ou diagonal.
	Parâmetros: O jogo e a peca(ganhadora)
	Retorno: 0(se não existe sequência) ou >0(se existe)
**/
int verificarVitoria(Jogo *jogo, Peca *peca) {
return   verificarLinhas(jogo->goban, peca, jogo->ganhando)
	   + verificarColunas(jogo->goban, peca, jogo->ganhando)
	   + verificarDiagPrincipalBaixo(jogo->goban, peca, jogo->ganhando)
	   + verificarDiagPrincipalCima(jogo->goban, peca, jogo->ganhando)
	   + verificarDiagSecundariaCima(jogo->goban, peca, jogo->ganhando)
	   + verificarDiagSecundariaBaixo(jogo->goban, peca, jogo->ganhando);
}

/**
	A função verificarLinhas verifica as linhas em busca de um ganhador
	Parâmetros: O goban, peca(ganhadora) e ganhando(quem está ganhando)
	Retorno: 0(se não houver ganhador pelas linhas) ou 1(caso haja)
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
	Parâmetros: O goban, peca(ganhadora) e ganhando(quem está ganhando)
	Retorno: 0(se não houver ganhador pelas colunas) ou 1(caso haja)
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
	A função verificarDiagPrincipalBaixo verifica as diagonais
	abaixo da diagonal principal em busca de um ganhador.
	Parâmetros: O goban, peca(ganhadora) e ganhando(quem está ganhando)
	Retorno: 0(se não houver ganhador pelas diagonais) ou 1(caso haja)
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
	A função verificarDiagPrincipalCima verifica as diagonais
	acima da diagonal principal em busca de um ganhador.
	Parâmetros: O goban, peca(ganhadora) e ganhando(quem está ganhando)
	Retorno: 0(se não houver ganhador pelas diagonais) ou 1(caso haja)
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
	A função verificarDiagSecundariaCima verifica as diagonais
	acima da diagonal secundária em busca de um ganhador.
	Parâmetros: O goban, peca(ganhadora) e ganhando(quem está ganhando)
	Retorno: 0(se não houver ganhador pelas diagonais) ou 1(caso haja)
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
	A função verificarDiagSecundariaBaixo verifica as diagonais
	abaixo da diagonal secundária em busca de um ganhador.
	Parâmetros: O goban, peca(ganhadora) e ganhando(quem está ganhando)
	Retorno: 0(se não houver ganhador pelas diagonais) ou 1(caso haja)
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
	Parâmetros: goban, proximoJogador e peca(que armazena -1 se for empate)
	Retorno: 0(se não há empate) ou 1(se jogo finalizado por empate)
**/
int verificarEmpate(Tabuleiro goban, int proximoJogador, Peca *peca) {
	for (int i = 0; i < goban.dimensao; i++) {
		for (int j = 0; j < goban.dimensao; j++) {
			if (goban.matriz[i][j] == -1 && !verificarFormacao3x3(goban, i, j, proximoJogador)){
				return 0;
			}
		}
	}

	*peca = -1;
	return 1;
}