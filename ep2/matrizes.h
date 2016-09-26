/* Recebe dois inteiros lin,col e devolve o endereço de uma matriz 
 * de dimensão mxn alocada dinamicamente. */
int **criaMatriz(int lin, int col);

/* Recebe o endereço de uma matriz, seu número de lin e colunas e 
 * zera todos os seus elementos. */
void zeraMatriz(int **tab, int lin, int col);

/* Recebe o endereço de uma matriz, seu número de lin e colunas e
 * libera o espaço que foi alocado para tal. */
void destroiMatriz(int **tab, int lin, int col);

/* Recebe o endereço de uma matriz, seu número de lin e colunas e
 * imprime a matriz */
void imprimeMatriz(int **tab, int lin, int col);

void montaTabuleiro77(int **tab);

void montaTabuleiro33(int **tab);

void montaTabuleiro43(int **tab);

/* Recebe o endereço de duas matrizes, o número de linhas e colunas de
 * ambas (que são de mesma dimensão) e troca (ou inverte) os valores da 
 * primeira da seguinte forma: 1 por -1 e -1 por 1, 
 * e armazena na seguunda */
void inverteMatriz (int **tab, int **tabInversa, int lin, int col);

/* Recebe o endereço de duas matrizes, o número de linhas e colunas de
 * ambas (que são de mesma dimensão) compara todos os elementos de ambas
 * verificando se todos são iguais. Se sim, devolve 1. Caso contrário,
 * devolve 0. */
int comparaMatriz (int **tabA, int **tabB, int lin, int col);
