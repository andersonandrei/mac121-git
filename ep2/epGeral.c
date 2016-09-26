#include "pilhaMov.h"
#include <stdio.h>
#include <stdlib.h>

/* Movimentos */

int podeMover(int **tab, int p, int q, int mov, int m, int n) {
	if (tab[p][q] == 1) {
		if (mov == 0 && p >= 2 && tab[p-1][q] == 1 && tab[p-2][q] == -1) return 1;
		else if (mov == 1 && q >= 2 && tab[p][q-1] == 1 && tab[p][q-2] == -1) return 1;
		else if (mov == 2 && p < m-2 && tab[p+1][q] == 1 && tab[p+2][q] == -1) return 1;
		else if (mov == 3 && q < n-2 && tab[p][q+1] == 1 && tab[p][q+2] == -1) return 1;
		else return 0;
	}
	else {
		return 0;
	}
}

void movePeca(int **tab,int *p, int *q, int mov, int *numBrancas, int *numPretas){
	if (mov == 0) {
		tab[*p-2][*q] = 1;
		tab[*p-1][*q] = -1;
		tab[*p][*q] = -1;
		*p -= 2;
	}
	else if (mov == 1) {
		tab[*p][*q-2] = 1;
		tab[*p][*q-1] = -1;
		tab[*p][*q] = -1;
		*q -= 2;
	}
	else if (mov == 2) {
		tab[*p+2][*q] = 1;
		tab[*p+1][*q] = -1;
		tab[*p][*q] = -1;
		*p += 2;
	}
	else if (mov == 3) {
		tab[*p][*q+2] = 1;
		tab[*p][*q+1] = -1;
		tab[*p][*q] = -1;
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

int **criaMatriz(int m, int n) {
	int i;
	int **matriz;
	matriz = malloc (m*sizeof(int *));
	if(matriz != NULL)
		for (i=0; i<m; i++) {
			matriz[i] = malloc (n*sizeof(int));
			if(matriz[i] == NULL) printf("\n n alocou matriz");
		}
	return matriz;
}

void zeraMatriz(int **tab, int m, int n) {
	int k,t;
	for(k=0; k< m; k++){
		for(t=0; t< n; t++){
			tab[k][t] = 0;
		}
	}
}

void destroiMatriz(int **tab, int m, int n){
	int i;
	for(i=0;i < m;i++)
		free(tab[i]);
	free(tab);
}

void imprimeMatriz(int **tab, int m, int n) {
	int i,j;
	for (i=0; i<m; i++) {
		printf("\n");
		for(j=0; j<n; j++) {
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

void **inverteMatriz (int **tab, int **tabInversa, int m, int n) {
	int i,j;
	for(i=0; i<m; i++) {
		for(j=0;j<n;j++) {
			if(tab[i][j] == 1) tabInversa[i][j] = -1;
			if(tab[i][j] == -1) tabInversa[i][j] = 1;
		}
	}
}

int comparaMatriz (int **tabA, int **tabB, int m, int n) {
	int i,j;
	for(i=0;i<m;i++) {
		for(j=0;j<n;j++) {
			if (tabA[i][j] != tabB[i][j]) return 0;
		}
	}
	return 1;
}

int restaUm(int **tab, int lin, int col) {
	pos posicao;
	pilha *moves;
	movimento mov;
	
	int i, j, m, auxl, auxc, l, c;
	int ok, moveu;
	int **tabInversa;
	int numBrancas, numPretas;
	int iguais;
	int tamPilha = 0;
	
	numBrancas = numPretas = 0;
	
	for (i = 0; i < lin; i++) {
		for (j = 0; j < col; j++){
			if(tab[i][j] == 1)
				numPretas++;
			if(tab[i][j] == -1)
				numBrancas++;
		}
	}
	
	moves = criaPilha(500);
	
	tabInversa = criaMatriz(lin,col);
	
	imprimeMatriz(tab,lin,col);
	
	inverteMatriz(tab,tabInversa,lin,col);
	imprimeMatriz(tabInversa,lin,col);
	
	posicao.col = posicao.lin = 0;
	l = c = moveu = 0;
	m = 0;
	
	iguais = comparaMatriz(tab,tabInversa,lin,col);
	
	while (iguais == 0) {
		printf("\n Entrou lin = %d",l);
		ok = 0;
		while (c < col && ok == 0) {
			printf("\n Entrou col = %d",c);
			printf("\n --->Linhas = %d",l);
			printf("\n Entrou m =%d",m); 
			if (tab[l][c] == 1) {
				printf("\nAchou\n");
				printf("\n antes mov= %d",m);
				while (m < 4 && moveu == 0) {
					printf("\n mov = %d",m);
					if (podeMover(tab,l,c,m,lin,col)){
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
				printf("\n ok == 0");
				m = 0;
				if (moveu == 0) {
					if (c == col-1 && l <= lin-2) {
						printf("\nCol == 2 -> lin++ col = 0\n");
						l++;
						c = 0;
					}
					else c++;
				}
				else {
					printf("\nsó col ++");
					c++;
				}
			}
			
		}
		printf("\n Parte dos ok");
		/* Ou ok = 1 ou = 0 */
		if (ok == 1) {
			printf("\n ok");
			posicao.lin = l;
			posicao.col = c;
			auxl = l;
			auxc = c;
			movePeca(tab,&auxl,&auxc,m, &numBrancas,&numPretas);
			mov.l = auxl;
			mov.c = auxc;
			mov.mv = m;
			empilha(moves,mov,&tamPilha);
			l = 0;
			c = 0;
			m = 0;
			moveu = 0;
			printf("\n --->>>>>>>> m = %d,lin = %d, col = %d",m,l,c);
			printf("\n --->>>>>>>> tamPilha = %d",tamPilha);
			/*
			if (col == 2 && lin <= 5) {
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
				destroiMatriz(tab,lin,col);
				destroiPilha(moves);
				return 0;
			}
			
			else {
				printf("\n Voltou");
				desempilha(moves,&mov,&tamPilha);
				printf("\n --->>>>>>>> tamPilha = %d",tamPilha);
				voltaPeca(tab,&(mov.l),&(mov.c),mov.mv,&numBrancas,&numPretas);
				c = mov.c;
				l = mov.l;
				if (mov.mv < 3) {
					m = mov.mv + 1;
					printf("\n Fui pro mov = %d",m);
				}
				else { 
					if (c == col-1 && l <= lin-2) {
						printf("\nCol == 2 -> lin++ col = 0\n");
						l ++;
						c = 0;
					}
					else c++;
					m = 0;
					printf("\n Else: Fui pro mov = %d",m);
				}
				printf("\n --->>>>Col = %d Lin = %d ",c,l);
			}
		}
		imprimeMatriz(tab,lin,col);
		iguais = comparaMatriz(tab,tabInversa,lin,col);

	}
	printf("\n Final");
	imprimeMatriz(tab,lin,col);
	destroiPilha(moves);
	destroiMatriz(tab,lin,col);
	return 1;
	
}

int main () {
	int i,j;
	int **tab;
	int m,n;
	int resta;
	
	/*
	printf("Insira m,n: ");
	scanf("%d %d",&m,&n);
	*/
	tab = criaMatriz(7,7);
	printf("\n >>>>>>>>>>>>>>>>>>>>Criou");
	/*
	printf("Insira a matrix de tamanho %d, %d\n",m,n);
	for (i = 0 ; i < m; i++) {
		printf("\n");
		for (j=0; j < n; j++) {
			scanf("%d",&tab[i][j]);
		}
		
	}
	*/
	montaTabuleiro77(tab);
	
	imprimeMatriz(tab,7,7);
	
	printf("\n Resta um : ");
	resta = restaUm(tab, 7, 7);
	printf("\n Resultado = %d\n",resta);
	
	return 0;

}
