#ifndef MENU_H
#define MENU_H

#include "lista.h"

typedef enum {OK, ERRO} CodErros;

int registros(Lista* lista);
int atendimento();
int atendimentoPrioritario();
int pesquisa();
int carregar_salvar();
void clearBuffer();

#endif