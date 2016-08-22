#include <stdio.h>
#include <stdlib.h>

int verifica (int n);
int verifica (int n);
void imprimeVetor(long int prox[]);
void initVetor(long int prox[], int inic, int fim);

int main() {
		int fn,interv,cont = 0,impar=0,tam;
		long int i,f,inic,seguinte,aux            ;
		long int *prox;
		inic=0;
		tam = 1000;
		prox = malloc (tam*sizeof(long int));
		tam = 1000 * sizeof(long int);
		
		
		scanf("%ld %ld",&i,&f);
		interv = f - i;
		fn = i;
		
		if(prox != NULL) initVetor(prox,inic,tam/sizeof(long int));
		else {
			printf("\n Falta de memoria.");
			return 0;
		}
		
		while(interv > 0) {
			printf("\n entrou interv");
			aux = fn;
			printf("%ld: ",aux);
			while(aux > 1) {
					printf("\n entrou aux");
					printf("\n aux: %ld",aux);
					
					if (aux%2 != 0) impar=1;
					seguinte = verifica(aux);
					
					printf("\n Point 1");
					printf("\n Seguinte:%ld,tam:%d",seguinte,tam);
					
					printf("\n é ou nao eh : %d",seguinte>tam);
					printf("\n blé");
					
					if(seguinte > tam) {
						printf("\n bla ");
						printf("\n entrou realloc");
						printf("\n bló");
						prox = realloc (prox,2*tam);
						if (prox == NULL) {
							printf("\n Falta memória porra.");
							return 0;
						}
						
						inic = (tam / sizeof(long int)) + 1;
						tam *=2;
						for (i=inic;i<(tam / sizeof(long int));i++) prox[i] = -2;
						
						printf("\n tamanho do vetor: %d",tam);
					}
					
					printf("\n oi ");
					
					printf("\n Point 2");
					
					printf("\n merda suja");
					
					printf("\n aux:  %ld seguinte: %ld", aux, seguinte);
					printf("\n sizeof prox:  %d", tam);
					
					fflush(stdout);
					if(prox[aux] != seguinte) {
						prox[aux]=seguinte;
					}

					printf("\n Point 3");
					
					if (impar==1) {
						cont+=2;
					}
					else {
						cont++;
					}
					
					printf("\n Point 4");
					
					aux = seguinte;
					impar = 0;
					
					printf("\n Point 5");
			}
			printf("---------Contador : %d \n",cont); 
			fn++;
			printf("fn++\n"); 
			interv --;
			printf("interv :%d\n",interv); 
			cont = 0;
		}
		printf("\n saiu");

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

