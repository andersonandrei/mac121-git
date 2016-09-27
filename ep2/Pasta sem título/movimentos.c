#include "movimentos.h"

int podeMover(int **tab, int p, int q, int mov, int lin, int col) {
	if (tab[p][q] == 1) {
		if (mov == 0 && q >= 2 && tab[p][q-1] == 1 && 
			tab[p][q-2] == -1) return 1;
		else if (mov == 1 && p < lin-2 && tab[p+1][q] == 1 && 
			tab[p+2][q] == -1) return 1;
		else if (mov == 2 && q < col-2 && tab[p][q+1] == 1 && 
			tab[p][q+2] == -1) return 1;
		else if (mov == 3 && p >= 2 && tab[p-1][q] == 1 && 
			tab[p-2][q] == -1) return 1;
		else return 0;
	}
	else {
		return 0;
	}
}

void movePeca(int **tab,int *p, int *q, int mov, int *espacos, 
	int *pecas){
	if (mov == 0) {
		tab[*p][*q-2] = 1;
		tab[*p][*q-1] = -1;
		tab[*p][*q] = -1;
		*q -= 2;
	}
	else if (mov == 1) {
		tab[*p+2][*q] = 1;
		tab[*p+1][*q] = -1;
		tab[*p][*q] = -1;
		*p += 2;
	}
	else if (mov == 2) {
		tab[*p][*q+2] = 1;
		tab[*p][*q+1] = -1;
		tab[*p][*q] = -1;
		*q += 2;
	}
	
	else if (mov == 3) {
		tab[*p-2][*q] = 1;
		tab[*p-1][*q] = -1;
		tab[*p][*q] = -1;
		*p -= 2;
	}
	*pecas -=1;
	*espacos += 1;
}

void voltaPeca(int **tab,int *p, int *q, int mov, int *espacos, 
	int *pecas){
	if (mov == 0) {
		tab[*p][*q+2] = 1;
		tab[*p][*q+1] = 1;
		tab[*p][*q] = -1;
		*q += 2;
	} 
	else if (mov == 1) {
		tab[*p-2][*q] = 1;
		tab[*p-1][*q] = 1;
		tab[*p][*q] = -1;
		*p -= 2;
	}
	else if (mov == 2) {
		tab[*p][*q-2] = 1;
		tab[*p][*q-1] = 1;
		tab[*p][*q] = -1;
		*q -= 2;
	}
	else if (mov == 3) {
		tab[*p+2][*q] = 1;
		tab[*p+1][*q] = 1;
		tab[*p][*q] = -1;
		*p += 2;
	}
	*pecas +=1;
	*espacos -= 1;
}
