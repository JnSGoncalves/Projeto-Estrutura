#define Nome_MAX_LEN 50
#define RG_MEX_LEN 12

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

