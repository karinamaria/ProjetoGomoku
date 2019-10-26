#include "Jogo.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>

void iniciarJogo(Jogo jogo){
	inicializarJogadores(&jogo.jogador1, &jogo.jogador2);
	inicializarTabuleiro(&jogo.goban);
	do{
		sortearPecas(&jogo.jogador1, &jogo.jogador2);
		jogo.proximoJogador=P;
		limparMatriz(jogo.goban.matriz, jogo.goban.dimensao);
		imprimirTabuleiro(jogo.goban);
		loopJogo(&jogo);
	}while(continuarJogo());
	liberarMatriz(jogo.goban.matriz, jogo.goban.dimensao);
}

/**
	A função loopJogo é responsável por receber informações para
	atualizar o tabuleiro
	Parâmetro: O jogo
**/
void loopJogo(Jogo *jogo){
	Peca peca = P;
	int lin,col;
	do{
		analisarProximoJogador(jogo);
		do{
			printf("Onde deseja inserir a peca (lin col)? ");
			scanf("%d",&lin);
			scanf("%d",&col);
		}while(validarInsercao(jogo->goban, lin, col));
		jogo->goban.matriz[lin][col] = 1-jogo->proximoJogador;
		imprimirTabuleiro(jogo->goban);
		
	}while(!verificarFimDeJogo(jogo, &peca));
	imprimirGanhador(jogo->jogador1, jogo->jogador2, peca);
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
	if (lin < 0 || lin >= tabuleiro.dimensao || col < 0 || col >= tabuleiro.dimensao)
		return 1;

	if (tabuleiro.matriz[lin][col] != -1)
		return 1;

	return 0;
}
/**
	A função continuarJogo é responsável por perguntar ao jogadores se eles desejam
	continuar o jogo.
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
	A função converterParaMinusculo será útil caso os jogadores digitem 
	'SIM' ou 'NAO' em letras maíusculas
	Parâmetro: A resposta digitada pelos jogadores
**/
char* converterParaMinusculo (char *resposta){
	for(int i=0; i<strlen(resposta); i++){
		resposta[i]=tolower(resposta[i]);
	}
	return resposta;
}

int verificarFimDeJogo(Jogo *jogo, Peca *peca) {
	return verificarLinhas(jogo, peca) || verificarColunas(jogo, peca);
}

int verificarLinhas(Jogo *jogo, Peca *peca) {
	int fim = 0;
	int cont = 1;

	for (int i = 0; i < jogo->goban.dimensao && !fim; i++) {
		for (int j = 1; j < jogo->goban.dimensao && !fim; j++) {
			if (jogo->goban.matriz[i][j] != -1 && jogo->goban.matriz[i][j] == jogo->goban.matriz[i][j-1]) {
				cont++;
			}else {
				cont = 1;
			}

			if (cont == 2) { // Troca de volta pra 5
				fim = 1;
				*peca = jogo->goban.matriz[i][j];
			}
		}
	}

	return fim;
}

int verificarColunas(Jogo *jogo, Peca *peca) {
	int fim = 0;
	int cont = 1;

	for (int j = 0; j < jogo->goban.dimensao && !fim; j++) {
		for (int i = 1; i < jogo->goban.dimensao && !fim; i++) {
			if (jogo->goban.matriz[i][j] != -1 && jogo->goban.matriz[i][j] == jogo->goban.matriz[i-1][j]) {
				cont++;
			}else {
				cont = 1;
			}

			if (cont == 2) { // Troca de volta pra 5
				fim = 1;
				*peca = jogo->goban.matriz[i][j];
			}
		}
	}

	return fim;
}

void imprimirGanhador(Jogador jogador1, Jogador jogador2, Peca peca) {
	if (peca == jogador1.peca) {
		printf("%s ganhou!\n", jogador1.nome);
	}
	else {
		printf("%s ganhou!\n", jogador2.nome);
	}
}