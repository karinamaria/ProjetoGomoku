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
	imprimirOpcao(menuP(SAIR, idioma), 0, idioma);
	imprimirFinal();
	imprimirComando(idioma);
}

void imprimirMenuNomeJog1(int idioma) {
	limparTela();
	imprimirTitulo(perguntas(JOGADOR, idioma));
	imprimirRetangulo();
	imprimirOpcao(menuP(SAIR, idioma), 0, idioma);
	imprimirFinal();
	printf("%s 1: ",perguntas(JOGADOR, idioma));
}

void imprimirMenuNomeJog2(int idioma) {
	limparTela();
	imprimirTitulo(perguntas(JOGADOR, idioma));
	imprimirRetangulo();
	imprimirOpcao(menuP(SAIR, idioma), 0, idioma);
	imprimirFinal();
	printf("%s 2: ",perguntas(JOGADOR, idioma));
}

void imprimirMenuSeuNome(int idioma) {
	limparTela();
	imprimirTitulo(perguntas(JOGADOR, idioma));
	imprimirRetangulo();
	imprimirOpcao(menuP(SAIR, idioma), 0, idioma);
	imprimirFinal();
	printf("%s 2: ",perguntas(JOGADOR, idioma));
}

void imprimirMenuDificuldade(int idioma) {
	limparTela();
	imprimirTitulo(menuD(DIFICULDADE, idioma));
	imprimirOpcao(menuD(FACIL, idioma), 1, idioma);
	imprimirOpcao(menuD(MEDIO, idioma), 2, idioma);
	imprimirOpcao(menuD(DIFICIL, idioma), 3, idioma);
	imprimirOpcao(menuP(SAIR, idioma), 0, idioma);
	imprimirFinal();
	imprimirComando(idioma);
}

void imprimirMenuNivelCOM1(int idioma) {
	limparTela();
	imprimirTitulo(menuD(DIFICULDADE, idioma));
	imprimirOpcao(menuD(FACIL, idioma), 1, idioma);
	imprimirOpcao(menuD(MEDIO, idioma), 2, idioma);
	imprimirOpcao(menuD(DIFICIL, idioma), 3, idioma);
	imprimirOpcao(menuP(SAIR, idioma), 0, idioma);
	imprimirFinal();
	imprimirComando(idioma);
}

void imprimirMenuNivelCOM2(int idioma) {
	limparTela();
	imprimirTitulo(menuD(DIFICULDADE, idioma));
	imprimirOpcao(menuD(FACIL, idioma), 1, idioma);
	imprimirOpcao(menuD(MEDIO, idioma), 2, idioma);
	imprimirOpcao(menuD(DIFICIL, idioma), 3, idioma);
	imprimirOpcao(menuP(SAIR, idioma), 0, idioma);
	imprimirFinal();
	imprimirComando(idioma);
}

void imprimirMenuDimensao(int idioma) {
	limparTela();
	imprimirTitulo(menuC(DIMENSAO, idioma));
	imprimirRetangulo();
	imprimirOpcao(menuP(SAIR, idioma), 0, idioma);
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
	imprimirOpcao(menuP(SAIR, jogo->idioma), 0, jogo->idioma);
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
	imprimirOpcao("Portugues", 1, jogo->idioma);
	imprimirOpcao("English", 2, jogo->idioma);
	imprimirOpcao("Espanol", 3, jogo->idioma);
	imprimirOpcao(menuP(SAIR, jogo->idioma), 0, jogo->idioma);
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

	sprintf(linha, "| %-13s jogo_%d", menuC(ARQUIVO, jogo->idioma), numArquivo);
	printf("|| %-58s %s: %-3d| ||\n", linha, menuC(OPCAO, jogo->idioma), numArquivo);

	sprintf(linha, "| %-13s %s %d x %d %s", menuC(PLACAR, jogo->idioma), jogo->jogador1.nome, jogo->jogador1.vitorias, jogo->jogador2.vitorias, jogo->jogador2.nome);
	printf("|| %-69s| ||\n", linha);

	sprintf(linha, "| %-13s %s", "Dificuldade:", textoDificuldade(jogo->jogador1.nivel, jogo->jogador2.nivel));
	printf("|| %-69s| ||\n", linha);

	sprintf(linha, "| %-13s %d", menuC(DIMENSAO, jogo->idioma), jogo->goban.dimensao);
	printf("|| %-69s| ||\n", linha);

	sprintf(linha, "| %-13s %s", "Modo de jogo:", textoModoDeJogo(jogo->modo_de_jogo));
	printf("|| %-69s| ||\n", linha);

	sprintf(linha, "| %-13s %02d:%02d:%02d %02d/%02d/%02d", menuC(DATA, jogo->idioma), data.hora, data.min, data.seg, data.dia, data.mes, data.ano);
	printf("|| %-69s| ||\n", linha);

	imprimirLinha();
	imprimirEspaco();
}

char* textoDificuldade(int nivelj1, int nivelj2) {
	char *texto = (char *) malloc(50 * sizeof(char));

	if (nivelj1 == 0 && nivelj2 == 0) {
		strcpy(texto, "-");
	}
	else if (nivelj1 == 0 && nivelj2 == 1) {
		strcpy(texto, "Facil");
	}
	else if (nivelj1 == 0 && nivelj2 == 2) {
		strcpy(texto, "Medio");
	}
	else if (nivelj1 == 0 && nivelj2 == 3) {
		strcpy(texto, "Dificil");
	}
	else {
		if (nivelj1 == 1) {
			strcpy(texto, "Facil vs ");
		}
		else if (nivelj1 == 2) {
			strcpy(texto, "Medio vs ");
		}
		else if (nivelj1 == 3) {
			strcpy(texto, "Dificil vs ");
		}

		if (nivelj2 == 1) {
			strcat(texto, "Facil");
		}
		else if (nivelj2 == 2) {
			strcat(texto, "Medio");
		}
		else if (nivelj2 == 3) {
			strcat(texto, "Dificil");
		}
	}

	return texto;
}

char* textoModoDeJogo(int modo) {
	char *texto = (char *) malloc(50 * sizeof(char));

	if (modo == 1) {
		strcpy(texto, "Jogador vs Jogador");
	}
	else if (modo == 2) {
		strcpy(texto, "Jogador vs Computador");
	}
	else {
		strcpy(texto, "Computador vs Computador");
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

	printf("|| %-57s %-6s: %-3d| ||\n", linha, menuC(OPCAO, idioma), valor);
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