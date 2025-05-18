#ifndef FUNCOES_FILA_H
#define FUNCOES_FILA_H

#include "fila.h"
#include "lista.h"
#include "menu.h"

CodErros adicionarPacienteNaFila(Lista* lista, Fila* fila);
CodErros chamarProximoPaciente(Fila* fila);
CodErros exibirFilaDeAtendimento(Fila* fila);

#endif