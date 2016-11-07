#include <stdio.h>
#include <stdlib.h>
#include "palavras.h"

void limpaPalavra (char *palavra, int n) {
	int i;
	for (i = 0; i < n; i++)
		palavra[i] = ' ';
	free(palavra);
	palavra = malloc (100 * sizeof (char));
	return;
}

int especial (char ch) {
	if(ch == ' ' || ch == '\n' || ch == '.' 
		|| ch == '-' || ch == '_'
		|| ch == '*' || ch == 60 || ch == '"'
		|| ch == '?' || ch == '!'
		|| ch == '@' || ch == 9 )  { /* 60 = ' e 9 = tab */
		return 1;
	}

	return 0;

}
