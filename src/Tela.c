#include "headers/Arquivo.h"
#include "headers/Util.h"
#include "headers/Traducao.h"
#include "headers/Tela.h"
#include <stdio.h>
#include <string.h>


/**
	A função imprimirMenuPrincipal imprime o menu principal
	Parâmetro:o idioma
**/
void imprimirMenuPrincipal(int idioma) {
	limparTela();
	imprimirMenu(menuP(MENU_PRINCIPAL, idioma));
	imprimirOpcao(menuP(NOVO_JOGO, idioma), 1, idioma);
	imprimirOpcao(menuP(CONTINUAR, idioma), 2, idioma);
	imprimirOpcao(menuP(CONFIGURACOES, idioma), 3, idioma);
	imprimirOpcao(menuP(SAIR, idioma), 0, idioma);
	imprimirFinal();
	imprimirComando(idioma);
}

/**
	A função imprimirMenuIdioma exibe os idiomas disponíveis
	Parâmetro:o jogo
**/
void imprimirMenuIdioma(Jogo *jogo){
	limparTela();
	imprimirMenu(menuP(LINGUA, jogo->idioma));
	imprimirOpcao("Portugues", 1, jogo->idioma);
	imprimirOpcao("English", 2, jogo->idioma);
	imprimirOpcao("Espanol", 3, jogo->idioma);
	imprimirOpcao(menuP(SAIR, jogo->idioma), 0, jogo->idioma);
	imprimirFinal();
	imprimirComando(jogo->idioma);
}
/**
	A função imprimirMenuContinuarJogo imprime a lista de jogos
	disponíveis para carregar.
	Parâmetros: O jogo e a qntJogosSalvos
**/
void imprimirMenuContinuarJogo(Jogo *jogo, int qntJogosSalvos) {
	limparTela();
	imprimirMenu(menuC(ESCOLHER_JOGO, jogo->idioma));
	for(int i=0; i<qntJogosSalvos; i++){
		imprimirArquivo(jogo, i+1);
	}
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

	sprintf(linha, "| %-9s jogo_%d", menuC(ARQUIVO, jogo->idioma), numArquivo);
	printf("|| %-58s %s: %-3d| ||\n", linha, menuC(OPCAO, jogo->idioma), numArquivo);

	sprintf(linha, "| %-9s %s %d x %d %s", menuC(PLACAR, jogo->idioma), jogo->jogador1.nome, jogo->jogador1.vitorias, jogo->jogador2.vitorias, jogo->jogador2.nome);
	printf("|| %-69s| ||\n", linha);

	sprintf(linha, "| %-9s %d", menuC(DIMENSAO, jogo->idioma), jogo->goban.dimensao);
	printf("|| %-69s| ||\n", linha);

	sprintf(linha, "| %-9s %02d:%02d:%02d %02d/%02d/%02d", menuC(DATA, jogo->idioma), data.hora, data.min, data.seg, data.dia, data.mes, data.ano);
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
void imprimirOpcao(char *nome, int valor, int idioma) {
	char linha[99];

	imprimirLinha();

	sprintf(linha, "| %s", nome);

	printf("|| %-58s %s: %-3d| ||\n", linha, menuC(OPCAO, idioma), valor);
	imprimirLinha();
	imprimirEspaco();
}

/**
	A função imprimirComando imprime um pedido para o usuário digitar
**/
void imprimirComando(int idioma) {
	printf("%s ",msg(MSG_INICIO, idioma));
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