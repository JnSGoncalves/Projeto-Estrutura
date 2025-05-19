#ifndef OPERACAO_H
#define OPERACAO_H

#include "registro.h"

typedef enum {ENFILEIRAR, DESENFILEIRAR} OpType;

typedef struct {
    OpType tipo;
    Registro *reg;
} Operacao;

// Funções
Operacao *criarOp(OpType tipo, Registro* registro);

#endif