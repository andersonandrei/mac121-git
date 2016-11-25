#include <stdio.h>
#include <stdlib.h>
#include "listasL.h"

int main () {
	polinomio polUm, polDois, soma;
	apontador teste;
	
	teste = malloc (sizeof (celula) );
	
	/* ---- Teste pros polinomios  ---- */
	polUm = malloc (sizeof (termo) );
	polDois = malloc (sizeof (termo) );
	polUm -> prox = polUm;
	polDois -> prox = polDois;
	
	polUm = insereTermoInicio (polUm, 4,3);
	polUm = insereTermoInicio (polUm, 3,3);
	polUm = insereTermoInicio (polUm, 2,3);
	polUm = insereTermoInicio (polUm, 1,3);
	
	polDois = insereTermoInicio (polDois, 4,8);
	polDois = insereTermoInicio (polDois, 3,8);
	polDois = insereTermoInicio (polDois, 2,8);
	polDois = insereTermoInicio (polDois, 1,8);
	
	imprimePolinomio(polUm);
	printf("\n\n");
	imprimePolinomio(polDois);
	
	soma = malloc (sizeof (termo) );
	soma = somaPolinomio (polUm, polDois);
	
	printf("\n\n");	
	imprimePolinomio (soma);
	
	
	/* ---- FIM: Teste pros polinomios  ---- */
	
	
	/* ---- Teste pras listas  ---- */
	
	insereFinal (&teste, 10);
	insereFinal (&teste, 20);
	insereFinal (&teste, 30);
	insereFinal (&teste, 40);
	
	imprimeLista (teste);
	
	teste = inverte (teste);
	imprimeLista (teste);
	
	
	
	printf("\n Blé");
	return 0;

}
