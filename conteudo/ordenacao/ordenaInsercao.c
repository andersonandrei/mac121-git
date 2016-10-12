#include <stdlib.h>
#include <stdio.h>

void ordenaInsercao(int *v, int n);

int main() {
	int n, i;
	int *v;
	
	scanf("%d",&n);
	
	v = malloc (n* sizeof(int));
	if (v == NULL)
		return 0;
	for (i = 0; i < n; i++) 
		scanf("%d",&v[i]);
	ordenaInsercao(v, n);
	printf("\n");
	for(i = 0; i < n; i++)
		printf("%d ",v[i]);
	printf("\n");	
	
	return 0;
}

void ordenaInsercao (int *v, int n) {
	int i,j,k,aux;
	
	for(i = 0; i < n-1; i++) {
		j = i + 1;
		k = i;
		while(v[j] < v[k] && k >= 0) {
			aux = v[k];
			v[k] = v[j];
			v[j] = aux;
			k--;
			j--;
		}	
	}
	
	return;
}

