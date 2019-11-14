#include "Jogo.h"
#include "Captura.h"

/**
	A função analisarCaptura incrementa a quantidade de capturas de um jogador,
	se permitido pela função verificarCaptura
	Parâmetro: O jogo, a linha e coluna da jogada atual 	
**/
void analisarCaptura(Jogo *jogo, int i, int j) {
	if (verificarCaptura(jogo, i, j)) {
		if (jogo->jogador1.peca == jogo->goban.matriz[i][j]) {
			jogo->jogador1.capturas++;
		}
		else {
			jogo->jogador2.capturas++;
		}
	}
}

/**
	A função verificarCaptura vê se em uma das 8 direções existe uma
	situação de captura (XYYX)
	Parâmetro: O jogo, a linha e coluna da jogada atual
	Retorno: 1(Se o jogador atual realizou uma captura) ou 0(Não houve nenhuma captura)
**/
int verificarCaptura(Jogo *jogo, int i, int j) {
	return    capturouPecas(jogo, i, j,  0, 1) || capturouPecas(jogo, i, j,  0, -1)
		   || capturouPecas(jogo, i, j,  1, 0) || capturouPecas(jogo, i, j, -1,  0)
		   || capturouPecas(jogo, i, j,  1, 1) || capturouPecas(jogo, i, j, -1, -1)
		   || capturouPecas(jogo, i, j, -1, 1) || capturouPecas(jogo, i, j,  1, -1);
}

/**
	A função capturouPecas é responsável por capturar as peças, se permitido
	pela função validarCaptura
	Parâmetros: O jogo, a linha, coluna, a direção da linha e a direção da coluna
	Retorno: 1(Se é possível realizar a captura) ou 0(Se não é possível)
**/
int capturouPecas(Jogo *jogo, int i, int j, int di, int dj) {
	if (validarCaptura(jogo, i, j, di, dj)) {
		jogo->goban.matriz[i +   di][j +   dj] = -1;
		jogo->goban.matriz[i + 2*di][j + 2*dj] = -1;

		return 1;
	}

	return 0;
}

/**
	A função validarCaptura analisa o tabuleiro a fim de verificar se 
	é possível fazer captura de peças
	Parâmetros: O jogo, a linha, coluna,
	a direção da linha(1:Para baixo, -1:Para cima e 0:Sem movimentos)
	e a direção da coluna(1:Para direita, -1:Para esquerda, 0: Sem movimento)
	Retorno: 1(Se é possível realizar a captura) ou 0(Se não é possível)
**/
int validarCaptura(Jogo *jogo, int i, int j, int di, int dj) {
	return    i + 3*di >= 0
           && i + 3*di < jogo->goban.dimensao
           && j + 3*dj >= 0
           && j + 3*dj < jogo->goban.dimensao
           && jogo->goban.matriz[    i   ][    j   ] == jogo->proximoJogador
           && jogo->goban.matriz[i +   di][j +   dj] == 1-jogo->proximoJogador
           && jogo->goban.matriz[i + 2*di][j + 2*dj] == 1-jogo->proximoJogador
           && jogo->goban.matriz[i + 3*di][j + 3*dj] == jogo->proximoJogador;
}