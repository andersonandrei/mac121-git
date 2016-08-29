#include "pilhaD.h"

#include <stdio.h>
#include <stdlib.h>

int **criaMatriz(n) {
	int i;
	int **matriz;
	matriz = malloc (n*sizeof(int));
	for (i=0; i<n; i++) 
		matriz[i] = malloc (n*sizeof(int));

	return matriz;
}

int livre(int **tab, int atual, int l, int c) {
	int i;
	
	/* Verifica linha livre */
	for(i=0;i<n;i++)
		if (matriz[l][i] == 1) return 0;
	/* Verifica coluna livre */
	for(i=0;i<n;i++)
		if (matriz[i][c] == 1) return 0;
	/* Verifica Diagonal principal */
	for(i=0;i<n && (l+i) <n && (c+i) <n ;i++)
		if (matriz[l+i][c+i] == 1) return 0;	
	/* Verifica Diagonal secundaria */
	for(i=0;i<n && (l-i) >0 && (c-i) >0 ;i++)
		if (matriz[l-i][c-i] == 1) return 0;	
}

int main() {
	printf("Brincando com as N-Kings\n");
	int **tabuleiro;
	pilha *colunas;
	int col,rainha,n
	
	tabuleiro = criaMatriz(4);
	
	colunas = criaPilha(4);
	
	
	
	
}



