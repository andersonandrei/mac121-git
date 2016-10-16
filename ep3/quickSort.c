#include "quickSort.h"

int separa(int *v, int i, int f);
void quickSort(int *v, int i, int f);
/*
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
	
	quickSort(v, 0, n-1);
	printf("\n");
	for(i = 0; i < n; i++)
		printf("%d ",v[i]);
	printf("\n");	
	
	return 0;
}
*/
int separa(int *v, int i, int f) {
	int j, k, aux, pos = 0;
	j = i;
	k = f;
	while (j != k) {
		if (v[k] <= v[j]) {
			aux = v[j];
			v[j] = v[k];
			v[k] = aux;
			if (pos == 0){
				pos = 1;
				j++;
			}
			else {
				pos = 0;
				k--;
			}
		}
		else
			if(pos == 0)
				k--;
			else 
				j++;
	}
	return j;
}

void quickSort(int *v, int i, int f) {

	int ind;
	if (f > i) {
		ind = separa(v, i, f);
		quickSort(v, i, ind-1);
		quickSort(v, ind + 1, f);
	}
	return;
}
