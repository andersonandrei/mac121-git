#include <stdlib.h>
#include <stdio.h>

void bubblesort(int *v, int n);

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
	
	bubblesort(v, n);
	printf("\n");
	for(i = 0; i < n; i++)
		printf("%d ",v[i]);
	printf("\n");	
	
	return 0;
}

void bubblesort(int *v, int n){
	int i,j,k, aux;
	for (i = 0; i < n; i++) {
		k = 0;
		for (j = k+1; j < n - i; j++) {
			if (v[j] < v[k]) {
				aux = v[k];
				v[k] = v[j];
				v[j] = aux;
			}
			k++;
		}
	}
	return;
}
