#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listasL.h"

int main () {
	apontador lista, palavras;
	int i;
	
	FILE *texto;
	char *palavra;
	char *arq;
	char ch;

	fflush(stdout);
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
	arq = "livro1.txt";

	texto = fopen(arq, "r");
	if(texto == NULL) printf("Erro, nao foi possivel abrir o arquivo\n");
	else {
		i = 0;
		while( (ch=fgetc (texto) ) != EOF ){
			if((ch >= 97 && ch <= 122) || (ch >= 65 && ch <= 90)) {
				fflush(stdout);
				palavra[i] = ch;
				i++;
			}
			if(ch == ' ')  {
				fflush(stdout);
				insereInicio(&palavras, palavra);
				i=0;
				free(palavra);
				palavra = malloc (100 * sizeof (char) );
			}
		}
		fflush(stdout);
		insereInicio(&palavras, palavra);
		free(palavra);
		palavra = malloc (100 * sizeof (char) );
		i=0;
	}  
	imprimeLista(palavras);
	
	fclose(texto);

	return 0;

}
