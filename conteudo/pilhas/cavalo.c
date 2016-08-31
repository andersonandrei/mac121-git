#include "pilhaD.h"
#include <stdio.h>
#include <stdlib.h>

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

int podePular(int **tab, int l, int c, int mov, int n) {
	
	if ((mov == 1) && (l-1>=0) && (c+2 < n) && (tab[l-1][c+2] == 0)) { return 1;  }
	else if (mov == 2 && l-2>=0 && c+1 < n && tab[l-2][c+1] == 0){ return 1;  }
	else if (mov == 3 && l-2>=0 && c-1 >=0  && tab[l-2][c-1] == 0) { return 1;  }
	else if (mov == 4 && l-1>=0 && c-2 >=0 && tab[l-1][c-2] == 0) {  return 1;}
	else if (mov == 5 && l+1<n && c-2 >=0 && tab[l+1][c-2] == 0) { return 1;  }
	else if (mov == 6 && l+2<n && c-1 >=0 && tab[l+2][c-1] == 0) { return 1;  }
	else if (mov == 7 && l+1<n && c+2 < n && tab[l+1][c+2] == 0) { return 1;  }
	else if (mov == 8 && l+2<n && c +1 < n && tab[l+2][c+1] == 0) { return 1;  }
	else {return 0; }
}

void pula(int **tab, int *i, int *j, int mov, int n) {
	if (mov == 1 ){
		*i -=1;
		*j +=2;
	}
	else if (mov == 2 ){
		*i -=2;
		*j +=1;
	}
	else if (mov == 3 ){
		*i -=2;
		*j -=1;
	}
	else if (mov == 4 ){
		*i -=1;
		*j -=2;
	}
	else if (mov == 5 ){
		*i +=1;
		*j -=2;
	}
	else if (mov == 6 ){
		*i +=2;
		*j -=1;
		
	}
	else if (mov == 7 ){
		*i +=1;
		*j +=2;
	}
	else if (mov == 8 ){
		*i +=2;
		*j +=1;
	}
	return ;
}

void despula(int **tab, int *i, int *j, int mov, int n) {
	if (mov == 1){
		*i +=1;
		*j -=2;
	}
	else if (mov == 2 ){
		*i +=2;
		*j -=1;
	}
	else if (mov == 3 ){
		*i +=2;
		*j +=1;
	}
	else if (mov == 4){
		*i +=1;
		*j +=2;
	}
	else if (mov == 5 ){
		*i -=1;
		*j +=2;
	}
	else if (mov == 6 ){
		*i -=2;
		*j +=1;
	}	
	else if (mov == 7 ){
		*i -=1;
		*j -=2;
	}
	else if (mov == 8 ){
		*i -=2;
		*j -=1;
	}
	return ;
}

int main() {
	pilha *pulo;
	int **tabuleiro;
	int atual, n, mov, ok, cavl,cavc;
	cavl=cavc =0;
	printf("\n Vamos brincar com o pulo do cavalo.");
	fflush(stdout);
	n=10;
	tabuleiro = criaMatriz(n);
	if(tabuleiro == NULL) printf("\n Bosta suja");
	zeraMatriz(tabuleiro,n);
	imprimeMatriz(tabuleiro,n);
	pulo = criaPilha(n*n);
	if (pulo == NULL) printf("\n merda");
	tabuleiro[cavl][cavc] = 1;
	atual = 2;
	ok=0;
	while( atual <= n*n) {
		fflush(stdout);
		ok=0;
		fflush(stdout);
		while(mov <= 8 && ok == 0){
			fflush(stdout);
			if (podePular(tabuleiro,cavl,cavc,mov,n) == 1)
			{
				ok =1;
			}
			else
			{
				mov ++;
			}
		}
		if(ok ==1) {
			empilha(pulo,mov);
			pula(tabuleiro,&cavl,&cavc,mov,n);
			fflush(stdout);
			tabuleiro[cavl][cavc] = atual;
			atual++;
			mov = 1;
		}
		else { /* BakcTrack*/
			if(pilhaVazia(pulo) == 1) {
				printf("\n Deu ruim.");
				destroiPilha(pulo);
				destroiMatriz(tabuleiro,n);
				return 0;
			}
			else { 
				printf("\n Despula: ");
				mov = desempilha(pulo);
				tabuleiro[cavl][cavc] = 0;
				despula(tabuleiro,&cavl,&cavc,mov,n);
				atual--;
				mov++;
				
			}
		}
		imprimeMatriz(tabuleiro,n);
		printf("\n");
		fflush(stdout);
	}
	imprimeMatriz(tabuleiro,n);
	destroiPilha(pulo);
	destroiMatriz(tabuleiro,n);

	return 0;
}
