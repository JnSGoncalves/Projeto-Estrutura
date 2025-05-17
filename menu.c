#include "menu.h"
#include "lista.h"
#include "funcoesRegistro.h"
#include "registro.h"
#include "funcoesFila.h"
#include <stdlib.h>
#include <stdio.h>


// Registros
// Atendimento
//  |_Desfazer (Dentro do atendimento)
// Atendimento Prioritário
// Pesquisa
// Carregar / Salvar
// Sobre

int registros(Lista* lista){
    char opcao;

    printf("Selecione uma operacao:\n");
    printf("1. Cadastrar novo paciente\n");
    printf("2. Consultar paciente cadastrado\n");
    printf("3. Mostrar lista completa\n");
    printf("4. Atualizar dados de paciente\n");
    printf("5. Remover paciente\n\n");

    printf("Escolha uma opcao: ");

    scanf("%c", &opcao);
    clearBuffer();

    printf("\n");
    
    CodErros Erro;
    switch (opcao) {
        case '1':
            Erro = NovoRegistro(lista);
            break;
        case '2':
            Erro = consultarPaciente(lista);
            break;
        case '3':
            if(lista->qtd != 0){
                printf("Lista de pacientes registrados:\n\n");
                mostrar(lista);
            }else{
                Erro = LISTA_VAZIA;
            }
            break;
        case '4':
            Erro = atualizarPaciente(lista);
            break;
        case '5':
            Erro = removerPaciente(lista);
            break;
        default:
            printf("Opcao invalida. Tente novamente.\n");
            break;
    }

    tratErros(Erro);

    return 0;
}

int atendimento(Lista* lista){
    static Fila* filaAtendimento = NULL;

    if (filaAtendimento == NULL) {
        filaAtendimento = criar_fila();
    }

    char opcao;

    printf("Selecione uma operacao:\n");
    printf("1. Enfileirar paciente\n");
    printf("2. Chamar próximo paciente\n");
    printf("3. Mostrar fila de atendimento\n\n");

    printf("Escolha uma opcao: ");
    scanf("%c", &opcao);
    clearBuffer();

    printf("\n");
    
    CodErros Erro;
    switch (opcao) {
        case '1':
            Erro = adicionarPacienteNaFila(lista, filaAtendimento);
            break;
        case '2':
            Erro = chamarProximoPaciente(filaAtendimento);
            break;
        case '3':
            Erro = exibirFilaDeAtendimento(filaAtendimento);
            break;
        default:
            printf("Opcao invalida. Tente novamente.\n");
            return 0;
    }

    tratErros(Erro);
    return 0;
}

int atendimentoPrioritario(Lista *lista, Heap *prioridade){
    char opcao;

    printf("Selecione uma operacao:\n");
    printf("1. Enfileirar paciente - Prioridade\n");
    printf("2. Desenfileirar paciente - Prioridade\n");
    printf("3. Mostrar fila completa - Prioridade\n\n");

    printf("Escolha uma opcao: ");

    scanf("%c", &opcao);
    clearBuffer();

    printf("\n");
    
    CodErros Erro;
    switch (opcao) {
        case '1':
            Erro = enfileirarPrioridade(prioridade, lista);
            break;
        case '2':
            Erro = desenfileirarPrioridade(prioridade);
            break;
        case '3':
            if(prioridade->qtde != 0){
                printf("Lista de pacientes registrados:\n\n");
                mostrarHeap(prioridade);
            }else{
                Erro = FILA_VAZIA;
            }
            break;
        default:
            printf("Opcao invalida. Tente novamente.\n");
            break;
    }

    tratErros(Erro);

    return 0;
}

int pesquisa(){
    printf("Funcao pesquisa executada.\n");
    return 0;
}

int carregar_salvar(){
    printf("Funcao carregar_salvar executada.\n");
    return 0;
}

void clearBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void tratErros(CodErros erro){
    switch (erro){
        case NAO_ENCONTRADO:
            printf("Paciente não cadastrado.\n");
            break;
        case ERRO:
            printf("Erro ao realizar a operação.\n");
            break;
        case FILA_VAZIA:
            printf("Fila vazia.\n");
            break;
        case LISTA_VAZIA:
            printf("Lista vazia.\n");
            break;
    default:
        break;
    }
    printf("\n");
}