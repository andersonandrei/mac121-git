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
			if(matriz[i] == NULL) printf("Impossivel\n");
		}
	return matriz;
}

void zeraMatriz(int **tab, int lin, int col, int valor) {
	int i,j;
	for(i=0; i< lin; i++){
		for(j=0; j< col; j++){
			tab[i][j] = valor;
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
			if (tab[i][j] == -2)
				printf("- ");
			else {
				if (tab[i][j] == 1)
					printf("b ");
				if (tab[i][j] == 0)
					printf("p "); 
			}
		}
	}
	printf("\n");
	return;
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

int *criaVetor(int lin) {
	int *vetor;
	vetor = malloc (lin*sizeof(int *));
	if(vetor == NULL)
		printf("Impossivel\n");
	return vetor;
}

void destroiVetor(int *v){
	free(v);
}
