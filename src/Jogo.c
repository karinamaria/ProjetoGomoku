#include "Validacoes.h"
#include "Util.h"
#include "Jogo.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <glob.h>

/**
	A função iniciarJogo inicializa todas as variáveis,
	roda o jogo em si e executa as funções de fim de jogo
	Parâmetro: O jogo
**/
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
	salvarJogo(jogo);
	liberarMatriz(jogo.goban.matriz, jogo.goban.dimensao);
}

/**
	A função loopJogo onde acontece a partida em si,
	todas as jogadas, verificações e impressões na tela
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
	A função validarInsercao verifica se a posição que o jogador
	escolheu no tabuleiro exite, não está ocupada e não gera a formação 3x3.
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
	escolheu no tabuleiro gera a formação 3x3.
	Parâmetros: tabuleiro, linha, coluna e peca
	Retorno: Será 0(se nem um problema) ou 1(se gera uma formação 3x3)
**/
int verificarFormacao3x3(Tabuleiro goban, int i, int j, Peca peca) {
	Casa c0 = {i, j};
	Casa c1, c2;

	if (existeSeqMaiorQ3(goban, c0, peca)) {
		return 0;
	}
	else if (validarPrimeiraSeq(goban, c0, &c1, &c2, 0, 1, peca)) {
		return analisarSegundaSeq(goban, 0, 1, c1, c2, peca);
	}
    else if (validarPrimeiraSeq(goban, c0, &c1, &c2, 1, 0, peca)) {
    	return analisarSegundaSeq(goban, 1, 0, c1, c2, peca);
    }
	else if (validarPrimeiraSeq(goban, c0, &c1, &c2, 1, 1, peca)) {
		return analisarSegundaSeq(goban, 1, 1, c1, c2, peca);
	}
	else if (validarPrimeiraSeq(goban, c0, &c1, &c2, -1, 1, peca)) {
		return analisarSegundaSeq(goban, -1, 1, c1, c2, peca);
	}

	return 0;

}

/**
	A função existeSeqMaiorQ3 verifica se a posição pretendida
	pelo jogador gera uma sequência de mais de 3 peças.
	Parâmetros: tabuleiro, posição/casa e peca
	Retorno: Será 0(se não gera uma sequência de 4 ou 5 peças) ou 1(se gera)
**/
int existeSeqMaiorQ3(Tabuleiro goban, Casa c, Peca peca) {
	return    contarSeq(goban, c, 0, 1, peca) > 4
	       || contarSeq(goban, c, 1, 0, peca) > 4
	       || contarSeq(goban, c, 1, 1, peca) > 4
	       || contarSeq(goban, c,-1, 1, peca) > 4;
}

/**
	A função contarSeq conta o número de peças em sequência na direção di dj
	Parâmetros: tabuleiro, casa, direção da linha, direção da coluna e peca
	Retorno: O número de peças da sequência
**/
int contarSeq(Tabuleiro goban, Casa c, int di, int dj, Peca peca) {
	int n1 = 1;
	int n2 = 1;

	while (verificarPeca(goban, c, di, dj, peca, n1)) {
		n1++;
	}

	while (verificarPeca(goban, c, -di, -dj, peca, n2)) {
		n2++;
	}

	return n1 + n2;
}

/**
	A função verificarPeca vê se a posição é valida e pertence ao jogador da vez
	Parâmetros: tabuleiro, casa, direção da linha, direção da coluna, peca e n
	Retorno: Será 0(se está fora do goban ou não é do jogador) ou 1(se é do jogador)
**/
int verificarPeca(Tabuleiro goban, Casa casa, int di, int dj, Peca peca, int n) {
	return    casa.lin + di*n >= 0
		   && casa.lin + di*n < goban.dimensao
		   && casa.col + dj*n >= 0
		   && casa.col + dj*n < goban.dimensao
		   && goban.matriz[casa.lin + di*n][casa.col + dj*n] == peca;
}

