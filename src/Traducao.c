#include "headers/Jogo.h"
#include "headers/Traducao.h"
#include <string.h>

char* menuP(int cod, int idioma){
	switch(cod){
		case MENU_PRINCIPAL:
			if (idioma == PORTUGUES)
				return PT_MENU_PRINCIPAL;
			else if (idioma == INGLES)
				return EN_MENU_PRINCIPAL;
			else if (idioma == ESPANHOL)
				return PT_MENU_PRINCIPAL;
		case NOVO_JOGO:
			if (idioma == PORTUGUES)
				return PT_NOVO_JOGO;
			else if (idioma == INGLES)
				return EN_NOVO_JOGO;
			else if (idioma == ESPANHOL)
				return ES_NOVO_JOGO;
		case CONTINUAR:
			if (idioma == PORTUGUES)
				return PT_CONTINUAR;
			else if (idioma == INGLES)
				return EN_CONTINUAR;
			else if (idioma == ESPANHOL)
				return PT_CONTINUAR;
		case SAIR:
			if (idioma == PORTUGUES)
				return PT_SAIR;
			else if (idioma == INGLES)
				return EN_SAIR;
			else if (idioma == ESPANHOL)
				return ES_SAIR;
		case CONFIGURACOES:
			if (idioma == PORTUGUES)
				return PT_CONFIGURACOES;
			else if (idioma == INGLES)
				return EN_CONFIGURACOES;
			else if (idioma == ESPANHOL)
				return ES_CONFIGURACOES;
		case LINGUA:
			if (idioma == PORTUGUES)
				return PT_LINGUA;
			else if (idioma == INGLES)
				return EN_LINGUA;
			else if (idioma == ESPANHOL)
				return ES_LINGUA;
	}
}
char* menuC(int cod, int idioma){
	switch (cod) {
		case ESCOLHER_JOGO:
			if (idioma == PORTUGUES)
				return PT_ESCOLHER_JOGO;
			else if (idioma == INGLES)
				return EN_ESCOLHER_JOGO;
			else if (idioma == ESPANHOL)
				return ES_ESCOLHER_JOGO;
		case OPCAO:
			if (idioma == PORTUGUES)
				return PT_OPCAO;
			else if (idioma == INGLES)
				return EN_OPCAO;
			else if (idioma == ESPANHOL)
				return ES_OPCAO;
		case ARQUIVO:
			if (idioma == PORTUGUES)
				return PT_ARQUIVO;
			else if (idioma == INGLES)
				return EN_ARQUIVO;
			else if (idioma == ESPANHOL)
				return ES_ARQUIVO;
		case PLACAR:
			if (idioma == PORTUGUES)
				return PT_PLACAR;
			else if (idioma == INGLES)
				return EN_PLACAR;
			else if (idioma == ESPANHOL)
				return ES_PLACAR;
		case DIMENSAO:
			if (idioma == PORTUGUES)
				return PT_DIMENSAO;
			else if (idioma == INGLES)
				return EN_DIMENSAO;
			else if (idioma == ESPANHOL)
				return ES_DIMENSAO;
		case DATA:
			if (idioma == PORTUGUES)
				return PT_DATA;
			else if (idioma == INGLES)
				return EN_DATA;
			else if (idioma == ESPANHOL)
				return ES_DATA;
	}
}
char* msg(int cod, int idioma){
	switch(cod){
		case MSG_INICIO:
			if (idioma == PORTUGUES){
				return PT_MSG_INICIO;
			}else if (idioma == INGLES){
				return EN_MSG_INICIO;
			}else if (idioma == ESPANHOL){
				return ES_MSG_INICIO;
			}
		case CAPTURAS:
			if (idioma == INGLES){
				return EN_CAPTURAS;
			}else{
				return PT_CAPTURAS;
			}
		case VEZ:
			if (idioma == PORTUGUES){
				return PT_VEZ;
			}else if (idioma == INGLES){
				return EN_VEZ;
			}else if (idioma == ESPANHOL){
				return ES_VEZ;
			}
		case JOGADA_INVALIDA:
			if (idioma == PORTUGUES){
				return PT_JOGADA_INVALIDA;
			}else if (idioma == INGLES){
				return EN_JOGADA_INVALIDA;
			}else if (idioma == ESPANHOL){
				return ES_JOGADA_INVALIDA;
			}
		case FORMACAO3x3:
			if (idioma == PORTUGUES){
				return PT_FORMACAO3x3;
			}else if (idioma == INGLES){
				return EN_FORMACAO3x3;
			}else if (idioma == ESPANHOL){
				return ES_FORMACAO3x3;
			}
	}
}

char* msgfim(int cod, int idioma){
	switch(cod){
		case EMPATE:
			if (idioma == PORTUGUES){
				return PT_EMPATE;
			}else if (idioma == INGLES){
				return EN_EMPATE;
			}else if (idioma == ESPANHOL){
				return ES_EMPATE;
			}
		case VITORIA:
			if (idioma == PORTUGUES){
				return PT_VITORIA;
			}else if (idioma == INGLES){
				return EN_VITORIA;
			}else if (idioma == ESPANHOL){
				return ES_VITORIA;
			}
		case DE:
			if (idioma == INGLES){
				return EN_DE;
			}else{
				return PT_DE;
			}
		case PORCAPTURA:
			if (idioma == INGLES){
				return EN_DE;
			}else{
				return PT_DE;
			}
	}
}

char* perguntas(int cod, int idioma){
	switch(cod){
		case JOGADOR:
			if (idioma == PORTUGUES){
				return PT_JOGADOR;
			}else if (idioma == INGLES){
				return EN_JOGADOR;
			}else if (idioma == ESPANHOL){
				return ES_JOGADOR;
			}
		case GOBAN:
			if (idioma == PORTUGUES){
				return PT_GOBAN;
			}else if (idioma == INGLES){
				return EN_GOBAN;
			}else if (idioma == ESPANHOL){
				return ES_GOBAN;
			}
		case NOVAJ:
			if (idioma == PORTUGUES){
				return PT_NOVAJ;
			}else if (idioma == INGLES){
				return EN_NOVAJ;
			}else if (idioma == ESPANHOL){
				return ES_NOVAJ;
			}
		case CONTINUAR_JOGO:
			if (idioma == PORTUGUES){
				return PT_CONTINUAR_JOGO;
			}else if (idioma == INGLES){
				return EN_CONTINUAR_JOGO;
			}else if (idioma == ESPANHOL){
				return ES_CONTINUAR_JOGO;
			}
		case SALVAR_JOGO:
			if (idioma == PORTUGUES){
				return PT_SALVAR_JOGO;
			}else if (idioma == INGLES){
				return EN_SALVAR_JOGO;
			}else if (idioma == ESPANHOL){
				return ES_SALVAR_JOGO;
			}
	}
}