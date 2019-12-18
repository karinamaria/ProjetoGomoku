#include "headers/Jogo.h"
#include "headers/Util.h"
#include "headers/Tela.h"
#include "headers/Arquivo.h"
#include "headers/Regra1.h"
#include "headers/Regra3.h"
#include "headers/IA.h"
#include "headers/Regra2.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


/**
	A função novoJogo inicializa todas as variáveis do jogo
	Parâmetro: O jogo
**/
void novoJogo(Jogo *jogo){
	jogo->id=0;
	modoDeJogo(jogo);
}

/**
	A função modoDeJogo imprime o menu modo de jogo e
	pede e inicia um dos modos
	Parâmetro: O jogo
**/
void modoDeJogo(Jogo *jogo) {
	do{
		imprimirMenuNovoJogo(jogo->idioma);
		scanf("%d", &jogo->modo_de_jogo);
		limparBuffer();

		switch (jogo->modo_de_jogo) {
			case 1:
				jogadorVSjogador(jogo);
				break;
			case 2:
				jogadorVScomputador(jogo);
				break;
			case 3:
				computadorVScomputador(jogo);
				break;
		}
	}while(jogo->modo_de_jogo != 0 && jogo->turno == 0);
}

/**
	A função jogadorVSjogador pede o nome dos dois jogadores
	Parâmetro: O jogo
**/
void jogadorVSjogador(Jogo *jogo) {
	do{
		imprimirMenuNomeJog1(jogo->idioma);
		fgets(jogo->jogador1.nome, 18, stdin);
		jogo->jogador1.nome[strlen(jogo->jogador1.nome)-1]='\0';

		if (strcmp(jogo->jogador1.nome, "0") != 0 && strcmp(jogo->jogador1.nome, "") != 0) {
			do{
				imprimirMenuNomeJog2(jogo->idioma);
				fgets(jogo->jogador2.nome, 18, stdin);
				jogo->jogador2.nome[strlen(jogo->jogador2.nome)-1]='\0';

				if (strcmp(jogo->jogador2.nome, "0") != 0 && strcmp(jogo->jogador2.nome, "") != 0) {
					pedirDimensao(jogo);
				}
				
			}while((strcmp(jogo->jogador2.nome, "0") != 0 || strcmp(jogo->jogador2.nome, "") == 0) && jogo->turno == 0);
		}
		
	}while((strcmp(jogo->jogador1.nome, "0") != 0 || strcmp(jogo->jogador1.nome, "") == 0) && jogo->turno == 0);
}

/**
	A função jogadorVScomputador pede o nível do computador e
	o nome do jogador.
	Parâmetro: O jogo
**/
void jogadorVScomputador(Jogo *jogo) {
	do{
		imprimirMenuDificuldade(jogo->idioma);
		scanf("%d", &jogo->jogador2.nivel);
		limparBuffer();

		if (jogo->jogador2.nivel > 0 && jogo->jogador2.nivel < 4) {
			do{
				imprimirMenuSeuNome(jogo->idioma);
				fgets(jogo->jogador1.nome, 18, stdin);
				jogo->jogador1.nome[strlen(jogo->jogador1.nome)-1]='\0';

				if (strcmp(jogo->jogador1.nome, "0") != 0 && strcmp(jogo->jogador1.nome, "") != 0) {
					pedirDimensao(jogo);
				}
				
			}while((strcmp(jogo->jogador1.nome, "0") != 0 || strcmp(jogo->jogador1.nome, "") == 0) && jogo->turno == 0);
		}
		
	}while(jogo->jogador2.nivel != 0 && jogo->turno == 0);
}

/**
	A função computadorVScomputador pede o nível dos dois computadores
	Parâmetro: O jogo
**/
void computadorVScomputador(Jogo *jogo) {
	do{
		imprimirMenuNivelCOM1(jogo->idioma);
		scanf("%d", &jogo->jogador1.nivel);
		limparBuffer();

		if (jogo->jogador1.nivel > 0 && jogo->jogador1.nivel < 4) {
			do{
				imprimirMenuNivelCOM2(jogo->idioma);
				scanf("%d", &jogo->jogador2.nivel);
				limparBuffer();

				if (jogo->jogador2.nivel > 0 && jogo->jogador2.nivel < 4) {
					pedirDimensao(jogo);
				}
				
			}while(jogo->jogador2.nivel != 0 && jogo->turno == 0);
		}
		
	}while(jogo->jogador1.nivel != 0 && jogo->turno == 0);
}

/**
	A função pedirDimensao pede o tamanho do goban
	Parâmetro: O jogo
**/
void pedirDimensao(Jogo *jogo) {
	do{
		imprimirMenuDimensao(jogo->idioma);
		scanf("%d", &jogo->goban.dimensao);
		limparBuffer();

		if (jogo->goban.dimensao > 4 && jogo->goban.dimensao < 20) {
			inicializarJogadores(&jogo->jogador1, &jogo->jogador2, jogo->modo_de_jogo);
			inicializarTabuleiro(&jogo->goban);
			jogar(jogo);
		}
		
	}while(jogo->goban.dimensao != 0 && (jogo->goban.dimensao < 5 || jogo->goban.dimensao > 19) && jogo->turno == 0);
}

