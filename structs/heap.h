#ifndef HEAP_H
#define HEAP_H

#include "registro.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define LEN 20

typedef struct {
    Registro* dados[LEN];
    int qtde;
} Heap;

int filho_esq(int pai);
int filho_dir(int pai);
int pai(int filho);
int ultimo_pai(Heap *h);
void peneirar(Heap *h, int pai);
void mostrarHeap(Heap *h);
void construir(Heap *h);
void inserirHeap(Heap *h, Registro *valor);
Registro* removerHeap(Heap *h);

#endif