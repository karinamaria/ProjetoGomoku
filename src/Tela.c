#include "headers/Arquivo.h"
#include "headers/Util.h"
#include "headers/Tela.h"
#include <stdio.h>
#include <string.h>


/**
	A função imprimirMenuPrincipal imprime o menu principal
**/
void imprimirMenuPrincipal() {
	limparTela();
	imprimirMenu("MENU PRINCIPAL");
	imprimirOpcao("NOVO JOGO", 1);
	imprimirOpcao("CONTINUAR JOGO", 2);
	imprimirOpcao("SAIR", 0);
	imprimirFinal();
	imprimirComando();
}

/**
	A função imprimirMenuContinuarJogo imprime a lista de jogos
	disponíveis para carregar.
	Parâmetros: O jogo e a qntJogosSalvos
**/
void imprimirMenuContinuarJogo(Jogo *jogo, int qntJogosSalvos) {
	limparTela();
	imprimirMenu("CONTINUAR JOGO");
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

	sprintf(linha, "| %-9s jogo_%d.txt", "Arquivo:", numArquivo);
	printf("|| %-58s Opcao: %-3d| ||\n", linha, numArquivo);

	sprintf(linha, "| %-9s %s %d x %d %s", "Placar:", jogo->jogador1.nome, jogo->jogador1.vitorias, jogo->jogador2.vitorias, jogo->jogador2.nome);
	printf("|| %-69s| ||\n", linha);

	sprintf(linha, "| %-9s %d", "Dimensao:", jogo->goban.dimensao);
	printf("|| %-69s| ||\n", linha);

	sprintf(linha, "| %-9s %02d:%02d:%02d %02d/%02d/%02d", "Data:", data.hora, data.min, data.seg, data.dia, data.mes, data.ano);
	printf("|| %-69s| ||\n", linha);

	imprimirLinha();
	imprimirEspaco();
}

/**
	A função imprimirMenu imprime a parte superior
	de uma tela incluindo o nome do menu.
	Parâmetro: o nome do menu
**/
void imprimirMenu(char *nome) {
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