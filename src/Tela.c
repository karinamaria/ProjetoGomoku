#include "headers/Tela.h"
#include "headers/Util.h"
#include "headers/Arquivo.h"
#include "headers/Traducao.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**
	A função imprimirMenuPrincipal imprime o menu principal
	Parâmetro:o idioma
**/
void imprimirMenuPrincipal(int idioma) {
	limparTela();
	imprimirTitulo(menuP(MENU_PRINCIPAL, idioma));
	imprimirOpcao(menuP(NOVO_JOGO, idioma), 1, idioma);
	imprimirOpcao(menuP(CONTINUAR, idioma), 2, idioma);
	imprimirOpcao(menuP(CONFIGURACOES, idioma), 3, idioma);
	imprimirOpcao(menuP(SAIR, idioma), 0, idioma);
	imprimirFinal();
	imprimirComando(idioma);
}

void imprimirMenuNovoJogo(int idioma) {
	limparTela();
	imprimirTitulo(modoJogo(MODO_JOGO, idioma));
	imprimirOpcao(modoJogo(JOGADORxJOGADOR, idioma), 1, idioma);
	imprimirOpcao(modoJogo(JOGADORxCOMP, idioma), 2, idioma);
	imprimirOpcao(modoJogo(COMPxCOMP, idioma), 3, idioma);
	imprimirOpcao(modoJogo(VOLTAR, idioma), 0, idioma);
	imprimirFinal();
	imprimirComando(idioma);
}

void imprimirMenuNomeJog1(int idioma) {
	limparTela();
	imprimirTitulo(menuC(MENU_JOGADOR1, idioma));
	imprimirRetangulo();
	imprimirOpcao(modoJogo(VOLTAR, idioma), 0, idioma);
	imprimirFinal();
	printf("%s ",perguntas(JOGADOR1, idioma));
}

void imprimirMenuNomeJog2(int idioma) {
	limparTela();
	imprimirTitulo(menuC(MENU_JOGADOR2, idioma));
	imprimirRetangulo();
	imprimirOpcao(modoJogo(VOLTAR, idioma), 0, idioma);
	imprimirFinal();
	printf("%s ",perguntas(JOGADOR2, idioma));
}

void imprimirMenuSeuNome(int idioma) {
	limparTela();
	imprimirTitulo(menuC(MENU_JOGADOR, idioma));
	imprimirRetangulo();
	imprimirOpcao(modoJogo(VOLTAR, idioma), 0, idioma);
	imprimirFinal();
	printf("%s ",perguntas(JOGADOR, idioma));
}

void imprimirMenuDificuldade(int idioma) {
	limparTela();
	imprimirTitulo(menuD(DIFICULDADE, idioma));
	imprimirOpcao(menuD(FACIL, idioma), 1, idioma);
	imprimirOpcao(menuD(MEDIO, idioma), 2, idioma);
	imprimirOpcao(menuD(DIFICIL, idioma), 3, idioma);
	imprimirOpcao(modoJogo(VOLTAR, idioma), 0, idioma);
	imprimirFinal();
	imprimirComando(idioma);
}

void imprimirMenuNivelCOM1(int idioma) {
	limparTela();
	imprimirTitulo(menuD(DIFICULDADE1, idioma));
	imprimirOpcao(menuD(FACIL, idioma), 1, idioma);
	imprimirOpcao(menuD(MEDIO, idioma), 2, idioma);
	imprimirOpcao(menuD(DIFICIL, idioma), 3, idioma);
	imprimirOpcao(modoJogo(VOLTAR, idioma), 0, idioma);
	imprimirFinal();
	imprimirComando(idioma);
}

void imprimirMenuNivelCOM2(int idioma) {
	limparTela();
	imprimirTitulo(menuD(DIFICULDADE2, idioma));
	imprimirOpcao(menuD(FACIL, idioma), 1, idioma);
	imprimirOpcao(menuD(MEDIO, idioma), 2, idioma);
	imprimirOpcao(menuD(DIFICIL, idioma), 3, idioma);
	imprimirOpcao(modoJogo(VOLTAR, idioma), 0, idioma);
	imprimirFinal();
	imprimirComando(idioma);
}

