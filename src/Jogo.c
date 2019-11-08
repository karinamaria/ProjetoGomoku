#include "Validacoes.h"
#include "Util.h"
#include "Jogo.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void iniciarJogo(Jogo jogo){
	inicializarJogadores(&jogo.jogador1, &jogo.jogador2);
	limparTela();
	inicializarTabuleiro(&jogo.goban);
	do{
		limparTela();
		sortearPecas(&jogo.jogador1, &jogo.jogador2);
		jogo.proximoJogador=P;
		zerarCapturas(&jogo.jogador1, &jogo.jogador2);
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
		analisarCaptura(jogo, lin, col);
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
	A função alternarJogador faz a alternância dos jogadores
	Parâmetro: O proximoJogador
**/
void alternarJogador(Peca *proximoJogador){
	*proximoJogador=(1-*proximoJogador);
}

/**
	A função validarInsercao verifica se a posição que o jogador escolheu no tabuleiro exite e não está ocupada.
	Parâmetros: tabuleiro, linha e coluna(escolhidos pelo usuário)
	Retorno: Será 0(se a posição for inválida/ocupada) ou 1(se não tiver nenhum impedimento)
**/
int validarInsercao(Tabuleiro tabuleiro, int lin, int col, Peca peca){
	if (lin < 0 || lin >= tabuleiro.dimensao || col < 0 || col >= tabuleiro.dimensao){
		printf("----Jogada invalida. Esta posicao esta fora do goban.----\n");
		return 0;
	}

	if (tabuleiro.matriz[lin][col] != -1){
		printf("----Jogada invalida. Ja existe uma peca nesta posicao.----\n");
		return 0;
	}

	if (!verificarFormacao3x3(tabuleiro, lin, col, peca)){
		printf("----Jogada invalida. Nao eh permitido fazer a formacao 3x3.----\n");
		return 0;
	}

	return 1;
}

int verificarFormacao3x3(Tabuleiro goban, int i, int j, Peca peca) {
	int di1, dj1, di2, dj2, di3, dj3, ip1, jp1, ip2, jp2, ip3, jp3;

	if (
		(  contarSequencia(goban, i, j,  0, 1, &di1, &dj1, &ip1, &jp1, peca) + contarSequencia(goban, i, j,  0, -1, &di2, &dj2, &ip2, &jp2, peca) == 4
        || contarSequencia(goban, i, j,  1, 0, &di1, &dj1, &ip1, &jp1, peca) + contarSequencia(goban, i, j, -1,  0, &di2, &dj2, &ip2, &jp2, peca) == 4
		|| contarSequencia(goban, i, j,  1, 1, &di1, &dj1, &ip1, &jp1, peca) + contarSequencia(goban, i, j, -1, -1, &di2, &dj2, &ip2, &jp2, peca) == 4
		|| contarSequencia(goban, i, j, -1, 1, &di1, &dj1, &ip1, &jp1, peca) + contarSequencia(goban, i, j,  1, -1, &di2, &dj2, &ip2, &jp2, peca) == 4)
		&&
		(  (contarSequencia(goban, ip1, jp1,  0, 1, &di3, &dj3, &ip3, &jp3, peca) == 3 && !(di3 == di1 && dj3 == dj1) && !(di3 == di2 && dj3 == dj2))
		|| (contarSequencia(goban, ip1, jp1,  0, -1, &di3, &dj3, &ip3, &jp3, peca) == 3 && !(di3 == di1 && dj3 == dj1) && !(di3 == di2 && dj3 == dj2))
        || (contarSequencia(goban, ip1, jp1,  1, 0, &di3, &dj3, &ip3, &jp3, peca) == 3 && !(di3 == di1 && dj3 == dj1) && !(di3 == di2 && dj3 == dj2))
        || (contarSequencia(goban, ip1, jp1, -1,  0, &di3, &dj3, &ip3, &jp3, peca) == 3 && !(di3 == di1 && dj3 == dj1) && !(di3 == di2 && dj3 == dj2))
		|| (contarSequencia(goban, ip1, jp1,  1, 1, &di3, &dj3, &ip3, &jp3, peca) == 3 && !(di3 == di1 && dj3 == dj1) && !(di3 == di2 && dj3 == dj2))
		|| (contarSequencia(goban, ip1, jp1, -1, -1, &di3, &dj3, &ip3, &jp3, peca) == 3 && !(di3 == di1 && dj3 == dj1) && !(di3 == di2 && dj3 == dj2))
		|| (contarSequencia(goban, ip1, jp1, -1, 1, &di3, &dj3, &ip3, &jp3, peca) == 3 && !(di3 == di1 && dj3 == dj1) && !(di3 == di2 && dj3 == dj2))
		|| (contarSequencia(goban, ip1, jp1,  1, -1, &di3, &dj3, &ip3, &jp3, peca) == 3 && !(di3 == di1 && dj3 == dj1) && !(di3 == di2 && dj3 == dj2))
		|| (contarSequencia(goban, ip2, jp2,  0, 1, &di3, &dj3, &ip3, &jp3, peca) == 3 && !(di3 == di1 && dj3 == dj1) && !(di3 == di2 && dj3 == dj2))
		|| (contarSequencia(goban, ip2, jp2,  0, -1, &di3, &dj3, &ip3, &jp3, peca) == 3 && !(di3 == di1 && dj3 == dj1) && !(di3 == di2 && dj3 == dj2))
        || (contarSequencia(goban, ip2, jp2,  1, 0, &di3, &dj3, &ip3, &jp3, peca) == 3 && !(di3 == di1 && dj3 == dj1) && !(di3 == di2 && dj3 == dj2))
        || (contarSequencia(goban, ip2, jp2, -1,  0, &di3, &dj3, &ip3, &jp3, peca) == 3 && !(di3 == di1 && dj3 == dj1) && !(di3 == di2 && dj3 == dj2))
		|| (contarSequencia(goban, ip2, jp2,  1, 1, &di3, &dj3, &ip3, &jp3, peca) == 3 && !(di3 == di1 && dj3 == dj1) && !(di3 == di2 && dj3 == dj2))
		|| (contarSequencia(goban, ip2, jp2, -1, -1, &di3, &dj3, &ip3, &jp3, peca) == 3 && !(di3 == di1 && dj3 == dj1) && !(di3 == di2 && dj3 == dj2))
		|| (contarSequencia(goban, ip2, jp2, -1, 1, &di3, &dj3, &ip3, &jp3, peca) == 3 && !(di3 == di1 && dj3 == dj1) && !(di3 == di2 && dj3 == dj2))
		|| (contarSequencia(goban, ip2, jp2,  1, -1, &di3, &dj3, &ip3, &jp3, peca) == 3 && !(di3 == di1 && dj3 == dj1) && !(di3 == di2 && dj3 == dj2)))
	) {
		return 0;
		}
	return 1;
}

int contarSequencia(Tabuleiro goban, int i, int j, int di, int dj, int *pdi, int *pdj, int *fi, int *fj, Peca peca) {
	int cont = 1;

	*fi = i;
	*fj = j;

	while (
		      i+di*cont >= 0
		   && i+di*cont < goban.dimensao
		   && j+dj*cont >= 0
		   && j+dj*cont < goban.dimensao
		   && goban.matriz[i+di*cont][j+dj*cont] == peca
    ) {
    	*pdi = di;
    	*pdj = dj;
		*fi = i+di*cont;
		*fj = j+dj*cont;
		cont++;
	}
	return cont;
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
	A função validarCaptura testa em todas as 8 direções se existe uma situação de captura
	(XYYX)
	Parâmetro: O jogo, a linha e coluna da jogada atual
	Retorno: 1(Se o jogador atual realizou uma captura) ou 0(Não houve nenhuma captura)
**/
int validarCaptura(Jogo *jogo, int i, int j) {
	return    capturarPecas(jogo, i, j,  0, 1) || capturarPecas(jogo, i, j,  0, -1)
		   || capturarPecas(jogo, i, j,  1, 0) || capturarPecas(jogo, i, j, -1,  0)
		   || capturarPecas(jogo, i, j,  1, 1) || capturarPecas(jogo, i, j, -1, -1)
		   || capturarPecas(jogo, i, j, -1, 1) || capturarPecas(jogo, i, j,  1, -1);
}

/**
	A função analisarCaptura incrementa a quantidade de capturas de um jogador,
	se permitido pela função validarCaptura
	Parâmetro: O jogo, a linha e coluna da jogada atual 	
**/
void analisarCaptura(Jogo *jogo, int i, int j) {
	if (validarCaptura(jogo, i, j)) {
		if (jogo->jogador1.peca == jogo->goban.matriz[i][j]) {
			jogo->jogador1.capturas++;
		}
		else {
			jogo->jogador2.capturas++;
		}
	}
}

/**
	A função verificarCaptura analisa o tabuleiro a fim de verificar se 
	é possível fazer captura de peças
	Parâmetros: O jogo, a linha, coluna, a direção da linha(1:Para baixo, -1:Para cima e 0:Sem movimentos)
	e a direção da coluna(1:Para direita, -1:Para esquerda, 0: Sem movimento)
	Retorno: 1(Se é possível realizar a captura) ou 0(Se não há capturas)
**/
int verificarCaptura(Jogo *jogo, int i, int j, int di, int dj) {
	return    i + 3*di >= 0
           && i + 3*di < jogo->goban.dimensao
           && j + 3*dj >= 0
           && j + 3*dj < jogo->goban.dimensao
           && jogo->goban.matriz[    i   ][    j   ] == jogo->proximoJogador
           && jogo->goban.matriz[i +   di][j +   dj] == 1-jogo->proximoJogador
           && jogo->goban.matriz[i + 2*di][j + 2*dj] == 1-jogo->proximoJogador
           && jogo->goban.matriz[i + 3*di][j + 3*dj] == jogo->proximoJogador;
}

/**
	A função capturarPecas é responsável por capturar as peças, se permitido
	pela função verificarCaptura
	Parâmetros: O jogo, a linha, coluna, a direção da linha e a direção da coluna
	Retorno: 1(Se é possível realizar a captura) ou 0(Se não há capturas)
**/
int capturarPecas(Jogo *jogo, int i, int j, int di, int dj) {
	if (verificarCaptura(jogo, i, j, di, dj)) {
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