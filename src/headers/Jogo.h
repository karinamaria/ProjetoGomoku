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
	int turno;
	int ganhando;
	int modo_de_jogo;
	int idioma;
}Jogo;

void novoJogo(Jogo *jogo);
void modoDeJogo(Jogo *jogo);
void jogadorVSjogador(Jogo *jogo);
void jogadorVScomputador(Jogo *jogo);
void computadorVScomputador(Jogo *jogo);
void pedirDimensao(Jogo *jogo);
void continuarJogo(Jogo *jogo);
void configurarJogo(Jogo *jogo);
void jogar(Jogo *jogo);
void inicializarJogo(Jogo *jogo);
void loopJogo(Jogo *jogo);
void informarProximoJogador(Jogo *jogo);
void novaJogada(Jogo *jogo, int *lin, int *col);
void alternarJogador(Peca *proximoJogador);
void ganhador(Jogador *jogador1, Jogador *jogador2, Peca peca, int vitoriaPorCaptura, int idioma);
int continuarJogando(int idioma);

#endif