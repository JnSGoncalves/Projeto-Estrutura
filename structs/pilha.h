#ifndef PILHA_H
#define PILHA_H

#include "operacao.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct EPilha {
  struct EPilha *anterior;
  struct EPilha *proximo;
  Operacao *dados;
} EPilha;

typedef struct {
  EPilha *top;
  int qtde;
} Pilha;

// Funções
EPilha *criar_epilha(Operacao* valor);
Pilha *criar_pilha();
void push(Pilha *stack, Operacao* valor);
Operacao* pop(Pilha *stack);
void mostrar_pilha(Pilha *stack);

#endif