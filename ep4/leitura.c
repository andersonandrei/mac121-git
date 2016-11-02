#include "listasL.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
	apontador palavras;
	int n = 0, i=0;
	FILE *texto;
	char *palavra;
	char *arq;
	char ch;
	
	palavras = malloc (sizeof(celula));
	palavra = malloc (100 * sizeof(char));
	arq = malloc (100 * sizeof(char));
	arq = "texto.txt";
	
	
	texto = fopen(arq, "r");
	if(texto == NULL)
			printf("Erro, nao foi possivel abrir o arquivo\n");
	else {
		i = 0;
		while( (ch=fgetc (texto) ) != EOF ){
			if(ch >= 97 && ch <= 122) {
				palavra[i] = ch;
				i++;
			}
			if(ch == ' ')  {
				insereInicio(&palavras, palavra);

			}
		}
		insereInicio(&palavras, palavra);
	}  
	imprimeLista(palavras);
	
	fclose(texto);
	
	return 0;
}
