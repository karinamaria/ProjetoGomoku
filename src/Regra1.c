#include "headers/Regra1.h"

/**
	A função verificarCaptura vê se em uma das 8 direções existe uma
	situação de captura (XYYX)
	Parâmetros: O jogo, a linha e coluna da jogada atual
**/
void verificarCaptura(Jogo *jogo, int i, int j) {
	capturarPecas(jogo, i, j,  0,  1);
	capturarPecas(jogo, i, j,  0, -1);
	capturarPecas(jogo, i, j,  1,  0);
	capturarPecas(jogo, i, j, -1,  0);
	capturarPecas(jogo, i, j,  1,  1);
	capturarPecas(jogo, i, j, -1, -1);
	capturarPecas(jogo, i, j, -1,  1);
	capturarPecas(jogo, i, j,  1, -1);
}

/**
	A função capturarPecas é responsável por capturar as peças, se permitido
	pela função validarCaptura
	Parâmetros: O jogo, a linha, coluna, a direção da linha e a direção da coluna
**/
void capturarPecas(Jogo *jogo, int i, int j, int di, int dj) {
	if (validarCaptura(jogo->goban, jogo->proximoJogador, i, j, di, dj)) {
		jogo->goban.matriz[i +   di][j +   dj] = -1;
		jogo->goban.matriz[i + 2*di][j + 2*dj] = -1;

		if (jogo->proximoJogador == jogo->jogador1.peca) {
			jogo->jogador1.capturas++;
		}
		else {
			jogo->jogador2.capturas++;
		}
	}
}

/**
	A função validarCaptura analisa o tabuleiro a fim de verificar se 
	é possível fazer captura de peças
	Parâmetros: O goban, a peca(da vez), a linha, coluna,
	a direção da linha(1:Para baixo, -1:Para cima e 0:Sem movimentos)
	e a direção da coluna(1:Para direita, -1:Para esquerda, 0: Sem movimento)
	Retorno: 1(Se é possível realizar a captura) ou 0(Se não é possível)
**/
int validarCaptura(Tabuleiro goban, int peca, int i, int j, int di, int dj) {
	return    i + 3*di >= 0
           && i + 3*di < goban.dimensao
           && j + 3*dj >= 0
           && j + 3*dj < goban.dimensao
           && goban.matriz[i +   di][j +   dj] == 1-peca
           && goban.matriz[i + 2*di][j + 2*dj] == 1-peca
           && goban.matriz[i + 3*di][j + 3*dj] == peca;
}