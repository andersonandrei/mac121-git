#include <stdlib.h>
#include <stdio.h>

void ordenaSelecao(int *v, int n);

int main() {
	int n, i;
	int *v;
	
	scanf("%d",&n);
	
	v = malloc (n* sizeof(int));
	if (v == NULL)
		return 0;
	for (i = 0; i < n; i++) 
		scanf("%d",&v[i]);
	printf("\n");
	for(i = 0; i < n; i++)
		printf("%d ",v[i]);
	printf("\n");	
	
	ordenaSelecao(v, n);
	printf("\n");
	for(i = 0; i < n; i++)
		printf("%d ",v[i]);
	printf("\n");	
	
	return 0;
}

void ordenaSelecao (int *v, int n) {
	int i, j, aux, ind;
	
	for (i = 0; i < n; i++) {
		ind = i;
		for (j = i+1; j < n; j++) {
			if (v[j] < v[ind]){
				ind = j;
			}
		}
		if (ind != i) {
			aux = v[i];
			v[i] = v[ind];
			v[ind] = aux;
		}
	}
	return;
}
