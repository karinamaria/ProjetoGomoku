#ifndef TRADUCAO_H
#define TRADUCAO_H

#define PORTUGUES 1
#define INGLES 2
#define ESPANHOL 3

#define MENU_PRINCIPAL 1
#define PT_MENU_PRINCIPAL "MENU PRINCIPAL"
#define EN_MENU_PRINCIPAL "MAIN MENU"

#define NOVO_JOGO 2
#define PT_NOVO_JOGO "MENU PRINCIPAL"
#define EN_NOVO_JOGO "NEW GAME"
#define ES_NOVO_JOGO "NUEVO JUEGO"

#define CONTINUAR 3
#define PT_CONTINUAR "CONTINUAR"
#define EN_CONTINUAR "CONTINUE"

#define SAIR 4
#define PT_SAIR "SAIR"
#define EN_SAIR "EXIT"
#define ES_SAIR "SALIR"

#define VOLTAR 5
#define PT_VOLTAR "VOLTAR"
#define EN_VOLTAR "RETURN"
#define ES_VOLTAR "VOLVER"

#define MSG_INICIO 6
#define PT_MSG_INICIO "Digite o numero da opcao e pressione enter:"
#define EN_MSG_INICIO "Enter the option number and press enter:"
#define ES_MSG_INICIO "Ingrese el numero de opcion y presione enter:"

#define ESCOLHER_JOGO 7
#define PT_ESCOLHER_JOGO "ESCOLHA UM JOGO"
#define EN_ESCOLHER_JOGO "CHOOSE A GAME"
#define ES_ESCOLHER_JOGO "ELIGE UN JUEGO"

#define OPCAO 8
#define PT_OPCAO "Opcao"
#define EN_OPCAO "Option"
#define ES_OPCAO "Opcion"

#define ARQUIVO 9
#define PT_ARQUIVO "Arquivo: "
#define EN_ARQUIVO "Archive: "
#define ES_ARQUIVO "Archivo: "

#define PLACAR 10
#define PT_PLACAR "Placar: "
#define EN_PLACAR "Score: "
#define ES_PLACAR "Marcador: "

#define DIMENSAO 11
#define PT_DIMENSAO "Dimensao: "
#define EN_DIMENSAO "Dimension: "
#define ES_DIMENSAO "Dimension: "

#define DATA 12
#define PT_DATA "Salvo em: "
#define EN_DATA "Saved in: "
#define ES_DATA "Guardado en: "

#define JOGADOR 13
#define PT_JOGADOR "Nome do jogador"
#define EN_JOGADOR "Player name"
#define ES_JOGADOR "Nombre del jugador"

#define CAPTURAS 14
#define PT_CAPTURAS "Capturas:"
#define EN_CAPTURAS "Catches:"

#define GOBAN 15
#define PT_GOBAN "Tamanho do goban"
#define EN_GOBAN "Goban size"
#define ES_GOBAN "Tamano de Goban"

#define VEZ 16
#define PT_VEZ "Vez de"
#define EN_VEZ "Instead of"
#define ES_VEZ "En lugar de"

#define NOVAJ 17
#define PT_NOVAJ "Onde deseja inserir a peca"
#define EN_NOVAJ "Where do you want to insert the part"
#define ES_NOVAJ "Donde quieres insertar la pieza"

#define EMPATE 18
#define PT_EMPATE "Empate"
#define EN_EMPATE "Draw"
#define ES_EMPATE "Dibujar"

#define VITORIA 20
#define PT_VITORIA "Vitoria"
#define EN_VITORIA "Victory"
#define ES_VITORIA "Victoria"

#define DE 21
#define PT_DE "de"
#define EN_DE "of"

#define PORCAPTURA 22
#define PT_POR_CAPTURA "por captura"
#define EN_POR_CAPTURA "by capture"

#define CONTINUAR_JOGO 23
#define PT_CONTINUAR_JOGO "Deseja continuar (sim | nao)?"
#define EN_CONTINUAR_JOGO "Do you want to continue (yes | no)?"
#define ES_CONTINUAR_JOGO "Quieres continuar (si | no)?"

#define SALVAR_JOGO 24
#define PT_SALVAR_JOGO "Deseja salvar esse jogo (sim | nao)?"
#define EN_SALVAR_JOGO "Do you want to save this game (yes | no)?"
#define ES_SALVAR_JOGO "Quieres guardar este juego (si | no)?"

#define CONFIGURACOES 25
#define PT_CONFIGURACOES "CONFIGURACOES"
#define EN_CONFIGURACOES "SETTINGS"
#define ES_CONFIGURACOES "AJUSTES"

#define JOGADA_INVALIDA 26
#define PT_JOGADA_INVALIDA "Posicao invalida. Por favor, tente novamente."
#define EN_JOGADA_INVALIDA "Invalid position. Please try again."
#define ES_JOGADA_INVALIDA "Posicion invalida. Por favor intente nuevamente."

#define FORMACAO3x3 27
#define PT_FORMACAO3x3 "Jogada invalida. Nao eh permitido fazer a formacao 3x3."
#define EN_FORMACAO3x3 "Invalid move. It is not allowed to do the 3x3 formation."
#define ES_FORMACAO3x3 "Movimiento invalido. No esta permitido hacer la formacion 3x3."

#define LINGUA 28
#define PT_LINGUA "Escolha a lingua"
#define EN_LINGUA "Choose a language"
#define ES_LINGUA "Elige un idioma"

char* menuP(int cod, int idioma);
char* menuC(int cod, int idioma);
char* msg(int cod, int idioma);
char* msgfim(int cod, int idioma);
char* perguntas(int cod, int idioma);

#endif