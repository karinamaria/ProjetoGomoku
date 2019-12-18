#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
	A função cifrarCaractere criptografa um caractere usando a fórmula m^e mod n
	Parâmetro: o caractere, n e e
	Retorno: O caractere cifrado
**/
char* cifrarCaractere(char caractere, unsigned long long int n, unsigned long long int e) {
	unsigned long long int aux = caractere;
	char *cifrado = (char *) malloc(12 * sizeof(char));

	for (unsigned long long int i = 1; i < e; i++) {
		aux *= caractere;
		if (aux > n)
			aux %= n;
	}
	sprintf(cifrado, "%lld", aux);

	return cifrado;
}

/**
	A função encriptar criptografa cada um dos caracteres da mensagem
	e os armazena de forma espaçada
	Parâmetro: a mensagem
	Retorno: a mensagem cifrado
**/
char* encriptar(char *mensagem) {
	// unsigned long long int p  = 10007;
	// unsigned long long int q  = 10069;
	unsigned long long int n  = 100760483; // n = p*q
	// unsigned long long int fi = 100740408; fi(n) = (p-1)(q-1)
	unsigned long long int e  = 18427;
	// unsigned long long int d  = 5467; // e*d == 1 (mod fi)
	int tam = strlen(mensagem);
	char *cifrado = (char *) malloc(tam * 12 * sizeof(char));

	strcpy(cifrado, cifrarCaractere(mensagem[0], n, e));

	for (int i = 1; i < tam; i++) {
		strcat(cifrado, " ");
		strcat(cifrado, cifrarCaractere(mensagem[i], n, e));
	}
	return cifrado;
}

/**
	A função decifrarCaractere descriptografa um caractere usando a fórmula c^d mod n
	Parâmetro: o caractere, n e d
	Retorno: O caractere decifrado
**/
char decifrarCaractere(unsigned long long int caractere, unsigned long long int n, unsigned long long int d) {
	unsigned long long int decifrado = caractere;

	for (unsigned long long int i = 1; i < d; i++) {
		decifrado *= caractere;
		if (decifrado > n)
			decifrado %= n;
	}
	return decifrado;
}

/**
	A função decriptar descriptografa cada um dos números separados por espaço
	e os junta em um só texto
	Parâmetro: a mensagem crifrada
	Retorno: a mensagem original
**/
char* decriptar(char* cifrado) {
	// unsigned long long int p  = 10007;
	// unsigned long long int q  = 10069;
	unsigned long long int n  = 100760483; // n = p*q
	// unsigned long long int fi = 100740408; // fi(n) = (p-1)(q-1)
	// unsigned long long int e  = 18427;
	unsigned long long int d  = 5467; // e*d == 1 (mod fi)
	int k = 0, tam = strlen(cifrado);
	char *mensagem = (char *) malloc(tam * sizeof(char));

	while (cifrado[0] != '\0') {
		mensagem[k] = decifrarCaractere(strtoull(cifrado, &cifrado, 10), n, d);
		k++;
	}
	return mensagem;
}