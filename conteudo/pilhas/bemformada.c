#include "pilhaD.h"
#include <stdio.h>
#include <stdlib.h>

int bemFormada (char c[]) {
	int i;
	char aux;
	pilha *mem;
	mem = criaPilha(100);
	for (i=0; c[i]!= '\0'; i++ ){
		if (c[i] == '(' || c[i] == '{' || c[i] == '[' ) {
			empilha(mem,c[i]);
		}
		else {
			aux = desempilha(mem);
			if(aux != c[i]) {
				printf("\n Não é bem formada.");
				return 0;
			}
		}
	}
	/* Neste ponto tudo já foi desempilhado, falta ver o q resta lá */
	if (pilhaVazia(mem)) {
		printf("\n Bem formada! ");
	}
	else {
		printf("\n Ops, %d ainda ta lá .. :(",c[0]);
	}
	return 0;
}


int main() {
	char c;
	int aux;
	
	printf("Brincando com BemFormada\n");
	scanf("%c", &c);
	
	aux = bemFormada(&c);

	return 0;
}
