## Projeto Gomoku

O objetivo deste projeto é aplicar todo o conhecimento adquirido ao decorrer das aulas da disciplina Introdução às Técnicas de Programação. Para isso, desenvolveremos um jogo eletrônico chamado Gomoku e também a sua versão mais elaborada, o Ninuki.

## Como usar este projeto

No Linux:
```
git clone https://github.com/karinamaria/ProjetoGomoku.git
bash script.sh
```
No Windows
```
git clone https://github.com/karinamaria/ProjetoGomoku.git
script.bat
```
## Regras do Gomoku

- O tabuleiro chama-se goban e tem tamanho que varia entre 5x5 e 19x19
- É sorteado as peças dos jogadores (preto ou branco)
- Quem começa são as pretas
- Cada jogador só pode colocar uma peça em uma interseção vaga por vez
- Quem conseguir alinhar cinco peças na horizontal, vertical ou diaginal primeiro vence

## Regras adicionais do Ninuki

- 1ª regra: Duas peças adversárias podem ser capturadas ao serem colocadas entre duas suas
- 2ª regra: É proibido criar a formação 3x3 que consiste no alinhamento cruzado de três peças em direções diferentes
- 3ª regra: Ganha quem conseguir cinco capturas ou alinhar cinco peças e seu adversário não consiga capturar nenhuma delas na jogada seguinte

## Funcionalidades implementadas

- Interface com caracteres ASCII
- Salvamento de jogo
- Carregamento de jogo
- Tradução para os idiomas:
	- Português
	- Inglês
	- Espanhol
- Modos de jogo:
	- Jogador vs Jogador
	- Jogador vs Computador
	- Computador vs Computador
- Inteligência artificial nos níveis:
	- Fácil
	- Médio
	- Difícil

## Autores

- Karina Maria - [@karinamaria](https://github.com/karinamaria)
- Wadson Pontes - [@WadsonPontes](https://github.com/WadsonPontes)