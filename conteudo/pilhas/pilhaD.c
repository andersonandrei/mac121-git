#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int topo;
	int *p;
} pilha;

pilha *criaPilha (int n) {
	pilha *p;
	p = malloc (n * sizeof (pilha));
	p->topo = 0;
	return p;
}

void pilhaVazia( pilha *p) {
	return p->topo == 0;
}

int desempilha (pilha *p) {
	if (pilhaVazia (*p)) {
		printf("\n Erro: Pilha vazia");
	}
	else {
		
	}

}
