#include "movimentos.h"
#include "matrizes.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


	/*Casa adjascentes dada i,j				 
		i, j-1
		i-1, j
		i-1, j-1
		i, j+1
		i+1, j
		i+1, j+1
		
		[i][j-1]
		[i-1][j]
		[i-1][j-1]
		[i][j+1]
		[i+1][j]
		[i+1][j+1]
		
	*/

int casaLivre (int **tabuleiro, int i, int j) {
	if ( (i >= 0 && i < 14 && j >= 0 && j < 14) && (tabuleiro[i][j] != 1 && tabuleiro[i][j] != 0) )
		return 1;
	return 0;
}

int **jogadaPonte (int **tabuleiro, int **grau, int cor, int n) {
	int i, j;
	for (i = 0; i < n; i++ ){
		for (j = 0; j < n; j++) {
			if (tabuleiro[i][j] == cor) {
				
				if (casaLivre (tabuleiro, i-2, j-1) )
					grau[i-2][j-1] += 10;
				
				if (casaLivre (tabuleiro, i-1, j-2) )
					grau[i-1][j-2] += 10;
				
				if (casaLivre (tabuleiro, i-1, j+1) )
					grau[i-1][j+1] += 10;
				
				if (casaLivre (tabuleiro, i+1, j-1) )
					grau[i+1][j-1] += 10;
	
				if (casaLivre (tabuleiro, i+2, j+1) )
					grau[i+2][j+1] += 10;
					
				if (casaLivre (tabuleiro, i+1, j+2) )
					grau[i+1][j+2] += 10;
			}
		}
	}
	return grau;
}

int **jogadaAdjascente (int **tabuleiro, int **grau, int cor, int n) {
	int i, j;
	for (i = 0; i < n; i++ ){
		for (j = 0; j < n; j++) {
			if (tabuleiro[i][j] == cor) {
				if (casaLivre (tabuleiro, i, j-1) )
					grau[i][j-1] += 5;
					
				if (casaLivre (tabuleiro, i-1, j) )
					grau[i-1][j] += 5;
					
				if (casaLivre (tabuleiro, i-1, j-1) )
					grau[i-1][j-1] += 5;
				
				if (casaLivre (tabuleiro, i, j+1) )
					grau[i][j+1] += 5;
				
				if (casaLivre (tabuleiro, i+1, j) )
					grau[i+1][j] += 5;
				
				if (casaLivre (tabuleiro, i+1, j+1) )
					grau[i+1][j+1] += 5;
			}
		}
	}
	return grau;
}

int **grauJogada (int **tabuleiro, int **grau, int cor, int n) {
	printf("\n Antes da Ponte:\n");
	imprimeMatriz (grau, 14, 14);
	grau = jogadaPonte (tabuleiro, grau, cor, n);
	printf("\n Depois da Ponte:\n");
	imprimeMatriz (grau, 14, 14);
	grau = jogadaAdjascente (tabuleiro, grau, cor, n);
	printf("\n Depois da Adsjacente:\n");
	imprimeMatriz (grau, 14, 14);
	return grau;
}

forcaJogada jogadaMaisForte (int ** grau, int n) {
	int i, k;
	forcaJogada j;
	j = malloc (sizeof (jogada) );
	j -> qnt = 0;
	j -> forca = grau[0][0];
	
	for (i = 0; i < n-1; i ++) {
		for (k = 0; k < n-1; k++) {
			if (grau[i][k] == j -> forca) {
				j -> qnt ++;
			}
			else if (grau[i][k] > j -> forca) {
				j -> forca = grau[i][k];
				j -> qnt = 1;
			}
		}
	}
	return j;
}
	
posicao sorteiaJogada (int **tabuleiro, int **grau, int n, int g, int qnt) {
	posicao *possibilidades, p;
	int i, j , k = 0, sort;
	srand( (unsigned)time(NULL) );
	p = malloc (sizeof (pos) );
	possibilidades = malloc (sizeof (qnt * sizeof (pos)) );
	for (i = 0; i < n; i++) {
		for (j = 0; j <n; j++) {
			if (grau[i][j] == g) {
				p -> lin = i;
				p -> col = j;
				possibilidades[k] = p;
				k++; 
			}
		}
	}
	sort = 0; /* Ajustar o sort */
	while (casaLivre (tabuleiro, possibilidades[sort] -> lin, possibilidades[sort] -> col) == 0) {
		sort = rand() % 10;
		printf("\n Sorteou : %d",sort);
	}
	
	grau[possibilidades[sort] -> lin][possibilidades[sort] -> col] = 0;
	return possibilidades[sort];
}

posicao buscaForcaMatriz(int **tab, int forca) {
	posicao casa;
	int i, j;
	fflush (stdout);
	casa = malloc (sizeof (pos) );
	
	for (i = 0; i < 14; i++) {
		for (j = 0; j < 14; j++) {
			if (tab[i][j] == forca) {
				casa -> lin = i;
				casa -> col = j;
				tab[i][j] = 0;
			}
		}
	}
	
	return casa;
}



