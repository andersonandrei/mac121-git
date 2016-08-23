/* Vamos fazer pilhas */

#include <stdio.h>
#define MAX 1000


/* Uma pilha deve ter: - Cria Pilha - Empilha - Desempilha - VerifVazia*/

typedef struct {
	int topo;
	int v[MAX];
} pilha;

pilha criaPilha () {
	pilha p;
	printf("\n Pilha criada com sucesso");
	return p;
}

int main() {
	printf("\n Estudando pilhas: ");
	pilha *pi;
	
	pi = criaPilha();
	
	return 0;

}
