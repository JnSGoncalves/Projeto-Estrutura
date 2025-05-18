#include "fila.h"
#include <stdio.h>
#include <stdlib.h>

Fila *criar_fila() {
    Fila *fila = malloc(sizeof(Fila));
    fila->head = NULL;
    fila->tail = NULL;
    fila->qtde = 0;
    return fila;
}

void enfileirar(Fila *fila, Registro *paciente) {
    CelulaFila *nova = malloc(sizeof(CelulaFila));
    nova->paciente = paciente;
    nova->proximo = NULL;

    if (fila->qtde == 0) {
        fila->head = nova;
    } else {
        fila->tail->proximo = nova;
    }

    fila->tail = nova;
    fila->qtde++;
}

Registro *desenfileirar(Fila *fila) {
    if (fila->qtde == 0) {
        return NULL;
    }

    CelulaFila *remover = fila->head;
    Registro *paciente = remover->paciente;

    fila->head = remover->proximo;
    free(remover);
    fila->qtde--;

    if (fila->qtde == 0) {
        fila->tail = NULL;
    }

    return paciente;
}

void mostrar_fila(Fila *fila) {
    CelulaFila *atual = fila->head;
    if (fila->qtde == 0) {
        printf("Fila vazia.\n");
        return;
    }

    int pos = 1;
    while (atual != NULL) {
        Registro *reg = atual->paciente;
        printf("%d - Nome: %s | Idade: %d | RG: %s | Entrada: %02d/%02d/%04d\n",
            pos++, reg->Nome, reg->Idade, reg->RG,
            reg->Entrada->dia, reg->Entrada->mes, reg->Entrada->ano);
        atual = atual->proximo;
    }
}