CC = gcc
CFLAGS = -Wall

prog: clean main.o jogador.o tabuleiro.o captura.o validacoes.o util.o jogo.o
	$(CC) -o Gomoku src/*.o
clean:
	rm -f src/*.o
main.o: 
	$(CC) -o src/main.o -c src/main.c $(CFLAGS)
jogador.o: 
	$(CC) -o src/Jogador.o -c src/Jogador.c $(CFLAGS)
tabuleiro.o: 
	$(CC) -o src/Tabuleiro.o -c src/Tabuleiro.c $(CFLAGS)
captura.o:
	$(CC) -o src/Captura.o -c src/Captura.c $(CFLAGS)
validacoes.o:
	$(CC) -o src/Validacoes.o -c src/Validacoes.c $(CFLAGS)
util.o:
	$(CC) -o src/Util.o -c src/Util.c $(CFLAGS)
jogo.o: 
	$(CC) -o src/Jogo.o -c src/Jogo.c $(CFLAGS)