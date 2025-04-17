#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "lista.h"

/* Comando de compilação do projeto:
gcc -o projeto *.c structs/*.c -I. -Istructs
*/

int main(){
    char opcao;

    Lista* listaRegistro = criar_lista();
    
    do{
        printf("Menu de Opcoes:\n");
        printf("\n");
        printf("1. Registros de Pacientes\n");
        printf("2. Atendimento\n");
        printf("3. Atendimento Prioritario\n");
        printf("4. Pesquisa\n");
        printf("5. Carregar / Salvar\n");
        printf("0. Sair\n\n");


        printf("Digite o numero da opcao desejada: ");
        scanf("%c", &opcao);
        clearBuffer();

        printf("\n");

        switch (opcao){
        case '1':
            registros(listaRegistro);
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