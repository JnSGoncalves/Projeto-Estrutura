#include <stdio.h>
#include <stdlib.h>
#include "menu.h"


// Funções do Menu

int main(){
    char opcao;
    
    do{
        printf("Menu de Opcoes:\n");
        printf("\n");
        printf("1. Cadastrar\n");
        printf("2. Atendimento\n");
        printf("3. Atendimento Prioritario\n");
        printf("4. Pesquisa\n");
        printf("5. Carregar / Salvar\n");
        printf("0. Sair\n\n");


        printf("Digite o número da opcao desejada: ");
        scanf("%c", &opcao);
        clearBuffer();

        printf("\n");

        switch (opcao){
        case '1':
            cadastrar();
            break;
        case '2':
            atendimento();
            break;
        case '3':
            atendimentoPrioritario();
            break;
        case '4':
            pesquisa();
            break;
        case '5':
            carregar_salvar();
            break;
        case '0':
            printf("Saindo...");
            break;
        default:
            printf("Opcao invalida.\n");
        }
    }while(opcao != '0');

    return 0;
}