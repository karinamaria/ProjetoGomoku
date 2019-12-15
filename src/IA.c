#include "headers/IA.h"
#include "headers/Util.h"
#include "headers/Regra2.h"
#include "headers/Regra1.h"
#include <stdio.h>

/**
	A função pedirJogadaIA armazena em lin e col a melhor jogada possível para o nível da IA
	Parâmetros: O jogo, a linha e a coluna
**/
void pedirJogadaIA(Jogo *jogo, int *lin, int *col) {
	Jogada jogadas[500];
	int n = 0;

	for (int i = 0; i < jogo->goban.dimensao; i++) {
		for (int j = 0; j < jogo->goban.dimensao; j++) {
			if (jogo->goban.matriz[i][j]==-1 && !verificarFormacao3x3(jogo->goban,i,j,jogo->proximoJogador)){
				jogadas[n].lin = i;
				jogadas[n].col = j;
				jogadas[n].prioridade = calcularPrioridade(jogo, i, j);
				n++;
			}
		}
	}

	selecionarMelhorJogada(jogadas, n, lin, col);
}

/**
	A função calcularPrioridade calcula a prioridade de fazer a jogada (i, j)
	de acordo com o nível da IA
	Parâmetro: O jogo, i e j
	Retorno: A prioridade da jogada
**/
long long int calcularPrioridade(Jogo *jogo, int i, int j) {
	Jogador jogador = (jogo->proximoJogador == jogo->jogador1.peca) ? jogo->jogador1 : jogo->jogador2;
	Jogador inimigo = (jogo->proximoJogador == jogo->jogador1.peca) ? jogo->jogador2 : jogo->jogador1;

	if (jogador.nivel == 1) {
		return   calcularSequencia(jogo->goban, jogo->ganhando, jogador.peca, jogador.nivel, i, j)
		       + calcularBloqueio(jogo->goban, jogo->ganhando, inimigo.peca, jogador.nivel, i, j);
	}

	if (jogador.nivel == 2) {
		return   calcularSequencia(jogo->goban, jogo->ganhando, jogador.peca, jogador.nivel, i, j)
	           + calcularBloqueio(jogo->goban, jogo->ganhando, inimigo.peca, jogador.nivel, i, j)
	           + calcularCaptura(jogo->goban, jogo->ganhando, jogador, jogador.nivel, i, j)
	           + calcularCapturado(jogo->goban, jogo->ganhando, inimigo, jogador.nivel, i, j);
	}

	return   calcularSequencia(jogo->goban, jogo->ganhando, jogador.peca, jogador.nivel, i, j)
	       + calcularBloqueio(jogo->goban, jogo->ganhando, inimigo.peca, jogador.nivel, i, j)
	       + calcularCaptura(jogo->goban, jogo->ganhando, jogador, jogador.nivel, i, j)
	       + calcularCapturado(jogo->goban, jogo->ganhando, inimigo, jogador.nivel, i, j)
	       + calcularEntrega(jogo->goban, jogo->ganhando, inimigo, jogador.nivel, i, j);
}

/**
	A função calcularBloqueio calcula a prioridade de se bloquear uma sequência
	inimiga que passa por (i, j)
	Parâmetro: O tabuleiro, ganhando, peca_inimiga, nivel, i e j
	Retorno: A prioridade da jogada
**/
long long int calcularBloqueio(Tabuleiro goban, int ganhando, int peca_inimiga, int nivel, int i, int j) {
	if (nivel == 1)
		return calcularSequencia(goban, ganhando, peca_inimiga, nivel, i, j) + INIMIGO_S;

	return calcularSequencia(goban, ganhando, peca_inimiga, nivel, i, j) / INIMIGO_N;
}

