#include "funcoesRegistro.h"
#include "registro.h"
#include "lista.h"
#include "menu.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

CodErros NovoRegistro(Lista* list){
    char nome[Nome_MAX_LEN];
    int idade;
    char rg[RG_MEX_LEN];
    int dia;
    int mes;
    int ano;

    printf("Digite os dados do paciente a ser cadastrado:\n\n");

    printf("Nome: ");
    fgets(nome, Nome_MAX_LEN, stdin);
    nome[strcspn(nome, "\n")] = '\0';

    printf("Idade: ");
    scanf("%d", &idade);
    clearBuffer();

    printf("RG: ");
    fgets(rg, RG_MEX_LEN, stdin);
    rg[strcspn(rg, "\n")] = '\0';

    printf("Digite o dia de entrada: ");
    scanf("%d", &dia);
    clearBuffer();

    printf("Digite o mes de entrada: ");
    scanf("%d", &mes);
    clearBuffer();

    printf("Digite o ano de entrada: ");
    scanf("%d", &ano);
    clearBuffer();

    Registro* novo = criarRegistro(nome, idade, rg, dia, mes, ano);
    inserir(list, novo);

    printf("Paciente registrado com sucesso!\n\n");

    return OK;
}