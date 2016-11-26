#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "movimentos.h"
#include "matrizes.h"
#include "pilhas.h"

int main () {
	int **tabuleiro, **grauJogadaBranca, **grauJogadaPreta;
	int m, n ,tam = 14;
	forcaJogada jog;
	posicao proximaJogada;
	int encerra;
	
	proximaJogada = malloc (sizeof (pos) );
	jog = malloc (sizeof (jogada) );
	
	grauJogadaBranca = criaMatriz (14, 14);
	grauJogadaPreta = criaMatriz (14, 14);
	tabuleiro = criaMatriz(14, 14);
	
	zeraMatriz(tabuleiro, 14, 14, -2);
	zeraMatriz(grauJogadaBranca, 14, 14, 0);
	zeraMatriz(grauJogadaPreta, 14, 14, 0);

	while (checaVitoria(tabuleiro, 0, tam) == 0 && checaVitoria(tabuleiro, 1, tam) == 0) {
		printf("\nFaca uma jogada (m,n) :");
		scanf("%d %d", &m,&n);
		
		while (casaLivre (tabuleiro, m, n) == 0) {
			printf("\nJogada invalida \nFaca uma jogada (m,n) :");
			scanf("%d %d", &m,&n);
		}
		tabuleiro[m][n] = 1;
			
		
		/* Calcular jogada da maquina */
		grauJogadaPreta = grauJogada(tabuleiro, grauJogadaPreta, 1, 14);
		jog = jogadaMaisForte (grauJogadaPreta, 14);
		if (jog -> qnt > 1) {
			proximaJogada = sorteiaJogada (tabuleiro, grauJogadaPreta, 14, jog -> forca, jog -> qnt);
		}
		else { /* Só uma casa com aquela força de ocorrencia */
			proximaJogada = buscaForcaMatriz(grauJogadaPreta, jog -> forca); /* Fazer a busca Matriz */
		}
	
		tabuleiro[proximaJogada -> lin][proximaJogada -> col] = 0;
		imprimeMatriz(tabuleiro, 14, 14);
	}

	return 0;
}