/**
	A função calcularSequencia calcula a prioridade da sequência que a jogada (i, j) pode formar
	Parâmetro: O tabuleiro, ganhando, peca, nivel, i e j
	Retorno: A prioridade da jogada
**/
long long int calcularSequencia(Tabuleiro goban, int ganhando, int peca, int nivel, int i, int j) {
	int prioridade = 0;

	if (nivel == 1) {
		return   calcularSeqDirSimples(goban, i, j, 0, 1, peca, &prioridade)
	           + calcularSeqDirSimples(goban, i, j, 1, 0, peca, &prioridade)
	           + calcularSeqDirSimples(goban, i, j, 1, 1, peca, &prioridade)
	           + calcularSeqDirSimples(goban, i, j,-1, 1, peca, &prioridade);
	}

	if (nivel == 2) {
		return   calcularSeqDirNormal(goban, ganhando, i, j, 0, 1, peca)
	           + calcularSeqDirNormal(goban, ganhando, i, j, 1, 0, peca)
	           + calcularSeqDirNormal(goban, ganhando, i, j, 1, 1, peca)
	           + calcularSeqDirNormal(goban, ganhando, i, j,-1, 1, peca);
	}

	return   calcularSeqDirReal(goban, ganhando, i, j, 0, 1, peca)
	       + calcularSeqDirReal(goban, ganhando, i, j, 1, 0, peca)
	       + calcularSeqDirReal(goban, ganhando, i, j, 1, 1, peca)
	       + calcularSeqDirReal(goban, ganhando, i, j,-1, 1, peca);
}

/**
	A função calcularSeqDirSimples é usada pelo nível Fácil e quando chamada 8 vezes
	(uma para cada direção) retorna a maior sequência que será formada em uma das 8 direções
	Parâmetro: O tabuleiro, i, j, di, dj, peca e prioridade 
	Retorno: 0 ou a difereça
**/
int calcularSeqDirSimples(Tabuleiro goban, int i, int j, int di, int dj, Peca peca, int *prioridade) {
	Casa casa = {i, j};
	int n1 = 1, n2 = 1, max1, max2, diferenca;

	percorrerSequencia(goban, casa, di, dj, peca, &n1, &max1);
	percorrerSequencia(goban, casa,-di,-dj, peca, &n2, &max2);

	diferenca = SEQUENCIA_S * (n1 + n2 - 2) - *prioridade;

	if (diferenca > 0) {
		*prioridade = SEQUENCIA_S * (n1 + n2 - 1);
		return diferenca;
	}
	return 0;
}

/**
	A função calcularSeqDirNormal é usada pelo nível Médio e calcula o tamanho da sequência na
	direção (di,dj) e retorna sua prioridade ou zero caso não tenha espaço para alinhar 5
	Parâmetro: O tabuleiro, ganhando, i, j, di, dj e peca
	Retorno: a prioridade
**/
long long int calcularSeqDirNormal(Tabuleiro goban, int ganhando, int i, int j, int di, int dj, Peca peca) {
	Casa casa = {i, j};
	int n1 = 1, n2 = 1, max1, max2;

	percorrerSequencia(goban, casa, di, dj, peca, &n1, &max1);
	percorrerSequencia(goban, casa, -di, -dj, peca, &n2, &max2);

	return prioridadeDaSequencia(n1, n2, max1, max2, ganhando, peca);
}

/**
	A função calcularSeqDirReal é usada pelo nível Difícil e calcula o tamanho da sequência na
	direção (di,dj), considerando também as sequências com espaçamentos entre as peças,
	e retorna sua prioridade ou zero caso não tenha espaço para alinhar 5
	Parâmetro: O tabuleiro, ganhando, i, j, di, dj e peca
	Retorno: a prioridade
**/
long long int calcularSeqDirReal(Tabuleiro goban, int ganhando, int i, int j, int di, int dj, Peca peca) {
	Casa casa = {i, j};
	int n1 = 1, n2 = 1, max1, max2, seq_atual, seq_real = 0;

	percorrerSequencia(goban, casa, di, dj, peca, &n1, &max1);
	percorrerSequencia(goban, casa,-di,-dj, peca, &n2, &max2);

	for (int k = -max2 + 1; k <= max1 - 5; k++) {
		seq_atual = contarSeqReal(goban, k, i, j, di, dj, peca);

		if (seq_atual > seq_real)
			seq_real = seq_atual;
	}

	if (seq_real == 0)
		return 0;

	if (seq_real == n1 + n2 - 1)
		return prioridadeDaSequencia(n1, n2, max1, max2, ganhando, peca);

	return prioridadeDaSequencia(seq_real+max1, 1-max1, max1, max2, ganhando, peca);
}

