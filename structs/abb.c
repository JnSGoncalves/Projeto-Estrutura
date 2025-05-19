#include "abb.h"

void in_ordem(EABB *raiz) {
    if (raiz != NULL) {
        in_ordem(raiz->esq);
        printf("    Nome: %s, Idade: %d, RG: %s, Data de registro: %02d/%02d/%04d\n", 
            raiz->dados->Nome, 
            raiz->dados->Idade,
            raiz->dados->RG,
            raiz->dados->Entrada->dia,
            raiz->dados->Entrada->mes,
            raiz->dados->Entrada->ano
        );
        in_ordem(raiz->dir);
    }
}

// void ng_ordem(EABB *raiz) {
//     if (raiz != NULL) {
//         ng_ordem(raiz->dir);
//         printf("    Nome: %s, Idade: %d, RG: %s, Data de registro: %02d/%02d/%04d\n", 
//             raiz->dados->Nome, 
//             raiz->dados->Idade,
//             raiz->dados->RG,
//             raiz->dados->Entrada->dia,
//             raiz->dados->Entrada->mes,
//             raiz->dados->Entrada->ano
//         );
//         ng_ordem(raiz->esq);
//     }
// }

EABB *cria_EABB(Registro* dados) {
    EABB* novo = malloc(sizeof(EABB));
    novo->dados = dados;
    novo->esq = NULL;
    novo->dir = NULL;
    novo->pai = NULL;
    return novo;
}

ABB *cria_ABB() {
    ABB* nova = malloc(sizeof(ABB));
    nova->raiz = NULL;
    nova->qtde = 0;
    return nova;
}

void abbInserirPorIdade(ABB* arvore, Registro* dados) {
    EABB* novo = cria_EABB(dados);
    
    EABB* anterior = NULL;
    EABB* atual = arvore->raiz;

    while(atual != NULL) {
        anterior = atual;
        if(dados->Idade <= atual->dados->Idade) {
            atual = atual->esq;
        } else {
            atual = atual->dir;
        }
    }

    novo->pai = anterior;
    if(anterior != NULL) {
        if(dados->Idade <= anterior->dados->Idade) {
            anterior->esq = novo;
        } else {
            anterior->dir = novo;
        }
    } else {
        arvore->raiz = novo;
    }
    arvore->qtde++;
}

void abbInserirPorAno(ABB* arvore, Registro* dados) {
    EABB* novo = cria_EABB(dados);
    
    EABB* anterior = NULL;
    EABB* atual = arvore->raiz;

    while(atual != NULL) {
        anterior = atual;
        if(dados->Entrada->ano <= atual->dados->Entrada->ano) {
            atual = atual->esq;
        } else {
            atual = atual->dir;
        }
    }

    novo->pai = anterior;
    if(anterior != NULL) {
        if(dados->Entrada->ano <= anterior->dados->Entrada->ano) {
            anterior->esq = novo;
        } else {
            anterior->dir = novo;
        }
    } else {
        arvore->raiz = novo;
    }
    arvore->qtde++;
}

void abbInserirPorMes(ABB* arvore, Registro* dados) {
    EABB* novo = cria_EABB(dados);
    
    EABB* anterior = NULL;
    EABB* atual = arvore->raiz;

    while(atual != NULL) {
        anterior = atual;
        if(dados->Entrada->mes <= atual->dados->Entrada->mes) {
            atual = atual->esq;
        } else {
            atual = atual->dir;
        }
    }

    novo->pai = anterior;
    if(anterior != NULL) {
        if(dados->Entrada->mes <= anterior->dados->Entrada->mes) {
            anterior->esq = novo;
        } else {
            anterior->dir = novo;
        }
    } else {
        arvore->raiz = novo;
    }
    arvore->qtde++;
}

void abbInserirPorDia(ABB* arvore, Registro* dados) {
    EABB* novo = cria_EABB(dados);
    
    EABB* anterior = NULL;
    EABB* atual = arvore->raiz;

    while(atual != NULL) {
        anterior = atual;
        if(dados->Entrada->dia <= atual->dados->Entrada->dia) {
            atual = atual->esq;
        } else {
            atual = atual->dir;
        }
    }

    novo->pai = anterior;
    if(anterior != NULL) {
        if(dados->Entrada->dia <= anterior->dados->Entrada->dia) {
            anterior->esq = novo;
        } else {
            anterior->dir = novo;
        }
    } else {
        arvore->raiz = novo;
    }
    arvore->qtde++;
}

EABB* buscar_registro_em_subarvore(EABB* atual, Registro* registro) {
    if (atual == NULL) return NULL;
    
    if (atual->dados == registro) return atual;
    
    EABB* encontrado = buscar_registro_em_subarvore(atual->esq, registro);
    if (encontrado == NULL) {
        encontrado = buscar_registro_em_subarvore(atual->dir, registro);
    }
    return encontrado;
}

EABB* buscar_por_registro(ABB* arvore, Registro* registro) {
    if (arvore == NULL || registro == NULL) return NULL;
    return buscar_registro_em_subarvore(arvore->raiz, registro);
}

int abbRemoverPorRegistro(ABB* arvore, Registro* registro) {
    if (arvore == NULL || registro == NULL) return -1;

    EABB* vertice = buscar_por_registro(arvore, registro);
    if (vertice == NULL) return -1;

    EABB* pai = vertice->pai;
    int filhos = 0;
    if (vertice->esq != NULL) filhos++;
    if (vertice->dir != NULL) filhos++;

    if (filhos == 0) {
        if (pai != NULL) {
            if (pai->esq == vertice) pai->esq = NULL;
            else pai->dir = NULL;
        } else {
            arvore->raiz = NULL;
        }
        free(vertice);
    } else if (filhos == 1) {
        EABB* filho = (vertice->esq != NULL) ? vertice->esq : vertice->dir;
        
        if (pai != NULL) {
            if (pai->esq == vertice) pai->esq = filho;
            else pai->dir = filho;
        } else {
            arvore->raiz = filho;
        }
        filho->pai = pai;
        free(vertice);
    } else {
        EABB* sucessor = vertice->dir;
        while (sucessor->esq != NULL) {
            sucessor = sucessor->esq;
        }
        
        Registro* temp = vertice->dados;
        vertice->dados = sucessor->dados;
        sucessor->dados = temp;

        abbRemoverPorRegistro(arvore, temp);
        return 0;
    }
    
    arvore->qtde--;
    return 0;
}

// EABB *buscar_idade(ABB* arvore, int idade) {
//     EABB* atual = arvore->raiz;
//     while(atual != NULL) {
//         if(idade < atual->dados->Idade) {
//             atual = atual->esq;
//         } else if(idade > atual->dados->Idade) {
//             atual = atual->dir;
//         } else {
//             return atual;
//         }
//     }
//     return NULL;
// }