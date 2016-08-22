#include <stdio.h>
#include <stdlib.h>

int verifica (int n);
int verifica (int n);
void imprimeVetor(long int prox[]);
void initVetor(long int prox[], int inic, int fim);

int main() {
		int fn,interv,cont = 0,impar=0;
		long int i,f,inic,fim,seguinte,aux,tam            ;
		long int *prox;
		inic=0;
		tam = 1000 * sizeof(long int) ;
		prox = malloc (tam);
		fim = tam / sizeof(long int);
		
		scanf("%ld %ld",&i,&f);
		interv = f - i;
		fn = i;
		
		if(prox != NULL) initVetor(prox,inic,fim);
		else {
			printf("\n Falta de memoria.");
			return 0;
		}
		
		while(interv > 0) {
			aux = fn;
			printf("%ld: ",aux);
			while(aux > 1) {
					
					if (aux%2 != 0) impar=1;
					seguinte = verifica(aux);
					
					if((seguinte > tam) && (2*tam > tam)){
						printf("Aux: %ld, seguinte : %ld\n",aux,seguinte);
						printf("Tamanho : %ld",tam/sizeof(long int));
						printf("\n segguinte: %ld",(seguinte));
						prox = realloc (prox,tam + (seguinte*sizeof(long int)));
						if (prox == NULL) {
							printf("\n Falta memoria.");
							return 0;
						}
						printf("\n intervalo anterior [ %ld,%ld [", inic,fim);
						
						inic = (tam / sizeof(long int)) + 1;
						tam +=(seguinte*sizeof(long int));
						printf("\n Agora tam: %ld",tam);
						fim = (tam / sizeof(long int));
						
		
						for (i=inic;i<fim;i++) prox[i] = -2;
					}

					if(prox[aux] != seguinte) {
						prox[aux]=seguinte;
					}
					
					if (impar==1) {
						cont+=2;
					}
					else {
						cont++;
					}
					
					aux = seguinte;
					impar = 0;

			}
			printf("---------Contador : %d \n",cont); 
			fn++;
			interv --;
			cont = 0;
		}
		free(prox);
		return 0;
}

int verifica (int n){
		if (n==1) return 1;
		else if (n%2 == 0) return n/2;
		else return (1.5*n)+0.5;
}

void imprimeVetor(long int prox[]) {
	int i;
	for(i=0;i<50;i++) printf("%ld ",prox[i]);
}

void initVetor(long int prox[], int inic, int fim) {
	int i;
	for (i=inic;i<fim;i++) prox[i] = -2;	
}

