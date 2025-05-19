#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "lista.h"

Pilha* logOp = NULL;

/* Comando de compilação do projeto:
gcc -o projeto *.c structs/*.c -I. -Istructs
*/

int main(){
    char opcao;

    Heap* prioridade = malloc(sizeof(Heap));
    prioridade->qtde = 0;

    logOp = criar_pilha();
    
    Lista* listaRegistro = criar_lista();

    ABB* abbList[4] = {
        cria_ABB(), // Por ano
        cria_ABB(), // Por mes
        cria_ABB(), // Por dia
        cria_ABB()  // Por Idade
    };
    
    do{
        printf("Menu de Opcoes:\n");
        printf("\n");
        printf("1. Registros de Pacientes\n");
        printf("2. Atendimento\n");
        printf("3. Atendimento Prioritario\n");
        printf("4. Pesquisa\n");
        printf("5. Carregar/Salvar\n");
        printf("6. Sobre\n");
        printf("0. Sair\n\n");


        printf("Digite o numero da opcao desejada: ");
        scanf("%c", &opcao);
        clearBuffer();

        printf("\n");

        switch (opcao){
        case '1':
            registros(listaRegistro, abbList);
            break;
        case '2':
            atendimento(listaRegistro);
            break;
        case '3':
            atendimentoPrioritario(listaRegistro, prioridade);
            break;
        case '4':
            pesquisa(abbList);
            break;
        case '5':
            carregar_salvar(listaRegistro);
            break;
        case '6':
            sobre();
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