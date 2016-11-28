#include "movimentos.h"
#include "matrizes.h"
#include "pilhas.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


	/*Casa adjascentes dada i,j				 
		i, j-1
		i-1, j
		i-1, j-1
		i, j+1
		i+1, j
		i+1, j+1
		
		[i][j-1]
		[i-1][j]
		[i-1][j-1]
		[i][j+1]
		[i+1][j]
		[i+1][j+1]
		
	*/

int casaLivre (int **tabuleiro, int i, int j) {
	if ( (i >= 0 && i < 14 && j >= 0 && j < 14) && (tabuleiro[i][j] != 1 && tabuleiro[i][j] != 0) )
		return 1;
	return 0;
}

int **jogadaPonte (int **tabuleiro, int **grau, int cor, int n) {
	int i, j;
	for (i = 0; i < n; i++ ){
		for (j = 0; j < n; j++) {
			if (tabuleiro[i][j] == cor) {
				
				if (casaLivre (tabuleiro, i-2, j-1) )
					grau[i-2][j-1] += 10;
				
				if (casaLivre (tabuleiro, i-1, j-2) )
					grau[i-1][j-2] += 10;
				
				if (casaLivre (tabuleiro, i-1, j+1) )
					grau[i-1][j+1] += 10;
				
				if (casaLivre (tabuleiro, i+1, j-1) )
					grau[i+1][j-1] += 10;
	
				if (casaLivre (tabuleiro, i+2, j+1) )
					grau[i+2][j+1] += 10;
					
				if (casaLivre (tabuleiro, i+1, j+2) )
					grau[i+1][j+2] += 10;
			}
		}
	}
	return grau;
}

int **jogadaAdjascente (int **tabuleiro, int **grau, int cor, int n) {
	int i, j;
	for (i = 0; i < n; i++ ){
		for (j = 0; j < n; j++) {
			if (tabuleiro[i][j] == cor) {
				if (casaLivre (tabuleiro, i, j-1) )
					grau[i][j-1] += 5;
					
				if (casaLivre (tabuleiro, i-1, j) )
					grau[i-1][j] += 5;
					
				if (casaLivre (tabuleiro, i-1, j-1) )
					grau[i-1][j-1] += 5;
				
				if (casaLivre (tabuleiro, i, j+1) )
					grau[i][j+1] += 5;
				
				if (casaLivre (tabuleiro, i+1, j) )
					grau[i+1][j] += 5;
				
				if (casaLivre (tabuleiro, i+1, j+1) )
					grau[i+1][j+1] += 5;
			}
		}
	}
	return grau;
}

int **grauJogada (int **tabuleiro, int **grau, int cor, int n) {
	printf("\n Antes da Ponte:\n");
	imprimeMatriz (grau, 14, 14);
	grau = jogadaPonte (tabuleiro, grau, cor, n);
	printf("\n Depois da Ponte:\n");
	imprimeMatriz (grau, 14, 14);
	grau = jogadaAdjascente (tabuleiro, grau, cor, n);
	printf("\n Depois da Adsjacente:\n");
	imprimeMatriz (grau, 14, 14);
	return grau;
}

