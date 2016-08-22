#include <stdio.h>
#define MAX 16777218

unsigned long int verifica(int n);
/* Recebe um inteiro n e verifica se o número recebido é ímpar ou par 
 * e então retorna o resultado de f(n) onde f é a função da 
 * conjectura de Collatz. */
 
void initVetor (long int prox[]);
/*Recebe um vetor de unsigned long int e irá inicializar as posições 
 * de 2 até MAX do vetor com o valor -2. */

int main() {
	int interv, cont = 0, impar = 0;
	unsigned long int fn, i, f, seguinte, aux;
	unsigned long int prox[MAX];
	scanf("%lu %lu", &i, &f);
	interv = f - i;
	fn = i;
	while (interv > 0) {
		aux = fn;
		while (aux > 1) {
			if (aux >= MAX) {
				printf("\nLimite de memória excedida, último " 
				"número computado: %lu.", fn-1);
				return 0;
			}
			if (aux % 2 != 0)
				impar = 1;
			seguinte = verifica(aux);
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
		interv--;
		cont = 0;
	}
	return 0;
}

unsigned long int verifica(int n){
	if (n == 1) return 1;
	else if (n % 2 == 0) return n / 2;
	else return (1.5 * n) + 0.5;
}

void initVetor(long int prox[]) {
	int i;
	prox[0] = prox[1] = -1;
	for (i = 2; i < MAX; i++ ) prox[i] = -2;	
}

