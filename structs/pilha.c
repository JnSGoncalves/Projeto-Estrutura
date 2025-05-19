#include "pilha.h"

EPilha *criar_epilha(Operacao* valor) {
    EPilha *nova = malloc(sizeof(EPilha));
    nova->anterior = NULL;
    nova->proximo = NULL;
    nova->dados = valor;
    return nova;
}

Pilha *criar_pilha() {
    Pilha *stack = malloc(sizeof(Pilha));
    stack->qtde = 0;
    stack->top = NULL;
    return stack;
}

void push(Pilha *stack, Operacao* valor) {
    EPilha *nova = criar_epilha(valor);
    if (stack->qtde != 0) {
        nova->proximo = stack->top;
        stack->top->anterior = nova;
    }
    stack->top = nova;
    stack->qtde++;
}

Operacao* pop(Pilha *stack) {
    if (stack->qtde > 0) {
        Operacao *valor = stack->top->dados;
        EPilha *top = stack->top;
        stack->top = stack->top->proximo;

        if (stack->top != NULL)
            stack->top->anterior = NULL;

        stack->qtde--;
        free(top);
        return valor;
    } else {
        return NULL;
    }
}

void mostrar_pilha(Pilha *stack) {
    if (stack->qtde == 0) {
        return;
    }

    EPilha *atual = stack->top;
    int indice = 1;

    while (atual != NULL) {
        char op = atual->dados->tipo == ENFILEIRAR ? '+' : '-';
        printf("%d. Operacao: %c, Paciente: %s, RG: %s\n", 
               indice, 
               op, 
               atual->dados->reg->Nome,
               atual->dados->reg->RG
            );
        atual = atual->proximo;
        indice++;
    }
    printf("\n");
}