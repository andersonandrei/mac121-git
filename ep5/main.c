#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "movimentos.h"
#include "matrizes.h"
#include "pilhas.h"

int main (int argc, char **argv) {
	int **tabuleiro, **grauJogadaBranca, **grauJogadaPreta;
	int m, n, vitP, vitB,tam = 5;
	int corPreta, corBranca, modoVerboso, troca = 0;
	forcaJogada jog;
	posicao proximaJogada;
	
	proximaJogada = malloc (sizeof (pos) );
	jog = malloc (sizeof (jogada) );
	
	grauJogadaBranca = criaMatriz (tam, tam);
	grauJogadaPreta = criaMatriz (tam, tam);
	tabuleiro = criaMatriz(tam, tam);

	if (argc > 3) {
		printf("\n Insira apenas 2 argumentos na linha de comando. Re-execute o programa.\n");
		return 0;
	}
	
	
	if (argv[1][0] == 'b') {
		corBranca = 1;
		corPreta = 0;
	}
	
	else if (argv[1][0] == 'p') {
		corBranca = 0;
		corPreta = 1;
	}
	
	else {
		printf("\n No segundo paramentro só é permitido as opções 'b' ou 'p'\n");
		return 0;
	}

	printf("argv 0,2 %c",argv[2][0]);

	if (argv[2][0] == 48) {
		modoVerboso = 0;
	}
	else if (argv[2][0] == 49) {
		modoVerboso = 1;
	}
	else {
		printf("\n No segundo paramentro só é permitido as opções '0' ou '1'\n");
		return 0;
	}
	
	zeraMatriz(tabuleiro, tam, tam, -2);
	zeraMatriz(grauJogadaBranca, tam, tam, -1);
	zeraMatriz(grauJogadaPreta, tam, tam, -1);
	imprimeMatriz(grauJogadaPreta, tam, tam);
	
	vitB = checaVitoria(tabuleiro, corBranca, tam);
	vitP = checaVitoria(tabuleiro, corPreta, tam);

	while (vitP == 0 && vitB == 0) {
		printf("\nFaca uma jogada (m,n) :");
		scanf("%d %d", &m,&n);
		
		if (m == tam/2 && n == tam/2 && troca == 0) {
			printf("\n Inverteu");
			corBranca = corPreta;
			corPreta = 1;
			troca = 1;
		}
		
		else {
			troca = 1;
		}
		
		while (casaLivre (tabuleiro, tam, m, n) == 0) {
			printf("\nJogada invalida \nFaca uma jogada (m,n) :");
			scanf("%d %d", &m,&n);
		}
		
		tabuleiro[m][n] = corBranca;
		if (modoVerboso == 1)
			imprimeMatriz (tabuleiro, tam, tam);
		printf("\n Colocou 1 em : %d %d ", m,n);
			
		/* Calcular jogada da maquina */
		zeraMatriz(grauJogadaPreta, tam, tam, -1);
		grauJogadaPreta = grauJogada(tabuleiro, tam, grauJogadaPreta, corPreta);
		jog = jogadaMaisForte (grauJogadaPreta, tam);
		if (jog -> qnt > 1) {
			proximaJogada = sorteiaJogada (tabuleiro, grauJogadaPreta, tam, jog -> forca, jog -> qnt);
		}
		else { /* Só uma casa com aquela força de ocorrencia */
			proximaJogada = buscaForcaMatriz(tabuleiro, n, grauJogadaPreta, tamGrau, jog -> forca); /* Fazer a busca Matriz */
		}
		printf("\n Sorteou : %d %d ", proximaJogada -> lin,proximaJogada -> col);
		tabuleiro[proximaJogada -> lin][proximaJogada -> col] = corPreta;
		printf("\n Jogo:");
		if (modoVerboso == 1)
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
