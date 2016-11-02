#include <stdlib.h>
#include <stdio.h>

typedef struct n0 {
	int info;
	struct n0 *prox;
} celula;

typedef celula *apontador;

void imprimeLista (apontador inicio) {
	/*Varre a partir do inicio todas as 
	 * listas imprimindo info de cada */
	
	apontador i;
	for (i = inicio; i != NULL ; i = i -> prox)
		printf ("%d", i -> info);
	printf ("\n");
}

apontador busca (apontador inicio, int x) {
	apontador i;
	for (i = inicio; i != NULL && i -> info != x; i = i -> prox) {}
	return i;
}

void insereInicio (apontador *inicio, int x) {
	apontador novo;
	novo = malloc (sizeof (celula) );
	novo -> info = x;
	novo -> prox = *(inicio);
	*(inicio) = novo;
}

void insereFinal (apontador *inicio, int x) {
	apontador i;
	i = *(inicio);
	while (i != NULL) {
		i = i -> prox;
	}
	i = malloc (sizeof (celula) );
	i -> info = x;
	i -> prox = NULL;
}

apontador insereOrdenado (apontador inicio, int x) {
	apontador p, novo, ant;
	novo = malloc (sizeof (celula) );
	novo -> info = x;
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

apontador removeLista (apontador inicio, int x) {
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








