#ifndef FUNCOES_PESQUISA_H
#define FUNCOES_PESQUISA_H

#include "menu.h"

// Funções
CodErros listagemPorAno(ABB* abbAno, Lista* lista);
CodErros listagemPorMes(ABB* abbMes, Lista* lista);
CodErros listagemPorDia(ABB* abbDia, Lista* lista);
CodErros listagemPorIdade(ABB* abbIdade, Lista* lista);

#endif