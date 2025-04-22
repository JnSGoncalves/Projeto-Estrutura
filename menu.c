#include "menu.h"
#include "lista.h"
#include "funcoesRegistro.h"
#include <structs/registro.h>
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
            printf("Lista de pacientes registrados:\n\n");
            mostrar(lista);
            break;
        case '4':
            printf("Atualizar dados de paciente selecionado.\n");
            break;
        case '5':
            printf("Remover paciente selecionado.\n");
            break;
        default:
            printf("Opcao invalida. Tente novamente.\n");
            break;
    }

    return 0;
}

int atendimento(){
    printf("Funcao atendimento executada.\n");
    return 0;
}

int atendimentoPrioritario(){
    printf("Funcao atendimentoPrioritario executada.\n");
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