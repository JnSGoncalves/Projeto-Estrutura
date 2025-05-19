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

    printf("Paciente com RG %s nao encontrado.\n", rgBusca);
    return NAO_ENCONTRADO;
}

CodErros chamarProximoPaciente(Fila* fila) {
    Registro* paciente = desenfileirar(fila);
    if (paciente == NULL) {
        printf("Nenhum paciente para atender.\n\n");
        return FILA_VAZIA;
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

CodErros desfazerAtendimento(Fila* fila){
    if(logOp->top != NULL){
        char op = logOp->top->dados->tipo == ENFILEIRAR ? '+' : '-';

        printf("Ultima operacao: %c, Paciente: %s, RG: %s\n", 
            op, 
            logOp->top->dados->reg->Nome, 
            logOp->top->dados->reg->Nome
        );

        printf("Deseja desfazer a ultima operacao realizada na Fila de Atendimento? (S/N): ");
        char opcao;
        scanf("%c", &opcao);
        clearBuffer();

        if (opcao == 's' || opcao == 'S'){
            CodErros erro = desfazer(fila);

            if(erro == OK){
                printf("Operacao desfeita.\n\n");
                return OK;
            }else{
                return erro;
            }
        }else{
            return OP_CANCELADA;
        }
    }else{
        return PILHA_VAZIA;
    }
}