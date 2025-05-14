#ifndef HEAP_H
#define HEAP_H

#include "registro.h"
#define LEN 20

typedef struct {
    Registro* dados[LEN];
    int qtde;
} heap;

int filho_esq(int pai);
int filho_dir(int pai);
int pai(int filho);
int ultimo_pai(heap *h);
void peneirar(heap *h, int pai);
void mostrar(heap *h);
void construir(heap *h);
void inserir(heap *h, Registro *valor);
Registro* remover(heap *h);

#endif