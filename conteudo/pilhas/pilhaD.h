typedef struct {
	int topo;
	int *v;
	int tam;
} pilha;

pilha *criaPilha (int n);

int pilhaVazia(pilha p);

int pilhaCheia (pilha *p);

int desempilha (pilha *p);

void empilha (pilha *p, int n);

void imprimePilha(pilha *p);

int topoPilha(pilha *p);

void destroiPilha(pilha *p);
