#include "movimentos.h"
#include "matrizes.h"
#include "pilhas.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int casaLivre (int **tabuleiro,int n, int i, int j) {
	if ( i >= 0 && i < n && j >= 0 && j < n && tabuleiro[i][j] != 1 && tabuleiro[i][j] != 0 )
		return 1;
	return 0;
}

int **jogadaLivre(int **tabuleiro, int n, int **grau, int cor) {
	int i, j;
	for (i = 0; i < n; i++ ){
		for (j = 0; j < n; j++) {
			if (tabuleiro[i][j] == -2) {
				grau[i][j] = 0;
			}
		}
	}
	return grau;
}

int existeJogada (int **grau, int n) {
	int i, j ;
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			if (grau[i][j] == 0)
				return 1;
	return 0;
}

int **jogadaPonte (int **tabuleiro, int n, int **grau, int cor) {
	int i, j;
	for (i = 0; i < n; i++ ){
		for (j = 0; j < n; j++) {
			if (tabuleiro[i][j] == cor) {
				
				if (casaLivre (tabuleiro, n, i-2, j-1) )
					grau[i-2][j-1] += 10;
				
				if (casaLivre (tabuleiro, n, i-1, j-2) )
					grau[i-1][j-2] += 10;
				
				if (casaLivre (tabuleiro, n, i-1, j+1) )
					grau[i-1][j+1] += 10;
				
				if (casaLivre (tabuleiro, n, i+1, j-1) )
					grau[i+1][j-1] += 10;
	
				if (casaLivre (tabuleiro, n, i+2, j+1) )
					grau[i+2][j+1] += 10;
					
				if (casaLivre (tabuleiro, n, i+1, j+2) )
					grau[i+1][j+2] += 10;
			}
		}
	}
	return grau;
}

int **jogadaAdjascente (int **tabuleiro, int n, int **grau, int cor) {
	int i, j;
	for (i = 0; i < n; i++ ){
		for (j = 0; j < n; j++) {
			if (tabuleiro[i][j] == cor) {
				if (casaLivre (tabuleiro, n, i, j-1) )
					grau[i][j-1] += 5;
					
				if (casaLivre (tabuleiro, n, i-1, j) )
					grau[i-1][j] += 5;
					
				if (casaLivre (tabuleiro, n, i-1, j-1) )
					grau[i-1][j-1] += 5;
				
				if (casaLivre (tabuleiro, n, i, j+1) )
					grau[i][j+1] += 5;
				
				if (casaLivre (tabuleiro, n, i+1, j) )
					grau[i+1][j] += 5;
				
				if (casaLivre (tabuleiro, n, i+1, j+1) )
					grau[i+1][j+1] += 5;
			}
		}
	}
	return grau;
}

int **grauJogada (int **tabuleiro, int n, int **grau, int cor) {	
	grau = jogadaLivre(tabuleiro, n, grau, cor);
	grau = jogadaPonte (tabuleiro, n, grau, cor);
	grau = jogadaAdjascente (tabuleiro, n, grau, cor);
	return grau;
}

forcaJogada jogadaMaisForte (int ** grau, int n) {
	int i, k;
	forcaJogada j;
	j = malloc (sizeof (jogada) );
	
	for (i = 0; i < n; i++) {
		for (k = 0; k < n; k++) {
			if (grau[i][k] >= 0) {
				j -> qnt = 1;
				j -> forca = grau[i][k];
			}
		}
	}
	
	for (i = 0; i < n; i ++) {
		for (k = 0; k < n; k++) {
			if (grau[i][k] == j -> forca) {
				j -> qnt ++;
			}
			else if (grau[i][k] > j -> forca) {
				j -> forca = grau[i][k];
				j -> qnt = 1;
			}
		}
	}
	return j;
}
	
posicao sorteiaJogada (int **tabuleiro, int **grau, int n, int g, int qnt) {
	posicao *possibilidades, p;
	int i, j , k = 0, sort;
	srand( (unsigned)time(NULL) );
	p = malloc (sizeof (pos) );
	possibilidades = malloc (sizeof (qnt * sizeof (pos)) );
	zeraVetorPos(possibilidades, qnt);
	for (i = 0; i < n; i++) {
		for (j = 0; j <n; j++) {
			if (grau[i][j] == g) {
				p -> lin = i;
				p -> col = j;
				possibilidades[k] = p;
				k++; 
			}
		}
	}
	sort = 0; /* Ajustar o sort */
	/* while (casaLivre (tabuleiro,  n, possibilidades[sort] -> lin, possibilidades[sort] -> col) == 0) {
		sort = rand() % 10;
		printf("\n Sorteou : %d",sort);
	}
	*/
	grau[possibilidades[sort] -> lin][possibilidades[sort] -> col] = 0;
	return possibilidades[sort];
}

