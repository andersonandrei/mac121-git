#include <stdio.h>
#include <stdlib.h>
#include "listasL.h"

int main () {
	apontador lista;
	
	printf("\n Lista Ligada criada!\n Veja:");
	imprimeLista (lista);
	insereFinal (&lista, 20);
	insereInicio (&lista, 10);
	insereInicio (&lista, 16);
	insereFinal (&lista, 20);
	imprimeLista (lista);
	imprimeLista (lista);
		
	
	return 0;

}
