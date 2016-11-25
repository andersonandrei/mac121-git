
typedef struct c0 {
	int lin;
	int col;
	int uso;
	} casa
	
typedef struct c0 *casa;

typedef struct j0 {
	int forca;
	int qnt;
}	jogada;

typedef struct j0 *forcaJogada;

typedef struct p0 {
	int lin;
	int col;
} pos;

typedef struct * posicao;

casa **criaTabuleiro (int n) {
	int i;
	casa **tabuleiro;
	tabuleiro = malloc (n * sizeof (casa) );
	for (i = 0; i < n; i++)
		tabuleiro[i] = malloc (n * sizeof (casa) );
	return tabuleiro;
}




