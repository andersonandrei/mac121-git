#include "pilhas.h"
#include "movimentos.h"
#include "vetores.h"
#include "bubbleSort.h"
#include <stdio.h>
#include <stdlib.h>

void tresReversao(int *v, int n);

int main() {
	int *vetor;
	int j, n;
	scanf("%d",&n);
	vetor = criaVetor(n);
	if(vetor == NULL) printf("Nao e possivel\n");
	zeraVetor(vetor, n);
	for(j = 0; j < n; j++) {
		scanf("%d", &vetor[j]);
	}
	tresReversao(vetor, n);
	return 0;
}

void tresReversao(int *vetor, int n) {
	pilha *trocas;
	int *copia;
	int i, ok, tent = 0;
	
	trocas = criaPilha(2*n*n);
	if (trocas == NULL) printf("Nao e possivel\n");
	ok = 0;
	i = 0;
	
	/* Caso particular, n=2 */
	if (n % 2 == 0) {
		if (n == 2) {
			if (vetor[0] <= vetor[1]) {
				imprimeVetor(vetor, n);
				return;
			}
			else {
				printf("Nao e possivel\n");
				destroiPilha(trocas);
				destroiVetor(vetor);
				return;
			}
		}
		else { /* Verificando com bubbleSort se é possível de ordenar */
			copia = malloc (n * sizeof(int));
			if (copia == NULL) 
				printf("Nao e possivel\n");
			for (i = 0; i < n; i++)
				copia[i] = vetor[i];
			bubbleSort(copia, n);
			imprimeVetor(copia, n);
			if (checaOrdenado(copia,n) == 0) {
				printf("Nao e possivel\n");
				destroiVetor(copia);
				destroiVetor(vetor);
				destroiPilha(trocas);
				return;
			}
		}
	}
	
	while((checaOrdenado(vetor, n)) != 1) {
		ok=0;
		while(tent <= n - 1 && ok == 0){
			if (podeTrocar(vetor, i, n) == 1)			
				ok = 1;
			else {
				i = verificaIndicePasso(vetor, i, n);
				tent++;
			}
		}
		
		if(ok == 1) {
			empilha(trocas, i);
			empilha(trocas, tent);
			troca(vetor, i, n);
			i = verificaIndicePasso(vetor, i, n);
			ok = 0;
			tent = 0;
		}
		else { /* BakcTrack*/
			if(pilhaVazia(trocas) == 1) {
				printf("Nao e possivel\n");
				destroiVetor(vetor);
				destroiPilha(trocas);
				
				return;
			}
			else { 
				tent = desempilha(trocas);
				i = desempilha(trocas);
				troca(vetor, i, n);
				i = verificaIndicePasso(vetor, i, n);
				ok = 0;
				tent++;
			}
		}
	}
	
	imprimeVetor(vetor, n);
	printf("\n");
	printf("\n Aqui;");
	imprimePilhaInversa(trocas);
	printf("\n Ainda;");
	
	destroiPilha(trocas);
	printf("\n nao bugou;");
	
	destroiVetor(vetor);

	return;
}
