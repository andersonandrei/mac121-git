#include "pilhas.h"
#include "movimentos.h"
#include "vetores.h"
#include "quickSort.h"
#include <stdio.h>
#include <stdlib.h>


int main() {
	
	pilha *trocas;
	int *vetor;
	int i, j, n, ok, tent = 0;
	
	scanf("%d",&n);
	
	vetor = criaVetor(n);
	if(vetor == NULL) printf("\n Bosta suja");
	zeraVetor(vetor,n);
	
	for(j=0; j<n; j++) {
		scanf("%d",&vetor[j]);
	}
	printf("\n");
	
	imprimeVetor(vetor,n);
	printf("\n");
	
	trocas = criaPilha(n);
	if (trocas == NULL) printf("\n merda");
	ok=0;
	i=0;
	
	/* Caso particular, n=2 */
	if (n == 2) {
		if (vetor[0] <= vetor[1]) {
			imprimeVetor(vetor,n);
			return 0;
		}
		else {
			printf("Nao e possivel.\n");
			return 0;
		}
	}
	
	while((checaOrdenado(vetor, n)) != 1) {
		ok=0;
		while(tent <=6 && ok == 0){
			if (podeTrocar(vetor, i, n) == 1)			
				ok = 1;
			else
				i = verificaIndicePasso(vetor, i, n);
				tent++;
		}
		
		if(ok == 1) {
			empilha(trocas,i);
			empilha(trocas,tent);
			troca(vetor, i, n);
			i = verificaIndicePasso(vetor, i, n);
			ok = 0;
			tent = 0;
		}
		else { /* BakcTrack*/
			if(pilhaVazia(trocas) == 1) {
				printf("\n Deu ruim.");
				destroiPilha(trocas);
				destroiVetor(vetor);
				return 0;
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
	imprimeVetor(vetor,n);
	destroiPilha(trocas);
	destroiVetor(vetor);

	return 0;
}
