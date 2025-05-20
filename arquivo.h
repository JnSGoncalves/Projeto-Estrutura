#ifndef ARQUIVO_H
#define ARQUIVO_H

#include "lista.h"
#include "menu.h"

CodErros salvarPacientes(Lista* lista, const char* nomeArquivo);
CodErros carregarPacientes(Lista* lista, const char* nomeArquivo, ABB* abbList[4]);

#endif