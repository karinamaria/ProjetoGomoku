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
		}while(!validarInsercao(jogo->goban, lin, col));
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
	A função validarInsercao verifica se a posição que o jogador escolheu no tabuleiro exite e não está ocupada.
	Parâmetros: tabuleiro, linha e coluna(escolhidos pelo usuário)
**/
int validarInsercao(Tabuleiro tabuleiro, int lin, int col){
	if (lin < 0 || lin >= tabuleiro.dimensao || col < 0 || col >= tabuleiro.dimensao)
		return 0;

	if (tabuleiro.matriz[lin][col] != -1)
		return 0;

	return 1;
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
	return    verificarLinhas(jogo, peca)
		   || verificarColunas(jogo, peca)
		   || verificarDiagPrincipalBaixo(jogo, peca)
		   || verificarDiagPrincipalCima(jogo, peca)
		   || verificarDiagSecundariaCima(jogo, peca)
		   || verificarDiagSecundariaBaixo(jogo, peca)
		   || verificarEmpate(jogo, peca);
}

int verificarLinhas(Jogo *jogo, Peca *peca) {
	int cont = 1;

	for (int i = 0; i < jogo->goban.dimensao; i++) {
		for (int j = 1; j < jogo->goban.dimensao; j++) {
			if (jogo->goban.matriz[i][j] != -1 && jogo->goban.matriz[i][j] == jogo->goban.matriz[i][j-1]) {
				cont++;
			}else {
				cont = 1;
			}

			if (cont == 5) {
				*peca = jogo->goban.matriz[i][j];
				return 1;
			}
		}
		cont = 1;
	}

	return 0;
}

int verificarColunas(Jogo *jogo, Peca *peca) {
	int cont = 1;

	for (int j = 0; j < jogo->goban.dimensao; j++) {
		for (int i = 1; i < jogo->goban.dimensao; i++) {
			if (jogo->goban.matriz[i][j] != -1 && jogo->goban.matriz[i][j] == jogo->goban.matriz[i-1][j]) {
				cont++;
			}else {
				cont = 1;
			}

			if (cont == 5) {
				*peca = jogo->goban.matriz[i][j];
				return 1;
			}
		}
		cont = 1;
	}

	return 0;
}

// Verificar diagonal principal para baixo
int verificarDiagPrincipalBaixo(Jogo *jogo, Peca *peca) {
	int cont = 1;

	for(int lin=0; lin < jogo->goban.dimensao; lin++){
		for(int i=lin+1, j=1; i < jogo->goban.dimensao; i++, j++){
			if (jogo->goban.matriz[i][j] != -1 && jogo->goban.matriz[i][j] == jogo->goban.matriz[i-1][j-1]) {
				cont++;
			}else{
				cont = 1;
			}

			if (cont == 5) {
				*peca = jogo->goban.matriz[i][j];
				return 1;
			}
		}
		cont = 1;
	}

	return 0;
}

// Verificar diagonal principal para cima
int verificarDiagPrincipalCima(Jogo *jogo, Peca *peca) {
	int cont = 1;

	for(int col=1; col < jogo->goban.dimensao; col++){
		for(int j=col+1, i=1; j < jogo->goban.dimensao; j++, i++){
			if (jogo->goban.matriz[i][j] != -1 && jogo->goban.matriz[i][j] == jogo->goban.matriz[i-1][j-1]) {
				cont++;
			}else{
				cont = 1;
			}

			if (cont == 5) {
				*peca = jogo->goban.matriz[i][j];
				return 1;
			}
		}
		cont = 1;
	}

	return 0;
}

// Verificar diagonal secundária para cima
int verificarDiagSecundariaCima(Jogo *jogo, Peca *peca) {
	int cont = 1;

	for(int lin=jogo->goban.dimensao-1; lin>=0; lin--){
		for(int i=lin-1, j=1; i>=0; i--, j++){
			if (jogo->goban.matriz[i][j] != -1 && jogo->goban.matriz[i][j] == jogo->goban.matriz[i+1][j-1]) {
				cont++;
			}else{
				cont = 1;
			}

			if (cont == 5) {
				*peca = jogo->goban.matriz[i][j];
				return 1;
			}
		}
		cont = 1;
	}

	return 0;
}

// Verificar diagonal secundária para baixo
int verificarDiagSecundariaBaixo(Jogo *jogo, Peca *peca) {
	int cont = 1;

	for(int col=1; col < jogo->goban.dimensao; col++){
		for(int j=col+1, i=jogo->goban.dimensao-2; j < jogo->goban.dimensao; j++, i--){
			if (jogo->goban.matriz[i][j] != -1 && jogo->goban.matriz[i][j] == jogo->goban.matriz[i+1][j-1]) {
				cont++;
			}else{
				cont = 1;
			}

			if (cont == 5) {
				*peca = jogo->goban.matriz[i][j];
				return 1;
			}
		}
		cont = 1;
	}

	return 0;
}

int verificarEmpate(Jogo *jogo, Peca *peca) {
	for (int i = 0; i < jogo->goban.dimensao; i++) {
		for (int j = 0; j < jogo->goban.dimensao; j++) {
			if (jogo->goban.matriz[i][j] == -1){
				return 0;
			}
		}
	}

	*peca = -1;
	return 1;
}

void imprimirGanhador(Jogador jogador1, Jogador jogador2, Peca peca) {
	if (peca == jogador1.peca) {
		printf("Vitoria de %s\n", jogador1.nome);
	}
	else if (peca == jogador2.peca) {
		printf("Vitoria de %s\n", jogador2.nome);
	}
	else{
		printf("Empate\n");
	}
}