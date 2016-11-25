#include <stdlib.h>
#include <stdio.h>
#include "listasL.h"

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
	return;
}

void insereFinal (apontador *inicio, int x) {
	apontador p, ant, novo;
	p = *inicio;
	novo = malloc (sizeof (celula) );
	novo -> info = x;
	novo -> prox = NULL;
	while (p != NULL) {
		ant = p;
		p = p -> prox;
	}
	if (*inicio == NULL)
		*inicio = novo;
	else 
		ant -> prox = novo;
	return;
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

polinomio somaPolinomio (polinomio um, polinomio dois) {
	polinomio novo, p, q, raiz, soma;
	
	if (um == NULL && dois == NULL) return NULL;
	if (um == NULL && dois != NULL) return dois;
	if (um != NULL && dois == NULL) return um;
	
	soma = malloc (sizeof (celula) );
	soma -> prox = NULL;	
	soma -> grau = soma -> coef = 	0;
	raiz = soma;
	p = um -> prox;
	q = dois -> prox;
	
	while (p != um && q != dois) {
		printf("\n Entrou pros diferentes: %d e %d", p -> grau, q -> grau);
		novo = malloc (sizeof (termo) );
		if (p -> grau == q -> grau) {
			printf("\n iguais");
			novo -> grau = p -> grau;
			novo -> coef = (p -> coef) + (q -> coef);
			novo -> prox = NULL;
			soma -> prox = novo;
			p = p -> prox;
			q = q -> prox;
		}
		
		else if (p -> grau < q -> grau) {
			novo -> grau = p -> grau;
			novo -> coef = (p -> coef);
			novo -> prox = NULL;
			soma -> prox = novo;
			p = p -> prox;
		}
		
		else {
			novo -> grau = q -> grau;
			novo -> coef = (q -> coef);
			novo -> prox = NULL;
			soma -> prox = novo;
			q = q -> prox;
		}
		
		soma = soma -> prox;
	}
	
	while (p != um) {
		printf("\nEntrou só pro p");
		novo = malloc (sizeof (termo) );
		novo -> grau = p -> grau;
		novo -> coef = (p -> coef);
		novo -> prox = NULL;
		soma -> prox = novo;
		p = p -> prox;
		soma = soma -> prox;
	}
	
	while (q != dois) {
		printf("\nEntrou só pro q");
		novo = malloc (sizeof (termo) );
		novo -> grau = q -> grau;
		novo -> coef = (q -> coef);
		novo -> prox = NULL;
		soma -> prox = novo;
		q = q -> prox;
		soma = soma -> prox;
	}
	
	soma -> prox = raiz;
	return soma;
}

polinomio insereTermoInicio (polinomio fim, int grau, int coef) {
	polinomio novo;
	if (fim == NULL) return NULL;
	novo = malloc (sizeof (termo) );
	novo -> prox = fim -> prox ;
	novo -> grau = grau;
	novo -> coef = coef;
	fim -> prox = novo;
	return fim;
}

void imprimePolinomio (polinomio fim) {
	polinomio p;
	if ( fim == NULL) return;
	for (p = fim -> prox; p!= fim; p = p -> prox){
		printf("(%dx ^ %d) +", p -> coef, p -> grau);
	}
	if (p-> coef != 0) printf("(%dx ^ %d)", p -> coef, p -> grau);
	return;
}

apontador inverte (apontador inicio) {
	apontador ant, p, novo, raiz;
	int j,i = 0;
	if (inicio == NULL) return inicio;
	p = inicio;
	ant = NULL;
	for (p = inicio; p!= NULL; p = p -> prox) {
		ant = p;
		i++;
	}
	novo = raiz = ant;
	j = 0;
	while (i > 1) {
		j = 0;
		for (p = inicio; p != raiz ; p = p->prox) {
			ant = p;
			j++;
		}
		raiz -> prox = ant;
		raiz = ant;
		i--;
	}
	raiz -> prox = NULL;
	return novo;
	
}




