
/* Recebe um ponteiro para um vetor, dois inteiros
 * n representando seu tamanho e um indice.
 * Ela verifica e retorna qual o indice para 
 * uma possível troca. */
int verificaIndiceTroca (int *v, int i, int n);

/* Recebe um ponteiro para um vetor, dois inteiros
 * n representando seu tamanho e um indice.
 * Ela verifica e retorna qual o próximo indice
 * dado um passo. */
int verificaIndicePasso (int *v, int i, int n);

/* Recebe um ponteiro para um vetor, dois inteiros
 * n representando seu tamanho e um indice.
 * Ela verifica e retorna 1 se for possivel 
 * efetuar uma troca, ou 0 caso contrário. */
int podeTrocar (int *v, int i, int n);

/* Recebe um ponteiro para um vetor, dois inteiros
 * n representando seu tamanho e um indice 
 * e efetua uma troca. */
void troca (int *v, int i, int n);
