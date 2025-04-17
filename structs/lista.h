#ifndef LISTA_H
#define LISTA_H

#include "registro.h"

// Estruturas
typedef struct ELista {
    Registro *dados;
    struct ELista *proximo;
} ELista;

typedef struct Lista {
    ELista *inicio;
    int qtd;
} Lista;

// Funções
ELista *criar_celula(Registro *valor);
Lista *criar_lista();
void inserir(Lista *lista, Registro* reg);
void remover(Lista *lista, char rg[RG_MEX_LEN]);
void mostrar(Lista *lista);

#endif