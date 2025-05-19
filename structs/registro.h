#ifndef REGISTRO_H
#define REGISTRO_H

#define Nome_MAX_LEN 50
#define RG_MEX_LEN 12

#include <stdlib.h>
#include <string.h>

// Estruturas
typedef struct{
    int dia;
    int mes;
    int ano;
}Data;

typedef struct{
    char Nome[Nome_MAX_LEN];
    int Idade;
    char RG[RG_MEX_LEN];
    Data* Entrada;
} Registro;

// Funções
Registro* criarRegistro(char nome[Nome_MAX_LEN], int idade, char rg[RG_MEX_LEN], int dia, int mes, int ano);

#endif