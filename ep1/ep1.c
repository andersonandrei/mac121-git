#include <stdio.h>
#define  MAX 999999

int verifica (int n);
int verifica (int n);
void imprimeVetor(int prox[]);
void initVetor(int prox[]);

int main() {
		int fn,interv,aux,seguinte,cont = 0,impar=0;
		long int i,f;
		int prox[MAX];
		
		scanf("%ld %ld",&i,&f);
		interv = f - i;
		fn = i;
		
		initVetor(prox);
		
		while(interv >= 0) {
			aux = fn;
			printf("%d: ",aux);
			while(aux > 1) {
					if (aux%2 != 0) impar=1;
					seguinte = verifica(aux);
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
			printf("%d \n",cont); 
			fn++;
			interv --;
			cont = 0;
		}
		return 0;
}

int verifica (int n){
		if (n==1) return 1;
		else if (n%2 == 0) return n/2;
		else return (1.5*n)+0.5;
}

void imprimeVetor(int prox[]) {
	int i;
	for(i=0;i<50;i++) printf("%d ",prox[i]);
}

void initVetor(int prox[]) {
	int i;
	for (i=0;i<50;i++) prox[i] = -2;	
}

