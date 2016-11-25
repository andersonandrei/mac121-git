#include <stdlib.h>
#include <stdio.h>

typedef struct n0 {
	int info;
	struct n0 *prox;
} celula;

typedef struct t0 {
	int coef, grau;
	struct t0 *prox;
} termo;

typedef celula *apontador;

typedef termo *polinomio;

void imprimeLista (apontador inicio);

apontador busca (apontador inicio, int x);

void insereInicio (apontador *inicio, int x);

void insereFinal (apontador *inicio, int x);

apontador insereOrdenado (apontador incio, int x);

apontador removeLista (apontador inicio, int x);

polinomio somaPolinomio (polinomio um, polinomio dois);

polinomio insereTermoInicio (polinomio fim, int grau, int coef);

void imprimePolinomio (polinomio fim);

apontador inverte (apontador inicio);

