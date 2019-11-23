#include "headers/IA.h"
#include "headers/Util.h"
#include "headers/Regra2.h"
#include "headers/Regra1.h"
#include <stdio.h>

void pedirJogadaIA(Jogo *jogo, int *lin, int *col) {
	Jogada jogadas[500];
	int n = 0;

	if (jogo->turno < 2) {
		*lin = sortearNumero(1, jogo->goban.dimensao - 2);
		*col = sortearNumero(1, jogo->goban.dimensao - 2);
		return;
	}

	for (int i = 0; i < jogo->goban.dimensao; i++) {
		for (int j = 0; j < jogo->goban.dimensao; j++) {
			if (jogo->goban.matriz[i][j] == -1 && !verificarFormacao3x3(jogo->goban, i, j, jogo->proximoJogador)) {
				jogadas[n].lin = i;
				jogadas[n].col = j;
				jogadas[n].prioridade = calcularPrioridade(jogo, i, j);
				n++;
			}
		}
	}

	selecionarMelhorJogada(jogadas, n, lin, col);
}

int calcularPrioridade(Jogo *jogo, int i, int j) {
	Jogador jogador = jogo->jogador1.peca == jogo->proximoJogador ? jogo->jogador1 : jogo->jogador2;

	return   calcularCaptura(jogo, jogador, i, j)
	       + calcularCapturado(jogo, jogador, i, j)
	       + calcularSequencia(jogo, jogador, i, j)
	       + calcularBloqueio(jogo, jogador, i, j);
}

int calcularCaptura(Jogo *jogo, Jogador jogador, int i, int j) {
	return   calcularCapDirecao(jogo, jogador, i, j,  0,  1)
	       + calcularCapDirecao(jogo, jogador, i, j,  0, -1)
	       + calcularCapDirecao(jogo, jogador, i, j,  1,  0)
	       + calcularCapDirecao(jogo, jogador, i, j, -1,  0)
	       + calcularCapDirecao(jogo, jogador, i, j,  1,  1)
	       + calcularCapDirecao(jogo, jogador, i, j, -1, -1)
	       + calcularCapDirecao(jogo, jogador, i, j, -1,  1)
	       + calcularCapDirecao(jogo, jogador, i, j,  1, -1);
}

int calcularCapDirecao(Jogo *jogo, Jogador jogador, int i, int j, int di, int dj) {
	int existe =    i + 3*di >= 0
                 && i + 3*di < jogo->goban.dimensao
                 && j + 3*dj >= 0
                 && j + 3*dj < jogo->goban.dimensao
                 && jogo->goban.matriz[i +   di][j +   dj] == 1-jogador.peca
                 && jogo->goban.matriz[i + 2*di][j + 2*dj] == 1-jogador.peca
                 && jogo->goban.matriz[i + 3*di][j + 3*dj] == jogador.peca;

    if (existe && jogador.capturas == 4) {
    	return 1000;
    }
    else if (existe) {
    	return   calcularBloqueio(jogo, jogador, i + di, j + dj)
    	       + calcularBloqueio(jogo, jogador, i + 2*di, j + 2*dj);
    }
    return 0;
}

int calcularCapturado(Jogo *jogo, Jogador jogador, int i, int j) {
	Jogador jog = jogo->jogador1.peca == jogo->proximoJogador ? jogo->jogador2 : jogo->jogador1;

	return calcularCaptura(jogo, jog, i, j) - 1;
}

int calcularSequencia(Jogo *jogo, Jogador jogador, int i, int j) {
	return   calcularSeqDirecao(jogo->goban, i, j, 0, 1, jogador.peca)
	       + calcularSeqDirecao(jogo->goban, i, j, 1, 0, jogador.peca)
	       + calcularSeqDirecao(jogo->goban, i, j, 1, 1, jogador.peca)
	       + calcularSeqDirecao(jogo->goban, i, j,-1, 1, jogador.peca);
}

int calcularBloqueio(Jogo *jogo, Jogador jogador, int i, int j) {
	return   1
	       + calcularSeqDirecao(jogo->goban, i, j, 0, 1, 1-jogador.peca)
	       + calcularSeqDirecao(jogo->goban, i, j, 1, 0, 1-jogador.peca)
	       + calcularSeqDirecao(jogo->goban, i, j, 1, 1, 1-jogador.peca)
	       + calcularSeqDirecao(jogo->goban, i, j,-1, 1, 1-jogador.peca);
}

int calcularSeqDirecao(Tabuleiro goban, int i, int j, int di, int dj, Peca peca) {
	Casa casa = {i, j};
	int n1 = 1;
	int n2 = 1;
	int n;

	while (verificarSeSeqContinua(goban, casa, di, dj, n1, peca)) {
		n1++;
	}

	while (verificarSeSeqContinua(goban, casa, -di, -dj, n2, peca)) {
		n2++;
	}

	n = n1 + n2 - 1;

	if (n > 4) {
		return 250;
	}
	else if (n == 4) {
		return 100;
	}
	else if (n == 3) {
		return 35;
	}
	else if (n == 2) {
		return 10;
	}
	return 0;
}

void selecionarMelhorJogada(Jogada jogadas[], int n, int *lin, int *col) {
	Jogada melhor = jogadas[0];

	for (int i = 0; i < n; i++) {
		if (jogadas[i].prioridade > melhor.prioridade) {
			melhor = jogadas[i];
		}
	}

	*lin = melhor.lin;
	*col = melhor.col;
}