#include <stdio.h>
#include <stdlib.h>

#define MAX 7

void movePeca(int **tab,int p, int q, int mov, int *numBrancas, int *numPretas);
void voltaPeca(int **tab,int p, int q, int mov, int *numBrancas, int *numPretas);
void imprimeTabuleiro(int **tab, int n);
int restaUm(int m, int n, int **tab);
int podeMover(int **tab, int p, int q, int mov);
int **criaMatriz(int n);

int main() {
	int **tab;
	int i, j;
	int funfa;
	
	tab = criaMatriz(7);
	
	for (i = 0; i < 7; i++)
		for (j = 0; j < 7; j++)
			tab[i][j] = 0;
			
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
	
	imprimeTabuleiro(tab,7);

	funfa = restaUm (7, 7, tab);
	printf("\nResultado: %d\n",funfa);
	
	return 0;
}

/* 33 espaços, 32 ocupados */
int restaUm(int m, int n, int **tab) {
	int l,c;
	int i,j,p,q;
	int peca, atual, mov;
	int numBInic,numPInic,numBrancas, numPretas;
	int ok;
	
	printf("Recebeu : \n");
	imprimeTabuleiro(tab,7);
	
	numBInic = numBrancas = 1;
	numPInic = numPretas = 32;
	p = q = 0;
	atual = tab[p][q];
	ok = 1;
	
	/* while (numBrancas != numPInic && ok == 1){ */
	while (ok == 1) {
		/* Procurando por -1 */
		if(tab[p][q] == -1) {
			mov = 0;
			while (mov < 4) {
				if (podeMover(tab, p, q, mov) == 1) {
					movePeca(tab, p, q, mov, &numBrancas, &numPretas);
					if (restaUm(m, n, tab)) return 1;
					voltaPeca(tab, p, q, mov,&numBrancas, &numPretas);
				}
				mov++;
			}
		}
		q++;
		if (q == n-1) {
			if(p == n-1) ok = 0;
			else {
				p++;
				q = 0;
			} 
			
		}	
	}
	
	return 0;
}

int podeMover(int **tab, int p, int q, int mov) {
	if (mov == 0 && p >= 2 && tab[p][q] == 1) return 1;
	else if (mov == 1 && q >= 2 && tab[p][q] == 1) return 1;
	else if (mov == 2 && p < 7 && tab[p][q] == 1) return 1;
	else if (mov == 3 && q < 7 && tab[p][q] == 1) return 1;
	return 0;
	
}

void movePeca(int **tab,int p, int q, int mov, int *numBrancas, int *numPretas){
	if (mov == 0) {
		tab[p-2][q] = -1;
		tab[p-1][q] = -1;
		tab[p][q] = 1;
	}
	else if (mov == 1) {
		tab[p][q-2] = -1;
		tab[p][q-1] = -1;
		tab[p][q] = 1;
	}
	else if (mov == 2) {
		tab[p+2][q] = -1;
		tab[p+1][q] = -1;
		tab[p][q] = 1;
	}
	else if (mov == 3) {
		tab[p][q+2] = -1;
		tab[p][q+1] = -1;
		tab[p][q] = 1;
	}
	*numPretas -=1;
	*numBrancas += 1;
}

void voltaPeca(int **tab,int p, int q, int mov, int *numBrancas, int *numPretas){
	if (mov == 0) {
		tab[p-2][q] = 1;
		tab[p-1][q] = 1;
		tab[p][q] = -1;
	}
	else if (mov == 1) {
		tab[p][q-2] = 1;
		tab[p][q-1] = 1;
		tab[p][q] = -1;
	} 
	else if (mov == 2) {
		tab[p+2][q] = 1;
		tab[p+1][q] = 1;
		tab[p][q] = -1;
	}
	else if (mov == 3) {
		tab[p][q+2] = 1;
		tab[p][q+1] = 1;
		tab[p][q] = -1;
	}
	*numPretas +=1;
	*numBrancas -= 1;
}

void imprimeTabuleiro(int **tab, int n) {
	int i,j;
	for (i=0; i<n; i++) {
		printf("\n");
		for(j=0; j<n; j++) {
			printf("%d ",tab[i][j]);
		}
	}
	return;
}

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
