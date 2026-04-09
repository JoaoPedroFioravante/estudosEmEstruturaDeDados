#include "lista.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct no
{
    struct no *anterior;
    struct no *proximo;
    int value;
    
}No;

struct lista
{
    No*inicio;
    No*fim;
};

Lista * createLista(){
    Lista*lista = malloc(sizeof(Lista));
    if(lista!=NULL){
        lista->fim = NULL;
        lista->inicio = NULL;
    }
    return lista;
}

int adicionarNoFim(Lista*lista, int num){
    if(lista == NULL) return 0;
    No*novoNo = malloc(sizeof(No));
    if(novoNo == NULL) return 0;
    novoNo->value = num;
    if(lista->inicio == NULL){
        lista->inicio = novoNo;
    }
    if(lista->fim != NULL){
        lista->fim->proximo = novoNo;
    }
    novoNo->anterior = lista->fim;
    novoNo->proximo = NULL;
    lista->fim = novoNo;
    return 1;
}

int adicionarNoInicio(Lista*lista, int num){
    if(lista == NULL) return 0;
    No*novoNo = malloc(sizeof(No));
    if(novoNo == NULL) return 0;
    novoNo->anterior = NULL;
    novoNo->proximo = lista->inicio;
    novoNo->value = num;
    lista->inicio = novoNo;
    if(lista->fim == NULL){
        lista->fim = novoNo;
    }
    return 1;
}

int adicionarApos(Lista*lista, int numProcurado, int num){
    if(lista == NULL)return 0;
    if(lista->inicio == NULL) return 0;
    No*percorredor = lista->inicio;
    while (percorredor != NULL && percorredor->value != numProcurado)
    {
        percorredor = percorredor->proximo;
    }
    if(percorredor == NULL) return 0;
    No*novoNo = malloc(sizeof(No));
    if(novoNo == NULL) return 0;
    novoNo->value = num;
    novoNo->anterior = percorredor;
    novoNo->proximo = percorredor->proximo;
    percorredor->proximo = novoNo;
    if(percorredor == lista->fim){
        lista->fim = novoNo;
        return 1;
    }
    novoNo->proximo->anterior = novoNo;
    return 1;
}

int removerElemento(Lista*lista, int num){
    if(lista == NULL) return 0;
    if(lista->inicio == NULL) return 0;
    No*percorredor = lista->inicio;
    while ( percorredor!= NULL && percorredor->value != num)
    {
        percorredor = percorredor->proximo;
    }
    if(percorredor == NULL) return 0;
    if(percorredor == lista->inicio){
        lista->inicio = percorredor->proximo;
        if(percorredor == lista->fim){
            free(percorredor);
            lista->fim = NULL;
            return 1;
        }
    }
    if(lista->fim == percorredor){
        lista->fim = percorredor->anterior;
    }
    if (percorredor->proximo != NULL)
    {
        percorredor->proximo->anterior = percorredor->anterior;
    }
    if(percorredor->anterior != NULL){
        percorredor->anterior->proximo = percorredor->proximo;
    }
    //inicio
    // proximo.anterior = now.anterior
    // inicio = proximo
    //meio
    // anterior.proximo = proximo
    // proximo.anterior = anterior
    //fim
    // anterior.proximo = proximo
    // fim = anterior
    free(percorredor);
    return 1;
}

void exibirLista(Lista*lista){
    if(lista == NULL) return;
    if(lista->inicio == NULL) return;
    No*exibidor = lista->inicio;
    printf("================lista================\n");
    while(exibidor != NULL){
        printf("%d\n", exibidor->value);
        exibidor = exibidor->proximo;
    }
}
void freeLista(Lista*lista){
    if(lista == NULL) return;
    free(lista);
}