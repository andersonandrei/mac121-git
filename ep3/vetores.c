#include "vetores.h"

int *criaVetor(int *v, int n) {
	v = malloc (n * sizeof(int));
	if (v != NULL)
		return v;
	return 0;
}

void zeraVetor (int *v, int n) {
	int i;
	for (i = 0; i < n; i++)
		v[i] = 0;
	return;
}

void destroiVetor (int *v) {
	free(v);
}

void imprimeVetor (int *v, int n) {
	int i;
	for (i=0; i < n; i++)
		printf("%d ",v[i]);
	return ;
}

int compara (int *v, int *w, int n) {
	int i;
	for (i=0; i < n; i++)
		if (v[i] != w[i])
			return 0;
	return 1;
}

