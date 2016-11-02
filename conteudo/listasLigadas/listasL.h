#include <stdlib.h>
#include <stdio.h>

typedef struct n0 {
	int info;
	struct n0 *prox;
} celula;

typedef celula *apontador;

void imprimeLista (apontador inicio);

apontador busca (apontador inicio, int x);

void insereInicio (apontador *inicio, int x);

void insereFinal (apontador *inicio, int x);

apontador insereOrdenado (apontador *incio, int x);

apontador removeLista (apontador inicio, int x);
