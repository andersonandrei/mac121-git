#include <stdio.h>
#include <stdlib.h>

unsigned long int collatz(int n);
/* Recebe um inteiro n e verifica se o número recebido é ímpar ou par 
 * e então retorna o resultado de f(n) onde f é a função da 
 * conjectura de Collatz. */
 
void initVetor (unsigned long int *prox);
/*Recebe um ponteiro para um vetor de unsigned long int e irá inicializar as posições 
 * de 2 até MAX do vetor com o valor -2. */

int main() {
	int intervalo, cont = 0, impar = 0, MAX = 3354432;
	unsigned long int fn, i, f, seguinte, aux;
	unsigned long int *prox;
	scanf("%lu %lu", &i, &f);
	intervalo = f - i;
	fn = i;
	prox = malloc (MAX * sizeof(unsigned long int));
	
	if (prox == NULL) {
		printf("\n Não foi possível alocar. Limite de memória excedida."
		" Requesito mínimo: 256 mb de memória livre.");
		free(prox);
		return 0;
	}
	
	initVetor(prox);
	while (intervalo > 0) {
		aux = fn;
		while (aux > 1) {
			if (aux >= MAX) {
				printf("\nLimite de memória excedida, pois para a "
				"última sequência \niniciada em: %lu chegamos "
				"em: %lu que não é comportado pelo programa.", fn, aux);
				return 0;
			}
			if (aux % 2 != 0)
				impar = 1;
			seguinte = collatz(aux);
			if (prox[aux] != seguinte) 
				prox[aux] = seguinte;
			if (impar == 1) 
				cont += 2;
			else 
				cont++;
			aux = seguinte;
			impar = 0;
		}
		printf("%d\n", cont); 
		fn++;
		intervalo--;
		cont = 0;
	}
	free(prox);
	return 0;
}

unsigned long int collatz(int n){
	if (n == 1) return 1;
	else if (n % 2 == 0) return n / 2;
	else return (1.5 * n) + 0.5;
}

void initVetor(unsigned long int *prox) {
	int i, MAX = 3354432;
	prox[0] = prox[1] = 0;
	for (i = 2; i < MAX; i++ ) prox[i] = 0;	
}