/**
	A função validarPrimeiraSeq verifica se a posição gera uma sequência de 3 peças
	Parâmetros: tabuleiro, casa central e as duas pontas, direção da linha e coluna e peca
	Retorno: Será 0(se não foi encontrada sequência de 3) ou 1(se foi encontrado)
**/
int validarPrimeiraSeq(Tabuleiro goban, Casa c0, Casa *c1, Casa *c2, int di, int dj, Peca peca) {
	int n1 = 1;
	int n2 = 1;

	while (verificarPeca(goban, c0, di, dj, peca, n1)) {
		n1++;
	}

	c1->lin = c0.lin + di*(n1 - 1);
	c1->col = c0.col + dj*(n1 - 1);

	while (verificarPeca(goban, c0, -di, -dj, peca, n2)) {
		n2++;
	}

	c2->lin = c0.lin - di*(n2 - 1);
	c2->col = c0.col - dj*(n2 - 1);

	if (n1 + n2 == 4) {
		return 1;
	}

	return 0;
}

/**
	A função analisarSegundaSeq verifica em ambas as pontas
	da primeira sequência encontrada se existe sequência de 3 conectada.
	Parâmetros: tabuleiro, direção da linha e coluna, casas das duas pontas e peca
	Retorno: Será 0(se não existe sequência de 3 a partir de c1 ou c2) ou 1(se existe)
**/
int analisarSegundaSeq(Tabuleiro goban, int direcao_lin, int direcao_col, Casa c1, Casa c2, Peca peca) {
	if (existeSeqMaiorQ3(goban, c1, peca) || existeSeqMaiorQ3(goban, c2, peca)) {
		return 0;
	}

	return    verificarSegundaSeq(goban, direcao_lin, direcao_col, c1, peca)
	       || verificarSegundaSeq(goban, direcao_lin, direcao_col, c2, peca);
		
}

/**
	A função verificarSegundaSeq verifica se existe sequência de tamanho 3 ou não
	Parâmetros: tabuleiro, direção da linha e coluna, casa e peca
	Retorno: Será 0(se não existe sequência de 3) ou 1(se existe)
**/
int verificarSegundaSeq(Tabuleiro goban, int di, int dj, Casa c, Peca peca) {
	return    (!(di ==  0 && dj == 1) && validarSegundaSeq(goban, c,  0, 1, peca))
           || (!(di ==  1 && dj == 0) && validarSegundaSeq(goban, c,  1, 0, peca))
		   || (!(di ==  1 && dj == 1) && validarSegundaSeq(goban, c,  1, 1, peca))
		   || (!(di == -1 && dj == 1) && validarSegundaSeq(goban, c, -1, 1, peca));
}

