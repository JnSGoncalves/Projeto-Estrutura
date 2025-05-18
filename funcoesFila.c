#include "funcoesFila.h"
#include <string.h>
#include <stdio.h>

CodErros adicionarPacienteNaFila(Lista* lista, Fila* fila) {
    char rgBusca[RG_MEX_LEN];
    printf("Digite o RG do paciente que deseja enfileirar: ");
    fgets(rgBusca, RG_MEX_LEN, stdin);
    rgBusca[strcspn(rgBusca, "\n")] = '\0';

    ELista* atual = lista->inicio;
    while (atual != NULL) {
        if (strcmp(atual->dados->RG, rgBusca) == 0) {
            enfileirar(fila, atual->dados);
            printf("Paciente enfileirado com sucesso!\n\n");
            return OK;
        }
        atual = atual->proximo;
    }

    printf("Paciente com RG %s nao encontrado.\n\n", rgBusca);
    return ERRO;
}

CodErros chamarProximoPaciente(Fila* fila) {
    Registro* paciente = desenfileirar(fila);
    if (paciente == NULL) {
        printf("Fila vazia. Nenhum paciente para atender.\n\n");
        return ERRO;
    }

    printf("Chamando o próximo paciente:\n");
    printf("Nome: %s | Idade: %d | RG: %s | Entrada: %02d/%02d/%04d\n\n",
        paciente->Nome, paciente->Idade, paciente->RG,
        paciente->Entrada->dia, paciente->Entrada->mes, paciente->Entrada->ano);

    return OK;
}

CodErros exibirFilaDeAtendimento(Fila* fila) {
    printf("Fila de Atendimento:\n\n");
    mostrar_fila(fila);
    return OK;
}



