#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "listasL.h"
#include "palavras.h"
#include "vetores.h"

int main () {
	int i, n = 0, k;
	char *vetor;
	int *freq;
	
	FILE *texto;
	char *arq;
	char ch;
	char *palavra;
	
	palavra = malloc (100 * sizeof(char));
	vetor = malloc (100 * sizeof (char));
	if (vetor == NULL) printf("\n Não alocou vetor");
	freq = malloc (100 * sizeof (int) );
	if (freq == NULL) printf("\n Não alocou freq");
	arq = malloc (100 * sizeof(char));
	arq = "livro2.txt";

	texto = fopen(arq, "r");
	printf("\n Li o texto");
	if(texto == NULL) printf("Erro, nao foi possivel abrir o arquivo\n");
	else {
		printf("\n Else");
		i = 0;
		while( (ch = fgetc (texto) ) != EOF ){
			printf("\n na mao: %c\n",ch);
			printf("\n While");
			if((ch >= 97 && ch <= 122)) {
				palavra[i] = ch;
				i++;
			}
			if((ch >= 65 && ch <= 90)) {
				palavra[i] = tolower(ch);
				i++;
			}
			if(especial	(ch) == 1)  { /* 60 = ' e 9 = tab */
				printf("\n Vai inserir");
				fflush(stdout);
				printf("\n Vamos olhar pra palavra: de tamanho %d\n",i);
				for (k=0;k<i; k++) printf("%c",palavra[k]);
				printf("\n");
				insereVetor (&vetor, freq, n, palavra);
				limpaPalavra(palavra, i);
				i = 0;
				n++;
			}
		}
		printf("\n pos no final");
		insereVetor (&vetor, freq, n, palavra);
		limpaPalavra(palavra, i);
	}  
	
	fclose(texto);

	
	return 0;
}
