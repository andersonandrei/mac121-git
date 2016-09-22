#include "pilhaMov.h"
#include <stdio.h>
#include <stdlib.h>

/* Movimentos */

int podeMover(int **tab, int p, int q, int mov) {
	if (mov == 0 && p >= 2 && tab[p][q] == -1) return 1;
	else if (mov == 1 && q >= 2 && tab[p][q] == -1) return 1;
	else if (mov == 2 && p < 7 && tab[p][q] == -1) return 1;
	else if (mov == 3 && q < 7 && tab[p][q] == -1) return 1;
	return 0;
	
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
		tab[*p+2][*q] = 1;
		tab[*p+1][*q] = 1;
		tab[*p][*q] = -1;
		*p += 2;
	}
	else if (mov == 1) {
		tab[*p][*q+2] = 1;
		tab[*p][*q+1] = 1;
		tab[*p][*q] = -1;
		*q += 2;
	} 
	else if (mov == 2) {
		tab[*p-2][*q] = 1;
		tab[*p-1][*q] = 1;
		tab[*p][*q] = -1;
		*p -= 2;
	}
	else if (mov == 3) {
		tab[*p][*q-2] = 1;
		tab[*p][*q-1] = 1;
		tab[*p][*q] = -1;
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

int main() {
	pos posicao;
	pilha *moves;
	movimento mov;
	
	int i,j,lin,col,m,auxl,auxc;
	int ok,moveu;
	int **tab;
	int numBrancas, numPretas;
	
	numBrancas = 1;
	numPretas = 32;
	
	moves = criaPilha(100);
	tab = criaMatriz(7);
	montaTabuleiro(tab);
	imprimeMatriz(tab,7);
	posicao.col = posicao.lin = 0;
	lin = col = 0;
	printf("\n oi");
	while (lin < 7 && numBrancas != 32 ) {
		printf("\n Entrou lin = %d",lin);
		fflush(stdout);
		ok = 0;
		col = 0;
		while (col < 7 && ok == 0) {
			printf("\n Entrou col = %d",col);
			printf("\n --->Linhas = %d",lin);
			if (tab[lin][col] == -1) {
				m = 0;
				while (m < 4 && moveu == 0) {
					printf("\n mov = %d",m);
					if (podeMover(tab,lin,col,m)){
						printf("\n Pode");
						ok = 1;
						moveu = 1;
					}
					else {
						m++;
					}
				}
			}
			else {
				if (col == 6 && lin <= 5) {
					lin ++;
					col = 0;
				}
				else 
					col++;
			}
		}
		/* Ou ok = 1 ou = 0 */
		if (ok == 1) {
			printf("\n ok");
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
			if (col == 6 && lin <= 5) {
					lin ++;
					col = 0;
			}
			else 
				col++;
		}
		
		else { /* Backtrack */
			if (pilhaVazia(moves) == 1) {
				printf("Acabaram as possibilidades.\n");
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
		imprimeMatriz(tab,7);

	}
	imprimeMatriz(tab,7);
	destroiPilha(moves);
	destroiMatriz(tab,7);
	return 0;
	
}
