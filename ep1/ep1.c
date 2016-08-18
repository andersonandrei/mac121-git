#include <stdio.h>
#define  MAX 255

int verifica (int n);

int main() {
		int num,fn,interv,aux,cont = 0,impar=0;
		long int i,f;
		
		scanf("%ld %ld",&i,&f);
		interv = f - i;
		fn = i;
		
		while(interv >= 0) {
			aux = fn;
			/* printf("\n Fazedno %d\n ",fn); */
			while(aux != 1) {
					impar=0;
					printf("\n a");
					if (aux%2 != 0) impar=1;
					aux = verifica(aux);
					printf("\n %ld",aux);
					/*printf("%d\n", aux); */
					if (impar==1) cont+=2;
					else cont ++;
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

int procura (int bd[MAX][MAX], int num, int ultx, int ulty, int *pcont, int *pachou) {
/* Função recebe a tabela banco de dados e o numero a ser procurado na 
 * tabela	e retorna a qnt de iterações pós encontrála ou 0 caso 
 * contrário */

	int i,j,col = 0,n,ult=0,add=0,parar=0,ultl=0,contRec=0;
	n=num;
	i=0;
	for (j=0; ultl == 0 && j < 12 ; j++) {
			for (i=0; bd[i][j]!=1 && i < 12 ; i++) {
				if ((bd[i][j] == n) && ((i!=ultx) && (j!=ulty))) {
					(*pachou)++;
					col = j;
					for (col = j;bd[i][col] != 0; i ++) {
						ult = bd[i][col];
						if (ult != num)(*pcont)++;
						ultx = i;
						ulty = col;
					}
					if (ult != 1) {
						add = procura (bd,ult,ultx,ulty,pcont,pachou);
						contRec++;
					}
					else {
						ultl=1;
						return *pcont ;	
					}
				}
			}
	}
	add-=contRec*add;
	return *pcont+add;
	
}

void insere (int bd[MAX][MAX], int num) {
	int i,j;
	
	for (i=0; i< MAX; i++){
			for (j=0;j<MAX;j++) {
				if (bd[i][j] != num) bd[i][j++] = num;				
			}
	}
	
	return;
}
