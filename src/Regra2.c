#include "headers/Regra2.h"
#include <stdio.h>

/**
	A função validarInsercao verifica se a posição escolhida pelo jogador
	existe no tabuleiro, não está ocupada e não gera a formação 3x3.
	Parâmetros: tabuleiro, linha e coluna(escolhidos pelo usuário) e peca
	Retorno: Será 0(se a jogada for inválida) ou 1(se não tiver nenhum impedimento)
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

	if (verificarFormacao3x3(tabuleiro, lin, col, peca)){
		printf("----Jogada invalida. Nao eh permitido fazer a formacao 3x3.----\n");
		return 0;
	}

	return 1;
}

/**
	A função verificarFormacao3x3 verifica se a posição que o jogador
	escolheu no tabuleiro gera uma formação 3x3.
	Parâmetros: tabuleiro, linha, coluna e peca
	Retorno: Será 0(se nem um problema) ou 1(se gera uma formação 3x3)
**/
int verificarFormacao3x3(Tabuleiro goban, int i, int j, Peca peca) {
	Casa c0 = {i, j};
	Casa c1, c2 = {-9, -9}, c3 = {-9, -9}, c4;

	if (validarPrimeiraSeq(goban, c0, &c1, &c2, &c3, &c4, 0, 1, peca)) {
		return validarSegundaSeq(goban, c1, c2, c3, c4, 0, 1, peca);
	}
    else if (validarPrimeiraSeq(goban, c0, &c1, &c2, &c3, &c4, 1, 0, peca)) {
    	return validarSegundaSeq(goban, c1, c2, c3, c4, 1, 0, peca);
    }
	else if (validarPrimeiraSeq(goban, c0, &c1, &c2, &c3, &c4, 1, 1, peca)) {
		return validarSegundaSeq(goban, c1, c2, c3, c4, 1, 1, peca);
	}
	else if (validarPrimeiraSeq(goban, c0, &c1, &c2, &c3, &c4, -1, 1, peca)) {
		return validarSegundaSeq(goban, c1, c2, c3, c4,-1, 1, peca);
	}

	return 0;
}

/**
	A função validarPrimeiraSeq verifica se a posição gera uma sequência de 3 ou mais peças
	Parâmetros: tabuleiro, casa pretendida e outras 4 casas, direção da linha e coluna e peca
	Retorno: Será 0(se não foi encontrada sequência de 3) ou 1(se foi encontrado)
**/
int validarPrimeiraSeq(Tabuleiro goban, Casa c0, Casa *c1, Casa *c2, Casa *c3, Casa *c4, int di, int dj, Peca peca) {
	int n1 = 1;
	int n2 = 1;

	while (verificarSeSeqContinua(goban, c0, di, dj, n1, peca)) {
		n1++;
	}

	while (verificarSeSeqContinua(goban, c0, -di, -dj, n2, peca)) {
		n2++;
	}

	c1->lin = c0.lin + di*(n1 - 1);
	c1->col = c0.col + dj*(n1 - 1);

	c4->lin = c0.lin - di*(n2 - 1);
	c4->col = c0.col - dj*(n2 - 1);

	if (n1 + n2 > 4) {
		c2->lin = c0.lin + di*(n1 - 2);
		c2->col = c0.col + dj*(n1 - 2);

		c3->lin = c0.lin - di*(n2 - 2);
		c3->col = c0.col - dj*(n2 - 2);
	}

	return n1 + n2 > 3;
}

/**
	A função verificarSeSeqContinua vê se a posição é valida e pertence ao jogador atual
	Parâmetros: tabuleiro, casa, direção da linha e coluna, n e peca
	Retorno: Será 0(se está fora do goban ou não é do jogador) ou 1(se é do jogador)
**/
int verificarSeSeqContinua(Tabuleiro goban, Casa casa, int di, int dj, int n, Peca peca) {
	return    casa.lin + di*n >= 0
		   && casa.lin + di*n < goban.dimensao
		   && casa.col + dj*n >= 0
		   && casa.col + dj*n < goban.dimensao
		   && goban.matriz[casa.lin + di*n][casa.col + dj*n] == peca;
}

/**
	A função validarSegundaSeq verifica a existência de uma segunda
	sequência a partir de um dos 4 pontos recebidos.
	Parâmetros: tabuleiro, 4 casas, direção da linha e coluna e peca
	Retorno: Será 0(se não existe sequência de 3 ou mais peças) ou 1(se existe)
**/
int validarSegundaSeq(Tabuleiro goban, Casa c1, Casa c2, Casa c3, Casa c4, int di, int dj, Peca peca) {
	return    verificarAPartirDaCasa(goban, c1, di, dj, peca)
	       || verificarAPartirDaCasa(goban, c2, di, dj, peca)
	       || verificarAPartirDaCasa(goban, c3, di, dj, peca)
	       || verificarAPartirDaCasa(goban, c4, di, dj, peca);
}

/**
	A função verificarAPartirDaCasa verifica se existe sequência em qualquer uma
	das 8 direções (duas a duas), com exceção das 2 direções da primeira sequência
	Parâmetros: tabuleiro, casa, direção da linha e coluna e peca
	Retorno: Será 0(se não existe sequência nem nemhuma direção) ou 1(se existe)
**/
int verificarAPartirDaCasa(Tabuleiro goban, Casa c, int di, int dj, Peca peca) {
	return    (!(di ==  0 && dj == 1) && verificarDirecoesOpostas(goban, 0, 1, c, peca))
           || (!(di ==  1 && dj == 0) && verificarDirecoesOpostas(goban, 1, 0, c, peca))
		   || (!(di ==  1 && dj == 1) && verificarDirecoesOpostas(goban, 1, 1, c, peca))
		   || (!(di == -1 && dj == 1) && verificarDirecoesOpostas(goban,-1, 1, c, peca));
}

/**
	A função verificarDirecoesOpostas verifica se existe sequência
	de 3 peças ou mais em uma das duas direções opostas
	Parâmetros: tabuleiro, direção da linha e coluna, casa e peca
	Retorno: Será 0(se não existe sequência maior que 2) ou 1(se existe)
**/
int verificarDirecoesOpostas(Tabuleiro goban, int di, int dj, Casa c, Peca peca) {
	int n1 = 1;
	int n2 = 1;

	while (verificarSeSeqContinua(goban, c, di, dj, n1, peca)) {
		n1++;
	}

	while (verificarSeSeqContinua(goban, c, -di, -dj, n2, peca)) {
		n2++;
	}

	return n1 > 2 || n2 > 2;
}