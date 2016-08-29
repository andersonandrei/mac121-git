#include "pilhaD.h"
#include <stdio.h>
#include <stdlib.h>

int **criaMatriz(n) {
	int i;
	int **matriz;
	matriz = malloc (n*sizeof(int));
	for (i=0; i<n; i++) 
		matriz[i] = malloc (n*sizeof(int));
	return matriz;
}

void destroiMatriz(int **tab){
	int i,j;
	for(i=0;i<n;i++)
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

int livre(int **tab, int l, int c, int n) {
	int i,linSec,colSec,linPrinc,colPrinc;
	
	/* Retroceder ei para os primeiros elementos de cada diagonal */
	linPrinc=l;
	colPrinc=c;
	for(i=0;i<n && linPrinc-i > 0 && colPrinc-i >0; i++){
		linPrinc-=1;
		colPrinc-=1;
	}
	
	linSec=l;
	colSec=c;
	for(i=0;i<n && linSec-i > 0 && colSec+i < n; i++){
		linSec-=1;
		colSec+=1;
	}
	
	printf("\n Reduzi ao max possivel, temos pra principal: %d,%d e secundaria %d,%d",linPrinc,colPrinc,linSec,colSec);
	
	imprimeMatriz(tab,n);
	fflush(stdout);
	/* Verifica linha livre */
	for(i=0;i<n;i++)
		if (tab[l][i] == 1) return 0;
	/* Verifica coluna livre */
	for(i=0;i<n;i++)
		if (tab[i][c] == 1) return 0;
	/* Diagonal principal*/
	for(i=0;i<n && linPrinc+i < n && colPrinc+i < n; i++){
		printf("\n Fuçando %d,%d",linPrinc+i,colPrinc+i);
		fflush(stdout);
		if(tab[linPrinc+i][colPrinc+i]==1) return 0;
	}
	/* Diagonal secundária*/
	printf("\n Aqui");
	fflush(stdout);
	for(i=0;i<n && linSec+i < n && colSec-i >=0; i++){
		printf("\n Fuçando %d,%d",linPrinc+i,colPrinc-i);
		fflush(stdout);
		if(tab[linSec+i][colSec-i]==1) return 0;
	}
	return 1;
}

int main() {
	int **tabuleiro;
	pilha *colunas;
	int col,rainha,n,i,j,ok=0;
	n=5;
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
		printf("\n Entrou 1");
		fflush(stdout);
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
			ok = 0;
			col = 0;
		}
		else {
			printf("\n else");
			
			if(pilhaVazia(*colunas) == 1) {
				printf("\n Deu ruim.");
				destroiPilha(colunas);
				destroiMatriz(tabuleiro);
				
				fflush(stdout);
				return 0;
			}
			else {
				printf("\n else do else -- Tirou");
				fflush(stdout);
				col = desempilha(colunas);
				fflush(stdout);
				rainha --;
				printf("\n Tentando por %d,%d",rainha-1,col);
				fflush(stdout);
				tabuleiro[rainha][col] = 0;
				
				col++;
			}
		}
		
	}
	printf("\n Mapa final: ");
	imprimeMatriz(tabuleiro,n);
	destroiPilha(colunas);
	destroiMatriz(tabuleiro);
	
	return 0;
}



