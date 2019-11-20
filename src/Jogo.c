#include "Arquivo.h"
#include "Regra1.h"
#include "Regra2.h"
#include "Regra3.h"
#include "Util.h"
#include "Jogo.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


/**
	A função iniciarJogo inicializa todas as variáveis do jogo
	Parâmetro: O jogo
**/
void iniciarJogo(Jogo jogo){
	jogo.id=0;
	limparBuffer();
	limparTela();
	inicializarJogadores(&jogo.jogador1, &jogo.jogador2);
	limparTela();
	inicializarTabuleiro(&jogo.goban);
	jogar(&jogo);
	
}

/**
	A função reiniciarJogo carrega um jogo salvo em um arquivo
	Parâmetro: o jogo
**/
void reiniciarJogo(Jogo jogo){
	if(existeArquivoJogo(&jogo)){
		jogo.goban.matriz=inicializarMatriz(jogo.goban.dimensao);
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
		limparMatriz(jogo->goban.matriz, jogo->goban.dimensao);
		loopJogo(jogo);
	}while(continuarJogo());
	salvarJogo(jogo);
	liberarMatriz(jogo->goban.matriz, jogo->goban.dimensao);
}


/**
	A função inicializarJogo atribui valores iniciais a estrutura Jogo
	Parâmetros: O jogo
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
		do{
			printf("Onde deseja inserir a peca (lin col)? ");
			scanf("%d",&lin);
			scanf("%d",&col);
		}while(!validarInsercao(jogo->goban, lin, col, jogo->proximoJogador));
		limparTela();
		jogo->goban.matriz[lin][col] = jogo->proximoJogador;
		verificarCaptura(jogo, lin, col);
		alternarJogador(&jogo->proximoJogador);
		peca = -1;
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
	A função alternarJogador faz a alternância dos jogadores
	Parâmetro: O proximoJogador
**/
void alternarJogador(Peca *proximoJogador){
	*proximoJogador=(1-*proximoJogador);
}

/**
	A função continuarJogo é responsável por perguntar ao jogadores se eles desejam
	continuar o jogo.
	Retorno: Será 0(caso não queira continuar o jogo) ou 1(se o jogo pode continuar)
**/
int continuarJogo(){
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
	printf("Placar: %s %d x %d %s \n",jogador1->nome,jogador1->vitorias,jogador2->vitorias, jogador2->nome);
}