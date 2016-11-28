#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "movimentos.h"
#include "matrizes.h"
#include "pilhas.h"

int main (int argc, char **argv) {
	int **tabuleiro, **grauJogadaBranca, **grauJogadaPreta;
	int m, n, vitP, vitB,tam = 14;
	int corPreta, corBranca, modoVerboso, eJogada, troca = 0;
	forcaJogada jog;
	posicao proximaJogada;
	
	proximaJogada = malloc (sizeof (pos) );
	jog = malloc (sizeof (jogada) );
	
	grauJogadaBranca = criaMatriz (tam, tam);
	grauJogadaPreta = criaMatriz (tam, tam);
	tabuleiro = criaMatriz(tam, tam);

	if (argc > 3)
		return 0;	
	if (argc == 3) 
		if (argv[2][0] == 'd')
			modoVerboso = 1;
		else
			modoVerboso = 0;
	if (argc == 2) 
		modoVerboso = 0;
	if (argv[1][0] == 'b') {
		corBranca = 1;
		corPreta = 0;
	}	
	else if (argv[1][0] == 'p') {
		corBranca = 0;
		corPreta = 1;
	}
	else {
		return 0;
	}
	
	zeraMatriz(tabuleiro, tam, tam, -2);
	zeraMatriz(grauJogadaBranca, tam, tam, -1);
	zeraMatriz(grauJogadaPreta, tam, tam, -1);
	
	vitB = checaVitoria(tabuleiro, corBranca, tam);
	vitP = checaVitoria(tabuleiro, corPreta, tam);

	while (vitP == 0 && vitB == 0) {
		scanf("%d %d", &m,&n);
		
		if (m == tam/2 && n == tam/2 && troca == 0) {
			corBranca = corPreta;
			corPreta = 1;
			troca = 1;
		}
		
		else {
			troca = 1;
		}
		
		while (casaLivre (tabuleiro, tam, m, n) == 0) {
			scanf("%d %d", &m,&n);
		}
		
		tabuleiro[m][n] = corBranca;
			
		/* Calcular jogada da maquina */
		zeraMatriz(grauJogadaPreta, tam, tam, -1);
		grauJogadaPreta = jogadaLivre (tabuleiro, tam, grauJogadaPreta, corPreta);
		eJogada = existeJogada (grauJogadaPreta, tam);
		
		if (eJogada == 1) {
			grauJogadaPreta = grauJogada(tabuleiro, tam, grauJogadaPreta, corPreta);
			jog = jogadaMaisForte (grauJogadaPreta, tam);
			if (jog -> qnt > 1) {
				proximaJogada = sorteiaJogada (tabuleiro, grauJogadaPreta, tam, jog -> forca, jog -> qnt);
			}
			else { /* Só uma casa com aquela força de ocorrencia */
				proximaJogada = buscaForcaMatriz(tabuleiro, tam, grauJogadaPreta, jog -> forca); /* Fazer a busca Matriz */
			}
			printf("%d %d\n", proximaJogada -> lin, proximaJogada -> col);
			tabuleiro[proximaJogada -> lin][proximaJogada -> col] = corPreta;
			if (modoVerboso == 1)
			imprimeMatriz(tabuleiro, tam, tam);
		}

	
		vitP = checaVitoria(tabuleiro, corPreta, tam);
		printf("\n vitP = %d",vitP);
		fflush(stdout);
		
		vitB = checaVitoria(tabuleiro, corBranca, tam);
		printf("\n vitB = %d",vitB);
		fflush(stdout);
	}
	
	if (vitB == 1) {
		printf("b ganhou\n");
		return 0;
	}
	if (vitP == 1){
		printf("p ganhou\n");
		return 0;
	}
	
	return 0;

}
