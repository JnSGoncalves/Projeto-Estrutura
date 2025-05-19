#include "registro.h"

Registro* criarRegistro(char nome[Nome_MAX_LEN], int idade, char rg[RG_MEX_LEN], int dia, int mes, int ano){
    Registro *novo = malloc(sizeof(Registro));
    Data *dataDeEntrada = malloc(sizeof(Data));

    dataDeEntrada->dia = dia;
    dataDeEntrada->mes = mes;
    dataDeEntrada->ano = ano;

    strcpy(novo->Nome, nome);
    novo->Idade = idade;
    strcpy(novo->RG, rg);
    novo->Entrada = dataDeEntrada;

    return novo;
}