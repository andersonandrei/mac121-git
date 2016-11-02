#include <stdlib.h>
#include <stdio.h>

typedef struct n0 {
	char *info;
	int qnt;
	struct n0 *prox;
} celula;

typedef celula *apontador;

void imprimeLista (apontador inicio);

apontador busca (apontador inicio, char *x);

void insereInicio (apontador *inicio, char *x);

void insereFinal (apontador *inicio, char *x);

apontador insereOrdenado (apontador inicio, char *x);

apontador removeLista (apontador inicio, char *x);
int ordemAlfabetica (apontador a, apontador b) ;








