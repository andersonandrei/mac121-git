#include <stdio.h>
#include <stdlib.h>
#include "listasL.h"

int main () {
	apontador lista;
	
	printf("\n Lista Ligada criada!\n Veja:");
	imprimeLista (lista);
	printf("\n 1");
	insereFinal (&lista, 20);
	imprimeLista (lista);
	insereInicio (&lista, 10);
	insereInicio (&lista, 16);
	insereFinal (&lista, 20);
	printf("\n Dois");
	imprimeLista (lista);
		
	
	return 0;

}
