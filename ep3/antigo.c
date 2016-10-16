#include "pilhas.h"
#include "movimentos.h"
#include "vetores.h"
#include <stdio.h>
#include <stdlib.h>


int main() {
	
	pilha *trocas;
	int *vetor, *w;
	int i, j, indice, n, ok, tent = 0;
	
	printf("\n oooii");
	scanf("%d",&n);
	
	vetor = criaVetor(vetor,n);
	if(vetor == NULL) printf("\n Bosta suja");
	zeraVetor(vetor,n);
	
	w = criaVetor(w,n);
	if(w == NULL) printf("\n Bosta suja");
	zeraVetor(w,n);
	
	for(j=0; j<n; j++) {
		scanf("%d",&vetor[j]);
	}
	printf("\n");
	for(j=0; j<n; j++) {
		scanf("%d",&w[j]);
	}
	printf("\n");
	imprimeVetor(vetor,n);
	printf("\n");
	imprimeVetor(w,n);
	printf("\n");
	
	trocas = criaPilha(100);
	if (trocas == NULL) printf("\n merda");
	ok=0;
	i=0;
	
	while(compara(vetor,w,n) != 1) {
		ok=0;
		while(tent <=6 && ok == 0){
			printf("\n Tentando pra i = %d",i);
			if (podeTrocar(vetor, i, n) == 1)			
				ok = 1;
			else
				i = verificaIndicePasso(vetor, i, n);
				tent++;
		}
		
		if(ok == 1) {
			empilha(trocas,i);
			empilha(trocas,tent);
			printf("\n Empilhou %d", i);
			troca(vetor, i, n);
			i = verificaIndicePasso(vetor, i, n);
			printf(" --- e foi pra %d\n",i);
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
				printf("\n Despula: ");
				tent = desempilha(trocas);
				i = desempilha(trocas);
				printf("Desempilhou %d",i);
				troca(vetor, i, n);
				i = verificaIndicePasso(vetor, i, n);
				printf("\n --- e olhou pra %d \n",i);
				ok = 0;
				tent++;
			}
		}
		imprimeVetor(vetor,n);
		printf("\n");
	}
	imprimeVetor(vetor,n);
	destroiPilha(trocas);
	destroiVetor(vetor);

	return 0;
}
