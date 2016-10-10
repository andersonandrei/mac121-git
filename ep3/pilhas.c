#include "pilhas.h"
#include <stdlib.h>
#include <stdio.h>

pilha *criaPilha (int n) {
	pilha *p;
	p = malloc (sizeof (pilha));
	p->v = malloc(n * sizeof(int));
	p->tam = n;
	p->topo = 0;
	return p;
}

int pilhaVazia(pilha *p) {
	return p->topo == 0;
}

int pilhaCheia (pilha *p) {
	return p->topo == p->tam; 
}

int desempilha (pilha *p) {
	int auxi;
	auxi = p->v[p->topo-1];
	p->topo--;
	return auxi;
}

void empilha (pilha *p, int indice) {
	if (pilhaCheia(p)) {
		p->v = realloc (p->v, (2 * (p->tam)) * sizeof(int));
		if (p == NULL) {
			return;
		}
	}
	p->v[p -> topo] = indice;
	p->topo++;
	return;
}

void destroiPilha(pilha *p){
	free(p->v);
	free(p);
	return;
}
