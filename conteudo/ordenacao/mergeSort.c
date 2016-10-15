#include <stdlib.h>
#include <stdio.h>

void intercala(int *v, int i, int m, int f);
void mergeSort(int *v, int i, int f);

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
	
	mergeSort(v, 0, n-1);
	printf("\n");
	for(i = 0; i < n; i++)
		printf("%d ",v[i]);
	printf("\n");	
	
	return 0;
}

void intercala(int *v, int i, int m, int f) {
	int p,q,r;
	int *w;
	w = malloc((f-i+1) * sizeof(int));
	p = i;
	q = m+1;
	r = 0;
	while (p <= m && q <= f) {
		if (v[p] <= v[q]) {
			w[r] = v[p];
			r++;
			p++;
		}
		else {
			w[r] = v[q];
			r++;
			q++;
		}
	}
	while(p <= m){
		w[r] = v[p];
		r++;
		p++;
	}
	while(q <= f) {
		w[r] = v[q];
		r++;
		q++;
	}
	for(p = 0; p < r; p++)
		v[i+p] = w[p];
	free(w);
		
	return;
}

void mergeSort(int *v, int i, int f) {
	int meio;
	if (f > i) {
		
		meio = ((f+i)/2) ;
		printf("\n Aquii, meio = %d",meio);
		mergeSort(v,i,meio);
		mergeSort(v,meio+1,f);
		intercala(v,i,meio,f);
		
	}
	return;
}
