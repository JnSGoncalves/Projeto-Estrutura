#include "funcoesPrioridade.h"
#include "menu.h"

// Funções
CodErros enfileirarPrioridade(Heap* prioridade, Lista* lista){
    printf("Digite o RG do paciente a ser adicionado a fila prioritaria:\n\n");

    char rg[RG_MEX_LEN];
    printf("RG: ");
    fgets(rg, RG_MEX_LEN, stdin);
    rg[strcspn(rg, "\n")] = '\0';
    
    ELista* paciente = lista->inicio;

    while (paciente != NULL){
        if(strcmp(paciente->dados->RG, rg) == 0){
            break;
        }
        paciente = paciente->proximo;
    }
    
    
    if (paciente == NULL)
        return NAO_ENCONTRADO;
    
    inserirHeap(prioridade, paciente->dados);

    printf("Paciente adicionado a fila de prioridade.\n\n");

    return OK;
}
CodErros desenfileirarPrioridade(Heap* prioridade){
    Registro* paciente = removerHeap(prioridade);
    if(paciente == NULL){
        return FILA_VAZIA;
    }
    
    printf("Próximo paciente removido da fila prioritaria:\n");
    printf("Nome: %s, Idade: %d, RG: %s, Data de registro: %d/%d/%d\n\n",
        paciente->Nome, 
        paciente->Idade,
        paciente->RG,
        paciente->Entrada->dia,
        paciente->Entrada->mes,
        paciente->Entrada->ano
    );

    return OK;
}