posicao buscaForcaMatriz(int **tabuleiro, int n, int **grau, int forca) {
	posicao casa;
	int i, j;
	casa = malloc (sizeof (pos) );

	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			if (grau[i][j] == forca && tabuleiro[i][j] != 1 && tabuleiro[i][j] != 0 ) {
				casa -> lin = i;
				casa -> col = j;
				grau[i][j] = 0;
			}
		}
	}
	return casa;
}

posicao *pecasNasParede (int **tabuleiro, int n, int cor, int *tamLista) {
	posicao *lista, p;
	int i, k = 0;
	p = malloc (sizeof (pos) );
	lista = malloc (n * sizeof (pos) );

	if (cor == 1) { /* Definido que brancas vao da linha 0 até a linha n */
		for (i = 0; i < n; i++) {
			if (tabuleiro[0][i] == 1) {
				p -> lin = 0;
				p -> col = i;
				lista[k] = p;
				k++;
			}
		}
	}
	
	else {
		for (i = 0; i < n; i++) {
			if (tabuleiro[i][0] == 0) {
				p -> lin = i;
				p -> col = 0;
				lista[k] = p;
				k++;
			}
		}
	}

	*tamLista = k;

	return lista;
}

int indiceValido (int **tabuleiro, int n, int i, int j) {
	if ((i >= 0 && i < n) && (j >= 0 && j < n)) return 1;
	return 0;
}

posicao *checaAdjascentes (int **tabuleiro, int n, int cor, int *tamLista, int i, int j) {
	posicao *lista, p;
	int k = 0;
	p = malloc (sizeof (pos));
	lista = malloc (n * sizeof (pos) );

	if (indiceValido (tabuleiro, n, i, j-1) && tabuleiro [i][j-1] == cor ) {
		p -> lin = i;
		p -> col = j-1;
		lista[k] = p;
		k++;
	}
	if (indiceValido (tabuleiro, n, i-1, j) && tabuleiro [i-1][j] == cor ) {
		p -> lin = i-1;
		p -> col = j;
		lista[k] = p;
		k++;
	}
	if (indiceValido (tabuleiro, n, i-1, j-1) && tabuleiro [i-1][j-1] == cor ) {
		p -> lin = i-1;
		p -> col = j-1;
		lista[k] = p;
		k++;
	}
	if (indiceValido (tabuleiro, n, i, j+1) && tabuleiro [i][j+1] == cor ) {
		p -> lin = i;
		p -> col = j+1;
		lista[k] = p;
		k++;
	}
	if (indiceValido (tabuleiro, n, i+1, j) && tabuleiro [i+1][j] == cor ) {
		p -> lin = i+1;
		p -> col = j;
		lista[k] = p;
		k++;
	}
	
	if (indiceValido (tabuleiro, n, i+1, j+1) && tabuleiro [i+1][j+1] == cor ) {
		p -> lin = i+1;
		p -> col = j+1;
		lista[k] = p;
		k++;
	}
	
	*tamLista = k;
	return lista;
}

int podeMover(int **tabuleiro, int i, int j, int mov, int ultMov, int n, int cor, posicao *vetor, int tamVetor) {
	if (mov == 1 && ultMov != 4 && checaNoVetor(vetor, tamVetor, i, j+1) == 0) 
		if (indiceValido (tabuleiro, n, i, j+1) && tabuleiro [i][j+1] == cor ) return 1;
	if (mov == 2 && ultMov != 5 && checaNoVetor(vetor, tamVetor, i-1, j) == 0) 
		if (indiceValido (tabuleiro, n, i-1, j) && tabuleiro [i-1][j] == cor ) return 1;
	if (mov == 3 && ultMov != 6 && checaNoVetor(vetor, tamVetor, i-1, j-1) == 0) 
		if (indiceValido (tabuleiro, n, i-1, j-1) && tabuleiro [i-1][j-1] == cor ) return 1;
	if (mov == 4 && ultMov != 1 && checaNoVetor(vetor, tamVetor, i, j-1) == 0) 
		if (indiceValido (tabuleiro, n, i, j-1) && tabuleiro [i][j-1] == cor )  return 1;
	if (mov == 5 && ultMov != 2 && checaNoVetor(vetor, tamVetor, i+1, j) == 0) 
		if (indiceValido (tabuleiro, n, i+1, j) && tabuleiro [i+1][j] == cor )return 1;
	if (mov == 6 && ultMov != 3 && checaNoVetor(vetor, tamVetor, i+1, j+1) == 0) 
		if (indiceValido (tabuleiro, n, i+1, j+1) && tabuleiro [i+1][j+1] == cor ) return 1;
	return 0;
}

