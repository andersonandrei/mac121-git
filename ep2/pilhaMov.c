#include "pilhaMov.h"
#include <stdio.h>
#include <stdlib.h>

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

void desempilha (pilha *p, movimento *mov) {
	movimento auxm;
	if (pilhaVazia(p)) {
		printf("\n Erro: Pilha vazia");
	}
	else {
		auxm = p->v[p->topo-1];
		p->topo--;
		mov->mv = auxm.mv;
		mov->l = auxm.l;
		mov->c = auxm.c;
		printf("\n ---->>>>Desempilhou: lin = %d, col = %d, mov = %d",auxm.l,auxm.c,auxm.mv);
	}
}

void empilha (pilha *p, movimento n) {
	printf("\n Entrou pilha");
	fflush(stdout);
	if (pilhaCheia(p)) {
		printf("\n Pilha cheia, vamos realocar com o dobro de espaço!");
		p->v = realloc (p->v, (2 * (p->tam)) * sizeof(int));
		if (p == NULL) {
			printf("\n Não foi possível realocar, sorry.");
			return;
		}
	}
	printf("\n ---->>>>Empilhou: lin = %d, col = %d, mov = %d",n.l,n.c,n.mv);
	p->v[p -> topo] = n;
	p->topo++;
	return;
}

/*
int topoPilha(pilha *p) {
	return p->v[p->topo-1];
}

void imprimePilha(pilha *p) {
	while (pilhaVazia(p) == 0){
		printf("\n Aquiiii");
		printf("%d ",desempilha(p));
	}
	return;
}
*/

void destroiPilha(pilha *p){
	free(p->v);
	free(p);
	return;
}

/* main que fiz pra testar

int main() { return 0;}

int main() {
	pilha *pi;
	int tamanho;
	int j;
	
	printf("\n Comecemos a brincar com pilhas alocadas dinamicamente:");
	printf("\n Qual tamanho da pilha: \n");
	scanf("%d",&tamanho);
	
	pi = criaPilha (tamanho);
	
	j=10;
	while (j>1) {
		empilha(pi,j);
		j--;
	}
	
	imprimePilha(pi);
	
	return 0;		
}

*/
