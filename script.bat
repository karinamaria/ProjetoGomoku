set FLAG = -Wall

del src\*.o
gcc -o src\Jogador.o -c src\Jogador.c %FLAG%
gcc -o src\Tabuleiro.o -c src\Tabuleiro.c %FLAG%
gcc -o src\Regra1.o -c src\Regra1.c %FLAG%
gcc -o src\Regra2.o -c src\Regra2.c %FLAG%
gcc -o src\Regra3.o -c src\Regra3.c %FLAG%
gcc -o src\Arquivo.o -c src\Arquivo.c %FLAG%
gcc -o src\Util.o -c src\Util.c %FLAG%
gcc -o src\Traducao.o -c src\Traducao.c %FLAG%
gcc -o src\IA.o -c src\IA.c %FLAG%
gcc -o src\Tela.o -c src\Tela.c %FLAG%
gcc -o src\Jogo.o -c src\Jogo.c %FLAG%
gcc -o src\main.o -c src\main.c %FLAG%
gcc -o Gomoku.exe src\*.o %FLAG%

Gomoku.exe