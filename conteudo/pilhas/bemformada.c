#include "pilhaD.h"
#include <stdio.h>
#include <stdlib.h>

int fecha (char x, char y) {
	if ((x == '(' && y == ')') || (x == '{' && y == '}') || (x == '[' && y == ']'))
		return 1;
	else
		return 0;
}

int bemFormada (char c[]) {
	int i,ok=1;
	char aux;
	pilha *mem;
	mem = criaPilha(50);
	
	for (i=0; (c[i] != '\0') && ok; i++ ){
		printf("Mexendo com %c",c[i]);
		if (c[i] == '(' || c[i] == '{' || c[i] == '[' ) {
			empilha(mem,c[i]);
		}
		else {
			printf("else");
			if(pilhaVazia(mem)){
				ok=0;
			}
			else {
				aux = desempilha(mem);
				printf("Desempilhou %c",aux);
				if(!fecha(c[i],aux)) {
					ok=0;
				}
			}
			if (!pilhaVazia(mem)){
				ok=0;
				destroiPilha(mem);
			}
			
			return ok;
		}
		
	}

}

int main() {
	char c;
	int aux;
	
	printf("Brincando com BemFormada\n");
	scanf("%c", &c);
	
	aux = bemFormada(&c);
	printf("Aux: %d",aux);

	return 0;
}
