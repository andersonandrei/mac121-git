#include "vetores.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int *criaVetor(int n) {
	int *v;
	v = malloc (n * sizeof(int));
	if (v != NULL)
		return v;
	return 0;
}

char **criaMatriz (int n) {
	int i;
	char **matriz;
	matriz = malloc (n*sizeof(char *));
	if(matriz != NULL)
		for (i=0; i<n; i++) {
			matriz[i] = malloc (n*sizeof(char));
			if(matriz[i] == NULL) printf("Impossivel\n");
		}
	return matriz;
}

void zeraMatriz(char **tab, int n) {
	int i,j;
	for(i=0; i< n; i++){
		for(j=0; j< n; j++){
			tab[i][j] = 0;
		}
	}
	return;
}

void imprimeMatriz(char **tab, int n) {
	int i,j;
	for (i=0; i<n; i++) {
		printf("\n");
		for(j=0; j<n; j++) {
			printf("%c",tab[i][j]);
		}
	}
	return;
}

void zeraVetorInt (int *v, int n) {
	int i;
	for (i = 0; i < n; i++)
		v[i] = 0;
	return;
}

void zeraMatrizChar (char **v, int n) {
	int i, j;
	for (i = 0; i < n; i++){
		for (j = 0; j < n; j++){
			v[i][j] = NULL;
		}
	}
	return;
}

void zeraVetorChar (char *v, int n) {
	int i;
	for (i = 0; i < n; i++)
			v[i] = NULL;
	return;
}

void destroiVetor (int *v) {
	free(v);
	return;
}

void imprimeVetor (int *v, int n) {
	int i;
	for (i = 0; i < n; i++)
		printf("%d ",v[i]);
	return ;
}

int checaOrdenado (int *v, int n) {
	int i;
	for (i = 0; i < n-1; i++){
		if (v[i+1] < v[i])
			return 0;
	}
	return 1;
}

void destroiMatriz(char **tab, int n){
	int i;
	for(i=0;i < n;i++)
		free(tab[i]);
	free(tab);
	return;
}

int buscaElemento (char **v, int n, char *palavra) {
	int i, k;
	for (k=0; k<strlen(palavra); k++) { printf("%c",palavra[k]); fflush(stdout);}
	for (i = 0; i < n && strcmp(v[i], palavra) != 0; i++) {}
	if ( i >= n ) return -1;
	return i;
}

void insereVetor (char **v, int *w, int n, char *ch) {
	char **aux;
	int *aux2;
	int i, j, k, busca;
	aux = criaMatriz (n+1);
	aux2 = criaVetor (n+1);
	
	zeraMatriz(aux, n+1);
	zeraVetorInt(aux2, n+1);
	
	busca = buscaElemento (aux, n, ch);
	if (busca > 0) {
		w[busca] ++;
		return;
	}
	else {
		for (i = 0; i < n; i++) {
			strcpy(aux[i], v[i]);
			aux2[i] = w[i];
		}
		strcpy(aux[n],ch);
		aux2[n] = 1;
		
		
		v = criaMatriz(n+1);
		v = aux;
		imprimeMatriz (v, n+1);
		w = criaVetor(n+1);
		w = aux2;
	}
	
	return;
}

void imprimeVetorFreq (char **v, int *w, int n) {
	int i,j;
	for (i = 0; i < n; i ++) {
		printf("\n");
		for (j = 0; j < n; j++) {
			printf("%c",v[i][j]);
		}
		printf(" : %d", w[i]);
	}
	return;

}



int ordemAlfabeticaVetores (char *a, char *b) {
	/* Retorna 0 se o certo for o primeiro e 1 c.contrario */
	int aux;
	aux = strcmp (a , b);
	if (aux > 0 ) return 1;
	return 0;
}

insereOrdenadoVetor (char **v, int *w, int n, char *ch) {
	char **aux, i;
	int *aux2, j, pos;
	aux2 = malloc (n+1 * sizeof( int ) );
	
	pos = buscaElemento (v, n, ch);
	if (pos >= 0) {
		w[pos] ++;
		return pos;
	}
	else {
		i = 0;
		while ((i < n) && (ordemAlfabeticaVetores(v[i], ch) == 0)) {
			i++;
		}
		if (i >= n ) {
			insereVetor (v, w, n, ch);
		}
		else {
			aux = malloc (n+1 * sizeof (char) );
			for (j = 0; j < i; j++) {
				aux[j] = v[j];
				aux2[j] = w[j];
			}
			aux[j+1] = ch;
			aux2[j+1] = 1;
			for (j = 1; j < n; j++) {
				aux[j+1] = v[j];
				aux2[j+1] = w[j];
			}
			free (v);
			free (w);
			v = aux;
			w = aux2;
		}
	}

	return n+1;

}
