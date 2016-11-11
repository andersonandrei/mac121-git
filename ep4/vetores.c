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

char ** redimensionaMatriz(char **tab, int n) {
	int i , j;
	char **novo;
	novo = criaMatriz(n+10);
	zeraMatriz(novo, n+10);
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++)
			novo[i][j] = tab[i][j];
	}
	destroiMatriz(tab,n);
	return novo;
}

int * redimensionaVetor(int *vetor, int n) {
	int i , j;
	int *novo;
	novo = criaVetor((n+10));
	zeraVetorInt(novo,n+10);
	for (i = 0; i < n; i++) {
		novo[i] = vetor[i];
	}
	destroiVetor(vetor);
	return novo;
}

void zeraMatriz(char **tab, int n) {
	int i,j;
	for(i=0; i< n; i++){
		for(j=0; j< n; j++){
			tab[i][j] = ' ';
		}
	}
	return;
}

void imprimeMatriz(char **tab, int n) {
	int i,j;
	printf("\n Entrou");
	fflush(stdout);
	for (i=0; i<n; i++) {
		printf("\n Entrou imp i : %d",i);
		fflush(stdout);
		for(j=0; j<20; j++) {
			printf("\n Entrou imp j : %d",j);
			fflush(stdout);
			printf("%c",tab[i][j]);
		}
		printf("\n");
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

int comparaPalavras (char *p1, int tamP1, char *p2, int tamP2) {
	int i ;
	
	if (tamP1 != tamP2)
		return -1;
	
	for(i = 0; i < tamP1; i++) {
		if (p1[i] != p2[i])
			return -1;
	}
	return 0;
}

int buscaElemento (char **v, int n, char *palavra, int tamP) {
	int i, k, j, tamAux;
	char *auxP, *copia;
	auxP = malloc (100 * sizeof(char));
	printf("\n Voltou em n: %d",n);
	for (i = 0; i < n  && v[i][0] != ' '; i++) {
		printf("\n Entoru em i: %d",i);
		fflush(stdout);
		printf("\n Olha ai : %d",v[0][0]);
		fflush(stdout);
		for (j = 0 ; j < 20 && v[i][j] != ' '; j++) {
			printf("\n Entoru em j: %d",j);
			fflush(stdout);
			auxP[j] = v[i][j];
		}
		printf("\n Saiu do for");
		fflush(stdout);
		tamAux = j;
		if (comparaPalavras (auxP, tamAux, palavra, tamP) == 0)
			return i;
	}
	printf("\n saiu do for");
	fflush(stdout);
	return -1;
}

int insereVetor (char **v, int *w, int n, char *ch, int tamP) {
	int i, j, lin, col, k;
	int busca;
	
	busca = buscaElemento (v, n, ch, tamP);
	printf("\n Oi");
	fflush(stdout);
	if (n == 0) {
		for (j = 0; j < tamP; j++) {
			v[0][j] = ch[j];
			w[0] = 1;
		}
	}
	if (busca >= 0) {
		w[busca]++;
		return n ;
	}
	for (i = 0; i < n && v[i] != NULL; i++) {
		printf("\n Ta aqui em i: %d",i);
		fflush(stdout);
	}
	lin = i;
	printf("\n Saiu do ta aqui %d",i);
	fflush(stdout);
	if (lin >= n) {
		printf("\n Passou do tamanho : %d",lin);
		fflush(stdout);
		printf("\n realocando : %d",lin);
		v = redimensionaMatriz(v, n);
		w = redimensionaVetor(w, n);
		n += 10;
		imprimeMatriz(v, n);
		printf("\n realocoi");
		fflush(stdout);
	}
	
	printf("\n Bosta suja");
	fflush(stdout);
	for (j = 0; j < tamP; j++) {
		printf("\n Lin = %d e j =%d", lin, j);
		fflush(stdout);
		
		printf("\n Na matriz: no vetor:  e no char %c", ch[0]);
		fflush(stdout);
		v[lin][j] = ch[j];
		w[lin] = 1;
	}
	printf("\n Inseriu");
	imprimeMatriz(v,n);
	fflush(stdout);
	
	return n;
	
}

void imprimeVetorFreq (char **v, int *w, int n) {
	int i,j;
	for (i = 0; i < n && v[i][0] != ' '; i ++) {
		printf("\n");
		for (j = 0; j < n; j++) {
			printf("%c",v[i][j]);
		}
		printf(": %d", w[i]);
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

int insereOrdenadoVetor (char **v, int *w, int n, char *ch) {
	char **aux;
	int *aux2, i, j, pos;
	aux2 = malloc (n+1 * sizeof( int ) );
	
	pos = buscaElemento (v, n, ch, n);
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
			insereVetor (v, w, n, ch, i);
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
