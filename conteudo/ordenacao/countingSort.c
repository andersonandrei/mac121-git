#include <stdlib.h>
#include <stdio.h>

void countingSort(int *v, int n, int a, int b);

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
	countingSort(v, n, 0, 100);
	printf("\n");
	for(i = 0; i < n; i++)
		printf("%d ",v[i]);
	printf("\n");	
	
	return 0;
}

void countingSort(int *v, int n, int a, int b) {
	int i,j;
	int *w;
	w = malloc(b*sizeof(int));
	if (w == NULL) return;
	for (i=0; i<b; i++)
		w[i] = 0;
	for (i=0; i<n; i++)
		w[v[i]]++;
	j=0;
	for(i=0; i<b; i++) {
		while (w[i] >0) {
			v[j++] = i;
			w[i]--;
		}
	}
	return;
}

