#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "listasL.h"

void imprimeLista (apontador inicio) {
	/*Varre a partir do inicio todas as 
	 * listas imprimindo info de cada */
	
	apontador i;
	int j;
	printf("\nLista de palavras: \n\n");
	for (i = inicio; i != NULL ; i = i -> prox) {
		for (j = 0; i -> info[j] != '\0'; j++){
			printf ("%c", i -> info[j]);
		}
		printf(" : %d \n", i -> qnt);
	}
	printf ("\n");
}

apontador busca (apontador inicio, char *x) {
	apontador i;
	fflush(stdout);
	for (i = inicio; i != NULL && strcmp(i -> info,x) != 0; i = i -> prox) {}
	return i;
}

void insereInicio (apontador *inicio, char *x) {
	apontador novo, aux, p, ant;
	novo = malloc ( sizeof (celula) );
	novo -> info = malloc (100 * sizeof	(char) );
	aux = malloc (sizeof (celula) );
	aux -> info = malloc (100 * sizeof	(char) );
	aux = busca (*inicio, x);
	if (aux != NULL) {
		(aux -> qnt)++;
	}
	else {
		strcpy(novo -> info, x);
		novo -> qnt = 1;
		p = *inicio;
		ant = NULL;
		while (p != NULL && ordemAlfabetica(p, novo) > 0) {
			ant = p;
			p = p -> prox;
		}
		if (ant == NULL) *inicio = novo;
		else ant -> prox = novo;
		novo -> prox = p;
	}
}

void insereFinal (apontador *inicio, char *x) {
	apontador i;
	i = *(inicio);
	while (i != NULL) {
		i = i -> prox;
	}
	i = malloc (sizeof (celula) );
	i -> info = malloc (100 * sizeof (celula) );
	strcpy(i -> info, x);
	i -> prox = NULL;
}

apontador insereOrdenado (apontador inicio, char *x) {
	apontador p, novo, ant;
	int i;
	novo = malloc (sizeof (celula) );
	for (i = 0; x[i] != '\0'; i++)
		novo -> info[i] = x[i];
	p = inicio;
	ant = NULL;
	while (p != NULL && p -> info < x) {
		ant = p;
		p = p -> prox;
	}
	if (ant == NULL) inicio = novo;
	else ant -> prox = novo;
	novo -> prox = p;
	return inicio;
}

apontador removeLista (apontador inicio, char *x) {
	apontador ant, p;
	p = inicio;
	ant = NULL;
	while (p != NULL && p -> info != x) {
		ant = p;
		p = p -> prox;	
	}
	if (p == NULL) return inicio; /* Chegou no fim e não achou */
	if (ant == NULL) inicio = p -> prox;
	else ant -> prox = p -> prox;
	free (p);
	return inicio;
}

int ordemAlfabetica (apontador a, apontador b) {
	/* Retorna 0 se o certo for o primeiro e 1 c.contrario */
	int aux;
	aux = strcmp (a -> info, b -> info);
	if (aux > 0 ) return 1;
	return 0;
}







