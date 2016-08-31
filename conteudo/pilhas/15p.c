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

int podeMover(int **tabuleiro, int i, int j, int m){
	int n=4;
	if(m==1 && i-1>0) return 1;
	else if(m==2 && j-1 >0) return 1;
	else if(m==3 && j+1 < n) return 1;
	else if(m==4 && i+1 < n) return 1;
	return 0;
}

void movePeca (int **tabuleiro,int *l,int *c,int atual){
	int aux;
	if (atual == 1) {
		aux = tabuleiro[*l-1][*c];
		tabuleiro[*l-1][*c] = -1;
		tabuleiro[*l][*c] = aux;
		*l-=1;
	}
	else if (atual == 2) {
		aux = tabuleiro[*l][*c-1];
		tabuleiro[*l][*c-1] = -1;
		tabuleiro[*l][*c] = aux;
		*c-=1;
	}
	else if (atual == 3) {
		aux = tabuleiro[*l+1][*c];
		tabuleiro[*l+1][*c] = -1;
		tabuleiro[*l][*c] = aux;
		*l+=1;
	}
	else {
		aux = tabuleiro[*l][*c+1];
		tabuleiro[*l][*c+1] = -1;
		tabuleiro[*l][*c] = aux;
		*c+=1;
	}
	return;
}

void voltaPeca (int **tabuleiro,int *l,int *c,int atual){
	int aux;
	if (atual == 1) {
		aux = tabuleiro[*l+1][*c];
		tabuleiro[*l+1][*c] = -1;
		tabuleiro[*l][*c] = aux;
		*l+=1;
	}
	else if (atual == 2) {
		aux = tabuleiro[*l][*c+1];
		tabuleiro[*l][*c+1] = -1;
		tabuleiro[*l][*c] = aux;
		*c+=1;
	}
	else if (atual == 3) {
		aux = tabuleiro[*l-1][*c];
		tabuleiro[*l-1][*c] = -1;
		tabuleiro[*l][*c] = aux;
		*l-=1;
	}
	else {
		aux = tabuleiro[*l][*c-1];
		tabuleiro[*l][*c-1] = -1;
		tabuleiro[*l][*c] = aux;
		*c-=1;
	}
	return;
}

int ordenado (int **tab) {
	int v[16],k,i,j,n=4;
	k=0;
	for (i=0;i<n;i++){
		for (j=0;j<n;j++){
			v[k] = tab[i][j];
			k++;
		}
	}
	printf("\n Tai o vetor que rep. a matriz :\n");
	for (i=0;i<16;i++) printf("%d ",v[i]);
	
	for (i=0;i<15;i++) {
		if (v[i] > v[i+1]) return 0;
	}
	
	return 1;
}

int main(){
	int **tabuleiro;
	pilha *mov;
	int i,j,ok,atual,l,c,n,ordem;
	n=4;
	tabuleiro = criaMatriz(n);
	if (tabuleiro == NULL) printf("\n Fodeu matriz");
	
	tabuleiro[0][0] = 3;
	tabuleiro[1][0] = 2;
	tabuleiro[2][0] = 1;
	tabuleiro[3][0] = 4;
	tabuleiro[0][1] = 5;
	tabuleiro[1][1] = -1;
	tabuleiro[2][1] = 11;
	tabuleiro[3][1] = 8;
	tabuleiro[0][2] = 9;
	tabuleiro[1][2] = 7;
	tabuleiro[2][2] = 10;
	tabuleiro[3][2] = 12;
	tabuleiro[0][3] = 13;
	tabuleiro[1][3] = 14;
	tabuleiro[2][3] = 6;
	tabuleiro[3][3] = 15;
	
	mov = criaPilha(16);
	if (mov == NULL) printf("\n Fodeu pilha");
	
	for (i=0;i<n;i++)
		for(j=0;j<n;j++)
			if(tabuleiro[i][j] == -1) {
				l=i;
				c=j;
			}
			
	printf("\n A casa vazia e : %d,%d", l, c);
	atual = 1;
	ok=0;
	printf("\n antes");
	ordem = ordenado(tabuleiro);
	printf("\n depois");
	while (atual <= 4 && ordem != 1){
		printf("\n Entrou , pos : %d,%d",l,c);
		atual = 1;
		ok=0;
		while (l>=0 && l<n && c>=0 && c<n && l!=3 && c!= 3 && ok == 0 && atual <=4) {
			printf("\n n ta la em baixo");
			if (podeMover(tabuleiro, l, c, atual) == 1) {
				ok=1;
				printf("\n moveu com %d",atual);
				atual++;
			}
			else ok =0;
		}
		
		if(ok == 1) {
			printf("\n movendo");
			empilha(mov,atual);
			movePeca (tabuleiro, &l, &c, atual);
			atual = 1;
			ordem = ordenado(tabuleiro);
		}
		else
		{
			if (pilhaVazia(mov) == 1) {
				printf("\n Deu ruim");
				return 0;
			}
			else {
				printf("\n desempilhando");
				atual = desempilha(mov);
				voltaPeca (tabuleiro, &l, &c, atual);
				atual++;
			}
		}
	}
	
	printf("\n Finish Him!");
	imprimeMatriz(tabuleiro,n);
	
	return 0;
}
