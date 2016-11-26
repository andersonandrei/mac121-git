#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "movimentos.h"
#include "matrizes.h"

int main () {
	int **tabuleiro, **grauJogadaBranca, **grauJogadaPreta;
	int m, n;
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
	
	printf("\n Deseja encerrar o jogo: ");
	scanf ("%d", &encerra);
	while (encerra == 0) {
		printf("\nFaca uma jogada (m,n) :");
		scanf("%d %d", &m,&n);
		
		tabuleiro[m][n] = 1;
		
		/* Calcular jogada da maquina */
		grauJogadaPreta = grauJogada(tabuleiro, grauJogadaPreta, 1, 14);
		jog = jogadaMaisForte (grauJogadaPreta, 14);
		if (jog -> qnt > 1) {
			proximaJogada = sorteiaJogada (tabuleiro, grauJogadaPreta, 14, jog -> forca, jog -> qnt);
			printf("\n vai inserir no indice: %d %d", proximaJogada -> lin,proximaJogada -> col);
		}
		else { /* Só uma casa com aquela força de ocorrencia */
			proximaJogada = buscaForcaMatriz(grauJogadaPreta, jog -> forca); /* Fazer a busca Matriz */
			printf("\n vai inserir no indice: %d %d", proximaJogada -> lin,proximaJogada -> col);
		}
		
		printf("\n vai inserir no indice: %d %d", proximaJogada -> lin,proximaJogada -> col);
		tabuleiro[proximaJogada -> lin][proximaJogada -> col] = 0;
		printf("\n Alterou valor na matriz");
		printf("\n Tabuleiro: ");
		fflush(stdout);
		imprimeMatriz(tabuleiro, 14, 14);
		printf("\n Deseja encerrar o jogo: ");
		fflush(stdout);
		scanf ("%d", &encerra);
	}

	return 0;
}
