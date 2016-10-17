#include <stdlib.h>
#include <stdio.h>

void rebaixa(int *v, int n, int i);
void heapfica(int *v, int n);
void heapSort(int *v, int n);

int main() {
	int n, i;
	int *v;

	printf("\n %d \n",'andrei');
	
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
	heapSort(v, n);
	printf("\n");
	for(i = 0; i < n; i++)
		printf("%d ",v[i]);
	printf("\n");	
	
	return 0;
}

void rebaixa (int *v, int n, int i) {
	int aux, filho;
	filho = 2*i + 1;
	while(filho < n) {
		if (filho + 1 < n && v[filho] < v[filho+1])
			filho = filho + 1;
		
		if (v[i] < v[filho]) {
			aux = v[i];
			v[i] = v[filho];
			v[filho] = aux;
			i = filho;
		}
		filho = (2*filho) + 1;
	}
	return ;
}

void heapfica (int *v, int n) {
	int i;
	for (i=(n-2)/2; i>=0; i--){
		rebaixa(v,n,i);
	}
	return;
}

void heapSort(int *v, int n) {
	int i,aux;
	heapfica(v,n);
	for (i=n-1;i>0;i--) {
		aux = v[i];
		v[i] = v[0];
		v[0] = aux;
		rebaixa(v,i,0);
	}
	return;
}
