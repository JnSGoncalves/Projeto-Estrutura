#include "lista.h"
#include "registro.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

ELista *criar_celula(Registro* reg){
    ELista *nova = malloc(sizeof(ELista));
    nova->proximo = NULL;
    nova->dados = reg;
    return nova;
}

Lista *criar_lista(){
    Lista *lista = malloc(sizeof(Lista));
    lista->inicio = NULL;
    lista->qtd = 0;
    return lista;
}

void inserir(Lista *lista, Registro* reg){
    ELista *nova = criar_celula(reg);

    ELista *anterior = NULL;
    ELista *atual = lista->inicio;

    while(atual != NULL){
        anterior = atual;
        atual = atual->proximo;
    }
    if(anterior == NULL){
        lista->inicio = nova;
    } else {
        anterior->proximo = nova;
    }
    nova->proximo = atual;
    lista->qtd++;
}

void remover(Lista *lista, char rg[RG_MEX_LEN]) {
    if (lista->qtd == 0) {
        return;
    }
    
    ELista *anterior = NULL;
    ELista *atual = lista->inicio;
    while (strcmp(atual->dados->RG, rg) != 0 && atual->proximo != NULL){
        anterior = atual;
        atual = atual->proximo;
    }
    
    int ver = 0;
    
    if(atual == NULL){
        return;
    }
    if (anterior == NULL){
    }else if (strcmp(atual->dados->RG, rg) == 0){
        anterior->proximo = atual->proximo;
    }

    if (ver){
        free(atual);
        lista->qtd--;
        return;
    }
}

void mostrar(Lista *lista){
    ELista *atual = lista->inicio;
    int cont = 1;

    if(lista->qtd == 0){
        printf("Nenhum paciente cadastrado\n");
        return;
    }

    while(atual != NULL){
        printf("%d - Nome: %s, Idade: %d, RG: %s, Data de registro: %02d/%02d/%04d\n", 
            cont,
            atual->dados->Nome, 
            atual->dados->Idade,
            atual->dados->RG,
            atual->dados->Entrada->dia,
            atual->dados->Entrada->mes,
            atual->dados->Entrada->ano
        );
        atual = atual->proximo;
        cont++;
    }
    printf("\n");
}

int existeNaLista(Lista *lista, const char rg[RG_MEX_LEN]) {
    ELista *atual = lista->inicio;

    while (atual != NULL) {
        if (strcmp(atual->dados->RG, rg) == 0) {
            return 1;
        }
        atual = atual->proximo;
    }

    return 0;
}