forcaJogada jogadaMaisForte (int ** grau, int n) {
	int i, k;
	forcaJogada j;
	j = malloc (sizeof (jogada) );
	j -> qnt = 0;
	j -> forca = grau[0][0];
	
	for (i = 0; i < n-1; i ++) {
		for (k = 0; k < n-1; k++) {
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
	while (casaLivre (tabuleiro, possibilidades[sort] -> lin, possibilidades[sort] -> col) == 0) {
		sort = rand() % 10;
		printf("\n Sorteou : %d",sort);
	}
	
	grau[possibilidades[sort] -> lin][possibilidades[sort] -> col] = 0;
	return possibilidades[sort];
}

posicao buscaForcaMatriz(int **tab, int forca) {
	posicao casa;
	int i, j;
	fflush (stdout);
	casa = malloc (sizeof (pos) );
	
	for (i = 0; i < 14; i++) {
		for (j = 0; j < 14; j++) {
			if (tab[i][j] == forca) {
				casa -> lin = i;
				casa -> col = j;
				tab[i][j] = 0;
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
	
	printf("\n Entrou nas Pecas aprede, n = %d",n);
	fflush(stdout);
	if (cor == 1) { /* Definido que brancas vao da linha 0 até a linha n */
		printf("\n Cor = %d",cor);
		fflush(stdout);
		for (i = 0; i < n; i++) {
			printf("\n i = %d",i);
			if (tabuleiro[0][i] == 1) {
				printf("\n colocou na lista das paredes na pos k %d: %d %d",k,0,i);
				p -> lin = 0;
				p -> col = i;
				printf("\n colocou na lista das paredes na pos k %d: %d---",k,i);
				lista[k] = p;
				k++;
				
			}
		}
		printf("\n Confirmando 1--------:");
		for (i = 0; i < k; i++ )
			printf("\n\n em %d : %d %d",i, lista[i] -> lin, lista[i] -> col );
	}
	
	else {
		printf("\n Cor = %d",cor);
		fflush(stdout);
		for (i = 0; i < n; i++) {
			printf("\n Ta no i,j = %d",i);
			fflush(stdout);
			if (tabuleiro[i][0] == 0) {
				printf("\n Achou");
				fflush(stdout);
				p -> lin = i;
				p -> col = 0;
				lista[k] = p;
				k++;
			}
		}
		printf("\n Confirmando  2--------:");
		for (i = 0; i < k; i++ )
			printf("\n\n em %d : %d %d",i, lista[i] -> lin, lista[i] -> col );
	}
	printf("\n Fim");
	fflush(stdout);
	*tamLista = k;
	
	printf("\n Confirmando --------:");
	for (i = 0; i < *tamLista; i++ )
		printf("\n\n em %d : %d %d",i, lista[i] -> lin, lista[i] -> col );
	
	
	return lista;
}

int indiceValido (int **tabuleiro, int n, int i, int j) {
	if ((i >= 0 && i < n) && (j >= 0 && j < n)) return 1;
	return 0;

}

posicao *checaAdjascentes (int **tabuleiro, int n, int cor, int *tamLista, int i, int j) {
	posicao *lista, p;
	int k = 0;
	p = malloc (sizeof (pos) );
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
	if (mov == 1 && ultMov != 4 && checaNoVetor(vetor, tamVetor, i, j) == 0) 
		if (indiceValido (tabuleiro, n, i, j+1) && tabuleiro [i][j+1] == cor ) return 1;
	if (mov == 2 && ultMov != 5 && checaNoVetor(vetor, tamVetor, i, j) == 0) 
		if (indiceValido (tabuleiro, n, i-1, j) && tabuleiro [i-1][j] == cor ) return 1;
	if (mov == 3 && ultMov != 6 && checaNoVetor(vetor, tamVetor, i, j) == 0) 
		if (indiceValido (tabuleiro, n, i-1, j-1) && tabuleiro [i-1][j-1] == cor ) return 1;
	if (mov == 4 && ultMov != 1 && checaNoVetor(vetor, tamVetor, i, j) == 0) 
		if (indiceValido (tabuleiro, n, i, j-1) && tabuleiro [i][j-1] == cor )  return 1;
	if (mov == 5 && ultMov != 2 && checaNoVetor(vetor, tamVetor, i, j) == 0) 
		if (indiceValido (tabuleiro, n, i+1, j) && tabuleiro [i+1][j] == cor )return 1;
	if (mov == 6 && ultMov != 3 && checaNoVetor(vetor, tamVetor, i, j) == 0) 
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
		printf("\n Entrou pra desandar aqui ---");
		p -> lin = i-1;
		p -> col = j;
		printf("\n\n OLHAAAAAa para %d %d", p-> lin, p -> col );
		*ultMov = 2;
	}
	if (mov == 6) {
		p -> lin = i-1;
		p -> col = j-1;
		*ultMov = 3;
	}
	printf("\n\n OLHAAAAAa 2  para %d %d", p-> lin, p -> col );
	return p;
}

int chegouFinal (int **tabuleiro, int n, int i, int j, int cor) {
	if (cor == 1) {
		if (i != 13)
			return 0;
		return 1;
	}
	else {
		if (j != 13)
			return 0;
		return 1;
	}
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
	for (i = 0; i < n * n; i++) {
		if (vetor[i] -> lin == l && vetor[i] -> col == c)
			return 1;
	}
	return 0;
}

int checaVitoria (int **tabuleiro, int cor, int n) {
	posicao *parede;
	int i, qntParede = 0, fim = 0;
	parede = malloc (n * sizeof (pos) );
	parede = pecasNasParede (tabuleiro, n, cor, &qntParede);
	for (i = 0; i < qntParede; i++) {
		fim = checaCaminho (tabuleiro, cor, n, parede[i] -> lin, parede[i] -> col);
		if (fim == 1)
			return 1;
	}
	return 0;
}


int checaCaminho (int **tabuleiro, int cor, int n, int lin, int col) {
	int mov , ultMov, ok, atual, qntJaViu = 1;
	posicao p, *jaViu;
	pilha *movimento;
	jaViu = malloc ((n*n) * sizeof (pos) );
	zeraVetorPos (jaViu, n);
	p = malloc (sizeof (pos) );
	p -> lin = lin;
	p -> col = col;
	jaViu[0] = p;
	movimento = criaPilha(n*n);
	if (movimento == NULL) printf("\n merda");
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
		if(ok ==1) {
			printf("\n Moveu para %d",mov);
			empilha(movimento,mov);
			p = anda(tabuleiro,p -> lin, p -> col,mov,n);
			jaViu[qntJaViu] = p;
			atual++;
			ultMov = mov;
			mov = 1;
			
		}
		else { /* BakcTrack*/
			if(pilhaVazia(movimento) == 1) {
				printf("\n Deu ruim.");
				return 0;
			}
			else { 
				printf("\n Despula: ");
				mov = desempilha(movimento);
				printf("\n mov antigo: %d",mov);
				p = volta(tabuleiro,p -> lin, p -> col,mov,&ultMov,n);
				printf("\n ultmov : %d",ultMov);
				atual--;
				mov++;
			}
		}
	}
	
	if (chegouFinal (tabuleiro, n, p -> lin,p -> col, cor) == 1)
		return 1;
	return 0;
}



