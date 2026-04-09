#include "lista.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct no
{
    int value;
    struct no *prox;
}No;


struct lista{
    No* inicio;
    No* fim;
};

Lista * createLista(){
    Lista*lista = malloc(sizeof(Lista));
    if(lista!=NULL){
        lista->inicio = NULL;
        lista->fim = NULL;
    }
    return lista;
}

int adicionarNoFim(Lista*lista, int num){
    if(lista == NULL) return 0;
    No * novoNo = malloc(sizeof(No));
    if(novoNo == NULL) return 0;
    novoNo->value = num;
    if(lista->inicio == NULL){
        lista->inicio = novoNo;
    }
    else{
        lista->fim->prox = novoNo;
    }
    lista->fim = novoNo;
    novoNo->prox = NULL;
    return 1;
}

int adicionarNoInicio(Lista*lista, int num){
    if(lista == NULL) return 0;
    No * novoNo = malloc(sizeof(No));
    if(novoNo == NULL) return 0;
    novoNo->value = num;
    // lista vazia
    // inicio e fim = novoNo
    // novoNo.prox = NULL
    // lista cheia
    // inicio = novoNo
    // novoNo.prox = INicio
    if(lista->inicio == NULL){
        lista->fim = novoNo;
        novoNo->prox = NULL;
    }
    else{
        novoNo->prox = lista->inicio;
    }
    lista->inicio = novoNo;
    return 1;
}

int adicionarApos(Lista*lista, int numProcurado, int num){
    if(lista ==  NULL) return 0;
    if(lista->inicio == NULL) return 0;
    No*novoNo = malloc(sizeof(No));
    if(novoNo == NULL) return 0;
    novoNo->value = num;
    No*percorredor = lista->inicio;
    while (percorredor->value != numProcurado && percorredor!= NULL)
    {
        percorredor = percorredor->prox;
    }
    if(percorredor == NULL) return 0;
    novoNo->prox = percorredor->prox;
    percorredor->prox = novoNo;
    if(lista->fim == percorredor){
        lista->fim = novoNo;
    }
    return 1;
}

int removerElemento(Lista*lista, int num){
    if(lista == NULL) return 0;
    if(lista->inicio == NULL) return 0;
    No*percorredor = lista->inicio;
    No*percorredorAux = NULL;
    while(percorredor->value != num && percorredor != NULL){
        percorredorAux = percorredor;
        percorredor = percorredor->prox;
    }
    if(percorredor == NULL) return 0;
    if(percorredor == lista->inicio){
        lista->inicio = percorredor->prox;
        if(percorredor == lista->fim){
            lista->fim == NULL;
        }
        free(percorredor);
        return 1;
    }
    percorredorAux->prox = percorredor->prox;
    if(percorredor == lista->fim){
        lista->fim = percorredorAux;
    }
    free(percorredor);
    return 1;
}
void exibirLista(Lista*lista){
    if(lista == NULL) return;
    if(lista->inicio == NULL) return;
    No*exibidor = lista->inicio;
    printf("==================lista==================\n");
    while(exibidor != NULL){
        printf("%d\n", exibidor->value);
        exibidor = exibidor->prox;
    }
}

void freeLista(Lista*lista){
    if(lista == NULL) return;
    free(lista);
}