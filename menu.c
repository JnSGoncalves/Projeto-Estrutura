#include "menu.h"
#include <structs/registro.h>
#include <stdlib.h>
#include <stdio.h>

// Cadastrar
// Atendimento
//  |_Desfazer (Dentro do atendimento)
// Atendimento Prioritário
// Pesquisa
// Carregar / Salvar

int cadastrar(){
    printf("Funcao cadastrar executada.\n");
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