#include "pilhaMov.h"
#include <stdio.h>
#include <stdlib.h>

/* Movimentos */

int podeMover(int **tab, int p, int q, int mov) {
	if (tab[p][q] == -1) {
		if (mov == 0 && p >= 2 && tab[p-1][q] == 1 && tab[p-2][q] == 1) return 1;
		else if (mov == 1 && q >= 2 && tab[p][q-1] == 1 && tab[p][q-2] == 1) return 1;
		else if (mov == 2 && p < 5 && tab[p+1][q] == 1 && tab[p+2][q] == 1) return 1;
		else if (mov == 3 && q < 5 && tab[p][q+1] == 1 && tab[p][q+2] == 1) return 1;
		else return 0;
	}
	else {
		return 0;
	}
}

void movePeca(int **tab,int *p, int *q, int mov, int *numBrancas, int *numPretas){
	if (mov == 0) {
		tab[*p-2][*q] = -1;
		tab[*p-1][*q] = -1;
		tab[*p][*q] = 1;
		*p -= 2;
	}
	else if (mov == 1) {
		tab[*p][*q-2] = -1;
		tab[*p][*q-1] = -1;
		tab[*p][*q] = 1;
		*q -= 2;
	}
	else if (mov == 2) {
		tab[*p+2][*q] = -1;
		tab[*p+1][*q] = -1;
		tab[*p][*q] = 1;
		*p += 2;
	}
	else if (mov == 3) {
		tab[*p][*q+2] = -1;
		tab[*p][*q+1] = -1;
		tab[*p][*q] = 1;
		*q += 2;
	}
	*numPretas -=1;
	*numBrancas += 1;
}

void voltaPeca(int **tab,int *p, int *q, int mov, int *numBrancas, int *numPretas){
	if (mov == 0) {
		tab[*p+2][*q] = -1;
		tab[*p+1][*q] = 1;
		tab[*p][*q] = 1;
		*p += 2;
	}
	else if (mov == 1) {
		tab[*p][*q+2] = -1;
		tab[*p][*q+1] = 1;
		tab[*p][*q] = 1;
		*q += 2;
	} 
	else if (mov == 2) {
		tab[*p-2][*q] = -1;
		tab[*p-1][*q] = 1;
		tab[*p][*q] = 1;
		*p -= 2;
	}
	else if (mov == 3) {
		tab[*p][*q-2] = -1;
		tab[*p][*q-1] = 1;
		tab[*p][*q] = 1;
		*q -= 2;
	}
	*numPretas +=1;
	*numBrancas -= 1;
}

/* Matriz */

int **criaMatriz(int n) {
	int i;
	int **matriz;
	matriz = malloc (n*sizeof(int *));
	if(matriz != NULL)
		for (i=0; i<n; i++) {
			matriz[i] = malloc (n*sizeof(int));
			if(matriz[i] == NULL) printf("\n n alocou");
		}
	return matriz;
}

void zeraMatriz(int **tab, int n) {
	int k,t;
	for(k=0; k< n; k++){
		for(t=0; t< n; t++){
			tab[k][t] = 0;
		}
	}
}

void destroiMatriz(int **tab, int n){
	int i;
	for(i=0;i < n;i++)
		free(tab[i]);
	free(tab);
}

void imprimeMatriz(int **tab, int n) {
	int i,j;
	for (i=0; i<n; i++) {
		printf("\n");
		for(j=0; j<n; j++) {
			printf("%d ",tab[i][j]);
		}
	}
	return;
}

void montaTabuleiro(int **tab) {
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

/* Vetor*/

void adicionaVetor(int *vet, int p,int q, int *n) {
	vet[*n] = p;
	(*n)++;
	vet[*n] = q;
	(*n)++;
}

void removeVetor(int *p) {
	*p+=2;
}

int *criaVetor(int n) {
	int *vetor;
	vetor = malloc (2*n*sizeof(int *));
	if(vetor == NULL) printf("\n Nao alocou");
	return vetor;
}

void zeraVetor(int *vet, int n) {
	int k;
	for(k=0; k< n; k++){
		vet[k] = 0;
	}
}

void destroiVetor(int *vet, int n){
	free(vet);
}

void imprimeVetor(int *vet, int inicV, int fimV) {
	int i;
	for (i=inicV; i<fimV; i++) {
		printf("%d ",vet[i]);
	}
	printf("\n");
	return;
}

int main() {
	pos posicao;
	pilha *moves;
	movimento mov;
	
	int i,j,lin,col,m,auxl,auxc;
	int ok,moveu;
	int **tab;
	int numBrancas, numPretas;
	int tamV = 50;
	int *espacos;
	int fimV, inicV;
	numBrancas = 1;
	numPretas = 32;
	
	fimV = inicV = 0;
	moves = criaPilha(1000);
	tab = criaMatriz(7);
	montaTabuleiro(tab);
	espacos = criaVetor(tamV);
	zeraVetor(espacos,tamV);
	for (i=0; i<7; i++) {
		for (j=0; j<7; j++) {
			if (tab[i][j] == -1) {
				adicionaVetor(espacos, i, j, &fimV);
			}
		}
	}
	imprimeVetor(espacos,inicV,fimV);
	
	posicao.col = posicao.lin = 0;
	lin = col = 0;
	while (numPretas != 1 ) {
		ok = 0;
		col = 0;
		while (fimV/2 > 0 && ok == 0) {
			if (tab[lin][col] == -1) {
				m = 0;
				moveu = 0;
				while (m < 4 && moveu == 0) {
					if (podeMover(tab,lin,col,m)){
						ok = 1;
						moveu = 1;
					}
					else {
						m++;
					}
				}
			}
			if (moveu == 0) {
				if (col == 6 && lin <= 5) {
					lin ++;
					col = 0;
				}
				else {
					col++;
				}
			}
			
			
		}
		/* Ou ok = 1 ou = 0 */
		if (ok == 1) {
			posicao.lin = lin;
			posicao.col = col;
			auxl = lin;
			auxc = col;
			movePeca(tab,&auxl,&auxc,m, &numBrancas,&numPretas);
			mov.l = auxl;
			mov.c = auxc;
			mov.mv = m;
			empilha(moves,mov);
			m = 0;
			moveu = 0;
			lin = 0;
			if (col == 6) col = 0;
			/*
			if (col == 6 && lin <= 5) {
					lin ++;
					col = 0;
			}
			else 
				col++;
			*/
		}
		
		else { /* Backtrack */
			fflush(stdout);
			if (pilhaVazia(moves) == 1) {
				destroiMatriz(tab,7);
				destroiPilha(moves);
				return 0;
			}
			
			else {
				desempilha(moves,&mov);
				voltaPeca(tab,&(mov.l),&(mov.c),mov.mv,&numBrancas,&numPretas);
				lin--;
				col++;
			}
		}

	}
	imprimeMatriz(tab,7);
	destroiPilha(moves);
	destroiMatriz(tab,7);
	return 0;
	
}
