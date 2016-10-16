#include "movimentos.h"
#include <stdio.h>

int verificaIndiceTroca (int *v, int i, int n) {
	int indice = 0;
	if(i <= n-3)
		indice = i+2;
	if(i > n-2) {
		if (i == n-2)
			indice = 0;
		if (i == n-1)
			indice = 1;
	}
	return indice;	
}

int verificaIndicePasso (int *v, int i, int n) {
	int indice = 0;
	if(i <= n-2)
		indice = i+1;
	if(i == n-1) {
		indice = 0;
	}
	return indice;	
}

int podeTrocar (int *v, int i, int n) {
	int indice;
	indice = verificaIndiceTroca(v, i, n);
	if(v[i] > v[indice] && i < indice) 
		return 1;
	if(v[i] < v[indice] && i > indice)
		return 1;
	return 0;
}

void troca (int *v, int i, int n) {
	int indice, aux;
	indice = verificaIndiceTroca(v, i, n);
	aux = v[i];
	v[i] = v[indice];
	v[indice] = aux;

	return;
}