/**
	A função calcularCapturado calcula a prioridade de se defender suas
	peças de uma possível captura inimiga
	Parâmetro: O tabuleiro, ganhando, inimigo, nivel, i e j
	Retorno: a prioridade
**/
long long int calcularCapturado(Tabuleiro goban, int ganhando, Jogador inimigo, int nivel, int i, int j) {
	return calcularCaptura(goban, ganhando, inimigo, nivel, i, j) / INIMIGO_N;
}

/**
	A função calcularCaptura calcula a prioridade de se fazer zero ou mais capturas
	jogando em (i, j)
	Parâmetro: O tabuleiro, ganhando, inimigo, nivel, i e j
	Retorno: a prioridade
**/
long long int calcularCaptura(Tabuleiro goban, int ganhando, Jogador jogador, int nivel, int i, int j) {
	int capturas = 0;
	long long int p =   calcularCapturaDir(goban, ganhando, jogador.peca, nivel, i, j, 0, 1, &capturas)
	                  + calcularCapturaDir(goban, ganhando, jogador.peca, nivel, i, j, 0,-1, &capturas)
	                  + calcularCapturaDir(goban, ganhando, jogador.peca, nivel, i, j, 1, 0, &capturas)
	                  + calcularCapturaDir(goban, ganhando, jogador.peca, nivel, i, j,-1, 0, &capturas)
	                  + calcularCapturaDir(goban, ganhando, jogador.peca, nivel, i, j, 1, 1, &capturas)
	                  + calcularCapturaDir(goban, ganhando, jogador.peca, nivel, i, j,-1,-1, &capturas)
	                  + calcularCapturaDir(goban, ganhando, jogador.peca, nivel, i, j,-1, 1, &capturas)
	                  + calcularCapturaDir(goban, ganhando, jogador.peca, nivel, i, j, 1,-1, &capturas);

	if (capturas + jogador.capturas > 4)
    	return (capturas + jogador.capturas) * CAPTURA_5;

    if (capturas > 0)
    	return (capturas + jogador.capturas) * CAPTURA_X + p;

    return 0;
}

/**
	A função calcularCapturaDir retorna zero se não houver captura na direção (di, dj)
	ou a prioridade referente a importância que as peças capturas tinha para o inimigo
	Parâmetro: O tabuleiro, ganhando, peca, nivel, i, j, di, dj e número de capturas 
	Retorno: a prioridade
**/
long long int calcularCapturaDir(Tabuleiro goban, int g, int p, int n, int i, int j, int di, int dj, int *c){
	if (validarCaptura(goban, p, i, j, di, dj)) {
		*c += 1;

    	return   calcularBloqueio(goban, g, 1-p, n, i + 1*di, j + 1*dj)
    	       + calcularBloqueio(goban, g, 1-p, n, i + 2*di, j + 2*dj);
	}
	return 0;
}

/**
	A função calcularEntrega retorna uma prioridade negativa para desincentivar a IA de
	entregar uma captura para o inimigo ou retorna zero caso a jogada não entregue uma captura
	Parâmetro: O tabuleiro, ganhando, inimigo, nivel, i e j
	Retorno: a prioridade
**/
long long int calcularEntrega(Tabuleiro goban, int ganhando, Jogador inimigo, int nivel, int i, int j) {
	int capturas = 0;
	long long int p =   calcularEntregaDir(goban, ganhando, inimigo.peca, nivel, i, j,  0,  1, &capturas)
	                  + calcularEntregaDir(goban, ganhando, inimigo.peca, nivel, i, j,  0, -1, &capturas)
	                  + calcularEntregaDir(goban, ganhando, inimigo.peca, nivel, i, j,  1,  0, &capturas)
	                  + calcularEntregaDir(goban, ganhando, inimigo.peca, nivel, i, j, -1,  0, &capturas)
	                  + calcularEntregaDir(goban, ganhando, inimigo.peca, nivel, i, j,  1,  1, &capturas)
	                  + calcularEntregaDir(goban, ganhando, inimigo.peca, nivel, i, j, -1, -1, &capturas)
	                  + calcularEntregaDir(goban, ganhando, inimigo.peca, nivel, i, j, -1,  1, &capturas)
	                  + calcularEntregaDir(goban, ganhando, inimigo.peca, nivel, i, j,  1, -1, &capturas);

	if (capturas + inimigo.capturas > 4)
    	return -((capturas + inimigo.capturas) * CAPTURA_5) / INIMIGO_N;

    if (capturas > 0)
    	return -((capturas + inimigo.capturas) * CAPTURA_X + p) / INIMIGO_N;

    return 0;
}

