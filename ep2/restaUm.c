#include "pilhas.h"
#include "matrizes.h"
#include "movimentos.h"
#include <stdio.h>
#include <stdlib.h>

/* Recebe um ponteiro de uma matriz de inteiros e dois inteiros
 * representando sua dimensão e imprime os passos caso for possível 
 * inverter os 1s e -1s de tab, ou 0, caso contrário.*/
void restaN (int **tab, int lin, int col);

int main () {
	int i,j;
	int **tab;
	int m,n;
	scanf("%d %d",&m,&n);
	tab = criaMatriz(m,n);
	for (i = 0 ; i < m; i++) {
		for (j=0; j < n; j++) {
			scanf("%d",&tab[i][j]);
		}
	}
	restaN(tab, m, n);
	return 0;
}

void restaN (int **tab, int lin, int col) {
	pilha *moves; /* Pilha de movimentos*/
	movimento mov; /* Gerenciador de movimentos */
	int i, j; /*Variaveis para auxiliar nos laços*/
	int m; /*Controlador do movimento*/
	int l, c; /* Controlar linhas e colunas */
	int ok, moveu; /* Flags verificadores de condições */
	int **tabInversa; /* Tabuleiro final que deve-se chegar */
	int espacos, pecas; 
	int iguais; /* Controlador de matrizes iguais */
	int jogadas, jogadasMax; /* Controladores dos números de jogadas */
	int *saida; /* Vetor para alterar a ordemd e saida da pilha */
	
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
	saida = criaVetor(jogadasMax * 4 + 1);
	moves = criaPilha(100);
	tabInversa = criaMatriz(lin,col);
	inverteMatriz(tab,tabInversa,lin,col);
	l = c = 0;
	moveu = m = 0;
	if(pecas < espacos) {
		printf("Impossivel\n");
		return;
	}
	iguais = comparaMatriz(tab,tabInversa,lin,col);
	while (iguais == 0) {
		ok = 0;
		while (c < col && ok == 0) {
			if (tab[l][c] == 1) {
				while (m < 4 && moveu == 0 && jogadas < jogadasMax) {
					if (podeMover(tab, l, c, m, lin, col)) {
						ok = 1;
						moveu = 1;
					}
					else 
						m++;
				}
			}
			/* Se saiu do while à cima então m = 4 ou moveu = 1 */
			if (moveu == 0) { /* Então m = 4*/
				m = 0;
				if (c == col - 1 && l <= lin - 2) {
					l++;
					c = 0;
				}
				else 
					c++;
			}			
		}
		/* Se saiu do while (2º à cima) então 
		 * c = col ou ok = 1 ou jogadas = jogadasMax  */
		if (ok == 1) {
			movePeca(tab, &l, &c, m, &espacos, &pecas);
			mov.l = l;
			mov.c = c;
			mov.mv = m;
			empilha(moves, mov);
			jogadas++;
			l = 0;
			c = 0;
			m = 0;
			moveu = 0;
		}
		else { /* Backtrack */
			if (pilhaVazia(moves) == 1) {
				printf("Impossivel\n");
				destroiMatriz(tab, lin, col);
				destroiPilha(moves);
				return;
			}
			else {
				desempilha(moves, &mov);
				voltaPeca(tab, &(mov.l), &(mov.c), mov.mv, &espacos, &pecas);
				jogadas--;
				c = mov.c;
				l = mov.l;
				if (mov.mv < 3)
					m = mov.mv + 1;
				
				else { 
					m = 0;
					if (c == col - 1 && l <= lin - 2) {
						l++;
						c = 0;
					}
					else 
						c++;
				}
			}
		}
		iguais = comparaMatriz(tab, tabInversa, lin, col);
	}
	
	/* Imprimir o estado final da pilha */
	i=0;
	while (!pilhaVazia(moves)) {
		desempilha(moves, &mov);
		l = mov.l;
		c = mov.c;
		voltaPeca(tab, &(mov.l), &(mov.c), mov.mv, &espacos, &pecas);
		saida[i+1] = mov.l;
		saida[i+2] = mov.c;
		saida[i+3] = l;
		saida[i+4] = c;
		i+=4;
	}
	for(j=i; j>2;j-=4)
		printf("%d:%d-%d:%d\n", saida[j-3], saida[j-2], saida[j-1], saida[j]);
		
	destroiPilha(moves);
	destroiVetor(saida);
	destroiMatriz(tab, lin, col);
	return;
}
