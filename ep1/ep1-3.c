#include <stdio.h>
#define  MAX 255

int verifica (int n);

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

	bd[0][0] = 10;
	bd[1][0] = 5;
	bd[2][0] = 16;
	bd[3][0] = 8;
	bd[4][0] = 4;
	bd[5][0] = 2;
	bd[6][0] = 1;
	
	bd[0][1] = 11;
	bd[1][1] = 34;
	bd[2][1] = 17;
	bd[3][1] = 52;
	bd[4][1] = 26;
	bd[5][1] = 13;
	bd[6][1] = 40;
	bd[7][1] = 20;
	bd[8][1] = 10;

	bd[0][2] = 12;
	bd[1][2] = 6;
	bd[2][2] = 3;
	bd[3][2] = 10;

	bd[0][3] = 21;
	bd[1][4] = 40;

	
	printf("\n Matriz:");
	j=0;
	for (i=0;i!=12;i++ ){
		printf("\n");
		for(j=0;j!=12;j++) /* Enquanto bd[i][j]!=0*/
			printf("%d ",bd[i][j]);
	}	
	
	printf("\n Procurar/iterar ");

	printf("-------Procurando por 10 valor e: %d\n",procura(bd,10,12,12,pcont,pachou));
	*pcont = *pachou =0;
	
	printf("-------Procurando por 11 e: %d\n", procura(bd,11,12,12,pcont,pachou));
	*pcont = *pachou =0;
	
	printf("-------Procurando por 12 e: %d\n", procura(bd,12,12,12,pcont,pachou));
	*pcont = *pachou =0;
	
	printf("-------Procurando por 13 e: %d\n", procura(bd,13,12,12,pcont,pachou));
	return 0;
	
	*pcont = 0;
	*pachou =0;
	
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
	int i,j,col = 0,n,ult=0,add=0,parar=0,ultl=0,contRec=0;
	n=num;
	i=0;
	for (j=0; ultl == 0 && j < 12 ; j++) {
			printf("Coluna -- %d\n",j);
			for (i=0; bd[i][j]!=1 && i < 12 ; i++) {
				printf("Linha %d\n",i);
				printf("%d\n",bd[i][j]);
				if ((bd[i][j] == n) && ((i!=ultx) && (j!=ulty))) {
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
						contRec++;
						printf("\n add: %d",add);
					}
					else {
						printf("Cont : %d e Achou : %d\n",*pcont,*pachou);
						printf("Segundo return");
						ultl=1;
						return *pcont ;	
					}
					
						
				}
			}
	}
	
	printf("\n Ultimo return");
	add-=contRec*add;
	return *pcont+add;
	
}
