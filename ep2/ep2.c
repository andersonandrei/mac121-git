#include "pilhas.h"
#include "matrizes.h"
#include "movimentos.h"
#include <stdio.h>
#include <stdlib.h>

int restaN (int **tab, int lin, int col);

int main () {
	int i,j;
	int **tab;
	int m,n;
	int resta;
	
	printf("Insira m,n: ");
	scanf("%d %d",&m,&n);
	
	tab = criaMatriz(m,n);
	
	for (i = 0 ; i < m; i++) {
		printf("\n");
		for (j=0; j < n; j++) {
			scanf("%d",&tab[i][j]);
		}
	}

	imprimeMatriz(tab,m,n);
	
	printf("\n Resta um : ");
	resta = restaN(tab, m, n);
	printf("\n Resultado = %d\n",resta);
	
	return 0;
}

int restaN (int **tab, int lin, int col) {
	pilha *moves; /* Pilha de movimentos*/
	movimento mov; /* Gerenciador de movimentos */
	int i, j; /*Variaveis para auxiliar nos laços*/
	int m; /*Controlador do movimento*/
	int l, c; /* Controlar linhas e colunas */
	int ok, moveu; /* Flags verificadores de condições */
	int **tabInversa; /* Tabuleiro final que deve-se chegar */
	int espacos, pecas; 
	int iguais; /* Controlador da verificação de matrizes iguais */
	int tamPilha = 0; /* Tamanho da pilha */
	int jogadas, jogadasMax; /* Controladores dos números de jogadas */
	
	espacos = pecas = 0;
	
	/* Verificação da quantidade de peças*/
	for (i = 0; i < lin; i++) {
		for (j = 0; j < col; j++){
			if(tab[i][j] == 1)
				pecas++;
			if(tab[i][j] == -1)
				espacos++;
		}
	}
	jogadas = 0;
	jogadasMax = pecas - espacos;
	moves = criaPilha(500);
	tabInversa = criaMatriz(lin,col);
	inverteMatriz(tab,tabInversa,lin,col);
	l = c = 0;
	moveu = m = 0;
	if(pecas < espacos) {
		printf("Impossivel.\n");
		return 0;
	}
	iguais = comparaMatriz(tab,tabInversa,lin,col);
	while (iguais == 0) {
		ok = 0;
		while (c < col && ok == 0 && jogadas < jogadasMax) {
			if (tab[l][c] == 1) {
				while (m < 4 && moveu == 0) {
					if (podeMover(tab, l, c, m, lin, col)) {
						ok = 1;
						moveu = 1;
					}
					else {
						m++;
					}
				}
			}
			/* Se saiu do while à cima então m = 4 ou moveu = 1 */
			if (moveu == 0) { /* Então m = 4*/
				m = 0;
				if (c == col-1 && l <= lin-2) {
					l++;
					c = 0;
				}
				else c++;
			}			
		}
		/* Se saiu do while (2º à cima) então 
		 * c = col ou ok = 1 ou jogadas = jogadasMax  */
		if (ok == 1) {
			movePeca(tab, &l, &c, m, &espacos, &pecas);
			mov.l = l;
			mov.c = c;
			mov.mv = m;
			empilha(moves, mov, &tamPilha);
			jogadas++;
			l = 0;
			c = 0;
			m = 0;
			moveu = 0;
		}
		else { /* Backtrack */
			if (pilhaVazia(moves) == 1) {
				printf("Impossivel.\n");
				destroiMatriz(tab, lin, col);
				destroiPilha(moves);
				return 0;
			}
			else {
				desempilha(moves, &mov, &tamPilha);
				voltaPeca(tab, &(mov.l), &(mov.c), mov.mv, &espacos, &pecas);
				jogadas--;
				c = mov.c;
				l = mov.l;
				if (mov.mv < 3) {
					m = mov.mv + 1;
				}
				else { 
					m = 0;
					if (c == col-1 && l <= lin-2) {
						l ++;
						c = 0;
					}
					else c++;
				}
			}
		}
		iguais = comparaMatriz(tab, tabInversa, lin, col);
	}
	imprimeMatriz(tab, lin, col);
	destroiPilha(moves);
	destroiMatriz(tab, lin, col);
	return 1;
}
