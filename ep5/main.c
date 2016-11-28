#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "movimentos.h"
#include "matrizes.h"
#include "pilhas.h"

int main () {
	int **tabuleiro, **grauJogadaBranca, **grauJogadaPreta;
	int m, n, vitP, vitB,tam = 5;
	int corPreta = 0, corBranca = 1;
	forcaJogada jog;
	posicao proximaJogada;
	
	proximaJogada = malloc (sizeof (pos) );
	jog = malloc (sizeof (jogada) );
	
	grauJogadaBranca = criaMatriz (tam, tam);
	grauJogadaPreta = criaMatriz (tam, tam);
	tabuleiro = criaMatriz(tam, tam);
	
	zeraMatriz(tabuleiro, tam, tam, -2);
	zeraMatriz(grauJogadaBranca, tam, tam, 0);
	zeraMatriz(grauJogadaPreta, tam, tam, 0);

	vitB = checaVitoria(tabuleiro, corBranca, tam);
	vitP = checaVitoria(tabuleiro, corPreta, tam);

	while (vitP == 0 && vitB == 0) {
		printf("\nFaca uma jogada (m,n) :");
		scanf("%d %d", &m,&n);
		
		if (m == tam/2 && n == tam/2) {
			corBranca = corPreta;
			corPreta = 1;
		}
		
		while (casaLivre (tabuleiro, tam, m, n) == 0) {
			printf("\nJogada invalida \nFaca uma jogada (m,n) :");
			scanf("%d %d", &m,&n);
		}
		tabuleiro[m][n] = corBranca;
		printf("\n Colocou 1 em : %d %d ", m,n);
			
		/* Calcular jogada da maquina */
		grauJogadaPreta = grauJogada(tabuleiro, tam, grauJogadaPreta, corPreta);
		jog = jogadaMaisForte (grauJogadaPreta, tam);
		if (jog -> qnt > 1) {
			proximaJogada = sorteiaJogada (tabuleiro, grauJogadaPreta, tam, jog -> forca, jog -> qnt);
		}
		else { /* Só uma casa com aquela força de ocorrencia */
			proximaJogada = buscaForcaMatriz(grauJogadaPreta, tam, jog -> forca); /* Fazer a busca Matriz */
		}
		printf("\n Sorteou : %d %d ", proximaJogada -> lin,proximaJogada -> col);
		tabuleiro[proximaJogada -> lin][proximaJogada -> col] = corPreta;
		printf("\n Jogo:");
		imprimeMatriz(tabuleiro, tam, tam);
		vitB = checaVitoria(tabuleiro, corBranca, tam);
		vitP = checaVitoria(tabuleiro, corPreta, tam);
	}
	
	if (vitB == 1) {
		printf("\n Branca win!");
		return 0;
	}
	if (vitP == 1){
		printf("\n Preta Win");
		return 0;
	}
	
	return 0;

}
