CC = gcc
CFLAGS = -Wall

prog: clean main.o jogador.o tabuleiro.o validacoes.o jogo.o
	$(CC) -o prog src/main.o src/Jogador.o src/Tabuleiro.o src/Validacoes.o src/Jogo.o
clean:
	rm -f src/*.o
main.o: 
	$(CC) -o src/main.o -c src/main.c $(CFLAGS)
jogador.o: 
	$(CC) -o src/Jogador.o -c src/Jogador.c $(CFLAGS)
tabuleiro.o: 
	$(CC) -o src/Tabuleiro.o -c src/Tabuleiro.c $(CFLAGS)
validacoes.o:
	$(CC) -o src/Validacoes.o -c src/Validacoes.c $(CFLAGS)
jogo.o: 
	$(CC) -o src/Jogo.o -c src/Jogo.c $(CFLAGS)