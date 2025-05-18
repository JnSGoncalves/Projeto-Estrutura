#ifndef MENU_H
#define MENU_H

#include "lista.h"
#include "heap.h"
#include "registro.h"
#include <stdlib.h>
#include <stdio.h>

typedef enum {OK, NAO_ENCONTRADO, FILA_VAZIA, LISTA_VAZIA, ERRO} CodErros;

#include "funcoesRegistro.h"
#include "funcoesPrioridade.h"

int registros(Lista* lista);
int atendimento(Lista* lista);
int atendimentoPrioritario();
int pesquisa();
int carregar_salvar();
void clearBuffer();
void tratErros(CodErros erro);

#endif