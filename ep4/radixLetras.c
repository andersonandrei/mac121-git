#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "listasL.h"
#include "palavras.h"

int main () {
	apontador lista, palavras;
	int i;
	
	FILE *texto;
	char *palavra;
	char *arq;
	char ch;

	lista = malloc (sizeof (celula) );
	lista -> info = malloc(100* sizeof (char) );
	lista -> prox = NULL;
	lista -> qnt = 0;

	fflush(stdout);
	palavras = malloc (sizeof(celula));
	palavras -> info = malloc(100* sizeof (char) );
	palavras -> prox = NULL;
	palavras -> qnt = 0;
	
	palavra = malloc (100 * sizeof(char));

	arq = malloc (100 * sizeof(char));
	arq = "livro2.txt";

	texto = fopen(arq, "r");
	if(texto == NULL) printf("Erro, nao foi possivel abrir o arquivo\n");
	else {
		i = 0;
		while( (ch=fgetc (texto) ) != EOF ){
			if((ch >= 97 && ch <= 122)) {
				palavra[i] = ch;
				i++;
			}
			if((ch >= 65 && ch <= 90)) {
				palavra[i] = tolower(ch);
				i++;
			}
			if(especial	(ch))  { /* 60 = ' e 9 = tab */
				insereFinal(&palavras, palavra);
				limpaPalavra(palavra, i);
				i = 0;
			}
		}
		printf("\n pos no final");
		insereFinal(&palavras, palavra);
		limpaPalavra(palavra, i);
	}  
	imprimeLista(palavras);
	
	fclose(texto);

	return 0;

}


