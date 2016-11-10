#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "listasL.h"
#include "palavras.h"
#include "vetores.h"

int main () {

	FILE *texto;
	char *arq, ch, *palavra;
	char **tab;
	int *freq, soma = 0;
	
	int i, j, n = 0, k;
	arq = malloc (100 * sizeof(char));
	arq = "livro1.txt";
	texto = fopen(arq, "r");
	
	palavra = malloc (100 * sizeof(char));
	
	tab = criaMatriz (1000);
	freq = criaVetor (1000);
	
	zeraMatriz (tab, 1000);
	zeraVetorInt (freq, 1000);
	
	if(texto == NULL)
		printf("Erro, nao foi possivel abrir o arquivo\n");
	else {
		i = 0;
		while( (ch = fgetc (texto) ) != EOF ){
			if((ch >= 97 && ch <= 122)) {
				palavra[i] = ch;
				i++;
			}
			if((ch >= 65 && ch <= 90)) {
				palavra[i] = tolower(ch);
				i++;
			}
			if(especial	(ch) == 1)  { /* 60 = ' e 9 = tab */
				insereVetor (tab, freq, n, palavra, i);
				printf("\n Inseriu -------------");
				fflush(stdout);
				imprimeMatriz(tab);
				limpaPalavra(palavra, i);
				i = 0;
				n++;
			}
		}
		insereVetor (tab, freq, n, palavra, i);
		limpaPalavra(palavra, i);
		
	}
	imprimeVetorFreq(tab,freq,n);
	for (i = 0; i < n; i++)
		soma+=freq[i];
	printf("\n Totoal de palavras: %d",soma);
	
	return 0;
}
