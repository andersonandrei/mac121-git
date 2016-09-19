#include <stdio.h>
#define MAX 10 

void movePeca(tab, p, q, mov);
void voltaPeca(tab, p, q, mov);

/* 33 espaços, 32 ocupados */
int restaUm(int m, int n, int tab[][]) {
	int l,c;
	int i,j,p,q;
	int peca, atual, mov;
	int numBInic,numPInic,numBrancas, numPretas;
	int ok;
	
	numBInic = numBrancas = 1;
	numPInic = numPretas = 32;
	p = q = 0;
	
	atual = tab[p][q];
	ok = 1;
	
	/* while (numBrancas != numPInic && ok == 1){ */
	for (q = 0; q<n && (tab[p][q] != 1 && numPretas == 1); q++) {
		/* Procurando por -1 */
		mov = 0;
		while (mov < 3) {
			if (podeMover(tab, p, q, mov) == 1) {
				movePeca(tab, p, q, mov, &numeroBrancas, &numeroPretas);
				if (restaUm(m, n, tab)) return 1;
				voltaPeca(tab, p, q, mov,&numeroBrancas, &numeroPretas);
			}
			mov++;
		}
	}
	return 0;
}

int podeMover(tab, p, q, mov) {
	if (mov == 0 && p >= 2 && tab[p][q] == 1) return 1;
	else if (mov == 1 && p >= 2 && tab[p][q] == 1) return 1;
	else if (mov == 2 && p < m 2 && tab[p][q] == 1) return 1;
	else if (mov == 3 && q >= 2 && tab[p][q] == 1) return 1;
	return 0;
	
}

void movePeca(tab, p, q, mov, *numBrancas, *numPretas){
	if (mov == 0) {
		tab[p-2][q] = -1;
		tab[p-1][q] = -1;
		tab[p][q] = 1;
	}
	else if (mov == 1) {
		tab[p][q-2] = -1;
		tab[p][q-1] = -1;
		tab[p][q] = 1;
	}
	else if (mov == 2) {
		tab[p+2][q] = -1;
		tab[p+1][q] = -1;
		tab[p][q] = 1;
	}
	else if (mov == 3) {
		tab[p][q+2] = -1;
		tab[p][q+1] = -1;
		tab[p][q] = 1;
	}
	*numPretas -=1;
	*numBrancas += 1;
}

void voltaPeca(tab, p, q, mov, *numBrancas, *numPretas){
	if (mov == 0) {
		tab[p-2][q] = 1;
		tab[p-1][q] = 1;
		tab[p][q] = -1;
	}
	else if (mov == 1) {
		tab[p][q-2] = 1;
		tab[p][q-1] = 1;
		tab[p][q] = -1;
	} 
	else if (mov == 2) {
		tab[p+2][q] = 1;
		tab[p+1][q] = 1;
		tab[p][q] = -1;
	}
	else if (mov == 3) {
		tab[p][q+2] = 1;
		tab[p][q+1] = 1;
		tab[p][q] = -1;
	}
	*numPretas +=1;
	*numBrancas -= 1;
}
