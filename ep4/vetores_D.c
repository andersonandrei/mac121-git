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
	int *freq;
	
	int i, n = 0, k;
	
	arq = malloc (100 * sizeof(char));
	arq = "livro2.txt";
	texto = fopen(arq, "r");
	
	palavra = malloc (100 * sizeof(char));
	
	tab = criaMatriz (10000);
	freq = criaVetor (10000);
	
	zeraMatriz (tab, 10000);
	zeraVetorInt (freq, 10000);
	
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
				printf("\n Mandou inserir: \n");
				for (k = 0; k < n; k++) { printf("%c",palavra[k]);}
				tab = insereVetor (tab, freq, n, palavra, i);
				imprimeMatriz(tab, n);
				limpaPalavra(palavra, i);
				i = 0;
				n++;
			}
		}
		tab = insereVetor (tab, freq, n, palavra, i);
		limpaPalavra(palavra, i);
		
	}
	
	return 0;
}
