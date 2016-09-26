#include "matrizes.h"
#include <stdio.h>
#include <stdlib.h>

int **criaMatriz(int lin, int col) {
	int i;
	int **matriz;
	matriz = malloc (lin*sizeof(int *));
	if(matriz != NULL)
		for (i=0; i<lin; i++) {
			matriz[i] = malloc (col*sizeof(int));
			if(matriz[i] == NULL) printf("\n n alocou matriz");
		}
	return matriz;
}

void zeraMatriz(int **tab, int lin, int col) {
	int i,j;
	for(i=0; i< lin; i++){
		for(j=0; j< col; j++){
			tab[i][j] = 0;
		}
	}
	return;
}

void destroiMatriz(int **tab, int lin, int col){
	int i;
	for(i=0;i < lin;i++)
		free(tab[i]);
	free(tab);
	return;
}

void imprimeMatriz(int **tab, int lin, int col) {
	int i,j;
	for (i=0; i<lin; i++) {
		printf("\n");
		for(j=0; j<col; j++) {
			printf("%d ",tab[i][j]);
		}
	}
	return;
}

void montaTabuleiro77(int **tab) {
	tab[0][0] = 0;
	tab[0][1] = 0;
	tab[0][2] = 1;
	tab[0][3] = 1;
	tab[0][4] = 1;
	tab[0][5] = 0;
	tab[0][6] = 0;
	
	tab[1][0] = 0;
	tab[1][1] = 0;
	tab[1][2] = 1;
	tab[1][3] = 1;
	tab[1][4] = 1;
	tab[1][5] = 0;
	tab[1][6] = 0;
	
	tab[2][0] = 1;
	tab[2][1] = 1;
	tab[2][2] = 1;
	tab[2][3] = 1;
	tab[2][4] = 1;
	tab[2][5] = 1;
	tab[2][6] = 1;
	
	tab[3][0] = 1;
	tab[3][1] = 1;
	tab[3][2] = 1;
	tab[3][3] = -1;
	tab[3][4] = 1;
	tab[3][5] = 1;
	tab[3][6] = 1;
	
	tab[4][0] = 1;
	tab[4][1] = 1;
	tab[4][2] = 1;
	tab[4][3] = 1;
	tab[4][4] = 1;
	tab[4][5] = 1;
	tab[4][6] = 1;
	
	tab[5][0] = 0;
	tab[5][1] = 0;
	tab[5][2] = 1;
	tab[5][3] = 1;
	tab[5][4] = 1;
	tab[5][5] = 0;
	tab[5][6] = 0;
	
	tab[6][0] = 0;
	tab[6][1] = 0;
	tab[6][2] = 1;
	tab[6][3] = 1;
	tab[6][4] = 1;
	tab[6][5] = 0;
	tab[6][6] = 0;
}

void montaTabuleiro33(int **tab) {
	tab[0][0] = 1;
	tab[0][1] = 1;
	tab[0][2] = -1;
	
	tab[1][0] = 1;
	tab[1][1] = 1;
	tab[1][2] = -1;
	
	tab[2][0] = 1;
	tab[2][1] = 1;
	tab[2][2] = -1;
}

void montaTabuleiro43(int **tab) {
	tab[0][0] = -1;
	tab[0][1] = 1;
	tab[0][2] = 1;
	
	tab[1][0] = 1;
	tab[1][1] = -1;
	tab[1][2] = 1;
	
	tab[2][0] = 1;
	tab[2][1] = 1;
	tab[2][2] = 1;
	
	tab[3][0] = -1;
	tab[3][1] = 1;
	tab[3][2] = -1;

	
}

void inverteMatriz (int **tab, int **tabInversa, int lin, int col) {
	int i,j;
	for(i=0; i<lin; i++) {
		for(j=0;j<col;j++) {
			if(tab[i][j] == 1) tabInversa[i][j] = -1;
			if(tab[i][j] == -1) tabInversa[i][j] = 1;
		}
	}
	return;
}

int comparaMatriz (int **tabA, int **tabB, int lin, int col) {
	int i,j;
	for(i=0;i<lin;i++) {
		for(j=0;j<col;j++) {
			if (tabA[i][j] != tabB[i][j]) return 0;
		}
	}
	return 1;
}
