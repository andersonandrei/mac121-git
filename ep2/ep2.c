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
/*
void montaTabuleiro(int **tab) {
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

*/
void **inverteMatriz (int **tab, int **tabInversa, int n) {
	int i,j;
	for(i=0; i<n; i++) {
		for(j=0;j<n;j++) {
			if(tab[i][j] == 1) tabInversa[i][j] = -1;
			if(tab[i][j] == -1) tabInversa[i][j] = 1;
		}
	}
}

int comparaMatriz (int **tabA, int **tabB, int n) {
	int i,j;
	for(i=0;i<n;i++) {
		for(j=0;j<n;j++) {
			if (tabA[i][j] != tabB[i][j]) return 0;
		}
	}
	return 1;
}

int main() {
	pos posicao;
	pilha *moves;
	movimento mov;
	
	int i,j,lin,col,m,auxl,auxc;
	int ok,moveu;
	int **tab, **tabInversa;
	int numBrancas, numPretas;
	int iguais;
	
	numBrancas = 1;
	numPretas = 32;
	
	moves = criaPilha(1000);
	
	tab = criaMatriz(7);
	tabInversa = criaMatriz(7);
	
	inverteMatriz(tab,tabInversa,7);
	
	montaTabuleiro(tab);
	imprimeMatriz(tab,7);
	
	posicao.col = posicao.lin = 0;
	lin = col = moveu = 0;
	m = 0;
	
	iguais = comparaMatriz(tab,tabInversa,7);
	
	while (iguais == 0) {
		printf("\n Entrou lin = %d",lin);
		ok = 0;
		while (col < 7 && ok == 0) {
			printf("\n Entrou col = %d",col);
			printf("\n --->Linhas = %d",lin);
			printf("\n Entrou m =%d",m); 
			if (tab[lin][col] == -1) {
				printf("\nAchou\n");
				printf("\n antes mov= %d",m);
				while (m < 4 && moveu == 0) {
					printf("\n mov = %d",m);
					if (podeMover(tab,lin,col,m)){
						printf("\n Pode");
						ok = 1;
						moveu = 1;
					}
					else {
						printf("\n movimento++");
						m++;
					}
				}
				printf("\n Saiu do while dos mov");
			}
			/* Se saiu do while de dentro entao ok = 1 ou moveu = 0 */
			if (ok == 0) {
				m = 0;
				if (moveu == 0) {
					if (col == 6 && lin <= 5) {
						printf("\nCol == 6 -> lin++ col = 0\n");
						lin ++;
						col = 0;
					}
					else col++;
				}
				else {
					printf("\nsó col ++");
					col++;
				}
			}
			
		}
		printf("\n Parte dos ok");
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
			lin = 0;
			col = 0;
			m = 0;
			moveu = 0;
			printf("\n --->>>>>>>> m = %d,lin = %d, col = %d",m,lin,col);
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
			printf("\n backtack");
			fflush(stdout);
			if (pilhaVazia(moves) == 1) {
				printf("Acabaram as possibilidades.\n");
				destroiMatriz(tab,7);
				destroiPilha(moves);
				return 0;
			}
			
			else {
				printf("\n Voltou");
				desempilha(moves,&mov);
				voltaPeca(tab,&(mov.l),&(mov.c),mov.mv,&numBrancas,&numPretas);
				col = mov.c;
				lin = mov.l;
				if (mov.mv < 3) {
					m = mov.mv + 1;
					printf("\n Fui pro mov = %d",m);
				}
				else { 
					if (col == 6 && lin <= 5) {
						printf("\nCol == 6 -> lin++ col = 0\n");
						lin ++;
						col = 0;
					}
					else col++;
					m = 0;
					printf("\n Else: Fui pro mov = %d",m);
				}
				printf("\n --->>>>Col = %d Lin = %d ",col,lin);
			}
		}
		imprimeMatriz(tab,7);
		iguais = comparaMatriz(tab,tabInversa,7);

	}
	imprimeMatriz(tab,7);
	destroiPilha(moves);
	destroiMatriz(tab,7);
	return 0;
	
}
