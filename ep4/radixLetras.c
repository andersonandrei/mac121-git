#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listasL.h"

int main () {
	apontador lista;
	char *c1, *c2, *c, *texto;
	int decide;
	int i, j;
	texto = c1 = c2 = c = malloc (100 *sizeof(char));
	lista = malloc (sizeof (celula) );
	lista -> info = malloc(100* sizeof (char) );
	lista -> prox = NULL;
	lista -> qnt = 0;
	
	texto = "deus e um cara gozador adora brincadeira pois pra me jogar no mundo tinha um mundo inteiro";
	c1 = "andreib";
	c2 = "anderson";
	
	printf("Strcomp = %d e %d", strcmp(c1,c2), strcmp(c2,c1));
	
	printf("Recebidos: ");
	for (i = 0; c1[i] != '\0'; i++) {
		printf("%c",c1[i]);
	}
	printf("\n");
	for (i = 0; c2[i] != '\0'; i++) {
		printf("%c",c2[i]);
	}
	
/* Compara ordem alfabética */
	printf("\n Compara ordem alfabetica\n");
	i = 0;
	decide = 0;
	while (decide == 0 && (c1[i] != '\0' || c2[i] != '\0') ) {
		if (c1[i] == c2[i]) i++;
		if (c1[i] <= c2[i]) decide = 1;
		else decide = 2;
	}
	
	if (decide == 1) {
		for (i = 0; c1[i] != '\0'; i++)
			printf("%c",c1[i]);
	}
	
	else {
		for (i = 0; c2[i] != '\0'; i++)
			printf("%c",c2[i]);
	}
/* Até aqui */

	
	j=0;
	for (i = 0; texto[i] != '\0'; i++) {
		if (texto[i] >= 'a' && texto[i] <= 'z') { 
			c[j] = texto[i];
			j++;
		}
		if (texto[i] == ' ') {
			printf("\n inseriu \n");
			insereInicio(&lista, c);
			
			j = 0;
			free (c);
			c = malloc (100 * sizeof (char) );
		}
	}
	insereInicio(&lista, c);
	free (c);
	c = malloc (100 * sizeof (char) );
	printf("\n fim");
	imprimeLista(lista);

	return 0;

}
