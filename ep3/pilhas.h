
/* Struct que define uma pilha */
typedef struct {
	int topo;
	int *v;
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
 * movimento. 
 * Então desempilha o elemento do topo da pilha e altera 
 * diretamente os valores de movimento através do 
 * ponteiro recebido. */
int desempilha (pilha *p);

/* Recebe o ponteiro para um pilha, um ponteiro para 
 * movimento e empilha o movimento na pilha. */
void empilha (pilha *p, int indice);

/* Recebe um ponteiro para pilha e devolve o elemento do topo.*/
int topoPilha(pilha *p);

/* Recebe um ponteiro para um pilha e libera o espaço que foi alocado 
 * para a mesma.*/
void destroiPilha(pilha *p);
