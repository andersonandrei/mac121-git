#include <stdio.h>

int verifica (int n);

int main() {
		int i,f,num,fn,interv,aux,cont = 0;
		
		scanf("%d %d",&i,&f);
		interv = f - i;
		fn = i;
		
		while(interv >= 0) {
			aux = fn;
			printf("\n Fazedno %d\n ",fn);
			while(aux != 1) {
					aux = verifica(aux);
					printf("%d\n", aux);
					cont ++;
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
		else return 3*n+1;
}
