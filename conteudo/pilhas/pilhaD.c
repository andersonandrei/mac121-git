#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int topo;
	int *v;
	int tam;
} pilha;

pilha *criaPilha (int n) {
	pilha *p;
	p = malloc (n * sizeof (pilha));
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
	if (pilhaVazia(p)) {
		printf("\n Erro: Pilha vazia");
		return 0;
	}
	else {
		int x = p->v[p->topo-1];
		p->topo--;
		return x;
	}
}

void empilha (pilha *p, int n) {
	printf("\n Entrou na func!");
	printf("\n Cheia/ R:%d",pilhaCheia(p));
	if (pilhaCheia (p) == 0) {
		p->v[p->topo] = n;
		p->topo++;
		fflush(stdout);
	}
	
	else {
		printf("\n Pilha cheia, tentaremos dobrar seu tamanho.\n");
		p = realloc (p, (p->tam)* 2 * sizeof(pilha));
		if( p == NULL) {
			printf("\n É... não deu.");
			free(p);
		}
		else
			p->v[p->topo++] = n;
	}
	
	return;
}

int main() {
	pilha *pi;
	int tamanho;
	int i,j;
	
	printf("\n Comecemos a brincar com pilhas alocadas dinamicamente: \n");
	printf("\n Qual tamanho da pilha: \n");
	scanf("%d",&tamanho);
	
	pi = criaPilha (tamanho);
	printf("Criou! \n");
	
	j=10;
	
	printf("\n Cheia/ R:%d",!pilhaCheia(pi));
	empilha( pi, 10);
	printf("\n Empilhou!");	
	fflush(stdout);
	while (!pilhaCheia (pi)) {
		printf("\n Entrou");
		
		j++;
	}
	
	printf("Olha o topo: ");
	desempilha(pi);
	
	return 0;		
}

