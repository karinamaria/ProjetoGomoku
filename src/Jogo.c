#include "Jogo.h"
#include <stdio.h>

void iniciarJogo(Jogo jogo){
	jogo.proximoJogador=P;
	inicializarJogador(&jogo.jogador1, &jogo.jogador2);
	jogo.goban = inicializarTabuleiro();
	imprimirTabuleiro(jogo.goban);
	inserirPecas(&jogo);
}

/**
	A função inserirPecas é responsável por receber informações para
	atualizar o tabuleiro
	Parâmetro: O jogo
**/
void inserirPecas(Jogo *jogo){
	int lin,col;
	for(int i=0; i<5; i++){
		analisarProximoJogador(jogo);
		do{
			printf("Onde deseja inserir a peca (lin col)? ");
			scanf("%d",&lin);
			scanf("%d",&col);
		}while(validarInsercao(jogo->goban, lin, col));
		imprimirTabuleiro(jogo->goban);
		
	}
}

/**
	A função analisarProximoJogador analisa quem deve jogar no momento e qual será
	o próximo jogador.
	Parâmetro: O jogo
**/
void analisarProximoJogador(Jogo *jogo){
	if(jogo->jogador1.peca == jogo->proximoJogador){
		printf("Vez de %s (%s)\n",jogo->jogador1.nome, (jogo->jogador1.peca == 0? "P":"B"));
		jogo->proximoJogador=(1-jogo->jogador1.peca);
	}else{
		printf("Vez de %s (%s)\n",jogo->jogador2.nome, (jogo->jogador2.peca == 0? "P":"B"));
		jogo->proximoJogador=(1-jogo->jogador2.peca);
	}
}

/**
	A função validarInsercao verifica se a posição que o jogador escolheu no tabuleiro já 
	está ocupada.
	Parâmetros: tabuleiro, linha e coluna(escolhidos pelo usuário)
**/
int validarInsercao(Tabuleiro tabuleiro, int lin, int col){
	return 0;
}