/**
	A função calcularEntregaDir retorna zero caso a jogada (i, j) não entregue uma captura para
	o inimigo ou a prioridade referente as duas peças que seriam capturadas
	Parâmetro: O tabuleiro, ganhando, peca, nivel, i, j, di, dj e capturas
	Retorno: a prioridade
**/
long long int calcularEntregaDir(Tabuleiro goban, int g, int p, int n, int i, int j, int di, int dj, int *c){
	if (validarEntrega(goban, p, i, j, di, dj)) {
		*c += 1;

		return   calcularSequencia(goban, g, 1-p, n, i +  0, j +  0)
    	       + calcularSequencia(goban, g, 1-p, n, i + di, j + dj);
	}
	return 0;
}

/**
	A função percorrerSequencia armazena o tamanho da sequência na direção (di, dj) em n
	e o tamanho máximo que a sequência pode ter em max
	Parâmetro: O tabuleiro, casa, di, dj peca, n e max
**/
void percorrerSequencia(Tabuleiro goban, Casa casa, int di, int dj, Peca peca, int *n, int *max) {
	while (verificarSeSeqContinua(goban, casa, di, dj, *n, peca))
		*n += 1;

	*max = *n;

	while (*max < 5 && verificarSeSeqPodeContinuar(goban, casa, di, dj, *max, peca))
		*max += 1;
}

/**
	A função verificarSeSeqPodeContinuar verifica se a casa pertence ao jogado ou
	está vazia e é uma jogada valida
	Parâmetro: tabuleiro, casa, di, dj e peca
	Retorno: Será 0(se a jogada for inválida) ou 1(se não tiver nenhum impedimento)
**/
int verificarSeSeqPodeContinuar(Tabuleiro goban, Casa casa, int di, int dj, int n, int peca) {
	return    verificarSeSeqContinua(goban, casa, di, dj, n, peca)
		   || (verificarSeSeqContinua(goban, casa, di, dj, n, -1)
		   && !verificarFormacao3x3(goban, casa.lin+di*n, casa.col+dj*n, peca));
}

/**
	A função contarSeqReal conta o tamanho da sequência considerendo sequências com
	espaços entre as peças
	Parâmetro: tabuleiro, k, i, j, di, dj e peca
	Retorno: O tamanho da sequência ou zero caso não tenha espaço para alinhar 5 peças
**/
int contarSeqReal(Tabuleiro goban, int k, int i, int j, int di, int dj, int peca) {
	int invalida = 0, seq = 0;
	int aux[5];

	for (int s = k; s < k + 5; s++) {
		aux[s-k] = goban.matriz[i + di*s][j + dj*s];
		goban.matriz[i + di*s][j + dj*s] = peca;
	}

	for (int s = k; s < k + 5; s++) {
		if (verificarFormacao3x3(goban, i+di*s, j+dj*s, peca))
			invalida = 1;
	}

	for (int s = k; s < k + 5; s++) {
		goban.matriz[i + di*s][j + dj*s] = aux[s-k];
	}

	if (invalida)
		return 0;

	for (int s = k; s < k + 5; s++) {
		if (goban.matriz[i + di*s][j + dj*s] == peca || s == 0)
			seq++;
	}
	return seq;
}

