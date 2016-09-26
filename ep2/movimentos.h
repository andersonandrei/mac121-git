/* Recebe um ponteiro para uma matriz tab, e inteiros p,q,mov,lin,col
 * representando respectivamente a posição (p,q) do elemento, 
 * um movimento e a dimensão da matriz tab lin x col.
 * Devolve se é possível fazer o movimento mov no tabuleiro tab dadas 
 * as condições dos paramentros recebidos.  */
int podeMover(int **tab, int p, int q, int mov, int lin, int col);

/* Recebe um ponteiro para uma matriz tab, ponteiros para inteiros p,q,
 * espaços e peças, e um inteiro mov representando respectivamente a 
 * posição (p,q) do elemento a ser movido, o número de espaços e peças 
 * no tabuleiro tab e o movimento em questão.
 * O movimento mov é feito, e as alterações necessárias são feitas 
 * diretamentes no tabuleiro tab. */
void movePeca(int **tab,int *p, int *q, int mov, int *espacos, int *pecas);

/* Recebe um ponteiro para uma matriz tab, ponteiros para inteiros p,q,
 * espaços e peças, e um inteiro mov representando respectivamente a 
 * posição (p,q) do elemento a ser movido, o número de espaços e peças 
 * no tabuleiro tab e o movimento em questão.
 * O movimento mov é desfeito, e as alterações necessárias são feitas 
 * diretamentes no tabuleiro tab. */
void voltaPeca(int **tab,int *p, int *q, int mov, int *espacos, int *pecas);
