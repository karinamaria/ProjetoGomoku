#include "headers/Tela.h"
#include "headers/Util.h"
#include "headers/Arquivo.h"
#include "headers/Traducao.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**
	A função imprimirMenuPrincipal imprime o menu principal
	Parâmetro: o idioma
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

/**
	A função imprimirMenuNovoJogo imprime o menu de escolha do modo de jogo
	Parâmetro: o idioma
**/
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

/**
	A função imprimirMenuNomeJog1 imprime a tela que pede
	o nome do jogador 1 (no modo de jogo Jogador vs Jogador)
	Parâmetro: o idioma
**/
void imprimirMenuNomeJog1(int idioma) {
	limparTela();
	imprimirTitulo(menuC(MENU_JOGADOR1, idioma));
	imprimirRetangulo();
	imprimirOpcao(modoJogo(VOLTAR, idioma), 0, idioma);
	imprimirFinal();
	printf("%s ",perguntas(JOGADOR1, idioma));
}

/**
	A função imprimirMenuNomeJog2 imprime a tela que pede
	o nome do jogador 2 (no modo de jogo Jogador vs Jogador)
	Parâmetro: o idioma
**/
void imprimirMenuNomeJog2(int idioma) {
	limparTela();
	imprimirTitulo(menuC(MENU_JOGADOR2, idioma));
	imprimirRetangulo();
	imprimirOpcao(modoJogo(VOLTAR, idioma), 0, idioma);
	imprimirFinal();
	printf("%s ",perguntas(JOGADOR2, idioma));
}

/**
	A função imprimirMenuSeuNome imprime a tela que pede
	o nome do jogador (no modo de jogo Jogador vs Computador)
	Parâmetro: o idioma
**/
void imprimirMenuSeuNome(int idioma) {
	limparTela();
	imprimirTitulo(menuC(MENU_JOGADOR, idioma));
	imprimirRetangulo();
	imprimirOpcao(modoJogo(VOLTAR, idioma), 0, idioma);
	imprimirFinal();
	printf("%s ",perguntas(JOGADOR, idioma));
}

/**
	A função imprimirMenuDificuldade imprime o menu dificuldade
	(no modo de jogo Jogador vs Computador)
	Parâmetro: o idioma
**/
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

/**
	A função imprimirMenuNivelCOM1 imprime a tela que pede
	o nível do Computador1 (no modo de jogo Computador vs Computador)
	Parâmetro: o idioma
**/
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

/**
	A função imprimirMenuNivelCOM2 imprime a tela que pede
	o nível do Computador2 (no modo de jogo Computador vs Computador)
	Parâmetro: o idioma
**/
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

/**
	A função imprimirMenuDimensao imprime a tela que pede
	o tamanho do goban, podendo ser um valor entre 5 e 19.
	Parâmetro: o idioma
**/
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
	char linha[500];
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
	free(nomeArquivo);
}

/**
	A função imprimirErroJogadaInvalida imprime uma mensagem de erro
	avisando que a jogada é invalida
	Parâmetro: o idioma
**/
void imprimirErroJogadaInvalida(int idioma) {
	printf("----%s----\n", msg(JOGADA_INVALIDA, idioma));
}

/**
	A função imprimirErroFormacao3x3 imprime uma mensagem de erro
	avisando que a jogada gera a formação 3x3
	Parâmetro: o idioma
**/
void imprimirErroFormacao3x3(int idioma) {
	printf("----%s----\n", msg(FORMACAO3x3, idioma));
}

/**
	A função imprimirGanhador imprime o ganhador
	Parâmetro: o nome do ganhador, vitoriaPorCaptura(0 ou 1) e o idioma
**/
void imprimirGanhador(char* ganhador, int vitoriaPorCaptura, int idioma) {
	char *por_captura = (char *) malloc(50 * sizeof(char));

	if (vitoriaPorCaptura) {
		strcpy(por_captura, msgfim(PORCAPTURA, idioma));
	}
	else {
		strcpy(por_captura, "");
	}

	printf("%s%s %s %s\n", msgfim(VITORIA, idioma), por_captura, msgfim(DE, idioma), ganhador);
	free(por_captura);
}

/**
	A função imprimirEmpate imprime uma mensagem de empate
	Parâmetro: o idioma
**/
void imprimirEmpate(int idioma) {
	printf("%s\n", msgfim(EMPATE, idioma));
}

/**
	A função imprimirPlacarCaptura imprime o placar de capturas
	Parâmetros: Os dois jogadores e o idioma
**/
void imprimirPlacarCapturas(Jogador jogador1, Jogador jogador2, int idioma) {
		printf("%s", msg(CAPTURAS, idioma));
		printf("%s %d", jogador1.nome, jogador1.capturas);
		printf(" x ");
		printf("%d %s\n", jogador2.capturas, jogador2.nome);
}

/**
	A função imprimirPlacarVitorias imprime o placar de vitórias
	Parâmetros: Os dois jogadores e o idioma
**/
void imprimirPlacarVitorias(Jogador jogador1, Jogador jogador2, int idioma) {
		printf("%s", menuC(PLACAR, idioma));
		printf("%s %d", jogador1.nome, jogador1.vitorias);
		printf(" x ");
		printf("%d %s\n", jogador2.vitorias, jogador2.nome);
}

/**
	A função imprimirContinuarJogando imprime uma mensagem perguntando
	se os jogadores desejam continuar jogando.
	Parâmetros: o idioma
**/
void imprimirContinuarJogando(int idioma) {
	printf("%s ", perguntas(CONTINUAR_JOGO, idioma));
}

/**
	A função textoDificuldade retorna o texto contendo a
	dificuldade no idioma atual.
	Parâmetros: O nível do jogador 1 e 2 e o idioma
	Retorno: Um texto
**/
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

/**
	A função textoModoDeJogo retorna o texto contendo a
	o modo de jogo no idioma atual.
	Parâmetros: O modo de jogo e o idioma
	Retorno: Um texto
**/
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
	Parâmetros: o nome, o valor da opção e o idioma
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
	Parâmetro: o idioma
**/
void imprimirComando(int idioma) {
	printf("%s ",msg(MSG_INICIO, idioma));
}

/**
	A função imprimirRetangulo imprime um retângulo vazio na tela
**/
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