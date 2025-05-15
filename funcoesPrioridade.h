#ifndef FUNCOES_PRIORIDADE_H
#define FUNCOES_PRIORIDADE_H

#include "menu.h"
#include <string.h>

// Funções
CodErros enfileirarPrioridade(Heap* prioridade, Lista* lista);
CodErros desenfileirarPrioridade(Heap* prioridade);

#endif