posicao anda(int **tabuleiro, int i, int j, int mov, int n) {
	posicao p;
	p = malloc (sizeof (pos) );
	if (mov == 1) {
		p -> lin = i;
		p -> col = j+1;
	}
	if (mov == 2) {
		p -> lin = i-1;
		p -> col = j;
	}
	
	if (mov == 3) {
		p -> lin = i-1;
		p -> col = j-1;
	}
	if (mov == 4) {
		p -> lin = i;
		p -> col = j-1;
	}
	if (mov == 5) {
		p -> lin = i+1;
		p -> col = j;
	}
	if (mov == 6) {
		p -> lin = i+1;
		p -> col = j+1;
	}
	return p;
}

posicao volta(int **tabuleiro, int i, int j, int mov, int *ultMov, int n) {
	posicao p;
	p = malloc (sizeof (pos) );
	if (mov == 1) {
		p -> lin = i;
		p -> col = j-1;
		*ultMov = 4;
	}
	if (mov == 2) {
		p -> lin = i+1;
		p -> col = j;
		*ultMov = 5;
	}
	
	if (mov == 3) {
		p -> lin = i+1;
		p -> col = j+1;
		*ultMov = 6;
	}
	if (mov == 4) {
		p -> lin = i;
		p -> col = j+1;
		*ultMov = 1;
	}
	if (mov == 5) {
		p -> lin = i-1;
		p -> col = j;
		*ultMov = 2;
	}
	if (mov == 6) {
		p -> lin = i-1;
		p -> col = j-1;
		*ultMov = 3;
	}
	return p;
}

int chegouFinal (int **tabuleiro, int n, int i, int j, int cor) {
	if (cor == 1) {
		if (i != n-1)
			return 0;
		return 1;
	}
	if (cor == 0) {
		if (j != n-1)
			return 0;
		return 1;
	}
	return 0;
}

void zeraVetorPos (posicao *vetor, int n) {
	posicao p = malloc (sizeof (pos) );
	int i;
	p -> lin = -1;
	p -> col = -1;
	for (i = 0; i < n; i++)
		vetor[i] = p;
	return;
}

int checaNoVetor (posicao *vetor, int n, int l, int c) {
	int i;
	fflush(stdout);
	for (i = 0; i < n ; i++) {
		if (vetor[i] -> lin == l && vetor[i] -> col == c)
			return 1;
	}
	return 0;
}

int checaVitoria (int **tabuleiro, int cor, int n) {
	posicao p;
	int i, fim = 0;
	p = malloc (sizeof (pos));
	if (cor == 1) {
		for (i = 0; i < n-1; i++) {
			if (tabuleiro[0][i] == cor) {
				p -> lin = 0;
				p -> col = i;
			
				fim = checaCaminho (tabuleiro, cor, n, p -> lin, p -> col);
				if (fim == 1)
					return 1;
			}	
		}
	}
	
	if (cor == 0) {
		for (i = 0; i < n-1; i++) {
			if (tabuleiro[i][0] == cor) {
				p -> lin = i;
				p -> col = 0;
			
				fim = checaCaminho (tabuleiro, cor, n, p -> lin, p -> col);
				if (fim == 1)
					return 1;		
			}
		}
	}
	return 0;
}


int checaCaminho (int **tabuleiro, int cor, int n, int lin, int col) {
	int mov , ultMov, ok, atual, qntJaViu = 0;
	posicao p, *jaViu;
	pilha *movimento;
	jaViu = malloc ((n*n) * sizeof (pos));
	zeraVetorPos (jaViu, n);
	p = malloc (sizeof (pos) );
	p -> lin = lin;
	p -> col = col;
	movimento = criaPilha(n*n);
	if (movimento == NULL) return 0;
	atual = 1;
	mov = 1;
	ok=0;
	while(tabuleiro[p->lin][p->col] == cor && chegouFinal (tabuleiro, n, p -> lin,p -> col, cor) == 0 ) {
		ok=0;
		while(mov <= 6 && ok == 0){
			if (podeMover(tabuleiro,p -> lin, p -> col,mov, ultMov, n, cor, jaViu, qntJaViu) == 1)
			{
				ok = 1;
			}
			else
			{
				mov ++;
			}
		}
		if(ok == 1) {
			empilha(movimento,mov);
			jaViu[qntJaViu] = p;
			qntJaViu ++;
			p = anda(tabuleiro, p -> lin, p -> col,mov, n);
			
			atual++;
			ultMov = mov;
			mov = 1;
			
		}
		else { /* BakcTrack*/
			if(pilhaVazia(movimento) == 1) {
				return 0;
			}
			else { 
				mov = desempilha(movimento);
				p = volta(tabuleiro,p -> lin, p -> col,mov,&ultMov,n);
				atual--;
				mov++;
			}
		}
	}
	if (chegouFinal (tabuleiro, n, p -> lin,p -> col, cor) == 1)
		return 1;
	return 0;
}



