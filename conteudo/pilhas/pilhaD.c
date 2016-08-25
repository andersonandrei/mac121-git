#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int topo;
	int *v;
	int tam;
} pilha;

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
	int x;
	if (pilhaVazia(p)) {
		printf("\n Erro: Pilha vazia");
		return 0;
	}
	else {
		x = p->v[p->topo-1];
		p->topo--;
		return x;
	}
}

void empilha (pilha *p, int n) {
	printf("\n Entrou com :%d",n);
	
	if (pilhaCheia(p)) {
		printf("\n Pilha cheia, vamos realocar com o dobro de espaço!");
		p->v = realloc (p->v, (2 * (p->tam)) * sizeof(int));
		if (p == NULL) {
			printf("\n Não foi possível realocar, sorry.");
			fflush(stdout);
			return;
		}
	}
	printf("\n Topo atual: %d",p->topo);
	p -> v[p -> topo] = n;
	p->topo++;
	printf("\n Topo agr: %d",p->topo);

	return;
}

int main() {
	pilha *pi;
	int tamanho;
	int j;
	
	printf("\n Comecemos a brincar com pilhas alocadas dinamicamente:");
	printf("\n Qual tamanho da pilha: \n");
	scanf("%d",&tamanho);
	
	pi = criaPilha (tamanho);
	printf("Criou! \n");
	
	j=10;
	empilha( pi, 10);
	empilha( pi, 11);
	empilha( pi, 12);
	
	printf("\n Empilhou: %d",pi->v[pi->topo-1]);

	printf("\nOlha o topo: %d ",desempilha(pi));
	
	
	return 0;		
}

