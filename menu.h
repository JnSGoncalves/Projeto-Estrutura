#ifndef MENU_H
#define MENU_H

#include "lista.h"
#include "heap.h"
#include "registro.h"
#include "abb.h"
#include "pilha.h"
#include <stdlib.h>
#include <stdio.h>

typedef enum {OK, NAO_ENCONTRADO, FILA_VAZIA, LISTA_VAZIA, PILHA_VAZIA, OP_CANCELADA, JA_CADASTRADO, ERRO} CodErros;
typedef enum {ANO, MES, DIA, IDADE} AbbIndex;

#include "funcoesRegistro.h"
#include "funcoesPrioridade.h"

// Declaração global
extern Pilha* logOp;

int registros(Lista* lista, ABB* abbList[4]);
int atendimento(Lista* lista);
int atendimentoPrioritario(Lista *lista, Heap *prioridade);
int pesquisa(ABB* abbList[4]);
int carregar_salvar();
int sobre();
void clearBuffer();
void tratErros(CodErros erro);

#endif