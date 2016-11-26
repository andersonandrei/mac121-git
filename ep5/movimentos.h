
typedef struct j0 {
	int forca;
	int qnt;
}	jogada;

typedef struct p0 {
	int lin;
	int col;
} pos;

typedef jogada *forcaJogada;

typedef pos *posicao;

int casaLivre (int **tabuleiro, int i, int j);

int **jogadaPonte (int **tabuleiro, int **grau, int cor, int n);

int **jogadaAdjascente (int **tabuleiro, int **grau, int cor, int n);

int **grauJogada (int **tabuleiro, int **grau, int cor, int n);

forcaJogada jogadaMaisForte (int ** grau, int n);
	
posicao sorteiaJogada (int **tabuleiro, int **grau, int n, int g, int qnt);

posicao buscaForcaMatriz(int **tab, int forca);









