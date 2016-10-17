#include <stdlib.h>
#include <stdio.h>

/* Recebe um inteiro n e devolve um vetor
 * de tamanhao n alocada dinamicamente. */
int *criaVetor(int n);

/* Recebe um ponteiro para um vetor e um inteiro 
 * n representando seu tamanho e atribui 0 a 
 * todas as posições do vetor. */
void zeraVetor (int *v, int n);

/* Recebe um ponteiro para um vetor e libera o 
 * espaço que foi alocado para o mesmo. */
void destroiVetor (int *v);

/* Recebe um ponteiro para um vetor e um inteiro 
 * n representando seu tamanho e imprime todos os 
 * valores armazenados por ele. */
void imprimeVetor (int *v, int n);

/* Recebe um ponteiro para um vetor e um inteiro 
 * n representando seu tamanho e checa se ele está ordenado. */
int checaOrdenado (int *v, int n);

