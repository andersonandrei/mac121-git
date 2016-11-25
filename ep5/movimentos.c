#include <stdio.h>
#include <stdlib.h>
#include "movimentos.h"

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
	if ( (i >= 0 && i < n && j >= 0 && j < n) && tabuleiro[i][j] == -1)
		return 1;
	return 0;
}

int **jogadaPonte (int **tabuleiro, int **grau, int cor, int n) {
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
	for (i = 0; i < n; i++ ){
		for (j = 0; j < n; j++) {
			
				if (casaLivre (tabuleiro, i, j-1) )
					grau[i][j-1] += 10;
					
				if (casaLivre (tabuleiro, i-1, j) )
					grau[i-1][j] += 10;
					
				if (casaLivre (tabuleiro, i-1, j-1) )
					grau[i-1][j-1] += 10;
				
				if (casaLivre (tabuleiro, i, j+1) )
					grau[i][j+1] += 10;
				
				if (casaLivre (tabuleiro, i+1, j) )
					grau[i+1][j] += 10;
				
				if (casaLivre (tabuleiro, i+1, j+1) )
					grau[i+1][j+1] += 10;
	
			}
		}
	}
	return grau;
}

int **grauJogada (int **tabuleiro, int **grau, int cor, int n) {
	grau = jogadaPonte (tabuleiro, grau, cor, n);
	grau = jogadaAdjascente (tabuleiro, grau, cor, n);
	return grau;
}

forcaJogada jogadaMaisForte (int ** grau, int n) {
	int i, j, maior = grau[0][0];
	int cont = 0;
	forcaJogada j;
	j = malloc (sizeof (jogada) );
	j -> qnt = 0;
	j -> forca = grau[0][0];
	
	for (i = 0; i < n; i ++) {
		for (j = 0; j < n; j++) {
			if (grau[i][j] == j -> forca) {
				forca -> qnt ++;
			}
			else if (grau[i][j] > maior) {
				j -> forca = grau[i][j];
				forca -> qnt = 1;
			}
		}
	return forcaJogada;
}

	srand( (unsigned)time(NULL) );
	x = 1 + ( rand() % 10 )
	
posicao sorteiaJogada (int **grau, int n, int g, int qnt) {
	posicao *possibildades, p;
	int i, j , k = 0, sort;
	srand( (unsigned)time(NULL) );
	p = malloc (sizeof (pos) );
	possibilidades = malloc (sizeof (qnt * sizeof (pos)) );
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			if (grau[i][j] == g) {
				p -> lin = i;
				p -> col = j;
				possibilidades[k] = p;
				k++; 
			}
		}
	}
	sort = rand() % 10;
	return possibildades[sort];
}




