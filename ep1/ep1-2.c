#include <stdio.h>
#define  MAX 255

int verifica (int n);
/*
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
		
} */

int main() {

	int bd[MAX][MAX];
	int i,j,num;
	int cont=0;
	int *pcont = &cont;
	int achou;
	int *pachou = &achou;

	for (i=0;i<MAX;i++ )
		for(j=0;j<MAX;j++)
			bd[i][j] = 0;

	bd[0][0] = 7;
	bd[1][0] = 3;
	bd[2][0] = 10;
	bd[3][0] = 5;
	bd[4][0] = 16;
	bd[5][0] = 8;
	bd[6][0] = 4;
	bd[7][0] = 2;
	bd[8][0] = 1;
	
	bd[0][1] = 1;
	bd[1][1] = 4;
	
	bd[0][2] = 1;
	bd[1][2] = 5;

	
	printf("\n Matriz:");
	j=0;
	for (i=0;i!=9;i++ ){
		printf("\n");
		for(j=0;bd[i][j]!=0;j++)
			printf("%d ",bd[i][j]);
	}	
	
	printf("\n Procurar/iterar ");
	num = procura(bd,3,9,9,pcont,pachou);
	printf("-------Procurando por 3 valor e: %d\n", num);
	*pcont = *pachou =0;
	
	printf("-------Procurando por 4 e: %d\n", procura(bd,4,9,9,pcont,pachou));
	*pcont = *pachou =0;
	printf("-------Procurando por 16 e: %d\n", procura(bd,16,9,9,pcont,pachou));
	*pcont = *pachou =0;
	
	return 0;
}

int verifica (int n){
		if (n==1) return 1;
		else if (n%2 == 0) return n/2;
		else return 3*n+1;
}

int procura (int bd[MAX][MAX], int num, int ultx, int ulty, int *pcont, int *pachou) {
/* Função recebe a tabela banco de dados e o numero a ser procurado na 
 * tabela	e retorna a qnt de iterações pós encontrála ou 0 caso 
 * contrário */
	printf("Entrou \n");
	printf("\n Procuramos por: %d\n",num);
	int i,j,col = 0,n,ult,add=0;
	
	n=num;
	
	for (j=0; j < 9; j++) {
			printf("Coluna -- %d\n",j);
			for (i=1; i < 9; i++) {
				printf("Linha %d\n",i);
				printf("%d\n",bd[i][j]);
				if ((bd[i][j] == n) && ((i!=ultx) && (j!=ultj))) {
					printf("achou\n");
					(*pachou)++;
					/*
					if (i == 1){
						printf("\n Topo: %d e cont: %d\n",bd[0][j],*pcont);
						printf("Achou : %d\n",*pachou);
						printf("\n Primeiro return");
						if(bd[i+bd[0][j]][j] == 1) return bd[0][j];
					}
					*/
					printf("else\n");
					col = j;
					for (col = j;bd[i][col] != 0; i ++) {
						printf("\n Olhou : %d",bd[i][col]);
						ult = bd[i][col];
						printf("Ult = %d\n",ult);
						
						if (ult != num){
							(*pcont)++;
							printf("contou\n");
						}
						ultx = i;
						ulty = col;
						printf("Aqui\n");
					}
					
					if (ult != 1) {
						printf("\n if dif 1");
						printf("Ultx: %d e ulty: %d",ultx,ulty);
						add = procura (bd,ult,ultx,ulty,pcont,pachou);
						printf("\n add: %d",add);
					}
					else {
						printf("Cont : %d e Achou : %d\n",*pcont,*pachou);
						printf("Segundo return");
						return *pcont ;	
					}
						
				}
			}	
	}
	
	printf("\n Ultimo return");
	
	return *pcont+add;
	
}


/*
 * int procura (int bd[MAX][MAX], int num, int ultx, int ulty, int *pcont, int *pachou) {
/* Função recebe a tabela banco de dados e o numero a ser procurado na 
 * tabela	e retorna a qnt de iterações pós encontrála ou 0 caso 
 * contrário 
	printf("Entrou \n");
	printf("\n Procuramos por: %d\n",num);
	int i,j,col = 0,n,ult,add=0;
	
	n=num;
	
	for (i=1; i < ultx; i++) {
			printf("linha %d\n",i);
			for (j=0; j < ulty; j++) {
				printf("coluna %d\n",j);
				printf("%d\n",bd[i][j]);
				if (bd[i][j] == n) {
					printf("achou\n");
					(*pachou)++;
					if (i == 1){
						printf("\n Topo: %d e cont: %d\n",bd[0][j],*pcont);
						printf("Achou : %d\n",*pachou);
						printf("\n Primeiro return");
						if(bd[i+bd[0][j]][j] == 1) return bd[0][j];
					}
					else {
						printf("Achou : %d\n",*pachou);
						printf("else\n");
						col = j;
						for (col = j;bd[i][col] != 0; i ++) {
							printf("\n Olhou : %d",bd[i][col]);
							ult = bd[i][col];
							printf("Ult = %d\n",ult);
							
							if (ult != num){
								(*pcont)++;
								printf("contou\n");
							}
							ultx = i;
							ulty = col;
							printf("Aqui\n");
						}
						
						if (ult != 1) {
							printf("\n if dif 1");
							add = procura (bd,ult,ultx,ulty,pcont,pachou);
							printf("\n add: %d",add);
						}
						else {
							printf("Cont : %d e Achou : %d\n",*pcont,*pachou);
							printf("Segundo return");
							return *pcont ;	
						}
					}
						
					}
				}	
			}
	}
	printf("\n Ultimo return");
	
	return *pcont+add;
	 ante com if ==1 separado
}*/


/* 
int procura (int bd[MAX][MAX], int num, int ultx, int ulty, int cont, int achou) {
/* Função recebe a tabela banco de dados e o numero a ser procurado na 
 * tabela	e retorna a qnt de iterações pós encontrála ou 0 caso 
 * contrário 
 * 
	printf("Entrou \n");
	printf("\n Procuramos por: %d\n",num);
	int i,j,k,col = 0,n,ult,add=0;
	
	n=num;
	
	for (i=1; i < ultx; i++) {
			printf("linha %d\n",i);
			for (j=0; j < ulty; j++) {
				printf("coluna %d\n",j);
				printf("%d\n",bd[i][j]);
				if (bd[i][j] == n) {
					printf("achou\n");
					if (i == 1){
						printf("\n Topo: %d e cont: %d\n",bd[0][j],cont);
						printf("Achou : %d\n",achou);
						return cont + bd[0][j] - achou;
					} 
					else {
						printf("else\n");
						col = j;
						for (col = j;bd[i][col] != 0; i ++) {
							printf("\n Olhou : %d",bd[i][col]);
							ult = bd[i][col];
							printf("Ult = %d\n",ult);
							printf("contou\n");
							cont ++;
							achou ++;
							ultx = i;
							ulty = col;
							printf("Aqui");
						}
						
						if (ult != 1) add = procura (bd,ult,ultx,ulty,cont,achou);
						else return cont - achou ;	
					}
				}	
			}
	}
	
	return cont+add-achou;
	* 
	* O unico problema aqui esta na sendo na contagem do achou por causa
	* da recursão, então vou tentar usar como ponteiro.
	
}
 * */
