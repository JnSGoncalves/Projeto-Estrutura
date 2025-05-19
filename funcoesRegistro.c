#include "funcoesRegistro.h"
#include "registro.h"
#include "lista.h"
#include "menu.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

CodErros NovoRegistro(Lista* list, ABB* abbList[4]){
    char nome[Nome_MAX_LEN];
    int idade;
    char rg[RG_MEX_LEN];
    int dia;
    int mes;
    int ano;

    printf("Digite os dados do paciente a ser cadastrado:\n\n");
    
    printf("RG: ");
    fgets(rg, RG_MEX_LEN, stdin);
    rg[strcspn(rg, "\n")] = '\0';

    if(existeNaLista(list, rg) == 1){
        return JA_CADASTRADO;
    }

    printf("Nome: ");
    fgets(nome, Nome_MAX_LEN, stdin);
    nome[strcspn(nome, "\n")] = '\0';

    printf("Idade: ");
    scanf("%d", &idade);
    clearBuffer();


    printf("Digite o dia de entrada: ");
    scanf("%d", &dia);
    clearBuffer();

    printf("Digite o mes de entrada: ");
    scanf("%d", &mes);
    clearBuffer();

    printf("Digite o ano de entrada: ");
    scanf("%d", &ano);
    clearBuffer();

    Registro* novo = criarRegistro(nome, idade, rg, dia, mes, ano);
    inserir(list, novo);

    // Inserção nas árvores de pesquisa
    abbInserirPorIdade(abbList[IDADE], novo);
    abbInserirPorAno(abbList[ANO], novo);
    abbInserirPorMes(abbList[MES], novo);
    abbInserirPorDia(abbList[DIA], novo);


    printf("Paciente registrado com sucesso!\n\n");

    return OK;
}

CodErros consultarPaciente(Lista* lista) {
    char rgBusca[RG_MEX_LEN];
    printf("Digite o RG do paciente a ser consultado: ");
    fgets(rgBusca, RG_MEX_LEN, stdin);
    rgBusca[strcspn(rgBusca, "\n")] = '\0';

    ELista* atual = lista->inicio;

    while (atual != NULL) {
        Registro* reg = atual->dados;

        if (strcmp(reg->RG, rgBusca) == 0) {
            printf("\nPaciente encontrado:\n");
            printf("Nome: %s\n", reg->Nome);
            printf("Idade: %d\n", reg->Idade);
            printf("RG: %s\n", reg->RG);
            printf("Data de entrada: %02d/%02d/%04d\n\n",
                reg->Entrada->dia,
                reg->Entrada->mes,
                reg->Entrada->ano);
            return OK;
        }

        atual = atual->proximo;
    }

    printf("Paciente com RG %s nao encontrado.\n", rgBusca);
    return NAO_ENCONTRADO;
}

CodErros atualizarPaciente(Lista* lista) {
    char rgBusca[RG_MEX_LEN];
    printf("Digite o RG do paciente a ser atualizado: ");
    fgets(rgBusca, RG_MEX_LEN, stdin);
    rgBusca[strcspn(rgBusca, "\n")] = '\0';

    ELista* atual = lista->inicio;

    while (atual != NULL) {
        Registro* reg = atual->dados;

        if (strcmp(reg->RG, rgBusca) == 0) {
            printf("\nPaciente encontrado. Dados atuais:\n");
            printf("Nome: %s\n", reg->Nome);
            printf("Idade: %d\n", reg->Idade);

            char novoNome[Nome_MAX_LEN];
            int novaIdade;

            printf("\nDigite o novo nome: ");
            fgets(novoNome, Nome_MAX_LEN, stdin);
            novoNome[strcspn(novoNome, "\n")] = '\0';

            printf("Digite a nova idade: ");
            scanf("%d", &novaIdade);
            clearBuffer();

            strcpy(reg->Nome, novoNome);
            reg->Idade = novaIdade;

            printf("Dados atualizados com sucesso!\n\n");
            return OK;
        }

        atual = atual->proximo;
    }

    printf("Paciente com RG %s nao encontrado.\n", rgBusca);
    return NAO_ENCONTRADO;
}

CodErros removerPaciente(Lista* lista, ABB* abbList[4]) {
    if (lista->qtd == 0) {
        printf("Nenhum paciente para remover.\n");
        return LISTA_VAZIA;
    }

    char rgBusca[RG_MEX_LEN];
    printf("Digite o RG do paciente a ser removido: ");
    fgets(rgBusca, RG_MEX_LEN, stdin);
    rgBusca[strcspn(rgBusca, "\n")] = '\0';

    ELista* atual = lista->inicio;
    ELista* anterior = NULL;

    while (atual != NULL) {
        if (strcmp(atual->dados->RG, rgBusca) == 0) {
            if (anterior == NULL) {
                lista->inicio = atual->proximo;
            } else {
                anterior->proximo = atual->proximo;
            }

            // Remoção das árvores de pesquisa
            abbRemoverPorRegistro(abbList[IDADE], atual->dados);
            abbRemoverPorRegistro(abbList[ANO], atual->dados);
            abbRemoverPorRegistro(abbList[MES], atual->dados);
            abbRemoverPorRegistro(abbList[DIA], atual->dados);

            free(atual->dados->Entrada);
            free(atual->dados);
            free(atual);
            lista->qtd--;

            printf("Paciente removido com sucesso!\n\n");
            return OK;
        }

        anterior = atual;
        atual = atual->proximo;
    }

    printf("Paciente com RG %s nao encontrado.\n", rgBusca);
    return NAO_ENCONTRADO;
}