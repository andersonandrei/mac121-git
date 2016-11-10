
int *criaVetor(int n);

char **criaMatriz (int n);

void zeraMatriz(char **tab, int n);

void imprimeMatriz(char **tab, int n);

void imprimeVetorFreq (char **v, int *w, int n);

void zeraVetorInt (int *v, int n);

void zeraVetorChar (char *v, int n);

void zeraMatrizChar (char **v, int n);

void destroiVetor (int *v) ;

void destroiMatriz(char **tab, int n) ;

void imprimeVetor (int *v, int n);

int checaOrdenado (int *v, int n);

int comparaPalavras (char *p1, int tamP1, char *p2, int tamP2);

int buscaElemento (char **v, int n, char *palavra, int tamP);

void insereVetor (char **v, int *w, int n, char *ch, int tamP);

int ordemAlfabeticaVetores (char *a, char *b);

int insereOrdenadoVetor (char **v, int *w, int n, char *ch); 


char ** redimensionaMatriz(char **tab, int n);

int * redimensionaVetor(int *vetor, int n);
