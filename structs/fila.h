#ifndef FILA_H
#define FILA_H

#include <stdio.h>
#include <stdlib.h>
#include "registro.h"
#include "pilha.h"
#include "menu.h"

typedef struct CelulaFila {
    Registro *paciente;
    struct CelulaFila *proximo;
} CelulaFila;

typedef struct {
    CelulaFila *head;
    CelulaFila *tail;
    int qtde;
} Fila;

Fila *criar_fila();
void enfileirar(Fila *fila, Registro *paciente);
Registro *desenfileirar(Fila *fila);
void mostrar_fila(Fila *fila);
void desfazer(Fila *fila);

#endif