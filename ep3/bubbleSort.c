#include "bubbleSort.h"

void bubbleSort(int *v, int n){
	int i, j, k, l, aux;
	for (i = 0; i < n; i++) {
		k = 0;
		for (j = k+2; j < n - 1 - i; j+=2) {
			if (v[j] < v[k]) {
				aux = v[k];
				v[k] = v[j];
				v[j] = aux;
			}
			k+=2;
		}
		l = 1;
		for (j = l+2; j < n - i ; j+=2) {
			if (v[j] < v[l]) {
				aux = v[l];
				v[l] = v[j];
				v[j] = aux;
			}
			l+=2;
		}
	}
	return;
}
