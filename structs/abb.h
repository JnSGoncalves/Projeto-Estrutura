#ifndef ABB_H
#define ABB_H

#include <stdio.h>
#include <stdlib.h>
#include "registro.h"

typedef struct EABB {
  Registro* dados;
  struct EABB *esq;
  struct EABB *dir;
  struct EABB *pai;
} EABB;

typedef struct ABB {
  EABB *raiz;
  int qtde;
} ABB;

void in_ordem(EABB* raiz);
// void ng_ordem(EABB *raiz);
EABB* cria_EABB(Registro* dados);
ABB* cria_ABB();
void abbInserirPorIdade(ABB* arvore, Registro* dados);
void abbInserirPorAno(ABB* arvore, Registro* dados);
void abbInserirPorMes(ABB* arvore, Registro* dados);
void abbInserirPorDia(ABB* arvore, Registro* dados);
EABB* buscar_por_registro(ABB* arvore, Registro* registro);
int abbRemoverPorRegistro(ABB* arvore, Registro* registro);
// EABB* buscar_idade(ABB* arvore, int idade);

#endif