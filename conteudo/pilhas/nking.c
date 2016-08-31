#include "pilhaD.h"
#include <stdio.h>
#include <stdlib.h>

int **criaMatriz(n) {
	int i;
	int **matriz;
	matriz = malloc (n*sizeof(int*));
	for (i=0; i<n; i++) 
		matriz[i] = malloc (n*sizeof(int));
	return matriz;
}

void destroiMatriz(int **tab, int n){
	int i,j;
	for(i=0;i<n;i++)
		free(tab[i]);
	free(tab);
	return; 
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

int livre(int **tab, int l, int c, int n) {
	int i,linSec,colSec,linPrinc,colPrinc;
	printf("\n Livre recebeu > %d,%d",l,c);
	/* Retroceder ei para os primeiros elementos de cada diagonal */
	linPrinc=l;
	colPrinc=c;
	for(i=0;i<n && l-i > 0 && c-i >0; i++){
		linPrinc-=1;
		colPrinc-=1;
	}
	
	linSec=l;
	colSec=c;
	for(i=0;i<n && l-i > 0 && c+i < n; i++){
		linSec-=1;
		colSec+=1;
	}
	
	printf("\n Foi reduzido na Pricipal pra %d,%d e %d,%d",linPrinc,colPrinc,linSec,colSec);
	
	/* Verifica linha livre */
	for(i=0;i<n;i++)
		if (tab[l][i] == 1) return 0;
	/* Verifica coluna livre */
	for(i=0;i<n;i++)
		if (tab[i][c] == 1) return 0;
	/* Diagonal principal*/
	for(i=0; i<n && linPrinc+i< n && colSec-i >=0 ; i++){
		printf("\n Fuçando %d,%d",linPrinc+i,colPrinc+i);
		if(tab[linPrinc+i][colPrinc+i]==1) return 0;
	}
	/* Diagonal secundária*/
	printf("\n Aqui");
	for(i=0;i<n && linSec+i <n && colSec-i >=0; i++){
		printf("\n Fuçando %d,%d",linPrinc+i,colPrinc-i);
		if(tab[linSec+i][colSec-i]==1) return 0;
	}
	return 1;
}

int main() {
	int **tabuleiro;
	pilha *colunas;
	int col,rainha,n,i,j,ok=0;
	n=6;
	tabuleiro = criaMatriz(n);
	if(tabuleiro == NULL) {
		printf("\n Alocou nao,sorry.");
		return 0;
	}
	colunas = criaPilha(n);
	if (colunas == NULL) {
		printf("\n Pilha a i não pertence.");
		return 0;
	}
	
	printf("Brincando com as N-Kings\n");
	for (i=0; i<n; i++)
		for(j=0; j<n; j++)
			tabuleiro[i][j] = 0;
	rainha = 0;
	i=0;
	col=0;
	while (rainha < n) {
		ok=0;
		printf("\n Entrou 1");
		while (col < n && ok == 0) {
			printf("\n entrou 2 com %d, %d",rainha,col);
			if(livre(tabuleiro,rainha,col,n) == 1) {
				printf("\n Verificou pra %d,%d",rainha,col);
				printf("\n ok");
				ok = 1;
			} 
			else col++;
		} 
		printf("\n saiu 2");
		if (ok == 1) {
			printf("\n if 1");
			tabuleiro[rainha][col] = 1;
			empilha(colunas,col);
			rainha++;
			col = 0;
		}
		else {
			printf("\n else");
			
			if(pilhaVazia(colunas) == 1) {
				printf("\n Deu ruim.");
				destroiPilha(colunas);
				destroiMatriz(tabuleiro,n);
				return 0;
			}
			else {
				printf("\n else do else -- Tirou");
				col = desempilha(colunas);
				rainha --;
				printf("\n Tentando por %d,%d",rainha-1,col);
				tabuleiro[rainha][col] = 0;
				col++;
			}
		}
		
	}
	printf("\n Mapa final: ");
	imprimeMatriz(tabuleiro,n);
	destroiPilha(colunas);
	destroiMatriz(tabuleiro,n);

	
	return 0;
}



