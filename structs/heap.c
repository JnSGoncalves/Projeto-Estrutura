#include "heap.h"

int filho_esq(int pai) { 
    return 2*pai + 1;
}

int filho_dir(int pai) { 
    return 2*pai + 2;
}

int pai(int filho) { 
    return (int) floor((filho - 1)/2);
}

int ultimo_pai(Heap *h) { 
    return (int) floor((h->qtde / 2)) - 1;
}

void peneirar(Heap *h, int pai) {
    int dir = filho_dir(pai);
    if(dir >= h->qtde)
    dir = pai;
    int esq = filho_esq(pai);
    if(esq >= h->qtde)
    esq = pai;
    
    int maior;
    maior = h->dados[dir]->Idade > h->dados[pai]->Idade ? dir : pai;
    maior = h->dados[esq]->Idade > h->dados[maior]->Idade ? esq : maior;
    
    if(maior == pai){
        return;
    }
    
    Registro *paiValor = h->dados[pai];
    h->dados[pai] = h->dados[maior];
    h->dados[maior] = paiValor;

    peneirar(h, maior);
}

void mostrarHeap(Heap *h) {
    for(int i = 0; i < h->qtde; i++){
        printf("    Nome: %s, Idade: %d, RG: %s, Data de registro: %d/%d/%d\n", 
            h->dados[i]->Nome, 
            h->dados[i]->Idade,
            h->dados[i]->RG,
            h->dados[i]->Entrada->dia,
            h->dados[i]->Entrada->mes,
            h->dados[i]->Entrada->ano
        );
    }
    printf("\n");
}

void construir(Heap *h) {
    for(int i = ultimo_pai(h); i >= 0; i--){
        peneirar(h, i);
    }
}

void inserirHeap(Heap *h, Registro *valor) {
    h->dados[h->qtde++] = valor;
    construir(h);
}

Registro* removerHeap(Heap *h) {
    if (h->qtde == 0)
        return NULL;

    Registro *prim = h->dados[0];
    h->dados[0] = h->dados[--h->qtde];
    peneirar(h, 0);
    return prim;
}