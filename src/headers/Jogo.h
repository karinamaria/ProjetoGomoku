#ifndef JOGO_H
#define JOGO_H

#include "Jogador.h"
#include "Tabuleiro.h"

typedef struct{
	int id;
	Jogador jogador1;
	Jogador jogador2;
	Tabuleiro goban;
	Peca proximoJogador;
	int ganhando;
	int idioma;
}Jogo;

void novoJogo(Jogo jogo);
void continuarJogo(Jogo jogo);
void configurarJogo(Jogo *jogo);
void jogar(Jogo *jogo);
void inicializarJogo(Jogo *jogo);
void loopJogo(Jogo *jogo);
void informarProximoJogador(Jogo *jogo);
void novaJogada(Jogo *jogo, int *lin, int *col);
void alternarJogador(Peca *proximoJogador);
void imprimirGanhador(Jogador *jogador1, Jogador *jogador2, Peca peca, int vitoriaPorCaptura, int idioma);
void imprimirPlacarVitorias(Jogador jogador1, Jogador jogador2, int idioma);
int continuarJogando(int idioma);

#endif