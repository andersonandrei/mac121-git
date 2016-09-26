
/* Struct que armazena os dados (linha,coluna e movimento feito) 
 * dos movimentos que serão empilhados*/
typedef struct {
	int l;
	int c;
	int mv;
} movimento;

/* Struct que define uma pilha */
typedef struct {
	int topo;
	movimento *v;
	int tam;
} pilha;

/* Recebe um inteiro n e devolve uma pilha de tamanhao n 
 * alocada dinamicamente. */
pilha *criaPilha (int n);

/* Recebe um ponteiro para um pilha e devolve 1 se ela 
 * estiver vazia ou 0 caso contrário.*/
int pilhaVazia(pilha *p);

/* Recebe um ponteiro para um pilha e devolve 1 se ela 
 * estiver cheia ou 0 caso contrário.*/
int pilhaCheia (pilha *p);

/* Recebe um ponteiro para um pilha, um ponteiro para 
 * movimento e um ponteiro para um inteiro tamanho (tam). 
 * Então desempilha o elemento do topo da pilha e altera 
 * diretamente os valores de movimento através do 
 * ponteiro recebido. */
void desempilha (pilha *p, movimento *mov, int *tam);

/* Recebe o ponteiro para um pilha, um ponteiro para 
 * movimento e um ponteiro para um inteiro tamanho (tam)
 *  e empilha o movimento na pilha. */
void empilha (pilha *p, movimento n, int *tam);

/* Recebe um ponteiro para pilha e devolve o elemento do topo.*/
int topoPilha(pilha *p);

/* Recebe um ponteiro para um pilha e libera o espaço que foi alocado 
 * para a mesma.*/
void destroiPilha(pilha *p);
