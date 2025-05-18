#include "abb.h"

void in_ordem(EABB *raiz) {
    if (raiz != NULL) {
        in_ordem(raiz->esq);
        printf("    Nome: %s, Idade: %d, RG: %s, Data de registro: %d/%d/%d\n", 
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

// void pre_ordem(EABB *raiz) {
//     if (raiz != NULL) {
//         printf("    Nome: %s, Idade: %d, RG: %s, Data de registro: %d/%d/%d\n", 
//             raiz->dados->Nome, 
//             raiz->dados->Idade,
//             raiz->dados->RG,
//             raiz->dados->Entrada->dia,
//             raiz->dados->Entrada->mes,
//             raiz->dados->Entrada->ano
//         );
//         pre_ordem(raiz->esq);
//         pre_ordem(raiz->dir);
//     }
// }

// void pos_ordem(EABB *raiz) {
//     if (raiz != NULL) {
//         pos_ordem(raiz->esq);
//         pos_ordem(raiz->dir);
//         printf("    Nome: %s, Idade: %d, RG: %s, Data de registro: %d/%d/%d\n", 
//             raiz->dados->Nome, 
//             raiz->dados->Idade,
//             raiz->dados->RG,
//             raiz->dados->Entrada->dia,
//             raiz->dados->Entrada->mes,
//             raiz->dados->Entrada->ano
//         );
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

void inserirPorIdade(ABB* arvore, Registro* dados) {
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