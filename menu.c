#include "menu.h"
#include "lista.h"
#include "funcoesRegistro.h"
#include "registro.h"
#include "funcoesFila.h"
#include "arquivo.h"
#include <stdlib.h>
#include <stdio.h>

// Registros
// Atendimento
//  |_Desfazer (Dentro do atendimento)
// Atendimento Prioritário
// Pesquisa
// Carregar / Salvar
// Sobre

int registros(Lista* lista, ABB* abbList[4]){
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
            Erro = NovoRegistro(lista, abbList);
            break;
        case '2':
            Erro = consultarPaciente(lista);
            break;
        case '3':
            if(lista->qtd != 0){
                printf("Lista de pacientes registrados:\n\n");
                mostrar(lista);
                Erro = OK;
            }else{
                Erro = LISTA_VAZIA;
            }
            break;
        case '4':
            Erro = atualizarPaciente(lista);
            break;
        case '5':
            Erro = removerPaciente(lista, abbList);
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
    printf("3. Mostrar fila de atendimento\n");
    printf("4. Mostrar Log das ultimas operações na Fila\n");
    printf("5. Desfazer última operação\n\n");

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
        case '4':
            if(logOp->qtde != 0){
                printf("Operacoes cadastradas:\n");
                mostrar_pilha(logOp);
                Erro = OK;
            }else
                Erro = PILHA_VAZIA;
            break;
        case '5':
            Erro = desfazerAtendimento(filaAtendimento);
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
                Erro = OK;
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

int pesquisa(ABB* abbList[4]){
    char opcao;

    printf("Selecione uma operacao:\n");
    printf("1. Mostrar Registros ordenados por Ano\n");
    printf("2. Mostrar Registros ordenados por Mes\n");
    printf("3. Mostrar Registros ordenados por Dia\n");
    printf("4. Mostrar Registros ordenados por Idade\n\n");

    printf("Escolha uma opcao: ");

    scanf("%c", &opcao);
    clearBuffer();

    printf("\n");
    
    CodErros Erro = OK;
    switch (opcao) {
        case '1':
            if(abbList[ANO]->raiz != NULL){
                in_ordem(abbList[ANO]->raiz);
            }else{
                Erro = LISTA_VAZIA;
            }
            break;
        case '2':
            if(abbList[MES]->raiz != NULL){
                in_ordem(abbList[MES]->raiz);
            }else{
                Erro = LISTA_VAZIA;
            }
            break;
        case '3':
            if(abbList[DIA]->raiz != NULL){
                in_ordem(abbList[DIA]->raiz);
            }else{
                Erro = LISTA_VAZIA;
            }
            break;
        case '4':
            if(abbList[IDADE]->raiz != NULL){
                in_ordem(abbList[IDADE]->raiz);
            }else{
                Erro = LISTA_VAZIA;
            }
            break;
        default:
            printf("Opcao invalida. Tente novamente.\n");
            break;
    }

    tratErros(Erro);

    return 0;
}

int carregar_salvar(Lista* lista, ABB* abbList[4]){
    char opcao;
    char nomeArquivo[] = "pacientes.txt";

    printf("Operacoes:\n");
    printf("1. Carregar pacientes do arquivo\n");
    printf("2. Salvar pacientes no arquivo\n");
    printf("Escolha uma opcao: ");
    scanf(" %c", &opcao);
    clearBuffer();

    CodErros Erro;

    switch (opcao) {
        case '1':
            Erro = carregarPacientes(lista, nomeArquivo, abbList);
            break;
        case '2':
            Erro = salvarPacientes(lista, nomeArquivo);
            break;
        default:
            printf("Opcao invalida.\n");
            return 0;
    }

    tratErros(Erro);
    return 0;
}

int sobre(){
    printf("\n=== SOBRE O PROJETO ===\n");
    printf("Desenvolvedores:\n");
    printf("- Vinícius do Nascimento Generoso | RA: 22.123.103-8\n");
    printf("- Jônatas da Silva Gonçalves      | RA: 22.123.095-6\n");
    printf("Ciclo: 4º\n");
    printf("Curso: Ciência da Computação\n");
    printf("Disciplina: Estrutura de Dados\n");
    printf("Data: Maio de 2025\n\n");
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
        case PILHA_VAZIA:
            printf("Pilha vazia.\n");
            break;
        case OP_CANCELADA:
            printf("Operação cancelada.\n");
            break;
        case JA_CADASTRADO:
            printf("Paciente já cadastrado.\n");
            break;
    default:
        break;
    }
    printf("\n");
}