void imprimirMenuDimensao(int idioma) {
	limparTela();
	imprimirTitulo(menuC(MENU_DIMENSAO, idioma));
	imprimirRetangulo();
	imprimirOpcao(modoJogo(VOLTAR, idioma), 0, idioma);
	imprimirFinal();
	printf("%s (4<n<20): ", perguntas(GOBAN, idioma));
}

/**
	A função imprimirMenuContinuarJogo imprime a lista de jogos
	disponíveis para carregar.
	Parâmetros: O jogo e a qntJogosSalvos
**/
void imprimirMenuContinuarJogo(Jogo *jogo, int qntJogosSalvos) {
	limparTela();
	imprimirTitulo(menuC(ESCOLHER_JOGO, jogo->idioma));
	for(int i=0; i<qntJogosSalvos; i++){
		imprimirArquivo(jogo, i+1);
	}
	imprimirOpcao(modoJogo(VOLTAR, jogo->idioma), 0, jogo->idioma);
	imprimirFinal();
	imprimirComando(jogo->idioma);
}

/**
	A função imprimirMenuIdioma exibe os idiomas disponíveis
	Parâmetro:o jogo
**/
void imprimirMenuIdioma(Jogo *jogo){
	limparTela();
	imprimirTitulo(menuP(LINGUA, jogo->idioma));
	imprimirOpcao("PORTUGUES", 1, jogo->idioma);
	imprimirOpcao("ENGLISH", 2, jogo->idioma);
	imprimirOpcao("ESPANOL", 3, jogo->idioma);
	imprimirOpcao(modoJogo(VOLTAR, jogo->idioma), 0, jogo->idioma);
	imprimirFinal();
	imprimirComando(jogo->idioma);
}

/**
	A função imprimirArquivo imprime o nome do arquivo, o placar,
	a dimensão do tabuleiro e a data do último salvamento.
	Parâmetros: O jogo e o número do arquivo
**/
void imprimirArquivo(Jogo *jogo, int numArquivo) {
	char *nomeArquivo = nomeArquivoJogo(numArquivo);
	char linha[99];
	Data data;

	buscarDadosArquivo(jogo, nomeArquivo, &data);

	imprimirLinha();

	sprintf(linha, "| %-14s jogo_%d", menuC(ARQUIVO, jogo->idioma), numArquivo);
	printf("|| %-57s %-7s %-3d| ||\n", linha, menuC(OPCAO, jogo->idioma), numArquivo);

	sprintf(linha, "| %-14s %s %d x %d %s", menuC(PLACAR, jogo->idioma), jogo->jogador1.nome, jogo->jogador1.vitorias, jogo->jogador2.vitorias, jogo->jogador2.nome);
	printf("|| %-69s| ||\n", linha);

	sprintf(linha, "| %-14s %s", menuC(A_DIFICULDADE, jogo->idioma), textoDificuldade(jogo->jogador1.nivel, jogo->jogador2.nivel, jogo->idioma));
	printf("|| %-69s| ||\n", linha);

	sprintf(linha, "| %-14s %d", menuC(DIMENSAO, jogo->idioma), jogo->goban.dimensao);
	printf("|| %-69s| ||\n", linha);

	sprintf(linha, "| %-14s %s", menuC(A_MODO_JOGO, jogo->idioma), textoModoDeJogo(jogo->modo_de_jogo, jogo->idioma));
	printf("|| %-69s| ||\n", linha);

	sprintf(linha, "| %-14s %02d:%02d:%02d %02d/%02d/%02d", menuC(DATA, jogo->idioma), data.hora, data.min, data.seg, data.dia, data.mes, data.ano);
	printf("|| %-69s| ||\n", linha);

	imprimirLinha();
	imprimirEspaco();
}

