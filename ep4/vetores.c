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
	printf("\n Entrou pra busca de tamanho %d",n);
	fflush(stdout);
	for (k=0; k<strlen(palavra); k++) { printf("%c",palavra[k]); fflush(stdout);}
	
	for (i = 0; i<n; i++) {
		printf("\n Posição %d",i);
		for (k=0; k < strlen(v[i]); k++)
			printf("%c",v[i][k]);
		printf("\n");
	}
	
	
	for (i = 0; i < n && strcmp(v[i], palavra) != 0; i++) {}
	printf("\n Saiu do for, qual é %d e %d ",i,n);
	fflush(stdout);
	if ( i >=n ) return -1;
	return 0;
}

char ** insereVetor (char **v, int *w, int n, char *ch) {
	
	char **aux;
	int *aux2, i, pos = -1, k, j;
	
	printf("\n Insere vetor:  Entrou com \n");
	fflush(stdout);
	
	for (k=0;k<strlen(ch); k++) printf("%c",ch[k]);
	
	printf("\n Vai começar a alocar");
	fflush(stdout);
	
	aux = malloc (100 * sizeof (char *));
	for (i = 0; i < 100; i++) {
		aux[i] = malloc (100 * sizeof (char));
		if (aux[i] == NULL) printf("\n Nao alocou minis");
	}
	
	

	
	printf("\n Mallocou aux");
	fflush(stdout);
	
	aux2 = malloc (n+1 * sizeof (int) );
	printf("\n Mallocou aux2");
	fflush(stdout);
	
	printf("\n Mandou pra busca de tamanho %d",n);
	fflush(stdout);
	
	for (k=0;k<strlen(ch); k++) { printf("%c",ch[k]); fflush(stdout);}
	
	pos = buscaElemento (v, n, ch);
	printf("\n pos");
	fflush(stdout);
	
	if (pos >= 0) {
		printf("\n ifou");
		fflush(stdout);
		w[pos] ++;
		return v;
	}
	
	printf("\n saiu");
	fflush(stdout);

	zeraMatrizChar (aux, n+1);
	printf("\n zerou matriz");
	fflush(stdout);
	
	zeraVetorInt(aux2, n+1);
	printf("\n zerou");
	fflush(stdout);
	/*
	for (i = 0 ; i < strlen(ch); i++) {
		printf("\n copiou, %d", i);
		fflush(stdout);
		printf("\n Olhemos para, %c", aux[n][i] );
		fflush(stdout);
		aux[n][i] = ch[i];
		printf("\n mexeu com, %d, %d", n, i);
		fflush(stdout);
	}
	*/
	strcpy (aux[n],ch);
	printf("\n Copiou");
	fflush(stdout);
	
	aux2[n] = 1;
	printf("\n freq");
	fflush(stdout);
	
	free(w);
	w = malloc (n+1 * sizeof (int) );
	w = aux2;
	
	/*
	destroiMatriz (v, n);
	
	printf("\n Destruiu");
	fflush(stdout);
	
	v = malloc ((n+1) * sizeof (char *) );
	for (i=0; i<n+2; i++) {
		v[i] = malloc ((n+1) * sizeof (char) );
	}
	
	printf("\n Liberou");
	fflush(stdout);
	v = aux;
	
	*/
	return aux ;
}

int ordemAlfabeticaVetores (char *a, char *b) {
	/* Retorna 0 se o certo for o primeiro e 1 c.contrario */
	int aux;
	aux = strcmp (a , b);
	if (aux > 0 ) return 1;
	return 0;
}

int insereOrdenadoVetor (char **v, int *w, int n, char *ch) {
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
