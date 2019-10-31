#ifndef JOGO_H
#define JOGO_H

#ifdef __WIN32__
#define LIMPAR_TELA "cls"
#else
#define LIMPAR_TELA "clear"
#endif

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
void analisarProximoJogador(Jogo *jogo);
int validarInsercao(Tabuleiro tabuleiro, int lin, int col);
int continuarJogo();
char* converterParaMinusculo(char *resposta);
int verificarFimDeJogo(Jogo *jogo, Peca *peca);
int verificarLinhas(Jogo *jogo, Peca *peca);
int verificarColunas(Jogo *jogo, Peca *peca);
int verificarDiagPrincipalBaixo(Jogo *jogo, Peca *peca);
int verificarDiagPrincipalCima(Jogo *jogo, Peca *peca);
int verificarDiagSecundariaCima(Jogo *jogo, Peca *peca);
int verificarDiagSecundariaBaixo(Jogo *jogo, Peca *peca);
int verificarEmpate(Jogo *jogo, Peca *peca);
void imprimirGanhador(Jogador *jogador1, Jogador *jogador2, Peca peca);
void limparTela();

#endif