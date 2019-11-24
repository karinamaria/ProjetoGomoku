#include "headers/Tela.h"
#include "headers/Util.h"
#include "headers/Arquivo.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**
	A função imprimirMenuPrincipal imprime o menu principal
**/
void imprimirMenuPrincipal() {
	limparTela();
	imprimirTitulo("MENU PRINCIPAL");
	imprimirOpcao("NOVO JOGO", 1);
	imprimirOpcao("CONTINUAR JOGO", 2);
	imprimirOpcao("SAIR", 0);
	imprimirFinal();
	imprimirComando();
}

void imprimirMenuNovoJogo() {
	limparTela();
	imprimirTitulo("MODO DE JOGO");
	imprimirOpcao("JOGADOR VS JOGADOR", 1);
	imprimirOpcao("JOGADOR VS COMPUTADOR", 2);
	imprimirOpcao("COMPUTADOR VS COMPUTADOR", 3);
	imprimirOpcao("VOLTAR", 0);
	imprimirFinal();
	imprimirComando();
}

void imprimirMenuNomeJog1() {
	limparTela();
	imprimirTitulo("NOME DO JOGADOR 1");
	imprimirRetangulo();
	imprimirOpcao("VOLTAR", 0);
	imprimirFinal();
	printf("Digite o nome do Jogador 1 e pressione enter: ");
}

void imprimirMenuNomeJog2() {
	limparTela();
	imprimirTitulo("NOME DO JOGADOR 2");
	imprimirRetangulo();
	imprimirOpcao("VOLTAR", 0);
	imprimirFinal();
	printf("Digite o nome do Jogador 2 e pressione enter: ");
}

void imprimirMenuSeuNome() {
	limparTela();
	imprimirTitulo("DIGITE SEU NOME");
	imprimirRetangulo();
	imprimirOpcao("VOLTAR", 0);
	imprimirFinal();
	printf("Digite seu nome e pressione enter: ");
}

void imprimirMenuDificuldade() {
	limparTela();
	imprimirTitulo("DIFICULDADE");
	imprimirOpcao("FACIL", 1);
	imprimirOpcao("MEDIO", 2);
	imprimirOpcao("DIFICIL", 3);
	imprimirOpcao("VOLTAR", 0);
	imprimirFinal();
	imprimirComando();
}

void imprimirMenuNivelCOM1() {
	limparTela();
	imprimirTitulo("NIVEL DO COMPUTADOR 1");
	imprimirOpcao("FACIL", 1);
	imprimirOpcao("MEDIO", 2);
	imprimirOpcao("DIFICIL", 3);
	imprimirOpcao("VOLTAR", 0);
	imprimirFinal();
	imprimirComando();
}

void imprimirMenuNivelCOM2() {
	limparTela();
	imprimirTitulo("NIVEL DO COMPUTADOR 2");
	imprimirOpcao("FACIL", 1);
	imprimirOpcao("MEDIO", 2);
	imprimirOpcao("DIFICIL", 3);
	imprimirOpcao("VOLTAR", 0);
	imprimirFinal();
	imprimirComando();
}

void imprimirMenuDimensao() {
	limparTela();
	imprimirTitulo("DIMENSAO DO GOBAN");
	imprimirRetangulo();
	imprimirOpcao("VOLTAR", 0);
	imprimirFinal();
	printf("Digite a dimensao do goban (4<n<20) e pressione enter: ");
}

/**
	A função imprimirMenuContinuarJogo imprime a lista de jogos
	disponíveis para carregar.
	Parâmetros: O jogo e a qntJogosSalvos
**/
void imprimirMenuContinuarJogo(Jogo *jogo, int qntJogosSalvos) {
	limparTela();
	imprimirTitulo("ESCOLHA UM JOGO");
	for(int i=0; i<qntJogosSalvos; i++){
		imprimirArquivo(jogo, i+1);
	}
	imprimirOpcao("VOLTAR", 0);
	imprimirFinal();
	imprimirComando();
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

	sprintf(linha, "| %-13s jogo_%d", "Jogo:", numArquivo);
	printf("|| %-58s Opcao: %-3d| ||\n", linha, numArquivo);

	sprintf(linha, "| %-13s %s %d x %d %s", "Placar:", jogo->jogador1.nome, jogo->jogador1.vitorias, jogo->jogador2.vitorias, jogo->jogador2.nome);
	printf("|| %-69s| ||\n", linha);

	sprintf(linha, "| %-13s %s", "Dificuldade:", textoDificuldade(jogo->jogador1.nivel, jogo->jogador2.nivel));
	printf("|| %-69s| ||\n", linha);

	sprintf(linha, "| %-13s %d", "Dimensao:", jogo->goban.dimensao);
	printf("|| %-69s| ||\n", linha);

	sprintf(linha, "| %-13s %s", "Modo de jogo:", textoModoDeJogo(jogo->modo_de_jogo));
	printf("|| %-69s| ||\n", linha);

	sprintf(linha, "| %-13s %02d:%02d:%02d %02d/%02d/%02d", "Salvo em:", data.hora, data.min, data.seg, data.dia, data.mes, data.ano);
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
void imprimirOpcao(char *nome, int valor) {
	char linha[99];

	imprimirLinha();

	sprintf(linha, "| %s", nome);

	printf("|| %-58s Opcao: %-3d| ||\n", linha, valor);
	imprimirLinha();
	imprimirEspaco();
}

void imprimirRetangulo() {
	imprimirLinha();
	printf("|| | %-66s | ||\n", "");
	imprimirLinha();
	imprimirEspaco();
}

/**
	A função imprimirComando imprime um pedido para o usuário digitar
**/
void imprimirComando() {
	printf("Digite o numero da opcao e pressione enter: ");
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