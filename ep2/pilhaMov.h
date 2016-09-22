typedef struct {
	int lin;
	int col;
} pos;

typedef struct {
	int l;
	int c;
	int mv;
} movimento;

typedef struct {
	int topo;
	movimento *v;
	int tam;
} pilha;

pilha *criaPilha (int n);

int pilhaVazia(pilha *p);

int pilhaCheia (pilha *p);

void desempilha (pilha *p, movimento *mov);

void empilha (pilha *p, movimento n);

void imprimePilha(pilha *p);

int topoPilha(pilha *p);

void destroiPilha(pilha *p);
