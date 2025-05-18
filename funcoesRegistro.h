#ifndef FUNCOES_REGISTRO_H
#define FUNCOES_REGISTRO_H

#include "menu.h"

// Funções
CodErros NovoRegistro(Lista* list, ABB* abbList[4]);
CodErros consultarPaciente(Lista* lista);
CodErros atualizarPaciente(Lista* lista);
CodErros removerPaciente(Lista* lista, ABB* abbList[4]);

#endif