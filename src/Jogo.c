#include "Jogo.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

void iniciarJogo(Jogo jogo){
	inicializarJogadores(&jogo.jogador1, &jogo.jogador2);
	limparTela();
	inicializarTabuleiro(&jogo.goban);
	do{
		limparTela();
		sortearPecas(&jogo.jogador1, &jogo.jogador2);
		jogo.proximoJogador=P;
		limparMatriz(jogo.goban.matriz, jogo.goban.dimensao);
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
		imprimirTabuleiro(jogo->goban);
		analisarProximoJogador(jogo);
		do{
			printf("Onde deseja inserir a peca (lin col)? ");
			scanf("%d",&lin);
			scanf("%d",&col);
		}while(!validarInsercao(jogo->goban, lin, col));
		limparTela();
		jogo->goban.matriz[lin][col] = 1-jogo->proximoJogador;
		testarCaptura(jogo, lin, col);
		
	}while(!verificarFimDeJogo(jogo, &peca));
	imprimirGanhador(&jogo->jogador1, &jogo->jogador2, peca);
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
	Retorno: Será 0(se a posição for inválida/ocupada) ou 1(se não tiver nenhum impedimento)
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
	A função converterParaMinusculo será útil caso os jogadores digitem 
	'SIM' ou 'NAO' em letras maíusculas
	Parâmetro: A resposta digitada pelos jogadores
	Retorno: A resposta em letras minúsculas
**/
char* converterParaMinusculo (char *resposta){
	for(int i=0; i<strlen(resposta); i++){
		resposta[i]=tolower(resposta[i]);
	}
	return resposta;
}

/**
	A função verificarFimDeJogo analisa linhas, colunas e diagonais procurando
	um ganhador.
	Parâmetros: O jogo e uma peca(que armazenará a peça ganhadora).
	Retorno: Será 0(Se o jogo não tiver finalizado) e 1(se o jogo acabou).
**/
int verificarFimDeJogo(Jogo *jogo, Peca *peca) {
	return    verificarLinhas(jogo, peca)
		   || verificarColunas(jogo, peca)
		   || verificarDiagPrincipalBaixo(jogo, peca)
		   || verificarDiagPrincipalCima(jogo, peca)
		   || verificarDiagSecundariaCima(jogo, peca)
		   || verificarDiagSecundariaBaixo(jogo, peca)
		   || verificarEmpate(jogo, peca);
}

/**
	A função verificarLinhas verifica as linhas em busca de um ganhador
	Parâmetro: O jogo e uma peca(armazenará peça ganhadora, caso o jogo tenha um ganhador)
	Retorno: 0(se não houver ganhador pelas linhas) ou 1(caso haja ganhador por uma linha)
**/ 
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

/**
	A função verificarColunas verifica as colunas em busca de um ganhador
	Parâmetro: O jogo e uma peca(que armazenará peça ganhadora, caso o jogo tenha um ganhador)
	Retorno: 0(se não houver ganhador pelas colunas) ou 1(caso haja ganhador por uma coluna)
**/ 
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

void testarCaptura(Jogo *jogo, int i, int j) {
	if (
		   capturou(jogo, i, j,  0, 1) || capturou(jogo, i, j,  0, -1)
		|| capturou(jogo, i, j,  1, 0) || capturou(jogo, i, j, -1,  0)
		|| capturou(jogo, i, j,  1, 1) || capturou(jogo, i, j, -1, -1)
		|| capturou(jogo, i, j, -1, 1) || capturou(jogo, i, j,  1, -1)
	   ) {
		if (jogo->jogador1.peca == jogo->goban.matriz[i][j]) {
			jogo->jogador1.capturas++;
		}
		else {
			jogo->jogador2.capturas++;
		}
	}
}

int capturou(Jogo *jogo, int i, int j, int di, int dj) {
	if (    
	       i + 3*di >= 0
        && i + 3*di < jogo->goban.dimensao
        && j + 3*dj >= 0
        && j + 3*dj < jogo->goban.dimensao
        && jogo->goban.matriz[    i   ][    j   ] == 1-jogo->proximoJogador
        && jogo->goban.matriz[i +   di][j +   dj] == jogo->proximoJogador
        && jogo->goban.matriz[i + 2*di][j + 2*dj] == jogo->proximoJogador
        && jogo->goban.matriz[i + 3*di][j + 3*dj] == 1-jogo->proximoJogador
	   ) {
		jogo->goban.matriz[i +   di][j +   dj] = -1;
		jogo->goban.matriz[i + 2*di][j + 2*dj] = -1;

		return 1;
	}

	return 0;
}

/**
	A função imprimirGanhador é responsável por imprimir o ganhador
	juntamente com o placar do jogo.
	Parâmetros: Jogador 1, Jogador 2 e a Peca(Ganhadora do jogo)

**/
void imprimirGanhador(Jogador *jogador1, Jogador *jogador2, Peca peca) {
	if (peca == jogador1->peca) {
		jogador1->vitorias+=1;
		printf("Vitoria de %s\n", jogador1->nome);
	}
	else if (peca == jogador2->peca) {
		jogador2->vitorias+=1;
		printf("Vitoria de %s\n", jogador2->nome);
	}
	else{
		printf("Empate\n");
	}
	printf("Placar: %s %d x %d %s \n",jogador1->nome,jogador1->vitorias,jogador2->vitorias, jogador2->nome);
}

void limparTela() {
	system(LIMPAR_TELA);
}