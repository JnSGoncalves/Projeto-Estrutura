#ifndef FUNCOES_REGISTRO_H
#define FUNCOES_REGISTRO_H

#include "menu.h"

// Funções
CodErros NovoRegistro();
CodErros consultarPaciente(Lista* lista);
CodErros atualizarPaciente(Lista* lista);
CodErros removerPaciente(Lista* lista);


#endif