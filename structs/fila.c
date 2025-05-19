#include "fila.h"

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

    Operacao* op = criarOp(ENFILEIRAR, paciente);
    push(logOp, op);
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

    Operacao* op = criarOp(DESENFILEIRAR, paciente);
    push(logOp, op);

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

void desfazer(Fila *fila) {
    if (logOp->qtde == 0) return;

    Operacao* op = pop(logOp);

    if (op->tipo == ENFILEIRAR) {
        if (fila->head == fila->tail) {
            free(fila->head);
            fila->head = fila->tail = NULL;
        } else {
            CelulaFila* atual = fila->head;
            CelulaFila* anterior = NULL;

            while (atual->proximo != NULL){
                anterior = atual;
                atual = atual->proximo;
            }

            anterior->proximo = NULL;
            fila->tail = anterior;
            free(atual);
        }
        fila->qtde--;
    } else {
        CelulaFila *nova = malloc(sizeof(CelulaFila));
        nova->paciente = op->reg;
        nova->proximo = fila->head;

        fila->head = nova;
        if (fila->tail == NULL) {
            fila->tail = nova;
        }
        fila->qtde++;
    }

    free(op);
}