/**
	A função validarSegundaSeq verifica se existe sequência de tamanho 3
	na direção di dj
	Parâmetros: tabuleiro, casa, direção da linha e coluna e peca
	Retorno: Será 0(se não existe sequência de 3) ou 1(se existe)
**/
int validarSegundaSeq(Tabuleiro goban, Casa c0, int di, int dj, Peca peca) {
	int n1 = 1;
	int n2 = 1;

	while (verificarPeca(goban, c0, di, dj, peca, n1)) {
		n1++;
	}

	while (verificarPeca(goban, c0, -di, -dj, peca, n2)) {
		n2++;
	}

	if (n1 == 3 && n2 == 1) {
		return 1;
	}

	else if (n1 == 1 && n2 == 3) {
		return 1;
	}

	return 0;
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
	A função salvarJogo pergunta se os usuário desejam salvar o jogo 
	Parâmetro: O jogo
**/
void salvarJogo(Jogo jogo){
	char resposta[3];
	do{
		printf("Deseja salvar esse jogo (sim | nao)? ");
		scanf("%s",resposta);
		strcpy(resposta,converterParaMinusculo(resposta));
	}while(strcmp("sim", resposta) != 0 && strcmp("nao", resposta) != 0);
	if(strcmp("sim", resposta) == 0){
		salvarInformacoesJogo(jogo);
	}
	
}

/**
	A função salvarInformacoesJogo grava os detalhes do jogo em um arquivo 'jogo_x.txt'
	Parâmetro: O jogo
**/
void salvarInformacoesJogo(Jogo jogo){
	char nomeArquivo[50];
	
	nomeArquivoJogo(nomeArquivo);

	FILE *arquivo;
	
	arquivo = fopen(nomeArquivo, "w");

	fprintf(arquivo, "%s; %d; %d; %d \n", jogo.jogador1.nome, jogo.jogador1.vitorias, 
		jogo.jogador1.capturas, jogo.jogador1.peca);
	fprintf(arquivo, "%s; %d; %d; %d \n", jogo.jogador2.nome, jogo.jogador2.vitorias, 
		jogo.jogador2.capturas, jogo.jogador2.peca);

	fprintf(arquivo, "%d \n", jogo.goban.dimensao);
	
	fclose(arquivo);
}

/**
	A função nomeArquivoJogo nomeia um arquivo que contém informações do jogo
	Parâmetro: O nome do arquivo;
**/
void nomeArquivoJogo(char *nomeArquivo){
	const char *pattern = "./jogo_*.txt";
  	glob_t pglob; 

  	glob(pattern, GLOB_ERR, NULL, &pglob);      

  	int qntJogosSalvos=(int)pglob.gl_pathc+1;

  	globfree(&pglob);

  	char caracter[3];
  	sprintf(caracter, "%i", qntJogosSalvos);

  	strcpy(nomeArquivo, "jogo_");
  	strcat(nomeArquivo, strcat(caracter, ".txt"));
  	

}

/**
	A função analisarCaptura incrementa a quantidade de capturas de um jogador,
	se permitido pela função verificarCaptura
	Parâmetro: O jogo, a linha e coluna da jogada atual 	
**/
void analisarCaptura(Jogo *jogo, int i, int j) {
	if (verificarCaptura(jogo, i, j)) {
		if (jogo->jogador1.peca == jogo->goban.matriz[i][j]) {
			jogo->jogador1.capturas++;
		}
		else {
			jogo->jogador2.capturas++;
		}
	}
}

/**
	A função verificarCaptura vê se em uma das 8 direções existe uma
	situação de captura (XYYX)
	Parâmetro: O jogo, a linha e coluna da jogada atual
	Retorno: 1(Se o jogador atual realizou uma captura) ou 0(Não houve nenhuma captura)
**/
int verificarCaptura(Jogo *jogo, int i, int j) {
	return    capturouPecas(jogo, i, j,  0, 1) || capturouPecas(jogo, i, j,  0, -1)
		   || capturouPecas(jogo, i, j,  1, 0) || capturouPecas(jogo, i, j, -1,  0)
		   || capturouPecas(jogo, i, j,  1, 1) || capturouPecas(jogo, i, j, -1, -1)
		   || capturouPecas(jogo, i, j, -1, 1) || capturouPecas(jogo, i, j,  1, -1);
}

/**
	A função capturouPecas é responsável por capturar as peças, se permitido
	pela função validarCaptura
	Parâmetros: O jogo, a linha, coluna, a direção da linha e a direção da coluna
	Retorno: 1(Se é possível realizar a captura) ou 0(Se não é possível)
**/
int capturouPecas(Jogo *jogo, int i, int j, int di, int dj) {
	if (validarCaptura(jogo, i, j, di, dj)) {
		jogo->goban.matriz[i +   di][j +   dj] = -1;
		jogo->goban.matriz[i + 2*di][j + 2*dj] = -1;

		return 1;
	}

	return 0;
}

/**
	A função validarCaptura analisa o tabuleiro a fim de verificar se 
	é possível fazer captura de peças
	Parâmetros: O jogo, a linha, coluna,
	a direção da linha(1:Para baixo, -1:Para cima e 0:Sem movimentos)
	e a direção da coluna(1:Para direita, -1:Para esquerda, 0: Sem movimento)
	Retorno: 1(Se é possível realizar a captura) ou 0(Se não é possível)
**/
int validarCaptura(Jogo *jogo, int i, int j, int di, int dj) {
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