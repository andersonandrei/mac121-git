
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

posicao *pecasNasParede (int **tabuleiro, int n, int cor, int *tamLista);

int indiceValido (int **tabuleiro, int n, int i, int j);

posicao *checaAdjascentes (int **tabuleiro, int n, int cor, int *tamLista, int i, int j);

int podeMover(int **tabuleiro, int i, int j, int mov, int ultMov, int n, int cor);

posicao anda(int **tabuleiro, int i, int j, int mov, int n) ;

posicao volta(int **tabuleiro, int i, int j, int mov, int *ultMov, int n);

int chegouFinal (int **tabuleiro, int n, int i, int j, int cor);

int checaVitoria (int **tabuleiro, int cor, int n);










