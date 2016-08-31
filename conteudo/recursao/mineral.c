#include <stdio.h>

float mineral (int n) {
	if (n == 1) return 2;
	else return 1+1/mineral(n-1);
}

int main() {
	int n;
	printf(" Will mineral.\n");
	printf(" Insira o grau de sua mineralidade: ");
	scanf("%d",&n);
	printf(" Willneral = %.1f . \n", mineral(n));
	return 0;
}
