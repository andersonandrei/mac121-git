/* Vamos fazer pilhas */

#include <stdio.h>
#include <stdlib.h>
#define MAX 1000

/* Uma pilha deve ter: - Cria Pilha - Empilha - Desempilha - VerifVazia*/

typedef struct {
	int topo;
	int v[MAX];
} pilha;

pilha *criaPilha () {
	pilha *p;
	p = malloc (sizeof (pilha));
	p->topo = 0;
	printf("\nPilha criada com sucesso\n");
	return p;
} 

int pilhaVazia (pilha *p) {
	return p->topo == 0;
}

void empilha(pilha *p, int n){
	p->v[p->topo++] = n;
	return;
}

int desempilha (pilha *p) {
	int num;
	if (pilhaVazia(p)) {
		printf("\n Erro: Pilha vazai! \n");
		return 0;
	}
	else {
		num = p->v[p->topo-1];
		p->topo--;
		return num;
	}
}

void destroiPilha( pilha *p) {
	free (p);
	return;
}

int main() {
	pilha *pi;
	printf("\n Criou");
	pi = criaPilha();
	printf("Desempilha: %d\n",desempilha(pi));
	
	empilha(pi,10);
	printf("Desempilha: %d\n",desempilha(pi));
	
	printf("Desempilha: %d\n",desempilha(pi));
	
	
	return 0;
}


