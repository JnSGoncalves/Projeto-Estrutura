#ifndef MENU_H
#define MENU_H

#include "lista.h"
#include "heap.h"
#include "registro.h"
#include "abb.h"
#include <stdlib.h>
#include <stdio.h>

typedef enum {OK, NAO_ENCONTRADO, FILA_VAZIA, LISTA_VAZIA, ERRO} CodErros;
typedef enum {ANO, MES, DIA, IDADE} AbbIndex;

#include "funcoesRegistro.h"
#include "funcoesPrioridade.h"

int registros(Lista* lista, ABB* abbList[4]);
int atendimento();
int atendimentoPrioritario(Lista *lista, Heap *prioridade);
int pesquisa(ABB* abbList[4]);
int carregar_salvar();
void clearBuffer();
void tratErros(CodErros erro);

#endif