#include "pilhaD.h"
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int prioridade (char s) {
	if (s == '(') return 0;
	else if (s == '/' || s == '*') return 2;
	else return 1;
}

void posfixa (char c[], int tam) {
	int i,priori,aux,topo;
	pilha *ordem;
	ordem = criaPilha(tam);
	
	for(i=0; i<tam; i++) {
		/* Se é número imprime direto */
		if (c[i]>='a' && c[i]<='z') {
			printf("%c",c[i]);
		}
		/* Se não é, ou é parenteses ou algum operador */
		else if(c[i] == '(') {
			empilha(ordem,c[i]);
		}
		else {
			if(c[i] == ')'){
				while((topo = desempilha(ordem)) != '(' && topo != 0 ) {
					printf("%c",topo);
				}
			}
			else {
				topo = topoPilha(ordem);
				while (!pilhaVazia(*ordem) && prioridade(topo) >= prioridade(c[i])) {
					printf("%c",desempilha(ordem));
					if (!pilhaVazia(*ordem)) topo = topoPilha(ordem);
				}
				empilha(ordem,c[i]);
			} 
		}
		
	}
	
	/* Acabou de ler a expressão, 
	 * temos de desempilharo que restou na pilha */
	
	while (!pilhaVazia(*ordem)) {
		printf("%c",desempilha(ordem));
	}
	destroiPilha(ordem);
	return ;
}


int main() { 
	int i,tam=11;
	char c[MAX];
	printf("\n Vamos brincar com exp polonesa. \n Insira uma exp de tamanho 17:");
	c[0] = 'a';
	c[1] ='*';
	c[2] ='b';
	c[3] ='+';
	c[4] ='(';
	c[5] ='c';
	c[6] ='+';
	c[7] ='d';
	c[8] =')';
	c[9] ='+';
	c[10] ='e';
	
	printf("\n Raio posfixador: ");
	posfixa(c,tam);
	
	
	return 0;
	
}
