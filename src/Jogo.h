#ifndef JOGO_H
#define JOGO_H

#include "Jogador.h"
#include "Tabuleiro.h"

typedef struct{
	Jogador jogador1;
	Jogador jogador2;
	Tabuleiro goban;
	Peca proximoJogador;
}Jogo;

void iniciarJogo(Jogo jogo);
void loopJogo(Jogo *jogo);
void informarProximoJogador(Jogo *jogo);
void alternarJogador(Peca *proximoJogador);
int validarInsercao(Tabuleiro tabuleiro, int lin, int col, Peca peca);
int existeSeqMaiorQ3(Tabuleiro goban, Casa c, Peca peca);
int contarSeq(Tabuleiro goban, Casa c, int di, int dj, Peca peca);
int verificarPeca(Tabuleiro goban, Casa casa, int di, int dj, Peca peca, int n);
int validarPrimeiraSeq(Tabuleiro goban, Casa c0, Casa *c1, Casa *c2, int di, int dj, Peca peca);
int verificarFormacao3x3(Tabuleiro goban, int i, int j, Peca peca);
int analisarSegundaSeq(Tabuleiro goban, int direcao_lin, int direcao_col, Casa c1, Casa c2, Peca peca);
int verificarSegundaSeq(Tabuleiro goban, int di, int dj, Casa c, Peca peca);
int validarSegundaSeq(Tabuleiro goban, Casa c0, int di, int dj, Peca peca);
int continuarJogo();
void salvarJogo(Jogo jogo);
void salvarInformacoesJogo(Jogo jogo);
void nomeArquivoJogo(char *nomeArquivo);
void analisarCaptura(Jogo *jogo, int i, int j);
int verificarCaptura(Jogo *jogo, int i, int j);
int capturouPecas(Jogo *jogo, int i, int j, int di, int dj);
int validarCaptura(Jogo *jogo, int i, int j, int di, int dj);
void imprimirGanhador(Jogador *jogador1, Jogador *jogador2, Peca peca, int vitoriaPorCaptura);

#endif