#include "headers/Arquivo.h"
#include "headers/Regra1.h"
#include "headers/Regra2.h"
#include "headers/Regra3.h"
#include "headers/Util.h"
#include "headers/Jogo.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


/**
	A função novoJogo inicializa todas as variáveis do jogo
	Parâmetro: O jogo
**/
void novoJogo(Jogo jogo){
	jogo.id=0;
	limparBuffer();
	limparTela();
	inicializarJogadores(&jogo.jogador1, &jogo.jogador2);
	limparTela();
	inicializarTabuleiro(&jogo.goban);
	jogar(&jogo);
}

/**
	A função continuarJogo carrega um jogo salvo em um arquivo
	Parâmetro: o jogo
**/
void continuarJogo(Jogo jogo){
	if(existeArquivoJogo(&jogo)){
		inicializarMatriz(&jogo.goban);
		jogar(&jogo);
	}
}

/**
	A função jogar executa o jogo e as funções de fim de jogo
	Parâmetro: o jogo
**/
void jogar(Jogo *jogo){
	do{
		limparTela();
		sortearPecas(&jogo->jogador1, &jogo->jogador2);
		inicializarJogo(jogo);
		zerarCapturas(&jogo->jogador1, &jogo->jogador2);
		limparTabuleiro(jogo->goban);
		loopJogo(jogo);
	}while(continuarJogando());
	salvarJogo(jogo);
	liberarMatriz(jogo->goban.matriz, jogo->goban.dimensao);
}


/**
	A função inicializarJogo atribui valores iniciais a estrutura Jogo
	Parâmetro: O jogo
**/
void inicializarJogo(Jogo *jogo) {
	jogo->proximoJogador=P;
	jogo->ganhando = -1;
}

/**
	A função loopJogo é onde acontece a partida em si, todas as jogadas, 
	verificações e impressões na tela
	Parâmetro: O jogo
**/
void loopJogo(Jogo *jogo){
	Peca peca;
	int vitoriaPorCaptura;
	int lin,col;
	do{
		informarQntCapturas(jogo->jogador1, jogo->jogador2);
		imprimirTabuleiro(jogo->goban);
		informarProximoJogador(jogo);
		novaJogada(jogo, &lin, &col);
		limparTela();
		verificarCaptura(jogo, lin, col);
		alternarJogador(&jogo->proximoJogador);
	}while(!verificarFimDeJogo(jogo, &peca, &vitoriaPorCaptura));
	informarQntCapturas(jogo->jogador1, jogo->jogador2);
	imprimirTabuleiro(jogo->goban);
	imprimirGanhador(&jogo->jogador1, &jogo->jogador2, peca, vitoriaPorCaptura);
}

/**
	A função informarProximoJogador informa quem deve jogar no momento
	Parâmetro: O jogo
**/
void informarProximoJogador(Jogo *jogo){
	if(jogo->jogador1.peca == jogo->proximoJogador){
		printf("Vez de %s (%c)\n",jogo->jogador1.nome, caracterPeca(jogo->jogador1.peca));
	}else{
		printf("Vez de %s (%c)\n",jogo->jogador2.nome, caracterPeca(jogo->jogador2.peca));
	}
}

/**
	A função novaJogada recebe a posição e adiciona a peça
	no tabuleiro
	Parâmetros: O jogo, a linha e a coluna
**/
void novaJogada(Jogo *jogo, int *lin, int *col) {
	do{
		printf("Onde deseja inserir a peca (lin col)? ");
		scanf("%d",lin);
		scanf("%d",col);
	}while(!validarInsercao(jogo->goban, *lin, *col, jogo->proximoJogador));

	jogo->goban.matriz[*lin][*col] = jogo->proximoJogador;
}

/**
	A função alternarJogador faz a alternância dos jogadores
	Parâmetro: O proximoJogador
**/
void alternarJogador(Peca *proximoJogador){
	*proximoJogador=(1-*proximoJogador);
}

/**
	A função imprimirGanhador é responsável por imprimir o ganhador
	juntamente com o placar do jogo.
	Parâmetros: Os dois jogadores, peca(ganhadora) e vitoriaPorCaptura(0 ou 1)
**/
void imprimirGanhador(Jogador *jogador1, Jogador *jogador2, Peca peca, int vitoriaPorCaptura) {
	if (peca == jogador1->peca) {
		jogador1->vitorias+=1;
		printf("Vitoria %sde %s\n", (vitoriaPorCaptura ? "por captura " : ""), jogador1->nome);
	}
	else if (peca == jogador2->peca) {
		jogador2->vitorias+=1;
		printf("Vitoria %sde %s\n", (vitoriaPorCaptura ? "por captura " : ""), jogador2->nome);
	}
	else{
		printf("Empate\n");
	}
	imprimirPlacarVitorias(*jogador1, *jogador2);
}

/**
	A função imprimirPlacarVitorias imprime o placar de vitórias
	Parâmetros: Os dois jogadores
**/
void imprimirPlacarVitorias(Jogador jogador1, Jogador jogador2) {
		printf("Placar: ");
		printf("%s %d", jogador1.nome, jogador1.vitorias);
		printf(" x ");
		printf("%d %s\n", jogador2.vitorias, jogador2.nome);
}

/**
	A função continuarJogando é responsável por perguntar ao jogadores se eles desejam
	continuar jogando.
	Retorno: Será 0(caso não queira continuar o jogo) ou 1(se o jogo pode continuar)
**/
int continuarJogando(){
	char resposta[3];

	do{
		printf("Deseja continuar (sim | nao)? ");
		scanf("%s",resposta);
		strcpy(resposta,converterParaMinusculo(resposta));
	}while(strcmp("sim", resposta) != 0 && strcmp("nao", resposta) != 0);
	if(strcmp("sim", resposta) == 0){
		return 1;
	}
	return 0;
}