/**
	A função prioridadeDaSequencia retorna a prioridade referente ao tamanho da sequência e
	a possibilidade de aumentar a sequência por ambos os lados ou por apenas um lado
	Parâmetro: n1, n2, max1, max2, ganhando e peca
	Retorno: A prioridade
**/
long long int prioridadeDaSequencia(int n1, int n2, int max1, int max2, int ganhando, int peca) {
	int n = n1 + n2 - 1;

	if (max1 + max2 - 1 < 5)
		return 0;

	if (n > 4 && ganhando == peca)
		return SEQUENCIA_G;

	if (n > 4)
		return SEQUENCIA_5;

	if (n == 4 && max1 > n1 && max2 > n2)
		return SEQUENCIA_4D;

	if (n == 4)
		return SEQUENCIA_4U;

	if (n == 3 && max1 > n1 && max2 > n2)
		return SEQUENCIA_3D;

	if (n == 3)
		return SEQUENCIA_3U;

	if (n == 2 && max1 > n1 && max2 > n2)
		return SEQUENCIA_2D;

	if (n == 2)
		return SEQUENCIA_2U;
	
    return (max1 + max2 - 1) * POSICAO_X;
}

/**
	A função validarEntrega verifica se o inimigo pode fazer uma captura caso a
	jogada (i, j) seja feita
	Parâmetro: o tabuleiro, peca, i, j, di e dj
	Retorno: Será 0(se a jogada não entrega uma captura para o inimigo) ou 1(se entrega)
**/
int validarEntrega(Tabuleiro goban, int peca, int i, int j, int di, int dj) {
	return  ( i + 2*di >= 0
           && i + 2*di < goban.dimensao
           && j + 2*dj >= 0
           && j + 2*dj < goban.dimensao
           && i - 1*di >= 0
           && i - 1*di < goban.dimensao
           && j - 1*dj >= 0
           && j - 1*dj < goban.dimensao
           && !verificarFormacao3x3(goban, i-di, j-dj, peca)
           && goban.matriz[i - 1*di][j - 1*dj] == -1
           && goban.matriz[i + 1*di][j + 1*dj] == 1-peca
           && goban.matriz[i + 2*di][j + 2*dj] == peca)
           ||
            ( i + 1*di >= 0
           && i + 1*di < goban.dimensao
           && j + 1*dj >= 0
           && j + 1*dj < goban.dimensao
           && i - 2*di >= 0
           && i - 2*di < goban.dimensao
           && j - 2*dj >= 0
           && j - 2*dj < goban.dimensao
           && !verificarFormacao3x3(goban, i-2*di, j-2*dj, peca)
           && goban.matriz[i - 2*di][j - 2*dj] == -1
           && goban.matriz[i - 1*di][j - 1*dj] == 1-peca
           && goban.matriz[i + 1*di][j + 1*dj] == peca);
}

/**
	A função selecionarMelhorJogada escolhe uma das jogadas com maior prioridade
	Parâmetro: as jogadas n, linha e coluna
**/
void selecionarMelhorJogada(Jogada *jogadas, int n, int *lin, int *col) {
	Jogada melhor;
	int i = 1;
	jogadas = insertionSort(jogadas, n);

	while (i < n && jogadas[i].prioridade == jogadas[0].prioridade) {
		i++;
	}

	melhor = jogadas[sortearNumero(0, i-1)];

	*lin = melhor.lin;
	*col = melhor.col;
}

/**
	A função insertionSort ordena as jogadas com base na prioridade
	Parâmetro: jogadas e o número de jogadas validas
	Retorno: As jogadas em ordem decrescente
**/
Jogada* insertionSort(Jogada *jogadas, int n) {
	Jogada aux;
	int pivo;

	for (int i = 1; i < n; i++) {
		pivo = i;

		while (pivo > 0 && jogadas[pivo].prioridade > jogadas[pivo - 1].prioridade) {
			aux = jogadas[pivo];
			jogadas[pivo] = jogadas[pivo - 1];
			jogadas[pivo - 1] = aux;
			pivo--;
		}
	}

	return jogadas;
}