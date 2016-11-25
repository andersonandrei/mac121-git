#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "movimentos.c"

int main () {
	int **tabuleiro, **grauJogadaBranca, **grauJogadaPreta;
	int m, n;
	forcaJogada jog;
	posicao proximaJogada;
	proximaJogada = malloc (sizeof (pos) );
	jog = malloc (sizeof (jogada) );
	tabuleiro = criaMatriz(14);
	zeraMatriz(tabuleiro, 14, 14); /* Mudar pra zera pondo -1*/
	zeraMatriz(grauJogadaBranca, 14, 14);
	zeraMatriz(grauJogadaPreta, 14, 14);
	
	while (fimDeJogo () == 0 ){
		prinf("\nFaca uma jogada (m,n) : %d %d");
		scanf("%d %d", &m,&n);
		
		tabuleiro[m][n] = 1;
		
		/* Calcular jogada da maquina */
		grauJogadaPreta = grauJogada(tabuleiro, grauJogadaPreta, 1, 14);
		jog = jogadaMaisForte (grau, 14);
		if (jog -> qnt > 1) {
			proximaJogada = sorteiaJogada (grauJogadaPreta, 14, jog -> forca, j -> qnt);
		}
		else { /* Só uma casa com aquela força de ocorrencia */
			proximaJogada = buscaMatriz(grauJogadaPreta, jog -> forca); /* Fazer a busca Matriz */
		}
		
		tabuleiro[proximaJogada -> i][proximaJogada -> j] = 0;
	}
}
return;