char* textoDificuldade(int nivelj1, int nivelj2, int idioma) {
	char *texto = (char *) malloc(50 * sizeof(char));

	if (nivelj1 == 0 && nivelj2 == 0) {
		strcpy(texto, "-");
	}
	else if (nivelj1 == 0 && nivelj2 == 1) {
		strcpy(texto, menuD(A_FACIL, idioma));
	}
	else if (nivelj1 == 0 && nivelj2 == 2) {
		strcpy(texto, menuD(A_MEDIO, idioma));
	}
	else if (nivelj1 == 0 && nivelj2 == 3) {
		strcpy(texto, menuD(A_DIFICIL, idioma));
	}
	else {
		if (nivelj1 == 1) {
			strcat(strcpy(texto, menuD(A_FACIL, idioma)), " vs ");
		}
		else if (nivelj1 == 2) {
			strcat(strcpy(texto, menuD(A_MEDIO, idioma)), " vs ");
		}
		else if (nivelj1 == 3) {
			strcat(strcpy(texto, menuD(A_DIFICIL, idioma)), " vs ");
		}

		if (nivelj2 == 1) {
			strcat(texto, menuD(A_FACIL, idioma));
		}
		else if (nivelj2 == 2) {
			strcat(texto, menuD(A_MEDIO, idioma));
		}
		else if (nivelj2 == 3) {
			strcat(texto, menuD(A_DIFICIL, idioma));
		}
	}

	return texto;
}

char* textoModoDeJogo(int modo, int idioma) {
	char *texto = (char *) malloc(50 * sizeof(char));

	if (modo == 1) {
		strcpy(texto, modoJogo(JOGADORxJOGADOR, idioma));
	}
	else if (modo == 2) {
		strcpy(texto, modoJogo(JOGADORxCOMP, idioma));
	}
	else {
		strcpy(texto, modoJogo(COMPxCOMP, idioma));
	}

	return texto;
}

/**
	A função imprimirTitulo imprime a parte superior
	de uma tela incluindo o nome do menu.
	Parâmetro: o nome do menu
**/
void imprimirTitulo(char *nome) {
	int tam = strlen(nome);
	int qtd = (68 - tam) / 2;

	imprimirFinal();
	imprimirLinha();

	printf("|| |");
	for (int i = 0; i < qtd; i++) {
		printf(" ");
	}
	printf("%s", nome);
	for (int i = 0; i < 68 - tam - qtd; i++) {
		printf(" ");
	}
	printf("| ||\n");

	imprimirLinha();
	imprimirEspaco();
}

/**
	A função imprimirOpcao imprime um retângulo contendo
	o nome e o valor da opção.
	Parâmetros: o nome e o valor da opção
**/
void imprimirOpcao(char *nome, int valor, int idioma) {
	char linha[99];

	imprimirLinha();

	sprintf(linha, "| %s", nome);

	printf("|| %-57s %-7s %-3d| ||\n", linha, menuC(OPCAO, idioma), valor);
	imprimirLinha();
	imprimirEspaco();
}

/**
	A função imprimirComando imprime um pedido para o usuário digitar
**/
void imprimirComando(int idioma) {
	printf("%s ",msg(MSG_INICIO, idioma));
}

void imprimirRetangulo() {
	imprimirLinha();
	printf("|| | %-66s | ||\n", "");
	imprimirLinha();
	imprimirEspaco();
}

/**
	A função imprimirFinal imprime a margem da tela
**/
void imprimirFinal() {
	printf("============================================================================\n");
}

/**
	A função imprimirLinha imprime a margem da opção
**/
void imprimirLinha() {
	printf("|| ---------------------------------------------------------------------- ||\n");
}

/**
	A função imprimirEspaco imprime um espaço entre as opções
**/
void imprimirEspaco() {
	printf("||                                                                        ||\n");
}