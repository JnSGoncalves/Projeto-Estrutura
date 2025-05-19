#include "operacao.h"

Operacao *criarOp(OpType tipo, Registro* registro){
    Operacao* op = malloc(sizeof(Operacao));

    op->tipo = tipo;

    Registro* copiaRegistro = criarRegistro(
        registro->Nome,
        registro->Idade,
        registro->RG,
        registro->Entrada->dia,
        registro->Entrada->mes,
        registro->Entrada->ano
    );

    op->reg = copiaRegistro;

    return op;
}