/**
	A função continuarJogo carrega um jogo salvo em um arquivo
	Parâmetro: o jogo
**/
void continuarJogo(Jogo *jogo){
	if(existeArquivoJogo(jogo)){
		inicializarTabuleiro(&jogo->goban);
		jogar(jogo);
	}
}

/**
	A função configurarJogo permite alterar o idioma do jogo 
	Parâmetro: o jogo
**/
void configurarJogo(Jogo *jogo){
	int opcao;
	do{
		imprimirMenuIdioma(jogo);
		scanf("%d",&opcao);
	}while(opcao < 0 || opcao > 3);
	if(opcao > 0){
		jogo->idioma=opcao;
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
		zerarCapturas(&jogo->jogador1, &jogo->jogador2);
		limparTabuleiro(jogo->goban);
		inicializarJogo(jogo);
		loopJogo(jogo);
	}while(continuarJogando(jogo->idioma));
	salvarJogo(jogo);
	liberarMatriz(jogo->goban.matriz, jogo->goban.dimensao);
	jogo->turno = -1;
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
		imprimirPlacarCapturas(jogo->jogador1, jogo->jogador2, jogo->idioma);
		imprimirTabuleiro(jogo->goban, jogo->proximoJogador);
		informarProximoJogador(jogo);
		novaJogada(jogo, &lin, &col);
		verificarCaptura(jogo, lin, col);
		alternarJogador(&jogo->proximoJogador);
		limparTela();
	}while(!verificarFimDeJogo(jogo, &peca, &vitoriaPorCaptura));
	imprimirPlacarCapturas(jogo->jogador1, jogo->jogador2, jogo->idioma);
	imprimirTabuleiro(jogo->goban, jogo->proximoJogador);
	ganhador(&jogo->jogador1, &jogo->jogador2, peca, vitoriaPorCaptura, jogo->idioma);
}

/**
	A função informarProximoJogador informa quem deve jogar no momento
	Parâmetro: O jogo
**/
void informarProximoJogador(Jogo *jogo){
	if(jogo->jogador1.peca == jogo->proximoJogador){
		printf("%s %s (%c)\n",
			   msg(VEZ, jogo->idioma),
			   jogo->jogador1.nome,
			   caracterePeca(jogo->goban, 0, 0, jogo->jogador1.peca, jogo->proximoJogador));
	}else{
		printf("%s %s (%c)\n",
			   msg(VEZ, jogo->idioma),
			   jogo->jogador2.nome,
			   caracterePeca(jogo->goban, 0, 0, jogo->jogador2.peca, jogo->proximoJogador));
	}
}

/**
	A função novaJogada recebe a posição e adiciona a peça
	no tabuleiro
	Parâmetros: O jogo, a linha e a coluna
**/
void novaJogada(Jogo *jogo, int *lin, int *col) {
	do{
		printf("%s (lin col)? ", perguntas(NOVAJ, jogo->idioma));
		if (jogo->modo_de_jogo == 3 || (jogo->modo_de_jogo == 2 && jogo->proximoJogador == jogo->jogador2.peca)) {
			pedirJogadaIA(jogo, lin, col);
			printf("%d %d", *lin, *col);
			getchar();
		}
		else {
			scanf("%d",lin);
			scanf("%d",col);
			limparBuffer();
		}
	}while(!validarInsercao(jogo->goban, *lin, *col, jogo->proximoJogador, jogo->idioma));
	jogo->goban.matriz[*lin][*col] = jogo->proximoJogador;
	jogo->turno++;
}

/**
	A função alternarJogador faz a alternância dos jogadores
	Parâmetro: O proximoJogador
**/
void alternarJogador(Peca *proximoJogador){
	*proximoJogador=(1-*proximoJogador);
}

/**
	A função ganhador é responsável por imprimir o ganhador
	juntamente com o placar do jogo.
	Parâmetros: Os dois jogadores, peca(ganhadora), vitoriaPorCaptura(0 ou 1) e o idioma
**/
void ganhador(Jogador *jogador1, Jogador *jogador2, Peca peca, int vitoriaPorCaptura, int idioma) {
	if (peca == jogador1->peca) {
		jogador1->vitorias+=1;
		imprimirGanhador(jogador1->nome, vitoriaPorCaptura, idioma);
	}
	else if (peca == jogador2->peca) {
		jogador2->vitorias+=1;
		imprimirGanhador(jogador2->nome, vitoriaPorCaptura, idioma);
	}
	else{
		imprimirEmpate(idioma);
	}
	imprimirPlacarVitorias(*jogador1, *jogador2, idioma);
}

/**
	A função continuarJogando é responsável por perguntar ao jogadores se eles desejam
	continuar jogando.
	Parâmetro: o idioma
	Retorno: Será 0(caso não queira continuar o jogo) ou 1(se o jogo pode continuar)
**/
int continuarJogando(int idioma){
	char resposta[3];

	do{
		imprimirContinuarJogando(idioma);
		scanf("%s",resposta);
		limparBuffer();
		strcpy(resposta,converterParaMinusculo(resposta));
	}while(verificarResposta(resposta, idioma));
	if(strcmp("sim", resposta) == 0 || strcmp("yes", resposta) == 0
		|| strcmp("si", resposta) == 0){
		return 1;
	}
	return 0;
}