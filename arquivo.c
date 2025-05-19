#include "arquivo.h"
#include <stdio.h>
#include <stdlib.h>

CodErros salvarPacientes(Lista* lista, const char* nomeArquivo) {
    FILE* arq = fopen(nomeArquivo, "w");
    if (arq == NULL) {
        return ERRO;
    }

    ELista* atual = lista->inicio;
    while (atual != NULL) {
        Registro* r = atual->dados;
        fprintf(arq, "%s;%d;%s;%d;%d;%d\n", 
            r->Nome, r->Idade, r->RG, 
            r->Entrada->dia, r->Entrada->mes, r->Entrada->ano);
        atual = atual->proximo;
    }

    fclose(arq);
    return OK;
}

CodErros carregarPacientes(Lista* lista, const char* nomeArquivo) {
    FILE* arq = fopen(nomeArquivo, "r");
    if (arq == NULL) {
        return ERRO;
    }

    char nome[Nome_MAX_LEN];
    int idade;
    char rg[RG_MEX_LEN];
    int dia, mes, ano;

    while (fscanf(arq, "%[^;];%d;%[^;];%d;%d;%d\n", nome, &idade, rg, &dia, &mes, &ano) == 6) {
        Registro* novo = criarRegistro(nome, idade, rg, dia, mes, ano);
        inserir(lista, novo);
    }

    fclose(arq);
    return OK;
}